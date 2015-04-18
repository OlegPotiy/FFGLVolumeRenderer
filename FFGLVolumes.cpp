#include "FFGL/FFGL.h"
#include "FFGL/FFGLLib.h"
#include "FFGLVolumes.h"
#include <gl\GLU.h>
#define USE_VBO

// Parameters
#define FFPARAM_VALUE1_IS_PERSPECTIVE (0)
#define FFPARAM_VALUE2_SCALE	(1)
#define FFPARAM_VALUE3_RX		(2)
#define FFPARAM_VALUE4_RY		(3)
#define FFPARAM_VALUE5_DISTANCE	(4)
#define FFPARAM_VALUE6_PCOUNT	(5)
#define FFPARAM_VALUE7_FOVY		(6)

////////////////////////////////////////////////////////////////////////////////////////////////////
//  Plugin information
////////////////////////////////////////////////////////////////////////////////////////////////////

static CFFGLPluginInfo PluginInfo ( 
	FFGLVolumeRendering::CreateInstance,	// Create method
	"VOLR",								// Plugin unique ID
	"FFGLVolume",     // Plugin name											
	1,						   			// API major version number 											
	000,								  // API minor version number	
	1,										// Plugin major version number
	000,									// Plugin minor version number
	FF_EFFECT,						// Plugin type
	"FFGL Volume rendering plug",	// Plugin description
	"by Oleg Potiy" // About
	);

static const int MaxPlanes = 200;


////////////////////////////////////////////////////////////////////////////////////////////////////
//  Constructor and destructor
////////////////////////////////////////////////////////////////////////////////////////////////////

FFGLVolumeRendering::FFGLVolumeRendering():CFreeFrameGLPlugin()
{
	// Input properties
	SetMinInputs(1);
	SetMaxInputs(1);

	// Parameters
	this->fXAngle = 0.5f;
	this->fYAngle = 0.5f;
	this->fScaleValue = 1.0f;

	this->fDistance = 1.0f;
	this->fPlanesCount = 0.5f;
	this->iPlanesCount = (float)MaxPlanes * this->fPlanesCount;

	this->fAngle = 0.5f;
	this->fScaleValue = 1.0f;

	this->fIsPerspective = 0.0f;

	SetParamInfo( FFPARAM_VALUE1_IS_PERSPECTIVE, "Perspective(?)", FF_TYPE_BOOLEAN, this->fIsPerspective);
	
	SetParamInfo( FFPARAM_VALUE2_SCALE , "Scale", FF_TYPE_STANDARD, this->fScaleValue);
	
	SetParamInfo( FFPARAM_VALUE3_RX  , "X angle", FF_TYPE_STANDARD, this->fXAngle);
	SetParamInfo( FFPARAM_VALUE4_RY  , "Y angle", FF_TYPE_STANDARD, this->fYAngle);

	SetParamInfo( FFPARAM_VALUE5_DISTANCE, "Volume level", FF_TYPE_STANDARD, this->fDistance);
	SetParamInfo( FFPARAM_VALUE6_PCOUNT  , "Planes count", FF_TYPE_STANDARD, this->fPlanesCount);

	SetParamInfo(FFPARAM_VALUE7_FOVY, "FOVY", FF_TYPE_STANDARD, this->fAngle);

	this->isGeometryRebuildNeeded = true;

	this->VertexData = NULL;
	this->TexcoordData = NULL;

}

FFGLVolumeRendering::~FFGLVolumeRendering()
{
	this->fXAngle = 0;
	this->fYAngle = 0;

}

DWORD FFGLVolumeRendering::InitGL(const FFGLViewportStruct *vp)
{
#ifndef  USE_VBO
	return FF_SUCCESS;
#else
	m_extensions.Initialize();
	bool lIsExtSupported = m_extensions.isExtensionSupported("GL_ARB_vertex_buffer_object");

	m_extensions.glGenBuffersARB(1, &(this->vboId));	
	m_extensions.glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);

	return lIsExtSupported ? FF_SUCCESS : FF_FAIL;
#endif
}

DWORD FFGLVolumeRendering::DeInitGL()
{
	return FF_SUCCESS;
} 

////////////////////////////////////////////////////////////////////////////////////////////////////
//  Methods
////////////////////////////////////////////////////////////////////////////////////////////////////

DWORD FFGLVolumeRendering::ProcessOpenGL(ProcessOpenGLStruct *pGL)
{
	if (pGL->numInputTextures<1)
		return FF_FAIL;

	if (pGL->inputTextures[0]==NULL)
		return FF_FAIL;

	


	FFGLTextureStruct &Texture = *(pGL->inputTextures[0]);

	//enable texturemapping
	glEnable(GL_TEXTURE_2D);

	//bind the texture handle
	glBindTexture(GL_TEXTURE_2D, Texture.Handle);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);


	

	//get the max s,t that correspond to the 
	//width,height of the used portion of the allocated texture space
	FFGLTexCoords maxCoords = GetMaxGLTexCoords(Texture);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR);


	glMatrixMode(GL_PROJECTION);		
	
	// Saving the projection matrix
	glPushMatrix();
	
	glLoadIdentity();

	// Setting parallel projection 
	if (this->fIsPerspective == 0) 
		glOrtho(-1,1,-1,1,-2,2);
	else
	{
		gluPerspective( 90.0*(this->fAngle + 0.5) , 1, 0.1, 100.0);
		gluLookAt( 0, 0, 1.5, 0, 0, 0, 0, 1, 0 );
	}

	

	float xRotationAngle = (this->fXAngle - 0.5) * 180;
	float yRotationAngle = (this->fYAngle - 0.5) * 180;


	glRotatef(xRotationAngle, 1, 0, 0);
	glRotatef(yRotationAngle, 0, 1, 0); 

	glScalef(this->fScaleValue, this->fScaleValue, this->fScaleValue);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	


#ifndef  USE_VBO

	if (this->isGeometryRebuildNeeded)
	{	
		this->isGeometryRebuildNeeded = false;
		this->iList = glGenLists(1);
		glNewList( this->iList, GL_COMPILE);
		if (this->iPlanesCount > 1)
		{			
			double dZStep = (double)this->fDistance/(double)(this->iPlanesCount - 1);
			glBegin(GL_QUADS);
			for (int i=0 ; i < this->iPlanesCount ; i++)
			{
				double ZCoord = -(this->fDistance/2) + dZStep * (double)i;        

				//lower left
				glTexCoord2d(0.0, 0.0);
				glVertex3f(-1, -1, ZCoord);

				//upper left
				glTexCoord2d(0.0, maxCoords.t);
				glVertex3f(-1, 1, ZCoord);

				//upper right
				glTexCoord2d(maxCoords.s, maxCoords.t);
				glVertex3f(1, 1, ZCoord);

				//lower right
				glTexCoord2d(maxCoords.s, 0.0);
				glVertex3f(1, -1, ZCoord);
			};
			glEnd();
		}
		else	
		{// simple quad:

			glBegin(GL_QUADS);

			//lower left
			glTexCoord2d(0.0, 0.0);
			glVertex3f(-1, -1, 0);

			//upper left
			glTexCoord2d(0.0, maxCoords.t);
			glVertex3f(-1, 1, 0);

			//upper right
			glTexCoord2d(maxCoords.s, maxCoords.t);
			glVertex3f(1, 1, 0);

			//lower right
			glTexCoord2d(maxCoords.s, 0.0);
			glVertex3f(1, -1, 0);

			glEnd();
		};
		glEndList();
	}

	glCallList(this->iList);
#else
	int vertextDataSize = 0;
	int texcoordDataSize = 0;

	if (this->isGeometryRebuildNeeded)
	{
		this->isGeometryRebuildNeeded = false;

		this->CreateArrayData(maxCoords);

		vertextDataSize = 4 * this->iPlanesCount * sizeof(GLVertexTriplet);
		texcoordDataSize = 4 * this->iPlanesCount * sizeof(GLTexcoords);

		m_extensions.glBindBufferARB(GL_ARRAY_BUFFER_ARB, vboId);
		m_extensions.glBufferDataARB(GL_ARRAY_BUFFER_ARB, vertextDataSize + texcoordDataSize, 0, GL_STATIC_DRAW_ARB);
		m_extensions.glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, 0, vertextDataSize, this->VertexData); // copy vertices starting from 0 offest
		m_extensions.glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, vertextDataSize, texcoordDataSize, this->TexcoordData); // copy texcoords after vertices;

		m_extensions.glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);


	}
	
	m_extensions.glBindBufferARB(GL_ARRAY_BUFFER_ARB, vboId);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	vertextDataSize = 4 * this->iPlanesCount * sizeof(GLVertexTriplet);
	texcoordDataSize = 4 * this->iPlanesCount * sizeof(GLTexcoords);

	glVertexPointer(3, GL_FLOAT, 0, 0);
	glTexCoordPointer(2, GL_FLOAT, 0, (void*)(vertextDataSize));

	glDrawArrays(GL_QUADS, 0, this->iPlanesCount*4);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	m_extensions.glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
	
#endif

	
	glMatrixMode(GL_PROJECTION);
	//Restoring projection matrix
	glPopMatrix();

	//unbind the texture
	glBindTexture(GL_TEXTURE_2D, 0);

	//disable texturemapping
	glDisable(GL_TEXTURE_2D);

	//disable blending
	glDisable(GL_BLEND);

	//restore default color
	glColor4f(1.f,1.f,1.f,1.f);

	return FF_SUCCESS;
}

void FFGLVolumeRendering::CreateArrayData(FFGLTexCoords maxCoords)
{

	if (this->VertexData != NULL) 
		delete this->VertexData;

	if (this->TexcoordData != NULL) 
		delete this->TexcoordData;


	

	this->VertexData = new FFGLVolumeRendering::GLVertexTriplet[4*this->iPlanesCount];
	this->TexcoordData = new FFGLVolumeRendering::GLTexcoords[4*this->iPlanesCount];

	if (this->iPlanesCount > 1)
	{			
		double dZStep = (double (this->fDistance))/(double (this->iPlanesCount - 1));	
		for (int i=0 ; i < this->iPlanesCount ; i++)
		{
			double ZCoord = -(this->fDistance/2) + dZStep * (double)i;        

			//lower left
			this->VertexData[4*i].x = -1;
			this->VertexData[4*i].y = -1;
			this->VertexData[4*i].z = ZCoord;
			this->TexcoordData[4*i].s = 0;
			this->TexcoordData[4*i].t = 0;

			//upper left
			this->VertexData[4*i + 1].x = -1;
			this->VertexData[4*i + 1].y = 1;
			this->VertexData[4*i + 1].z = ZCoord;
			this->TexcoordData[4 * i + 1].s = 0;
			this->TexcoordData[4 * i + 1].t = maxCoords.t;


			//upper right
			this->VertexData[4*i + 2].x = 1;
			this->VertexData[4*i + 2].y = 1;
			this->VertexData[4*i + 2].z = ZCoord;
			this->TexcoordData[4*i + 2].s = maxCoords.s;
			this->TexcoordData[4*i + 2].t = maxCoords.t;


			//lower right
			this->VertexData[4*i + 3].x = 1;
			this->VertexData[4*i + 3].y = -1;
			this->VertexData[4*i + 3].z = ZCoord;
			this->TexcoordData[4 * i + 3].s = maxCoords.s;
			this->TexcoordData[4 * i + 3].t = 0;
		};

	}
	else	
	{	// simple quad:

		//lower left
		this->VertexData[0].x = -1;
		this->VertexData[0].y = -1;
		this->VertexData[0].z = 0;
		this->TexcoordData[0].s = 0;
		this->TexcoordData[0].t = 0;

		//upper left
		this->VertexData[1].x = -1;
		this->VertexData[1].y = 1;
		this->VertexData[1].z = 0;
		this->TexcoordData[1].s = 0;
		this->TexcoordData[1].t = maxCoords.t;


		//upper right
		this->VertexData[2].x = 1;
		this->VertexData[2].y = 1;
		this->VertexData[2].z = 0;
		this->TexcoordData[2].s = maxCoords.s;
		this->TexcoordData[2].t = maxCoords.t;


		//lower right
		this->VertexData[3].x = 1;
		this->VertexData[3].y = -1;
		this->VertexData[3].z = 0;
		this->TexcoordData[3].s = maxCoords.s;
		this->TexcoordData[3].t = 0;
	};



}

DWORD FFGLVolumeRendering::GetParameter(DWORD dwIndex)
{
	DWORD dwRet;

	switch (dwIndex) {

	case FFPARAM_VALUE2_SCALE  :
		//sizeof(DWORD) must == sizeof(float)
		*((float *)(unsigned)(&dwRet)) = this->fScaleValue  ;
		return dwRet;

	case FFPARAM_VALUE3_RX:
		//sizeof(DWORD) must == sizeof(float)
		*((float *)(unsigned)(&dwRet)) = this->fXAngle;		
		return dwRet;

	case FFPARAM_VALUE4_RY:
		//sizeof(DWORD) must == sizeof(float)
		*((float *)(unsigned)(&dwRet)) = this->fYAngle;
		return dwRet;

	case FFPARAM_VALUE5_DISTANCE:
		//sizeof(DWORD) must == sizeof(float)
		*((float *)(unsigned)(&dwRet)) = this->fDistance;
		return dwRet;

	case FFPARAM_VALUE6_PCOUNT:
		//sizeof(DWORD) must == sizeof(float)
		*((float *)(unsigned)(&dwRet)) = this->fPlanesCount;
		return dwRet;

	case FFPARAM_VALUE7_FOVY:
		//sizeof(DWORD) must == sizeof(float)
		*((float *)(unsigned)(&dwRet)) = this->fAngle;
		return dwRet;

	default:
		return FF_FAIL;
	}
}

DWORD FFGLVolumeRendering::SetParameter(const SetParameterStruct* pParam)
{

	if (pParam != NULL) 
	{
		float fNewValue = *((float *)(unsigned)&(pParam->NewParameterValue));

		switch (pParam->ParameterNumber) {

		case FFPARAM_VALUE1_IS_PERSPECTIVE:
			this->fIsPerspective = fNewValue;
			break;

		case FFPARAM_VALUE2_SCALE:			
			this->fScaleValue = fNewValue;
			break;

		case FFPARAM_VALUE3_RX:					
			this->fXAngle = fNewValue;
			break;

		case FFPARAM_VALUE4_RY:			
			this->fYAngle = fNewValue;
			break;

		case FFPARAM_VALUE5_DISTANCE:
			if (this->fDistance != fNewValue)
			{ 
				this->fDistance = fNewValue;
				this->isGeometryRebuildNeeded  = true;
			};
			break;

		case FFPARAM_VALUE6_PCOUNT:
			if (this->fPlanesCount != fNewValue)
			{ 
				this->fPlanesCount = fNewValue;
				this->iPlanesCount = (float)MaxPlanes * this->fPlanesCount;
				if (this->iPlanesCount == 0)
					this->iPlanesCount = 1;
				this->isGeometryRebuildNeeded = true;
			};
			break;

		case FFPARAM_VALUE7_FOVY:			
			this->fAngle = fNewValue;
			break;

		default:
			return FF_FAIL;
		}

		return FF_SUCCESS;

	}

	return FF_FAIL;
}
