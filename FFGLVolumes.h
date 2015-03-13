#ifndef FFGLBRIGHTNESS_H
#define FFGLBRIGHTNESS_H

#include "FFGL/FFGLShader.h"
#include "FFGL/FFGLPluginSDK.h"


class FFGLVolumeRendering : public CFreeFrameGLPlugin
{
public:
    FFGLVolumeRendering();
    virtual ~FFGLVolumeRendering();

    ///////////////////////////////////////////////////
    // FreeFrame plugin methods
    ///////////////////////////////////////////////////

    DWORD	SetParameter(const SetParameterStruct* pParam);		
    DWORD	GetParameter(DWORD dwIndex);					
    DWORD	ProcessOpenGL(ProcessOpenGLStruct* pGL);
	DWORD	InitGL(const FFGLViewportStruct *vp);
	DWORD	DeInitGL();
 


    ///////////////////////////////////////////////////
    // Factory method
    ///////////////////////////////////////////////////

    static DWORD __stdcall CreateInstance(CFreeFrameGLPlugin **ppInstance)
    {
        *ppInstance = new FFGLVolumeRendering();
        if (*ppInstance != NULL) return FF_SUCCESS;
        return FF_FAIL;
    }

protected:	
    


private:


    float fXAngle;
    float fYAngle;
	float fScaleValue;
	float fDistance;
	float fPlanesCount;
	float fIsPerspective;

	float fAngle;

	GLuint iPlanesCount;

	
	
	GLuint iVertexArrayID;
	GLuint iTexcoordArrayID;

	FFGLExtensions m_extensions;
	
	struct GLVertexTriplet	{	GLfloat x,y,z;	};
	struct GLTexcoords		{	GLfloat s,t;	};

	FFGLVolumeRendering::GLVertexTriplet *VertexData;
	FFGLVolumeRendering::GLTexcoords *TexcoordData;

	
	GLuint iList;
	void CreateArrayData(FFGLTexCoords maxCoords);

	GLuint vboId = 0;                   // ID of VBO for vertex arrays

	GLuint vboId1 = 0;
	
	
	bool isGeometryRebuildNeeded;



};



#endif
