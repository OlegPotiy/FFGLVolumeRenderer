//
// Header file to libExt
//
// Author: Alex V. Boreskoff <steps3d@gmail.com>, <steps3d@narod.ru>
//

#ifndef __LIB_EXT__
#define __LIB_EXT__

#ifdef  _WIN32
    #include    <windows.h>
	#pragma warning (disable:4996)
#else
    #include	<stdint.h>
    #define GLX_GLXEXT_LEGACY
#endif

#include    <GL/gl.h>
#include    <GL/glu.h>
#include    "../glext.h"

#ifdef  _WIN32
    #include    "../wglext.h"
#else
    #include    "../glx.h"
    #include    "../glxext.h"
#endif

bool    isExtensionSupported ( const char * ext );
void    assertExtensionsSupported ( const char * extList );
void    initExtensions       ();
void    printfInfo           ();                // print info about card, driver, version & etc

const char * getGeneralExtensions  ();			// get list of platform-independant (GL) extensions
const char * getPlatformExtensions ();			// get list of extensions for current platform (WGL or GLX)

#ifdef  _WIN32
extern  PFNGLACTIVETEXTUREARBPROC               glActiveTextureARB;
extern  PFNGLCLIENTACTIVETEXTUREARBPROC         glClientActiveTextureARB;
extern  PFNGLMULTITEXCOORD1FARBPROC             glMultiTexCoord1f;
extern  PFNGLMULTITEXCOORD1FVARBPROC            glMultiTexCoord1fv;
extern  PFNGLMULTITEXCOORD2FARBPROC             glMultiTexCoord2f;
extern  PFNGLMULTITEXCOORD2FVARBPROC            glMultiTexCoord2fv;
extern  PFNGLMULTITEXCOORD3FARBPROC             glMultiTexCoord3f;
extern  PFNGLMULTITEXCOORD3FVARBPROC            glMultiTexCoord3fv;
extern  PFNGLMULTITEXCOORD4FARBPROC             glMultiTexCoord4f;
extern  PFNGLMULTITEXCOORD4FVARBPROC            glMultiTexCoord4fv;

	#define	glBindAttribLocation		glBindAttribLocationARB
#else
    #define  glActiveTextureARB         glActiveTexture
    #define  glClientActiveTextureARB   glClientActiveTexture
#endif
                                        // fog coord function
extern  PFNGLFOGCOORDFEXTPROC                      glFogCoordf;

                                        // secondary color functions
extern  PFNGLSECONDARYCOLOR3FPROC               glSecondaryColor3f;
extern  PFNGLSECONDARYCOLOR3FVPROC              glSecondaryColor3fv;
extern  PFNGLSECONDARYCOLORPOINTERPROC          glSecondaryColorPointer;

                                    // register combiners functions
extern  PFNGLCOMBINERPARAMETERFVNVPROC          glCombinerParameterfvNV;
extern  PFNGLCOMBINERPARAMETERIVNVPROC          glCombinerParameterivNV;
extern  PFNGLCOMBINERPARAMETERFNVPROC           glCombinerParameterfNV;
extern  PFNGLCOMBINERPARAMETERINVPROC           glCombinerParameteriNV;
extern  PFNGLCOMBINERINPUTNVPROC                glCombinerInputNV;
extern  PFNGLCOMBINEROUTPUTNVPROC               glCombinerOutputNV;
extern  PFNGLFINALCOMBINERINPUTNVPROC           glFinalCombinerInputNV;

                                    // VBO functions
extern  PFNGLBINDBUFFERARBPROC                  glBindBufferARB;
extern  PFNGLDELETEBUFFERSARBPROC               glDeleteBuffersARB;
extern  PFNGLGENBUFFERSARBPROC                  glGenBuffersARB;
extern  PFNGLISBUFFERARBPROC                    glIsBufferARB;
extern  PFNGLBUFFERDATAARBPROC                  glBufferDataARB;
extern  PFNGLBUFFERSUBDATAARBPROC               glBufferSubDataARB;
extern  PFNGLGETBUFFERSUBDATAARBPROC            glGetBufferSubDataARB;
extern  PFNGLMAPBUFFERARBPROC                   glMapBufferARB;
extern  PFNGLUNMAPBUFFERARBPROC                 glUnmapBufferARB;
extern  PFNGLGETBUFFERPARAMETERIVARBPROC        glGetBufferParameterivARB;
extern  PFNGLGETBUFFERPOINTERVARBPROC           glGetBufferPointervARB;

#ifdef  _WIN32
extern  PFNWGLGETEXTENSIONSSTRINGARBPROC        wglGetExtensionsStringARB;

                                    // p-buffer functions
extern  PFNWGLCREATEPBUFFERARBPROC              wglCreatePbufferARB;
extern  PFNWGLGETPBUFFERDCARBPROC               wglGetPbufferDCARB;
extern  PFNWGLRELEASEPBUFFERDCARBPROC           wglReleasePbufferDCARB;
extern  PFNWGLDESTROYPBUFFERARBPROC             wglDestroyPbufferARB;
extern  PFNWGLQUERYPBUFFERARBPROC               wglQueryPbufferARB;

                                    // WGL_ARB_pixel_format
extern  PFNWGLCHOOSEPIXELFORMATARBPROC          wglChoosePixelFormatARB;

                                    // WGL_ARB_render_texture
extern  PFNWGLBINDTEXIMAGEARBPROC               wglBindTexImageARB;
extern  PFNWGLRELEASETEXIMAGEARBPROC            wglReleaseTexImageARB;
extern  PFNWGLSETPBUFFERATTRIBARBPROC           wglSetPbufferAttribARB;

                                    // WGL_EXT_swap_control
extern  PFNWGLSWAPINTERVALEXTPROC               wglSwapIntervalEXT;
extern  PFNWGLGETSWAPINTERVALEXTPROC            wglGetSwapIntervalEXT;
#else
                                    // GLX_SGIX_pbuffer
extern  PFNGLXCREATEGLXPBUFFERSGIXPROC          glXCreateGLXPbufferSGIX;
extern  PFNGLXDESTROYGLXPBUFFERSGIXPROC         glXDestroyGLXPbufferSGIX;
extern  PFNGLXQUERYGLXPBUFFERSGIXPROC           glXQueryGLXPbufferSGIX;

                                    // GLX_SGIX_fbconfig
extern  PFNGLXCHOOSEFBCONFIGSGIXPROC            glXChooseFBConfigSGIX;
extern  PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC   glXCreateContextWithConfigSGIX;
#endif

                                    // NV-occlusion query extension
extern  PFNGLGENOCCLUSIONQUERIESNVPROC          glGenOcclusionQueriesNV;
extern  PFNGLBEGINOCCLUSIONQUERYNVPROC          glBeginOcclusionQueryNV;
extern  PFNGLENDOCCLUSIONQUERYNVPROC            glEndOcclusionQueryNV;
extern  PFNGLGETOCCLUSIONQUERYIVNVPROC          glGetOcclusionQueryivNV;

                                    // ARB_vertex_program extension
extern  PFNGLGENPROGRAMSARBPROC                 glGenProgramsARB;
extern  PFNGLDELETEPROGRAMSARBPROC              glDeleteProgramsARB;
extern  PFNGLBINDPROGRAMARBPROC                 glBindProgramARB;
extern  PFNGLISPROGRAMARBPROC                   glIsProgramARB;

extern  PFNGLPROGRAMSTRINGARBPROC               glProgramStringARB;
extern  PFNGLGETPROGRAMIVARBPROC                glGetProgramivARB;

extern  PFNGLVERTEXATTRIB4FARBPROC              glVertexAttrib4fARB;
extern  PFNGLVERTEXATTRIB4FVARBPROC             glVertexAttrib4fvARB;
extern  PFNGLVERTEXATTRIB3FARBPROC              glVertexAttrib3fARB;
extern  PFNGLVERTEXATTRIB3FVARBPROC             glVertexAttrib3fvARB;

extern  PFNGLVERTEXATTRIBPOINTERARBPROC         glVertexAttribPointerARB;
extern  PFNGLENABLEVERTEXATTRIBARRAYARBPROC     glEnableVertexAttribArrayARB;
extern  PFNGLDISABLEVERTEXATTRIBARRAYARBPROC    glDisableVertexAttribArrayARB;

extern  PFNGLPROGRAMLOCALPARAMETER4FARBPROC     glProgramLocalParameter4fARB;
extern  PFNGLPROGRAMLOCALPARAMETER4FVARBPROC    glProgramLocalParameter4fvARB;
extern  PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC  glGetProgramLocalParameterfvARB;

extern  PFNGLPROGRAMENVPARAMETER4FARBPROC       glProgramEnvParameter4fARB;
extern  PFNGLPROGRAMENVPARAMETER4FVARBPROC      glProgramEnvParameter4fvARB;
extern  PFNGLGETPROGRAMENVPARAMETERFVARBPROC    glGetProgramEnvParameterfvARB;

                                    // EXT_texture3D
extern  PFNGLTEXIMAGE3DEXTPROC                  glTexImage3DEXT;

                                    // ARB_texture_compression
extern  PFNGLCOMPRESSEDTEXIMAGE3DARBPROC        glCompressedTexImage3DARB;
extern  PFNGLCOMPRESSEDTEXIMAGE2DARBPROC        glCompressedTexImage2DARB;
extern  PFNGLCOMPRESSEDTEXIMAGE1DARBPROC        glCompressedTexImage1DARB;
extern  PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC     glCompressedTexSubImage3DARB;
extern  PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC     glCompressedTexSubImage2DARB;
extern  PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC     glCompressedTexSubImage1DARB;
extern  PFNGLGETCOMPRESSEDTEXIMAGEARBPROC       glGetCompressedTexImageARB;

                                    // ARB_point_parameters
extern  PFNGLPOINTPARAMETERFARBPROC             glPointParameterfARB;
extern  PFNGLPOINTPARAMETERFVARBPROC            glPointParameterfvARB;

                                    // ARB_occlusion_query
extern  PFNGLGENQUERIESARBPROC                  glGenQueriesARB;
extern  PFNGLDELETEQUERIESARBPROC               glDeleteQueriesARB;
extern  PFNGLISQUERYARBPROC                     glIsQueryARB;
extern  PFNGLBEGINQUERYARBPROC                  glBeginQueryARB;
extern  PFNGLENDQUERYARBPROC                    glEndQueryARB;
extern  PFNGLGETQUERYIVARBPROC                  glGetQueryivARB;
extern  PFNGLGETQUERYOBJECTIVARBPROC            glGetQueryObjectivARB;
extern  PFNGLGETQUERYOBJECTUIVARBPROC           glGetQueryObjectuivARB;

                                    // GLSL-specific extensions
                                    // GL_ARB_shader_object
extern  PFNGLDELETEOBJECTARBPROC                glDeleteObjectARB;
extern  PFNGLGETHANDLEARBPROC                   glGetHandleARB;
extern  PFNGLDETACHOBJECTARBPROC                glDetachObjectARB;
extern  PFNGLCREATESHADEROBJECTARBPROC          glCreateShaderObjectARB;
extern  PFNGLSHADERSOURCEARBPROC                glShaderSourceARB;
extern  PFNGLCOMPILESHADERARBPROC               glCompileShaderARB;
extern  PFNGLCREATEPROGRAMOBJECTARBPROC         glCreateProgramObjectARB;
extern  PFNGLATTACHOBJECTARBPROC                glAttachObjectARB;
extern  PFNGLLINKPROGRAMARBPROC                 glLinkProgramARB;
extern  PFNGLUSEPROGRAMOBJECTARBPROC            glUseProgramObjectARB;
extern  PFNGLVALIDATEPROGRAMARBPROC             glValidateProgramARB;
extern  PFNGLUNIFORM1FARBPROC                   glUniform1fARB;
extern  PFNGLUNIFORM2FARBPROC                   glUniform2fARB;
extern  PFNGLUNIFORM3FARBPROC                   glUniform3fARB;
extern  PFNGLUNIFORM4FARBPROC                   glUniform4fARB;
extern  PFNGLUNIFORM1IARBPROC                   glUniform1iARB;
extern  PFNGLUNIFORM2IARBPROC                   glUniform2iARB;
extern  PFNGLUNIFORM3IARBPROC                   glUniform3iARB;
extern  PFNGLUNIFORM4IARBPROC                   glUniform4iARB;
extern  PFNGLUNIFORM1FVARBPROC                  glUniform1fvARB;
extern  PFNGLUNIFORM2FVARBPROC                  glUniform2fvARB;
extern  PFNGLUNIFORM3FVARBPROC                  glUniform3fvARB;
extern  PFNGLUNIFORM4FVARBPROC                  glUniform4fvARB;
extern  PFNGLUNIFORM1IVARBPROC                  glUniform1ivARB;
extern  PFNGLUNIFORM2IVARBPROC                  glUniform2ivARB;
extern  PFNGLUNIFORM3IVARBPROC                  glUniform3ivARB;
extern  PFNGLUNIFORM4IVARBPROC                  glUniform4ivARB;
extern  PFNGLUNIFORMMATRIX2FVARBPROC            glUniformMatrix2fvARB;
extern  PFNGLUNIFORMMATRIX3FVARBPROC            glUniformMatrix3fvARB;
extern  PFNGLUNIFORMMATRIX4FVARBPROC            glUniformMatrix4fvARB;
extern  PFNGLGETOBJECTPARAMETERFVARBPROC        glGetObjectParameterfvARB;
extern  PFNGLGETOBJECTPARAMETERIVARBPROC        glGetObjectParameterivARB;
extern  PFNGLGETINFOLOGARBPROC                  glGetInfoLogARB;
extern  PFNGLGETATTACHEDOBJECTSARBPROC          glGetAttachedObjectsARB;
extern  PFNGLGETUNIFORMLOCATIONARBPROC          glGetUniformLocationARB;
extern  PFNGLGETACTIVEUNIFORMARBPROC            glGetActiveUniformARB;
extern  PFNGLGETUNIFORMFVARBPROC                glGetUniformfvARB;
extern  PFNGLGETUNIFORMIVARBPROC                glGetUniformivARB;
extern  PFNGLGETSHADERSOURCEARBPROC             glGetShaderSourceARB;

                                        // GL_ARB_vertex_shader
extern  PFNGLBINDATTRIBLOCATIONARBPROC          glBindAttribLocationARB;
extern  PFNGLGETACTIVEATTRIBARBPROC             glGetActiveAttribARB;
extern  PFNGLGETATTRIBLOCATIONARBPROC           glGetAttribLocationARB;
extern  PFNGLGETVERTEXATTRIBFVARBPROC           glGetVertexAttribfvARB;

                                        // EXT_stencil_two_side
extern  PFNGLACTIVESTENCILFACEEXTPROC           glActiveStencilFaceEXT;

										// EXT_depth_bounds_test
extern	PFNGLDEPTHBOUNDSEXTPROC					glDepthBoundsEXT;

										// EXT_framebuffer_object
extern	PFNGLISRENDERBUFFEREXTPROC						glIsRenderbufferEXT;
extern	PFNGLBINDRENDERBUFFEREXTPROC					glBindRenderbufferEXT;
extern	PFNGLDELETERENDERBUFFERSEXTPROC					glDeleteRenderbuffersEXT;
extern	PFNGLGENRENDERBUFFERSEXTPROC					glGenRenderbuffersEXT;
extern	PFNGLRENDERBUFFERSTORAGEEXTPROC					glRenderbufferStorageEXT;
extern	PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC			glGetRenderbufferParameterivEXT;
extern	PFNGLISFRAMEBUFFEREXTPROC						glIsFramebufferEXT;
extern	PFNGLBINDFRAMEBUFFEREXTPROC						glBindFramebufferEXT;
extern	PFNGLDELETEFRAMEBUFFERSEXTPROC					glDeleteFramebuffersEXT;
extern	PFNGLGENFRAMEBUFFERSEXTPROC						glGenFramebuffersEXT;
extern	PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC				glCheckFramebufferStatusEXT;
extern	PFNGLFRAMEBUFFERTEXTURE1DEXTPROC				glFramebufferTexture1DEXT;
extern	PFNGLFRAMEBUFFERTEXTURE2DEXTPROC				glFramebufferTexture2DEXT;
extern	PFNGLFRAMEBUFFERTEXTURE3DEXTPROC				glFramebufferTexture3DEXT;
extern	PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC				glFramebufferRenderbufferEXT;
extern	PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC	glGetFramebufferAttachmentParameterivEXT;
extern	PFNGLGENERATEMIPMAPEXTPROC						glGenerateMipmapEXT;


#ifndef	GL_VERSION_1_3										// ARB_transpose matrix
extern	PFNGLLOADTRANSPOSEMATRIXFPROC					glLoadTransposeMatrixfARB;
extern	PFNGLLOADTRANSPOSEMATRIXDPROC					glLoadTransposeMatrixdARB;
extern	PFNGLMULTTRANSPOSEMATRIXFPROC					glMultTransposeMatrixfARB;
extern	PFNGLMULTTRANSPOSEMATRIXDPROC					glMultTransposeMatrixdARB;
#endif

															// ARB_color_buffer_float
extern	PFNGLCLAMPCOLORARBPROC							glClampColorARB;
															
#ifdef	_WIN32												// fresh Linux already has 2.0
															// stenccl ops from OpenGL 2.0
extern	PFNGLSTENCILFUNCSEPARATEPROC			glStencilFuncSeparate;
extern	PFNGLSTENCILOPSEPARATEPROC				glStencilOpSeparate;
extern	PFNGLSTENCILMASKSEPARATEPROC			glStencilMaskSeparate;

															// blend ops from OpenGL 2.0
extern	PFNGLBLENDEQUATIONPROC					glBlendEquation;
extern	PFNGLBLENDEQUATIONSEPARATEPROC		 	glBlendEquationSeparate;
extern	PFNGLBLENDFUNCSEPARATEPROC				glBlendFuncSeparate;
extern	PFNGLBLENDCOLORPROC						glBlendColor;
#endif

															// draw buffers from OpenGL 2.0
extern	PFNGLDRAWBUFFERSPROC					glDrawBuffers;
															// ATI_draw_buffers
extern	PFNGLDRAWBUFFERSATIPROC					glDrawBuffersATI;

															// EXT_texture_integer
extern	PFNGLTEXPARAMETERIIVEXTPROC				glTexParameterIivEXT;
extern	PFNGLTEXPARAMETERIUIVEXTPROC			glTexParameterIuivEXT;
extern	PFNGLGETTEXPARAMETERIIVEXTPROC			glGetTexParameterIivEXT;
extern	PFNGLGETTEXPARAMETERIUIVEXTPROC			glGetTexParameterIuivEXT;
extern	PFNGLCLEARCOLORIIEXTPROC				glClearColorIiEXT;
extern	PFNGLCLEARCOLORIUIEXTPROC				glClearColorIuiEXT;

															// EXT_draw_instanced
extern	PFNGLDRAWARRAYSINSTANCEDEXTPROC			glDrawArraysInstancedEXT;
extern	PFNGLDRAWELEMENTSINSTANCEDEXTPROC		glDrawElementsInstancedEXT;


															// EXT_texture_buffer_object
extern	PFNGLTEXBUFFEREXTPROC 					glTexBufferEXT;
															
															// EXT_gpu_shader4
extern	PFNGLGETUNIFORMUIVEXTPROC				glGetUniformuivEXT;
extern	PFNGLBINDFRAGDATALOCATIONEXTPROC		glBindFragDataLocationEXT;
extern	PFNGLGETFRAGDATALOCATIONEXTPROC			glGetFragDataLocationEXT;
extern	PFNGLUNIFORM1UIEXTPROC					glUniform1uiEXT;
extern	PFNGLUNIFORM2UIEXTPROC					glUniform2uiEXT;
extern	PFNGLUNIFORM3UIEXTPROC					glUniform3uiEXT;
extern	PFNGLUNIFORM4UIEXTPROC					glUniform4uiEXT;
extern	PFNGLUNIFORM1UIVEXTPROC					glUniform1uivEXT;
extern	PFNGLUNIFORM2UIVEXTPROC					glUniform2uivEXT;
extern	PFNGLUNIFORM3UIVEXTPROC					glUniform3uivEXT;
extern	PFNGLUNIFORM4UIVEXTPROC					glUniform4uivEXT;
extern	PFNGLVERTEXATTRIBI1IEXTPROC				glVertexAttribI1iEXT;
extern	PFNGLVERTEXATTRIBI2IEXTPROC				glVertexAttribI2iEXT;
extern	PFNGLVERTEXATTRIBI3IEXTPROC				glVertexAttribI3iEXT;
extern	PFNGLVERTEXATTRIBI4IEXTPROC				glVertexAttribI4iEXT;
extern	PFNGLVERTEXATTRIBI1UIEXTPROC			glVertexAttribI1uiEXT;
extern	PFNGLVERTEXATTRIBI2UIEXTPROC			glVertexAttribI2uiEXT;
extern	PFNGLVERTEXATTRIBI3UIEXTPROC			glVertexAttribI3uiEXT;
extern	PFNGLVERTEXATTRIBI4UIEXTPROC			glVertexAttribI4uiEXT;
extern	PFNGLVERTEXATTRIBI1IVEXTPROC			glVertexAttribI1ivEXT;
extern	PFNGLVERTEXATTRIBI2IVEXTPROC			glVertexAttribI2ivEXT;
extern	PFNGLVERTEXATTRIBI3IVEXTPROC			glVertexAttribI3ivEXT;
extern	PFNGLVERTEXATTRIBI4IVEXTPROC			glVertexAttribI4ivEXT;
extern	PFNGLVERTEXATTRIBI1UIVEXTPROC			glVertexAttribI1uivEXT;
extern	PFNGLVERTEXATTRIBI2UIVEXTPROC			glVertexAttribI2uivEXT;
extern	PFNGLVERTEXATTRIBI3UIVEXTPROC			glVertexAttribI3uivEXT;
extern	PFNGLVERTEXATTRIBI4UIVEXTPROC			glVertexAttribI4uivEXT;
extern	PFNGLVERTEXATTRIBI4BVEXTPROC			glVertexAttribI4bvEXT;
extern	PFNGLVERTEXATTRIBI4SVEXTPROC			glVertexAttribI4svEXT;
extern	PFNGLVERTEXATTRIBI4UBVEXTPROC			glVertexAttribI4ubvEXT;
extern	PFNGLVERTEXATTRIBI4USVEXTPROC			glVertexAttribI4usvEXT;
extern	PFNGLVERTEXATTRIBIPOINTEREXTPROC		glVertexAttribIPointerEXT;
extern	PFNGLGETVERTEXATTRIBIIVEXTPROC			glGetVertexAttribIivEXT;
extern	PFNGLGETVERTEXATTRIBIUIVEXTPROC			glGetVertexAttribIuivEXT;
															
														// EXT_geometry_shader4
extern	PFNGLPROGRAMPARAMETERIEXTPROC			glProgramParameteriEXT;
extern	PFNGLFRAMEBUFFERTEXTUREEXTPROC			glFramebufferTextureEXT;
extern	PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC		glFramebufferTextureLayerEXT;
extern	PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC		glFramebufferTextureFaceEXT;

														// EXT_bindable_uniform
extern	PFNGLUNIFORMBUFFEREXTPROC				glUniformBufferEXT;
extern	PFNGLGETUNIFORMBUFFERSIZEEXTPROC		glGetUniformBufferSizeEXT;
extern	PFNGLGETUNIFORMOFFSETEXTPROC			glGetUniformOffsetEXT;

														// OpenGL 2.0 shader 														
extern	PFNGLCOMPILESHADERPROC					glCompileShader;
extern	PFNGLCREATEPROGRAMPROC					glCreateProgram;
extern	PFNGLCREATESHADERPROC					glCreateShader;
extern	PFNGLDELETEPROGRAMPROC					glDeleteProgram;
extern	PFNGLDELETESHADERPROC					glDeleteShader;
extern	PFNGLDETACHSHADERPROC					glDetachShader;
extern	PFNGLGETPROGRAMINFOLOGPROC				glGetProgramInfoLog;
extern	PFNGLGETSHADERINFOLOGPROC				glGetShaderInfoLog;
extern	PFNGLGETSHADERSOURCEPROC				glGetShaderSource;
extern	PFNGLLINKPROGRAMPROC					glLinkProgram;
extern	PFNGLSHADERSOURCEPROC					glShaderSource;
extern	PFNGLUSEPROGRAMPROC						glUseProgram;
extern	PFNGLVALIDATEPROGRAMPROC				glValidateProgram;
extern	PFNGLGETPROGRAMIVPROC					glGetProgramiv;
extern	PFNGLGETSHADERIVPROC					glGetShaderiv;
extern	PFNGLATTACHSHADERPROC					glAttachShader;
extern	PFNGLGETUNIFORMLOCATIONPROC				glGetUniformLocation;
extern	PFNGLGETATTRIBLOCATIONPROC				glGetAttribLocation;

extern	PFNGLUNIFORM4FVPROC						glUniform4fv;
extern	PFNGLUNIFORM3FVPROC						glUniform3fv;
extern	PFNGLUNIFORM2FVPROC						glUniform2fv;
extern	PFNGLUNIFORM1FPROC						glUniform1f;
extern	PFNGLUNIFORM1IPROC						glUniform1i;
extern	PFNGLUNIFORMMATRIX2FVPROC				glUniformMatrix2fv;
extern	PFNGLUNIFORMMATRIX3FVPROC				glUniformMatrix3fv;
extern	PFNGLUNIFORMMATRIX4FVPROC				glUniformMatrix4fv;
extern	PFNGLGETUNIFORMFVPROC					glGetUniformfv;
extern	PFNGLVERTEXATTRIB4FVPROC				glVertexAttrib4fv;
extern	PFNGLGETVERTEXATTRIBFVPROC				glGetVertexAttribfv;

                                    // OOpenGL 2 query support
extern  PFNGLGENQUERIESPROC                  glGenQueries;
extern  PFNGLDELETEQUERIESPROC               glDeleteQueries;
extern  PFNGLISQUERYPROC                     glIsQuery;
extern  PFNGLBEGINQUERYPROC                  glBeginQuery;
extern  PFNGLENDQUERYPROC                    glEndQuery;
extern  PFNGLGETQUERYIVPROC                  glGetQueryiv;
extern  PFNGLGETQUERYOBJECTIVPROC            glGetQueryObjectiv;
extern  PFNGLGETQUERYOBJECTUIVPROC           glGetQueryObjectuiv;


														// NV_transform_feedback
extern	PFNGLBEGINTRANSFORMFEEDBACKNVPROC		glBeginTransformFeedbackNV;
extern	PFNGLENDTRANSFORMFEEDBACKNVPROC			glEndTransformFeedbackNV;
extern	PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC		glTransformFeedbackAttribsNV;
extern	PFNGLBINDBUFFERRANGENVPROC				glBindBufferRangeNV;
extern	PFNGLBINDBUFFEROFFSETNVPROC				glBindBufferOffsetNV;
extern	PFNGLBINDBUFFERBASENVPROC				glBindBufferBaseNV;
extern	PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC	glTransformFeedbackVaryingsNV;
extern	PFNGLACTIVEVARYINGNVPROC				glActiveVaryingNV;
extern	PFNGLGETVARYINGLOCATIONNVPROC			glGetVaryingLocationNV;
extern	PFNGLGETACTIVEVARYINGNVPROC				glGetActiveVaryingNV;
extern	PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC	glGetTransformFeedbackVaryingNV;

														// NV_fence
extern	PFNGLDELETEFENCESNVPROC					glDeleteFencesNV;
extern	PFNGLGENFENCESNVPROC					glGenFencesNV;
extern	PFNGLISFENCENVPROC						glIsFenceNV;
extern	PFNGLTESTFENCENVPROC					glTestFenceNV;
extern	PFNGLGETFENCEIVNVPROC					glGetFenceivNV;
extern	PFNGLFINISHFENCENVPROC					glFinishFenceNV;
extern	PFNGLSETFENCENVPROC						glSetFenceNV;

														// NV__conditional_render
extern	PFNGLBEGINCONDITIONALRENDERNVPROC		glBeginConditionalRenderNV;
extern	PFNGLENDCONDITIONALRENDERNVPROC			glEndConditionalRenderNV;

														// ARB_sampler_objects
#ifndef	PFNGLGENSAMPLERSPROC
	typedef void (APIENTRYP PFNGLGENSAMPLERSPROC) (GLsizei count, GLuint *samplers);
	typedef void (APIENTRYP PFNGLDELETESAMPLERSPROC) (GLsizei count, const GLuint *samplers);
	typedef GLboolean (APIENTRYP PFNGLISSAMPLERPROC) (GLuint sampler);
	typedef void (APIENTRYP PFNGLBINDSAMPLERPROC) (GLuint unit, GLuint sampler);
	typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIPROC) (GLuint sampler, GLenum pname, GLint param);
	typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIVPROC) (GLuint sampler, GLenum pname, const GLint *param);
	typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFPROC) (GLuint sampler, GLenum pname, GLfloat param);
	typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFVPROC) (GLuint sampler, GLenum pname, const GLfloat *param);
	typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIIVPROC) (GLuint sampler, GLenum pname, const GLint *param);
	typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC) (GLuint sampler, GLenum pname, const GLuint *param);
	typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC) (GLuint sampler, GLenum pname, GLint *params);
	typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC) (GLuint sampler, GLenum pname, GLint *params);
	typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC) (GLuint sampler, GLenum pname, GLfloat *params);
	typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIFVPROC) (GLuint sampler, GLenum pname, GLfloat *params);
#endif

extern	PFNGLGENSAMPLERSPROC			glGenSamplers;
extern	PFNGLDELETESAMPLERSPROC			glDeleteSamplers;
extern	PFNGLISSAMPLERPROC				glIsSampler;
extern	PFNGLBINDSAMPLERPROC			glBindSampler;
extern	PFNGLSAMPLERPARAMETERIPROC		glSamplerParameteri;
extern	PFNGLSAMPLERPARAMETERIVPROC		glSamplerParameteriv;
extern	PFNGLSAMPLERPARAMETERFPROC		glSamplerParameterf;
extern	PFNGLSAMPLERPARAMETERFVPROC		glSamplerParameterfv;
extern	PFNGLSAMPLERPARAMETERIIVPROC	glSamplerParameterIiv;
extern	PFNGLSAMPLERPARAMETERIUIVPROC	glSamplerParameterIuiv;
extern	PFNGLGETSAMPLERPARAMETERIVPROC	glGetSamplerParameteriv;
extern	PFNGLGETSAMPLERPARAMETERIIVPROC	glGetSamplerParameterIiv;
extern	PFNGLGETSAMPLERPARAMETERFVPROC	glGetSamplerParameterfv;
extern	PFNGLGETSAMPLERPARAMETERIFVPROC	glGetSamplerParameterIfv;
														
														// ARB_vertex_array_object
extern	PFNGLBINDVERTEXARRAYPROC		glBindVertexArray;
extern	PFNGLDELETEVERTEXARRAYSPROC		glDeleteVertexArrays;
extern	PFNGLGENVERTEXARRAYSPROC		glGenVertexArrays;
extern	PFNGLISVERTEXARRAYPROC			glIsVertexArray;

														// ARB_get_program_binary
#define	GL_PROGRAM_BINARY_RETRIEVABLE_HINT             0x8257
#define	GL_PROGRAM_BINARY_LENGTH                       0x8741
#define	GL_NUM_PROGRAM_BINARY_FORMATS                  0x87FE
#define	GL_PROGRAM_BINARY_FORMATS                      0x87FF

typedef void (APIENTRYP PFNGLGETPROGRAMBINARYPROC)  ( GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, GLvoid *binary );
typedef void (APIENTRYP PFNGLPROGRAMBINARYPROC)     ( GLuint program, GLenum binaryFormat, const GLvoid *binary, GLsizei length );
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIPROC) ( GLuint program, GLenum pname, GLint value );

extern PFNGLGETPROGRAMBINARYPROC  glGetProgramBinary;
extern PFNGLPROGRAMBINARYPROC     glProgramBinary;
extern PFNGLPROGRAMPARAMETERIPROC glProgramParameteri;

														// ARB_instanced_arrays
extern	PFNGLVERTEXATTRIBDIVISORARBPROC	glVertexAttribDivisor;

														// ARB_timer_query
extern PFNGLQUERYCOUNTERPROC			glQueryCounter;
extern	PFNGLGETQUERYOBJECTI64VPROC		glGetQueryObjecti64v;
extern	PFNGLGETQUERYOBJECTUI64VPROC	glGetQueryObjectui64v;

														// ARB_sync
extern	PFNGLFENCESYNCPROC		glFenceSync;
extern	PFNGLISSYNCPROC			glIsSync;
extern	PFNGLDELETESYNCPROC		glDeleteSync;
extern	PFNGLCLIENTWAITSYNCPROC	glClientWaitSync;
extern	PFNGLWAITSYNCPROC		glWaitSync;
extern	PFNGLGETINTEGER64VPROC	glGetInteger64v;
extern	PFNGLGETSYNCIVPROC		glGetSynciv;

														// ARB_separate_shader_objects
extern	PFNGLUSEPROGRAMSTAGESPROC		glUseProgramStages;
extern	PFNGLACTIVESHADERPROGRAMPROC	glActiveShaderProgram;
extern	PFNGLCREATESHADERPROGRAMVPROC	glCreateShaderProgramv;
extern	PFNGLBINDPROGRAMPIPELINEPROC	glBindProgramPipeline;
extern	PFNGLDELETEPROGRAMPIPELINESPROC	glDeleteProgramPipelines;
extern	PFNGLGENPROGRAMPIPELINESPROC	glGenProgramPipelines;
extern	PFNGLISPROGRAMPIPELINEPROC		glIsProgramPipeline;
extern	PFNGLGETPROGRAMPIPELINEIVPROC	glGetProgramPipelineiv;
extern	PFNGLPROGRAMUNIFORM1IPROC		glProgramUniform1i;
extern	PFNGLPROGRAMUNIFORM1IVPROC		glProgramUniform1iv;
extern	PFNGLPROGRAMUNIFORM1FPROC		glProgramUniform1f;
extern	PFNGLPROGRAMUNIFORM1FVPROC		glProgramUniform1fv;
extern	PFNGLPROGRAMUNIFORM1DPROC		glProgramUniform1d;
extern	PFNGLPROGRAMUNIFORM1DVPROC		glProgramUniform1dv;
extern	PFNGLPROGRAMUNIFORM1UIPROC		glProgramUniform1ui;
extern	PFNGLPROGRAMUNIFORM1UIVPROC		glProgramUniform1uiv;
extern	PFNGLPROGRAMUNIFORM2IPROC		glProgramUniform2i;
extern	PFNGLPROGRAMUNIFORM2IVPROC		glProgramUniform2iv;
extern	PFNGLPROGRAMUNIFORM2FPROC		glProgramUniform2f;
extern	PFNGLPROGRAMUNIFORM2FVPROC		glProgramUniform2fv;
extern	PFNGLPROGRAMUNIFORM2DPROC		glProgramUniform2d;
extern	PFNGLPROGRAMUNIFORM2DVPROC		glProgramUniform2dv;
extern	PFNGLPROGRAMUNIFORM2UIPROC		glProgramUniform2ui;
extern	PFNGLPROGRAMUNIFORM2UIVPROC		glProgramUniform2uiv;
extern	PFNGLPROGRAMUNIFORM3IPROC		glProgramUniform3i;
extern	PFNGLPROGRAMUNIFORM3IVPROC		glProgramUniform3iv;
extern	PFNGLPROGRAMUNIFORM3FPROC		glProgramUniform3f;
extern	PFNGLPROGRAMUNIFORM3FVPROC		glProgramUniform3fv;
extern	PFNGLPROGRAMUNIFORM3DPROC		glProgramUniform3d;
extern	PFNGLPROGRAMUNIFORM3DVPROC		glProgramUniform3dv;
extern	PFNGLPROGRAMUNIFORM3UIPROC		glProgramUniform3ui;
extern	PFNGLPROGRAMUNIFORM3UIVPROC		glProgramUniform3uiv;
extern	PFNGLPROGRAMUNIFORM4IPROC		glProgramUniform4i;
extern	PFNGLPROGRAMUNIFORM4IVPROC		glProgramUniform4iv;
extern	PFNGLPROGRAMUNIFORM4FPROC		glProgramUniform4f;
extern	PFNGLPROGRAMUNIFORM4FVPROC		glProgramUniform4fv;
extern	PFNGLPROGRAMUNIFORM4DPROC		glProgramUniform4d;
extern	PFNGLPROGRAMUNIFORM4DVPROC		glProgramUniform4dv;
extern	PFNGLPROGRAMUNIFORM4UIPROC		glProgramUniform4ui;
extern	PFNGLPROGRAMUNIFORM4UIVPROC		glProgramUniform4uiv;
extern	PFNGLPROGRAMUNIFORMMATRIX2FVPROC	glProgramUniformMatrix2fv;
extern	PFNGLPROGRAMUNIFORMMATRIX3FVPROC	glProgramUniformMatrix3fv;
extern	PFNGLPROGRAMUNIFORMMATRIX4FVPROC	glProgramUniformMatrix4fv;
extern	PFNGLPROGRAMUNIFORMMATRIX2DVPROC	glProgramUniformMatrix2dv;
extern	PFNGLPROGRAMUNIFORMMATRIX3DVPROC	glProgramUniformMatrix3dv;
extern	PFNGLPROGRAMUNIFORMMATRIX4DVPROC	glProgramUniformMatrix4dv;
extern	PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC	glProgramUniformMatrix2x3fv;
extern	PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC	glProgramUniformMatrix3x2fv;
extern	PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC	glProgramUniformMatrix2x4fv;
extern	PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC	glProgramUniformMatrix4x2fv;
extern	PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC	glProgramUniformMatrix3x4fv;
extern	PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC	glProgramUniformMatrix4x3fv;
extern	PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC	glProgramUniformMatrix2x3dv;
extern	PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC	glProgramUniformMatrix3x2dv;
extern	PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC	glProgramUniformMatrix2x4dv;
extern	PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC	glProgramUniformMatrix4x2dv;
extern	PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC	glProgramUniformMatrix3x4dv;
extern	PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC	glProgramUniformMatrix4x3dv;
extern	PFNGLVALIDATEPROGRAMPIPELINEPROC	glValidateProgramPipeline;
extern	PFNGLGETPROGRAMPIPELINEINFOLOGPROC	glGetProgramPipelineInfoLog;

/////////////////////////////////////////////////////////////////////////////////////

/*
											// ARB_ES2_compatibility
extern	PFNGLRELEASESHADERCOMPILERPROC			glReleaseShaderCompiler;
extern	PFNGLSHADERBINARYPROC					glShaderBinary;
extern	PFNGLGETSHADERPRECISIONFORMATPROC		glGetShaderPrecisionFormat;
extern	PFNGLDEPTHRANGEFPROC					glDepthRangef;
extern	PFNGLCLEARDEPTHFPROC					glClearDepthf;
*/
											// ARB_transform_feedback3
extern	PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC	glDrawTransformFeedbackStream;
extern	PFNGLBEGINQUERYINDEXEDPROC				glBeginQueryIndexed;
extern	PFNGLENDQUERYINDEXEDPROC				glEndQueryIndexed;
extern	PFNGLGETQUERYINDEXEDIVPROC				glGetQueryIndexediv;
												
											// ARB_transform_feedback2
extern	PFNGLBINDTRANSFORMFEEDBACKPROC			glBindTransformFeedback;
extern	PFNGLDELETETRANSFORMFEEDBACKSPROC		glDeleteTransformFeedbacks;
extern	PFNGLGENTRANSFORMFEEDBACKSPROC			glGenTransformFeedbacks;
extern	PFNGLISTRANSFORMFEEDBACKPROC			glIsTransformFeedback;
extern	PFNGLPAUSETRANSFORMFEEDBACKPROC			glPauseTransformFeedback;
extern	PFNGLRESUMETRANSFORMFEEDBACKPROC		glResumeTransformFeedback;
extern	PFNGLDRAWTRANSFORMFEEDBACKPROC			glDrawTransformFeedback;

											// ARB_tessellation_shader
extern	PFNGLPATCHPARAMETERIPROC				glPatchParameteri;
extern	PFNGLPATCHPARAMETERFVPROC				glPatchParameterfv;

											// ARB_draw_indirect
extern	PFNGLDRAWARRAYSINDIRECTPROC				glDrawArraysIndirect;
extern	PFNGLDRAWELEMENTSINDIRECTPROC			glDrawElementsIndirect;

											// ARB_blend_func_extended
extern	PFNGLBINDFRAGDATALOCATIONINDEXEDPROC	glBindFragDataLocationIndexed;
extern	PFNGLGETFRAGDATAINDEXPROC				glGetFragDataIndex;

											// ARB_shading_language_include
extern	PFNGLNAMEDSTRINGARBPROC				glNamedStringARB;
extern	PFNGLDELETENAMEDSTRINGARBPROC		glDeleteNamedStringARB;
extern	PFNGLCOMPILESHADERINCLUDEARBPROC	glCompileShaderIncludeARB;
extern	PFNGLISNAMEDSTRINGARBPROC			glIsNamedStringARB;
extern	PFNGLGETNAMEDSTRINGARBPROC			glGetNamedStringARB;
extern	PFNGLGETNAMEDSTRINGIVARBPROC		glGetNamedStringivARB;

											// ARB_sample_shading
extern	PFNGLMINSAMPLESHADINGARBPROC		glMinSampleShadingARB;

											// ARB_draw_buffers_blend
extern	PFNGLBLENDEQUATIONIARBPROC			glBlendEquationiARB;
extern	PFNGLBLENDEQUATIONSEPARATEIARBPROC	glBlendEquationSeparateiARB;
extern	PFNGLBLENDFUNCIARBPROC				glBlendFunciARB;
extern	PFNGLBLENDFUNCSEPARATEIARBPROC		glBlendFuncSeparateiARB;

											// ARB_provoking_vertex
extern	PFNGLPROVOKINGVERTEXPROC			glProvokingVertex;

											// ARB_draw_elements_base_vertex
extern	PFNGLDRAWELEMENTSBASEVERTEXPROC				glDrawElementsBaseVertex;
extern	PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC		glDrawRangeElementsBaseVertex;
extern	PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC	glDrawElementsInstancedBaseVertex;
extern	PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC		glMultiDrawElementsBaseVertex;

											// ARB_copy_buffer
extern	PFNGLCOPYBUFFERSUBDATAPROC		glCopyBufferSubData;

											// ARB_uniform_buffer_object
extern	PFNGLGETUNIFORMINDICESPROC			glGetUniformIndices;
extern	PFNGLGETACTIVEUNIFORMSIVPROC		glGetActiveUniformsiv;
extern	PFNGLGETACTIVEUNIFORMNAMEPROC		glGetActiveUniformName;
extern	PFNGLGETUNIFORMBLOCKINDEXPROC		glGetUniformBlockIndex;
extern	PFNGLGETACTIVEUNIFORMBLOCKIVPROC	glGetActiveUniformBlockiv;
extern	PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC	glGetActiveUniformBlockName;
extern	PFNGLUNIFORMBLOCKBINDINGPROC		glUniformBlockBinding;

											// ARB_texture_buffer_object
extern	PFNGLTEXBUFFERARBPROC	glTexBufferARB;

											// ARB_map_buffer_range
extern	PFNGLMAPBUFFERRANGEPROC			glMapBufferRange;
extern	PFNGLFLUSHMAPPEDBUFFERRANGEPROC	glFlushMappedBufferRange;

											// ARB_geometry_shader4
extern	PFNGLPROGRAMPARAMETERIARBPROC			glProgramParameteriARB;
extern	PFNGLFRAMEBUFFERTEXTUREARBPROC			glFramebufferTextureARB;
extern	PFNGLFRAMEBUFFERTEXTURELAYERARBPROC		glFramebufferTextureLayerARB;
extern	PFNGLFRAMEBUFFERTEXTUREFACEARBPROC		glFramebufferTextureFaceARB;
											
											// ARB_framebuffer_object
extern	PFNGLISRENDERBUFFERPROC							glIsRenderbuffer;
extern	PFNGLBINDRENDERBUFFERPROC						glBindRenderbuffer;
extern	PFNGLDELETERENDERBUFFERSPROC					glDeleteRenderbuffers;
extern	PFNGLGENRENDERBUFFERSPROC						glGenRenderbuffers;
extern	PFNGLRENDERBUFFERSTORAGEPROC					glRenderbufferStorage;
extern	PFNGLGETRENDERBUFFERPARAMETERIVPROC				glGetRenderbufferParameteriv;
extern	PFNGLISFRAMEBUFFERPROC							glIsFramebuffer;
extern	PFNGLBINDFRAMEBUFFERPROC						glBindFramebuffer;
extern	PFNGLDELETEFRAMEBUFFERSPROC						glDeleteFramebuffers;
extern	PFNGLGENFRAMEBUFFERSPROC						glGenFramebuffers;
extern	PFNGLCHECKFRAMEBUFFERSTATUSPROC					glCheckFramebufferStatus;
extern	PFNGLFRAMEBUFFERTEXTURE1DPROC					glFramebufferTexture1D;
extern	PFNGLFRAMEBUFFERTEXTURE2DPROC					glFramebufferTexture2D;
extern	PFNGLFRAMEBUFFERTEXTURE3DPROC					glFramebufferTexture3D;
extern	PFNGLFRAMEBUFFERRENDERBUFFERPROC				glFramebufferRenderbuffer;
extern	PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC	glGetFramebufferAttachmentParameteriv;
extern	PFNGLGENERATEMIPMAPPROC							glGenerateMipmap;
extern	PFNGLBLITFRAMEBUFFERPROC						glBlitFramebuffer;
extern	PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC			glRenderbufferStorageMultisample;
extern	PFNGLFRAMEBUFFERTEXTURELAYERPROC				glFramebufferTextureLayer;

											// ARB_draw_instanced
extern	PFNGLDRAWARRAYSINSTANCEDARBPROC					glDrawArraysInstancedARB;
extern	PFNGLDRAWELEMENTSINSTANCEDARBPROC				glDrawElementsInstancedARB;

											// ARB_draw_buffers
extern	PFNGLDRAWBUFFERSARBPROC			glDrawBuffersARB;
												
											// ARB_multisample
extern	PFNGLSAMPLECOVERAGEARBPROC		glSampleCoverageARB;

											// EXT_shader_image_load_store
extern	PFNGLBINDIMAGETEXTUREEXTPROC	glBindImageTextureEXT;
extern	PFNGLMEMORYBARRIEREXTPROC		glMemoryBarrierEXT;

											// EXT_direct_state_access
extern	PFNGLCLIENTATTRIBDEFAULTEXTPROC				glClientAttribDefaultEXT;
extern	PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC			glPushClientAttribDefaultEXT;
extern	PFNGLMATRIXLOADFEXTPROC						glMatrixLoadfEXT;
extern	PFNGLMATRIXLOADDEXTPROC						glMatrixLoaddEXT;
extern	PFNGLMATRIXMULTFEXTPROC						glMatrixMultfEXT;
extern	PFNGLMATRIXMULTDEXTPROC						glMatrixMultdEXT;
extern	PFNGLMATRIXLOADIDENTITYEXTPROC				glMatrixLoadIdentityEXT;
extern	PFNGLMATRIXROTATEFEXTPROC					glMatrixRotatefEXT;
extern	PFNGLMATRIXROTATEDEXTPROC					glMatrixRotatedEXT;
extern	PFNGLMATRIXSCALEFEXTPROC					glMatrixScalefEXT;
extern	PFNGLMATRIXSCALEDEXTPROC					glMatrixScaledEXT;
extern	PFNGLMATRIXTRANSLATEFEXTPROC				glMatrixTranslatefEXT;
extern	PFNGLMATRIXTRANSLATEDEXTPROC				glMatrixTranslatedEXT;
extern	PFNGLMATRIXFRUSTUMEXTPROC					glMatrixFrustumEXT;
extern	PFNGLMATRIXORTHOEXTPROC						glMatrixOrthoEXT;
extern	PFNGLMATRIXPOPEXTPROC						glMatrixPopEXT;
extern	PFNGLMATRIXPUSHEXTPROC						glMatrixPushEXT;
extern	PFNGLMATRIXLOADTRANSPOSEFEXTPROC			glMatrixLoadTransposefEXT;
extern	PFNGLMATRIXLOADTRANSPOSEDEXTPROC			glMatrixLoadTransposedEXT;
extern	PFNGLMATRIXMULTTRANSPOSEFEXTPROC			glMatrixMultTransposefEXT;
extern	PFNGLMATRIXMULTTRANSPOSEDEXTPROC			glMatrixMultTransposedEXT;
extern	PFNGLTEXTUREPARAMETERFEXTPROC				glTextureParameterfEXT;
extern	PFNGLTEXTUREPARAMETERFVEXTPROC				glTextureParameterfvEXT;
extern	PFNGLTEXTUREPARAMETERIEXTPROC				glTextureParameteriEXT;
extern	PFNGLTEXTUREPARAMETERIVEXTPROC				glTextureParameterivEXT;
extern	PFNGLTEXTUREIMAGE1DEXTPROC					glTextureImage1DEXT;
extern	PFNGLTEXTUREIMAGE2DEXTPROC					glTextureImage2DEXT;
extern	PFNGLTEXTURESUBIMAGE1DEXTPROC				glTextureSubImage1DEXT;
extern	PFNGLTEXTURESUBIMAGE2DEXTPROC				glTextureSubImage2DEXT;
extern	PFNGLCOPYTEXTUREIMAGE1DEXTPROC				glCopyTextureImage1DEXT;
extern	PFNGLCOPYTEXTUREIMAGE2DEXTPROC				glCopyTextureImage2DEXT;
extern	PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC			glCopyTextureSubImage1DEXT;
extern	PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC			glCopyTextureSubImage2DEXT;
extern	PFNGLGETTEXTUREIMAGEEXTPROC					glGetTextureImageEXT;
extern	PFNGLGETTEXTUREPARAMETERFVEXTPROC			glGetTextureParameterfvEXT;
extern	PFNGLGETTEXTUREPARAMETERIVEXTPROC			glGetTextureParameterivEXT;
extern	PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC		glGetTextureLevelParameterfvEXT;
extern	PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC		glGetTextureLevelParameterivEXT;
extern	PFNGLTEXTUREIMAGE3DEXTPROC					glTextureImage3DEXT;
extern	PFNGLTEXTURESUBIMAGE3DEXTPROC				glTextureSubImage3DEXT;
extern	PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC			glCopyTextureSubImage3DEXT;
extern	PFNGLMULTITEXPARAMETERFEXTPROC				glMultiTexParameterfEXT;
extern	PFNGLMULTITEXPARAMETERFVEXTPROC				glMultiTexParameterfvEXT;
extern	PFNGLMULTITEXPARAMETERIEXTPROC				glMultiTexParameteriEXT;
extern	PFNGLMULTITEXPARAMETERIVEXTPROC				glMultiTexParameterivEXT;
extern	PFNGLMULTITEXIMAGE1DEXTPROC					glMultiTexImage1DEXT;
extern	PFNGLMULTITEXIMAGE2DEXTPROC					glMultiTexImage2DEXT;
extern	PFNGLMULTITEXSUBIMAGE1DEXTPROC				glMultiTexSubImage1DEXT;
extern	PFNGLMULTITEXSUBIMAGE2DEXTPROC				glMultiTexSubImage2DEXT;
extern	PFNGLCOPYMULTITEXIMAGE1DEXTPROC				glCopyMultiTexImage1DEXT;
extern	PFNGLCOPYMULTITEXIMAGE2DEXTPROC				glCopyMultiTexImage2DEXT;
extern	PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC			glCopyMultiTexSubImage1DEXT;
extern	PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC			glCopyMultiTexSubImage2DEXT;
extern	PFNGLGETMULTITEXIMAGEEXTPROC				glGetMultiTexImageEXT;
extern	PFNGLGETMULTITEXPARAMETERFVEXTPROC			glGetMultiTexParameterfvEXT;
extern	PFNGLGETMULTITEXPARAMETERIVEXTPROC			glGetMultiTexParameterivEXT;
extern	PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC		glGetMultiTexLevelParameterfvEXT;
extern	PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC		glGetMultiTexLevelParameterivEXT;
extern	PFNGLMULTITEXIMAGE3DEXTPROC					glMultiTexImage3DEXT;
extern	PFNGLMULTITEXSUBIMAGE3DEXTPROC				glMultiTexSubImage3DEXT;
extern	PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC			glCopyMultiTexSubImage3DEXT;
extern	PFNGLBINDMULTITEXTUREEXTPROC				glBindMultiTextureEXT;
extern	PFNGLENABLECLIENTSTATEINDEXEDEXTPROC		glEnableClientStateIndexedEXT;
extern	PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC		glDisableClientStateIndexedEXT;
extern	PFNGLMULTITEXCOORDPOINTEREXTPROC			glMultiTexCoordPointerEXT;
extern	PFNGLMULTITEXENVFEXTPROC					glMultiTexEnvfEXT;
extern	PFNGLMULTITEXENVFVEXTPROC					glMultiTexEnvfvEXT;
extern	PFNGLMULTITEXENVIEXTPROC					glMultiTexEnviEXT;
extern	PFNGLMULTITEXENVIVEXTPROC					glMultiTexEnvivEXT;
extern	PFNGLMULTITEXGENDEXTPROC					glMultiTexGendEXT;
extern	PFNGLMULTITEXGENDVEXTPROC					glMultiTexGendvEXT;
extern	PFNGLMULTITEXGENFEXTPROC					glMultiTexGenfEXT;
extern	PFNGLMULTITEXGENFVEXTPROC					glMultiTexGenfvEXT;
extern	PFNGLMULTITEXGENIEXTPROC					glMultiTexGeniEXT;
extern	PFNGLMULTITEXGENIVEXTPROC					glMultiTexGenivEXT;
extern	PFNGLGETMULTITEXENVFVEXTPROC				glGetMultiTexEnvfvEXT;
extern	PFNGLGETMULTITEXENVIVEXTPROC				glGetMultiTexEnvivEXT;
extern	PFNGLGETMULTITEXGENDVEXTPROC				glGetMultiTexGendvEXT;
extern	PFNGLGETMULTITEXGENFVEXTPROC				glGetMultiTexGenfvEXT;
extern	PFNGLGETMULTITEXGENIVEXTPROC				glGetMultiTexGenivEXT;
extern	PFNGLGETFLOATINDEXEDVEXTPROC				glGetFloatIndexedvEXT;
extern	PFNGLGETDOUBLEINDEXEDVEXTPROC				glGetDoubleIndexedvEXT;
extern	PFNGLGETPOINTERINDEXEDVEXTPROC				glGetPointerIndexedvEXT;
extern	PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC		glCompressedTextureImage3DEXT;
extern	PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC		glCompressedTextureImage2DEXT;
extern	PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC		glCompressedTextureImage1DEXT;
extern	PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC		glCompressedTextureSubImage3DEXT;
extern	PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC		glCompressedTextureSubImage2DEXT;
extern	PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC		glCompressedTextureSubImage1DEXT;
extern	PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC		glGetCompressedTextureImageEXT;
extern	PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC		glCompressedMultiTexImage3DEXT;
extern	PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC		glCompressedMultiTexImage2DEXT;
extern	PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC		glCompressedMultiTexImage1DEXT;
extern	PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC	glCompressedMultiTexSubImage3DEXT;
extern	PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC	glCompressedMultiTexSubImage2DEXT;
extern	PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC	glCompressedMultiTexSubImage1DEXT;
extern	PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC		glGetCompressedMultiTexImageEXT;
extern	PFNGLNAMEDPROGRAMSTRINGEXTPROC					glNamedProgramStringEXT;
extern	PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC		glNamedProgramLocalParameter4dEXT;
extern	PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC		glNamedProgramLocalParameter4dvEXT;
extern	PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC		glNamedProgramLocalParameter4fEXT;
extern	PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC		glNamedProgramLocalParameter4fvEXT;
extern	PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC		glGetNamedProgramLocalParameterdvEXT;
extern	PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC		glGetNamedProgramLocalParameterfvEXT;
extern	PFNGLGETNAMEDPROGRAMIVEXTPROC					glGetNamedProgramivEXT;
extern	PFNGLGETNAMEDPROGRAMSTRINGEXTPROC				glGetNamedProgramStringEXT;
extern	PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC		glNamedProgramLocalParameters4fvEXT;
extern	PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC		glNamedProgramLocalParameterI4iEXT;
extern	PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC		glNamedProgramLocalParameterI4ivEXT;
extern	PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC		glNamedProgramLocalParametersI4ivEXT;
extern	PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC		glNamedProgramLocalParameterI4uiEXT;
extern	PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC		glNamedProgramLocalParameterI4uivEXT;
extern	PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC	glNamedProgramLocalParametersI4uivEXT;
extern	PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC	glGetNamedProgramLocalParameterIivEXT;
extern	PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC	glGetNamedProgramLocalParameterIuivEXT;
extern	PFNGLTEXTUREPARAMETERIIVEXTPROC							glTextureParameterIivEXT;
extern	PFNGLTEXTUREPARAMETERIUIVEXTPROC						glTextureParameterIuivEXT;
extern	PFNGLGETTEXTUREPARAMETERIIVEXTPROC						glGetTextureParameterIivEXT;
extern	PFNGLGETTEXTUREPARAMETERIUIVEXTPROC						glGetTextureParameterIuivEXT;
extern	PFNGLMULTITEXPARAMETERIIVEXTPROC						glMultiTexParameterIivEXT;
extern	PFNGLMULTITEXPARAMETERIUIVEXTPROC						glMultiTexParameterIuivEXT;
extern	PFNGLGETMULTITEXPARAMETERIIVEXTPROC						glGetMultiTexParameterIivEXT;
extern	PFNGLGETMULTITEXPARAMETERIUIVEXTPROC					glGetMultiTexParameterIuivEXT;
extern	PFNGLPROGRAMUNIFORM1FEXTPROC							glProgramUniform1fEXT;
extern	PFNGLPROGRAMUNIFORM2FEXTPROC							glProgramUniform2fEXT;
extern	PFNGLPROGRAMUNIFORM3FEXTPROC							glProgramUniform3fEXT;
extern	PFNGLPROGRAMUNIFORM4FEXTPROC							glProgramUniform4fEXT;
extern	PFNGLPROGRAMUNIFORM1IEXTPROC							glProgramUniform1iEXT;
extern	PFNGLPROGRAMUNIFORM2IEXTPROC							glProgramUniform2iEXT;
extern	PFNGLPROGRAMUNIFORM3IEXTPROC							glProgramUniform3iEXT;
extern	PFNGLPROGRAMUNIFORM4IEXTPROC							glProgramUniform4iEXT;
extern	PFNGLPROGRAMUNIFORM1FVEXTPROC							glProgramUniform1fvEXT;
extern	PFNGLPROGRAMUNIFORM2FVEXTPROC							glProgramUniform2fvEXT;
extern	PFNGLPROGRAMUNIFORM3FVEXTPROC							glProgramUniform3fvEXT;
extern	PFNGLPROGRAMUNIFORM4FVEXTPROC							glProgramUniform4fvEXT;
extern	PFNGLPROGRAMUNIFORM1IVEXTPROC							glProgramUniform1ivEXT;
extern	PFNGLPROGRAMUNIFORM2IVEXTPROC							glProgramUniform2ivEXT;
extern	PFNGLPROGRAMUNIFORM3IVEXTPROC							glProgramUniform3ivEXT;
extern	PFNGLPROGRAMUNIFORM4IVEXTPROC							glProgramUniform4ivEXT;
extern	PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC						glProgramUniformMatrix2fvEXT;
extern	PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC						glProgramUniformMatrix3fvEXT;
extern	PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC						glProgramUniformMatrix4fvEXT;
extern	PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC					glProgramUniformMatrix2x3fvEXT;
extern	PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC					glProgramUniformMatrix3x2fvEXT;
extern	PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC					glProgramUniformMatrix2x4fvEXT;
extern	PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC					glProgramUniformMatrix4x2fvEXT;
extern	PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC					glProgramUniformMatrix3x4fvEXT;
extern	PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC					glProgramUniformMatrix4x3fvEXT;
extern	PFNGLPROGRAMUNIFORM1UIEXTPROC							glProgramUniform1uiEXT;
extern	PFNGLPROGRAMUNIFORM2UIEXTPROC							glProgramUniform2uiEXT;
extern	PFNGLPROGRAMUNIFORM3UIEXTPROC							glProgramUniform3uiEXT;
extern	PFNGLPROGRAMUNIFORM4UIEXTPROC							glProgramUniform4uiEXT;
extern	PFNGLPROGRAMUNIFORM1UIVEXTPROC							glProgramUniform1uivEXT;
extern	PFNGLPROGRAMUNIFORM2UIVEXTPROC							glProgramUniform2uivEXT;
extern	PFNGLPROGRAMUNIFORM3UIVEXTPROC							glProgramUniform3uivEXT;
extern	PFNGLPROGRAMUNIFORM4UIVEXTPROC							glProgramUniform4uivEXT;
extern	PFNGLNAMEDBUFFERDATAEXTPROC								glNamedBufferDataEXT;
extern	PFNGLNAMEDBUFFERSUBDATAEXTPROC							glNamedBufferSubDataEXT;
extern	PFNGLMAPNAMEDBUFFEREXTPROC								glMapNamedBufferEXT;
extern	PFNGLUNMAPNAMEDBUFFEREXTPROC							glUnmapNamedBufferEXT;
extern	PFNGLMAPNAMEDBUFFERRANGEEXTPROC							glMapNamedBufferRangeEXT;
extern	PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC					glFlushMappedNamedBufferRangeEXT;
extern	PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC						glNamedCopyBufferSubDataEXT;
extern	PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC					glGetNamedBufferParameterivEXT;
extern	PFNGLGETNAMEDBUFFERPOINTERVEXTPROC						glGetNamedBufferPointervEXT;
extern	PFNGLGETNAMEDBUFFERSUBDATAEXTPROC						glGetNamedBufferSubDataEXT;
extern	PFNGLTEXTUREBUFFEREXTPROC								glTextureBufferEXT;
extern	PFNGLMULTITEXBUFFEREXTPROC								glMultiTexBufferEXT;
extern	PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC					glNamedRenderbufferStorageEXT;
extern	PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC				glGetNamedRenderbufferParameterivEXT;
extern	PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC					glCheckNamedFramebufferStatusEXT;
extern	PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC					glNamedFramebufferTexture1DEXT;
extern	PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC					glNamedFramebufferTexture2DEXT;
extern	PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC					glNamedFramebufferTexture3DEXT;
extern	PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC				glNamedFramebufferRenderbufferEXT;
extern	PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC	glGetNamedFramebufferAttachmentParameterivEXT;
extern	PFNGLGENERATETEXTUREMIPMAPEXTPROC						glGenerateTextureMipmapEXT;
extern	PFNGLGENERATEMULTITEXMIPMAPEXTPROC						glGenerateMultiTexMipmapEXT;
extern	PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC						glFramebufferDrawBufferEXT;
extern	PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC						glFramebufferDrawBuffersEXT;
extern	PFNGLFRAMEBUFFERREADBUFFEREXTPROC						glFramebufferReadBufferEXT;
extern	PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC					glGetFramebufferParameterivEXT;
extern	PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC			glNamedRenderbufferStorageMultisampleEXT;
extern	PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC	glNamedRenderbufferStorageMultisampleCoverageEXT;
extern	PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC						glNamedFramebufferTextureEXT;
extern	PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC				glNamedFramebufferTextureLayerEXT;
extern	PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC					glNamedFramebufferTextureFaceEXT;
extern	PFNGLTEXTURERENDERBUFFEREXTPROC							glTextureRenderbufferEXT;
extern	PFNGLMULTITEXRENDERBUFFEREXTPROC						glMultiTexRenderbufferEXT;
extern	PFNGLPROGRAMUNIFORM1DEXTPROC							glProgramUniform1dEXT;
extern	PFNGLPROGRAMUNIFORM2DEXTPROC							glProgramUniform2dEXT;
extern	PFNGLPROGRAMUNIFORM3DEXTPROC							glProgramUniform3dEXT;
extern	PFNGLPROGRAMUNIFORM4DEXTPROC							glProgramUniform4dEXT;
extern	PFNGLPROGRAMUNIFORM1DVEXTPROC							glProgramUniform1dvEXT;
extern	PFNGLPROGRAMUNIFORM2DVEXTPROC							glProgramUniform2dvEXT;
extern	PFNGLPROGRAMUNIFORM3DVEXTPROC							glProgramUniform3dvEXT;
extern	PFNGLPROGRAMUNIFORM4DVEXTPROC							glProgramUniform4dvEXT;
extern	PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC						glProgramUniformMatrix2dvEXT;
extern	PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC						glProgramUniformMatrix3dvEXT;
extern	PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC						glProgramUniformMatrix4dvEXT;
extern	PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC					glProgramUniformMatrix2x3dvEXT;
extern	PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC					glProgramUniformMatrix2x4dvEXT;
extern	PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC					glProgramUniformMatrix3x2dvEXT;
extern	PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC					glProgramUniformMatrix3x4dvEXT;
extern	PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC					glProgramUniformMatrix4x2dvEXT;
extern	PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC					glProgramUniformMatrix4x3dvEXT;

											// ARB_robustness
extern	PFNGLGETGRAPHICSRESETSTATUSARBPROC		glGetGraphicsResetStatusARB;
extern	PFNGLGETNMAPDVARBPROC					glGetnMapdvARB;
extern	PFNGLGETNMAPFVARBPROC					glGetnMapfvARB;
extern	PFNGLGETNMAPIVARBPROC					glGetnMapivARB;
extern	PFNGLGETNPIXELMAPFVARBPROC				glGetnPixelMapfvARB;
extern	PFNGLGETNPIXELMAPUIVARBPROC				glGetnPixelMapuivARB;
extern	PFNGLGETNPIXELMAPUSVARBPROC				glGetnPixelMapusvARB;
extern	PFNGLGETNPOLYGONSTIPPLEARBPROC			glGetnPolygonStippleARB;
extern	PFNGLGETNCOLORTABLEARBPROC				glGetnColorTableARB;
extern	PFNGLGETNCONVOLUTIONFILTERARBPROC		glGetnConvolutionFilterARB;
extern	PFNGLGETNSEPARABLEFILTERARBPROC			glGetnSeparableFilterARB;
extern	PFNGLGETNHISTOGRAMARBPROC				glGetnHistogramARB;
extern	PFNGLGETNMINMAXARBPROC					glGetnMinmaxARB;
extern	PFNGLGETNTEXIMAGEARBPROC				glGetnTexImageARB;
extern	PFNGLREADNPIXELSARBPROC					glReadnPixelsARB;
extern	PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC		glGetnCompressedTexImageARB;
extern	PFNGLGETNUNIFORMFVARBPROC				glGetnUniformfvARB;
extern	PFNGLGETNUNIFORMIVARBPROC				glGetnUniformivARB;
extern	PFNGLGETNUNIFORMUIVARBPROC				glGetnUniformuivARB;
extern	PFNGLGETNUNIFORMDVARBPROC				glGetnUniformdvARB;

											// ARB_debug_output
extern	PFNGLDEBUGMESSAGECONTROLARBPROC			glDebugMessageControlARB;
extern	PFNGLDEBUGMESSAGEINSERTARBPROC			glDebugMessageInsertARB;
extern	PFNGLDEBUGMESSAGECALLBACKARBPROC		glDebugMessageCallbackARB;
extern	PFNGLGETDEBUGMESSAGELOGARBPROC			glGetDebugMessageLogARB;
											
											// ARB_cl_event
extern	PFNGLCREATESYNCFROMCLEVENTARBPROC	glCreateSyncFromCLeventARB;

											// ARB_viewport_array
extern	PFNGLVIEWPORTARRAYVPROC		glViewportArrayv;
extern	PFNGLVIEWPORTINDEXEDFPROC	glViewportIndexedf;
extern	PFNGLVIEWPORTINDEXEDFVPROC	glViewportIndexedfv;
extern	PFNGLSCISSORARRAYVPROC		glScissorArrayv;
extern	PFNGLSCISSORINDEXEDPROC		glScissorIndexed;
extern	PFNGLSCISSORINDEXEDVPROC	glScissorIndexedv;
extern	PFNGLDEPTHRANGEARRAYVPROC	glDepthRangeArrayv;
extern	PFNGLDEPTHRANGEINDEXEDPROC	glDepthRangeIndexed;
extern	PFNGLGETFLOATI_VPROC		glGetFloati_v;
extern	PFNGLGETDOUBLEI_VPROC		glGetDoublei_v;

											// EXT_draw_buffers2
extern	PFNGLCOLORMASKINDEXEDEXTPROC	glColorMaskIndexedEXT;
extern	PFNGLGETBOOLEANINDEXEDVEXTPROC	glGetBooleanIndexedvEXT;
extern	PFNGLGETINTEGERINDEXEDVEXTPROC	glGetIntegerIndexedvEXT;
extern	PFNGLENABLEINDEXEDEXTPROC		glEnableIndexedEXT;
extern	PFNGLDISABLEINDEXEDEXTPROC		glDisableIndexedEXT;
extern	PFNGLISENABLEDINDEXEDEXTPROC	glIsEnabledIndexedEXT;

#endif
