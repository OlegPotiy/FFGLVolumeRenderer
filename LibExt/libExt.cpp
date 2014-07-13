//
// Simple library to load basic extensions
//
// Author: Alex V. Boreskoff <steps3d@gmail.com>, <steps3d@narod.ru>
//

#ifdef  _WIN32
    #include    <windows.h>
#endif

#include    "libExt.h"
#include    <GL/gl.h>
#include    "../glext.h"
#include    <stdio.h>
#include    <string.h>
#include    <ctype.h>
#include    <stdlib.h>
#include    <malloc.h>


                                // multitexture functions
#ifdef  _WIN32
                                // under Linux all multitexture is
                                // supported by OpenGL itself

PFNGLACTIVETEXTUREARBPROC        glActiveTextureARB        = NULL;
PFNGLCLIENTACTIVETEXTUREARBPROC  glClientActiveTextureARB  = NULL;
PFNGLMULTITEXCOORD1FARBPROC      glMultiTexCoord1f         = NULL;
PFNGLMULTITEXCOORD1FVARBPROC     glMultiTexCoord1fv        = NULL;
PFNGLMULTITEXCOORD2FARBPROC      glMultiTexCoord2f         = NULL;
PFNGLMULTITEXCOORD2FVARBPROC     glMultiTexCoord2fv        = NULL;
PFNGLMULTITEXCOORD3FARBPROC      glMultiTexCoord3f         = NULL;
PFNGLMULTITEXCOORD3FVARBPROC     glMultiTexCoord3fv        = NULL;
PFNGLMULTITEXCOORD4FARBPROC      glMultiTexCoord4f         = NULL;
PFNGLMULTITEXCOORD4FVARBPROC     glMultiTexCoord4fv        = NULL;
#endif

                                        // fog coord function
PFNGLFOGCOORDFEXTPROC            glFogCoordf               = NULL;

                                        // secondary color functions
PFNGLSECONDARYCOLOR3FPROC        glSecondaryColor3f        = NULL;
PFNGLSECONDARYCOLOR3FVPROC       glSecondaryColor3fv       = NULL;
PFNGLSECONDARYCOLORPOINTERPROC   glSecondaryColorPointer   = NULL;


                                        // register combiners functions
PFNGLCOMBINERPARAMETERFVNVPROC   glCombinerParameterfvNV   = NULL;
PFNGLCOMBINERPARAMETERIVNVPROC   glCombinerParameterivNV   = NULL;
PFNGLCOMBINERPARAMETERFNVPROC    glCombinerParameterfNV    = NULL;
PFNGLCOMBINERPARAMETERINVPROC    glCombinerParameteriNV    = NULL;
PFNGLCOMBINERINPUTNVPROC         glCombinerInputNV         = NULL;
PFNGLCOMBINEROUTPUTNVPROC        glCombinerOutputNV        = NULL;
PFNGLFINALCOMBINERINPUTNVPROC    glFinalCombinerInputNV    = NULL;

                                    // VBO functions
PFNGLBINDBUFFERARBPROC           glBindBufferARB           = NULL;
PFNGLDELETEBUFFERSARBPROC        glDeleteBuffersARB        = NULL;
PFNGLGENBUFFERSARBPROC           glGenBuffersARB           = NULL;
PFNGLISBUFFERARBPROC             glIsBufferARB             = NULL;
PFNGLBUFFERDATAARBPROC           glBufferDataARB           = NULL;
PFNGLBUFFERSUBDATAARBPROC        glBufferSubDataARB        = NULL;
PFNGLGETBUFFERSUBDATAARBPROC     glGetBufferSubDataARB     = NULL;
PFNGLMAPBUFFERARBPROC            glMapBufferARB            = NULL;
PFNGLUNMAPBUFFERARBPROC          glUnmapBufferARB          = NULL;
PFNGLGETBUFFERPARAMETERIVARBPROC glGetBufferParameterivARB = NULL;
PFNGLGETBUFFERPOINTERVARBPROC    glGetBufferPointervARB    = NULL;


#ifdef  _WIN32
PFNWGLGETEXTENSIONSSTRINGARBPROC        wglGetExtensionsStringARB = NULL;

                                    // p-buffer functions
PFNWGLCREATEPBUFFERARBPROC              wglCreatePbufferARB     = NULL;
PFNWGLGETPBUFFERDCARBPROC               wglGetPbufferDCARB      = NULL;
PFNWGLRELEASEPBUFFERDCARBPROC           wglReleasePbufferDCARB  = NULL;
PFNWGLDESTROYPBUFFERARBPROC             wglDestroyPbufferARB    = NULL;
PFNWGLQUERYPBUFFERARBPROC               wglQueryPbufferARB      = NULL;

                                    // WGL_ARB_pixel_format
PFNWGLCHOOSEPIXELFORMATARBPROC          wglChoosePixelFormatARB = NULL;

                                    // WGL_ARB_render_texture
PFNWGLBINDTEXIMAGEARBPROC               wglBindTexImageARB      = NULL;
PFNWGLRELEASETEXIMAGEARBPROC            wglReleaseTexImageARB   = NULL;
PFNWGLSETPBUFFERATTRIBARBPROC           wglSetPbufferAttribARB  = NULL;

                                    // WGL_EXT_swap_control
PFNWGLSWAPINTERVALEXTPROC               wglSwapIntervalEXT      = NULL;
PFNWGLGETSWAPINTERVALEXTPROC            wglGetSwapIntervalEXT   = NULL;
#else
                                    // GLX_SGIX_pbuffer
PFNGLXCREATEGLXPBUFFERSGIXPROC          glXCreateGLXPbufferSGIX  = NULL;
PFNGLXDESTROYGLXPBUFFERSGIXPROC         glXDestroyGLXPbufferSGIX = NULL;
PFNGLXQUERYGLXPBUFFERSGIXPROC           glXQueryGLXPbufferSGIX   = NULL;

                                    // GLX_SGIX_fbconfig
PFNGLXCHOOSEFBCONFIGSGIXPROC            glXChooseFBConfigSGIX          = NULL;
PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC   glXCreateContextWithConfigSGIX = NULL;
#endif

                                    // NV-occlusion query extension
PFNGLGENOCCLUSIONQUERIESNVPROC          glGenOcclusionQueriesNV = NULL;
PFNGLBEGINOCCLUSIONQUERYNVPROC          glBeginOcclusionQueryNV = NULL;
PFNGLENDOCCLUSIONQUERYNVPROC            glEndOcclusionQueryNV   = NULL;
PFNGLGETOCCLUSIONQUERYIVNVPROC          glGetOcclusionQueryivNV = NULL;

                                    // ARB_vertex_program extension
PFNGLGENPROGRAMSARBPROC                 glGenProgramsARB        = NULL;
PFNGLDELETEPROGRAMSARBPROC              glDeleteProgramsARB     = NULL;
PFNGLBINDPROGRAMARBPROC                 glBindProgramARB        = NULL;
PFNGLISPROGRAMARBPROC                   glIsProgramARB          = NULL;

PFNGLPROGRAMSTRINGARBPROC               glProgramStringARB      = NULL;
PFNGLGETPROGRAMIVARBPROC                glGetProgramivARB       = NULL;

PFNGLVERTEXATTRIB4FARBPROC              glVertexAttrib4fARB     = NULL;
PFNGLVERTEXATTRIB4FVARBPROC             glVertexAttrib4fvARB    = NULL;
PFNGLVERTEXATTRIB3FARBPROC              glVertexAttrib3fARB     = NULL;
PFNGLVERTEXATTRIB3FVARBPROC             glVertexAttrib3fvARB    = NULL;

PFNGLVERTEXATTRIBPOINTERARBPROC         glVertexAttribPointerARB        = NULL;
PFNGLENABLEVERTEXATTRIBARRAYARBPROC     glEnableVertexAttribArrayARB    = NULL;
PFNGLDISABLEVERTEXATTRIBARRAYARBPROC    glDisableVertexAttribArrayARB   = NULL;

PFNGLPROGRAMLOCALPARAMETER4FARBPROC     glProgramLocalParameter4fARB    = NULL;
PFNGLPROGRAMLOCALPARAMETER4FVARBPROC    glProgramLocalParameter4fvARB   = NULL;

PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC  glGetProgramLocalParameterfvARB = NULL;

PFNGLPROGRAMENVPARAMETER4FARBPROC       glProgramEnvParameter4fARB      = NULL;
PFNGLPROGRAMENVPARAMETER4FVARBPROC      glProgramEnvParameter4fvARB     = NULL;

PFNGLGETPROGRAMENVPARAMETERFVARBPROC    glGetProgramEnvParameterfvARB   = NULL;

                                    // GL_EXT_texture3D
PFNGLTEXIMAGE3DEXTPROC                  glTexImage3DEXT                  = NULL;

                                    // ARB_texture_compression
PFNGLCOMPRESSEDTEXIMAGE3DARBPROC        glCompressedTexImage3DARB        = NULL;
PFNGLCOMPRESSEDTEXIMAGE2DARBPROC        glCompressedTexImage2DARB        = NULL;
PFNGLCOMPRESSEDTEXIMAGE1DARBPROC        glCompressedTexImage1DARB        = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC     glCompressedTexSubImage3DARB     = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC     glCompressedTexSubImage2DARB     = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC     glCompressedTexSubImage1DARB     = NULL;
PFNGLGETCOMPRESSEDTEXIMAGEARBPROC       glGetCompressedTexImageARB       = NULL;

                                    // ARB_point_parameters
PFNGLPOINTPARAMETERFARBPROC             glPointParameterfARB             = NULL;
PFNGLPOINTPARAMETERFVARBPROC            glPointParameterfvARB            = NULL;

                                    // ARB_occlusion_query
PFNGLGENQUERIESARBPROC                  glGenQueriesARB        = NULL;
PFNGLDELETEQUERIESARBPROC               glDeleteQueriesARB     = NULL;
PFNGLISQUERYARBPROC                     glIsQueryARB           = NULL;
PFNGLBEGINQUERYARBPROC                  glBeginQueryARB        = NULL;
PFNGLENDQUERYARBPROC                    glEndQueryARB          = NULL;
PFNGLGETQUERYIVARBPROC                  glGetQueryivARB        = NULL;
PFNGLGETQUERYOBJECTIVARBPROC            glGetQueryObjectivARB  = NULL;
PFNGLGETQUERYOBJECTUIVARBPROC           glGetQueryObjectuivARB = NULL;

                                    // GLSL-specific extensions
                                    // GL_ARB_shader_object
PFNGLDELETEOBJECTARBPROC                glDeleteObjectARB         = NULL;
PFNGLGETHANDLEARBPROC                   glGetHandleARB            = NULL;
PFNGLDETACHOBJECTARBPROC                glDetachObjectARB         = NULL;
PFNGLCREATESHADEROBJECTARBPROC          glCreateShaderObjectARB   = NULL;
PFNGLSHADERSOURCEARBPROC                glShaderSourceARB         = NULL;
PFNGLCOMPILESHADERARBPROC               glCompileShaderARB        = NULL;
PFNGLCREATEPROGRAMOBJECTARBPROC         glCreateProgramObjectARB  = NULL;
PFNGLATTACHOBJECTARBPROC                glAttachObjectARB         = NULL;
PFNGLLINKPROGRAMARBPROC                 glLinkProgramARB          = NULL;
PFNGLUSEPROGRAMOBJECTARBPROC            glUseProgramObjectARB     = NULL;
PFNGLVALIDATEPROGRAMARBPROC             glValidateProgramARB      = NULL;
PFNGLUNIFORM1FARBPROC                   glUniform1fARB            = NULL;
PFNGLUNIFORM2FARBPROC                   glUniform2fARB            = NULL;
PFNGLUNIFORM3FARBPROC                   glUniform3fARB            = NULL;
PFNGLUNIFORM4FARBPROC                   glUniform4fARB            = NULL;
PFNGLUNIFORM1IARBPROC                   glUniform1iARB            = NULL;
PFNGLUNIFORM2IARBPROC                   glUniform2iARB            = NULL;
PFNGLUNIFORM3IARBPROC                   glUniform3iARB            = NULL;
PFNGLUNIFORM4IARBPROC                   glUniform4iARB            = NULL;
PFNGLUNIFORM1FVARBPROC                  glUniform1fvARB           = NULL;
PFNGLUNIFORM2FVARBPROC                  glUniform2fvARB           = NULL;
PFNGLUNIFORM3FVARBPROC                  glUniform3fvARB           = NULL;
PFNGLUNIFORM4FVARBPROC                  glUniform4fvARB           = NULL;
PFNGLUNIFORM1IVARBPROC                  glUniform1ivARB           = NULL;
PFNGLUNIFORM2IVARBPROC                  glUniform2ivARB           = NULL;
PFNGLUNIFORM3IVARBPROC                  glUniform3ivARB           = NULL;
PFNGLUNIFORM4IVARBPROC                  glUniform4ivARB           = NULL;
PFNGLUNIFORMMATRIX2FVARBPROC            glUniformMatrix2fvARB     = NULL;
PFNGLUNIFORMMATRIX3FVARBPROC            glUniformMatrix3fvARB     = NULL;
PFNGLUNIFORMMATRIX4FVARBPROC            glUniformMatrix4fvARB     = NULL;
PFNGLGETOBJECTPARAMETERFVARBPROC        glGetObjectParameterfvARB = NULL;
PFNGLGETOBJECTPARAMETERIVARBPROC        glGetObjectParameterivARB = NULL;
PFNGLGETINFOLOGARBPROC                  glGetInfoLogARB           = NULL;
PFNGLGETATTACHEDOBJECTSARBPROC          glGetAttachedObjectsARB   = NULL;
PFNGLGETUNIFORMLOCATIONARBPROC          glGetUniformLocationARB   = NULL;
PFNGLGETACTIVEUNIFORMARBPROC            glGetActiveUniformARB     = NULL;
PFNGLGETUNIFORMFVARBPROC                glGetUniformfvARB         = NULL;
PFNGLGETUNIFORMIVARBPROC                glGetUniformivARB         = NULL;
PFNGLGETSHADERSOURCEARBPROC             glGetShaderSourceARB      = NULL;

                                    // GL_ARB_vertex_shader
PFNGLBINDATTRIBLOCATIONARBPROC          glBindAttribLocationARB   = NULL;
PFNGLGETACTIVEATTRIBARBPROC             glGetActiveAttribARB      = NULL;
PFNGLGETATTRIBLOCATIONARBPROC           glGetAttribLocationARB    = NULL;
PFNGLGETVERTEXATTRIBFVARBPROC           glGetVertexAttribfvARB    = NULL;

                                    // EXT_stencil_two_side
PFNGLACTIVESTENCILFACEEXTPROC           glActiveStencilFaceEXT    = NULL;

				    				// EXT_depth_bounds_test
PFNGLDEPTHBOUNDSEXTPROC			glDepthBoundsEXT                  = NULL;

									// EXT_framebuffer_object
PFNGLISRENDERBUFFEREXTPROC						glIsRenderbufferEXT                      = NULL;
PFNGLBINDRENDERBUFFEREXTPROC					glBindRenderbufferEXT                    = NULL;
PFNGLDELETERENDERBUFFERSEXTPROC					glDeleteRenderbuffersEXT                 = NULL;
PFNGLGENRENDERBUFFERSEXTPROC					glGenRenderbuffersEXT                    = NULL;
PFNGLRENDERBUFFERSTORAGEEXTPROC					glRenderbufferStorageEXT                 = NULL;
PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC			glGetRenderbufferParameterivEXT          = NULL;
PFNGLISFRAMEBUFFEREXTPROC						glIsFramebufferEXT                       = NULL;
PFNGLBINDFRAMEBUFFEREXTPROC						glBindFramebufferEXT                     = NULL;
PFNGLDELETEFRAMEBUFFERSEXTPROC					glDeleteFramebuffersEXT                  = NULL;
PFNGLGENFRAMEBUFFERSEXTPROC						glGenFramebuffersEXT                     = NULL;
PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC				glCheckFramebufferStatusEXT              = NULL;
PFNGLFRAMEBUFFERTEXTURE1DEXTPROC				glFramebufferTexture1DEXT                = NULL;
PFNGLFRAMEBUFFERTEXTURE2DEXTPROC				glFramebufferTexture2DEXT                = NULL;
PFNGLFRAMEBUFFERTEXTURE3DEXTPROC				glFramebufferTexture3DEXT                = NULL;
PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC				glFramebufferRenderbufferEXT             = NULL;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC	glGetFramebufferAttachmentParameterivEXT = NULL;
PFNGLGENERATEMIPMAPEXTPROC						glGenerateMipmapEXT                      = NULL;

#ifndef	GL_VERSION_1_3										// ARB_transpose matrix
PFNGLLOADTRANSPOSEMATRIXFPROC					glLoadTransposeMatrixfARB                = NULL;
PFNGLLOADTRANSPOSEMATRIXDPROC					glLoadTransposeMatrixdARB                = NULL;
PFNGLMULTTRANSPOSEMATRIXFPROC					glMultTransposeMatrixfARB                = NULL;
PFNGLMULTTRANSPOSEMATRIXDPROC					glMultTransposeMatrixdARB                = NULL;
#endif
															// ARB_color_buffer_float
PFNGLCLAMPCOLORARBPROC							glClampColorARB        = NULL;

#ifdef	_WIN32											// fresh Linux already has 2.0
														// stencel ops from OpenGL 2.0
PFNGLSTENCILFUNCSEPARATEPROC					glStencilFuncSeparate  = NULL;
PFNGLSTENCILOPSEPARATEPROC						glStencilOpSeparate    = NULL;
PFNGLSTENCILMASKSEPARATEPROC					glStencilMaskSeparate  = NULL;

															// blend ops from OPenGL 2.0
PFNGLBLENDEQUATIONPROC							glBlendEquation         = NULL;
PFNGLBLENDEQUATIONSEPARATEPROC		 			glBlendEquationSeparate = NULL;
PFNGLBLENDFUNCSEPARATEPROC						glBlendFuncSeparate     = NULL;
PFNGLBLENDCOLORPROC								glBlendColor            = NULL;
#endif

															// draw buffers from OpenGL 2.0
PFNGLDRAWBUFFERSPROC							glDrawBuffers           = NULL;

															// ATI_draw_buffers
PFNGLDRAWBUFFERSATIPROC							glDrawBuffersATI        = NULL;

															// EXT_texture_integer
PFNGLTEXPARAMETERIIVEXTPROC				glTexParameterIivEXT      = NULL;
PFNGLTEXPARAMETERIUIVEXTPROC			glTexParameterIuivEXT     = NULL;
PFNGLGETTEXPARAMETERIIVEXTPROC			glGetTexParameterIivEXT   = NULL;
PFNGLGETTEXPARAMETERIUIVEXTPROC			glGetTexParameterIuivEXT  = NULL;
PFNGLCLEARCOLORIIEXTPROC				glClearColorIiEXT         = NULL;
PFNGLCLEARCOLORIUIEXTPROC				glClearColorIuiEXT        = NULL;
															
															// EXT_draw_instanced
PFNGLDRAWARRAYSINSTANCEDEXTPROC			glDrawArraysInstancedEXT  = NULL;
PFNGLDRAWELEMENTSINSTANCEDEXTPROC		glDrawElementsInstancedEXT  = NULL;


															// EXT_texture_buffer_object
PFNGLTEXBUFFEREXTPROC 					glTexBufferEXT  = NULL;
															
															// EXT_gpu_shader4
PFNGLGETUNIFORMUIVEXTPROC				glGetUniformuivEXT        = NULL;
PFNGLBINDFRAGDATALOCATIONEXTPROC		glBindFragDataLocationEXT = NULL;
PFNGLGETFRAGDATALOCATIONEXTPROC			glGetFragDataLocationEXT  = NULL;
PFNGLUNIFORM1UIEXTPROC					glUniform1uiEXT           = NULL;
PFNGLUNIFORM2UIEXTPROC					glUniform2uiEXT           = NULL;
PFNGLUNIFORM3UIEXTPROC					glUniform3uiEXT           = NULL;
PFNGLUNIFORM4UIEXTPROC					glUniform4uiEXT           = NULL;
PFNGLUNIFORM1UIVEXTPROC					glUniform1uivEXT          = NULL;
PFNGLUNIFORM2UIVEXTPROC					glUniform2uivEXT          = NULL;
PFNGLUNIFORM3UIVEXTPROC					glUniform3uivEXT          = NULL;
PFNGLUNIFORM4UIVEXTPROC					glUniform4uivEXT          = NULL;
PFNGLVERTEXATTRIBI1IEXTPROC				glVertexAttribI1iEXT      = NULL;
PFNGLVERTEXATTRIBI2IEXTPROC				glVertexAttribI2iEXT      = NULL;
PFNGLVERTEXATTRIBI3IEXTPROC				glVertexAttribI3iEXT      = NULL;
PFNGLVERTEXATTRIBI4IEXTPROC				glVertexAttribI4iEXT      = NULL;
PFNGLVERTEXATTRIBI1UIEXTPROC			glVertexAttribI1uiEXT     = NULL;
PFNGLVERTEXATTRIBI2UIEXTPROC			glVertexAttribI2uiEXT     = NULL;
PFNGLVERTEXATTRIBI3UIEXTPROC			glVertexAttribI3uiEXT     = NULL;
PFNGLVERTEXATTRIBI4UIEXTPROC			glVertexAttribI4uiEXT     = NULL;
PFNGLVERTEXATTRIBI1IVEXTPROC			glVertexAttribI1ivEXT     = NULL;
PFNGLVERTEXATTRIBI2IVEXTPROC			glVertexAttribI2ivEXT     = NULL;
PFNGLVERTEXATTRIBI3IVEXTPROC			glVertexAttribI3ivEXT     = NULL;
PFNGLVERTEXATTRIBI4IVEXTPROC			glVertexAttribI4ivEXT     = NULL;
PFNGLVERTEXATTRIBI1UIVEXTPROC			glVertexAttribI1uivEXT    = NULL;
PFNGLVERTEXATTRIBI2UIVEXTPROC			glVertexAttribI2uivEXT    = NULL;
PFNGLVERTEXATTRIBI3UIVEXTPROC			glVertexAttribI3uivEXT    = NULL;
PFNGLVERTEXATTRIBI4UIVEXTPROC			glVertexAttribI4uivEXT    = NULL;
PFNGLVERTEXATTRIBI4BVEXTPROC			glVertexAttribI4bvEXT     = NULL;
PFNGLVERTEXATTRIBI4SVEXTPROC			glVertexAttribI4svEXT     = NULL;
PFNGLVERTEXATTRIBI4UBVEXTPROC			glVertexAttribI4ubvEXT    = NULL;
PFNGLVERTEXATTRIBI4USVEXTPROC			glVertexAttribI4usvEXT    = NULL;
PFNGLVERTEXATTRIBIPOINTEREXTPROC		glVertexAttribIPointerEXT = NULL;
PFNGLGETVERTEXATTRIBIIVEXTPROC			glGetVertexAttribIivEXT   = NULL;
PFNGLGETVERTEXATTRIBIUIVEXTPROC			glGetVertexAttribIuivEXT  = NULL;

														// EXT_geometry_shader4
PFNGLPROGRAMPARAMETERIEXTPROC			glProgramParameteriEXT       = NULL;
PFNGLFRAMEBUFFERTEXTUREEXTPROC			glFramebufferTextureEXT      = NULL;
PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC		glFramebufferTextureLayerEXT = NULL;
PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC		glFramebufferTextureFaceEXT  = NULL;

														// EXT_bindable_uniform
PFNGLUNIFORMBUFFEREXTPROC				glUniformBufferEXT           = NULL;
PFNGLGETUNIFORMBUFFERSIZEEXTPROC		glGetUniformBufferSizeEXT    = NULL;
PFNGLGETUNIFORMOFFSETEXTPROC			glGetUniformOffsetEXT        = NULL;

														// OpenGL 2.0 shader support
PFNGLCOMPILESHADERPROC					glCompileShader       = NULL;
PFNGLCREATEPROGRAMPROC					glCreateProgram       = NULL;
PFNGLCREATESHADERPROC					glCreateShader        = NULL;
PFNGLDELETEPROGRAMPROC					glDeleteProgram       = NULL;
PFNGLDELETESHADERPROC					glDeleteShader        = NULL;
PFNGLDETACHSHADERPROC					glDetachShader        = NULL;
PFNGLGETPROGRAMINFOLOGPROC				glGetProgramInfoLog   = NULL;
PFNGLGETSHADERINFOLOGPROC				glGetShaderInfoLog    = NULL;
PFNGLGETSHADERSOURCEPROC				glGetShaderSource     = NULL;
PFNGLLINKPROGRAMPROC					glLinkProgram         = NULL;
PFNGLSHADERSOURCEPROC					glShaderSource        = NULL;
PFNGLUSEPROGRAMPROC						glUseProgram          = NULL;
PFNGLVALIDATEPROGRAMPROC				glValidateProgram     = NULL;
PFNGLGETPROGRAMIVPROC					glGetProgramiv        = NULL;
PFNGLGETSHADERIVPROC					glGetShaderiv         = NULL;
PFNGLATTACHSHADERPROC					glAttachShader        = NULL;
PFNGLGETUNIFORMLOCATIONPROC				glGetUniformLocation  = NULL;
PFNGLGETATTRIBLOCATIONPROC				glGetAttribLocation   = NULL;
PFNGLUNIFORM4FVPROC						glUniform4fv          = NULL;
PFNGLUNIFORM3FVPROC						glUniform3fv          = NULL;
PFNGLUNIFORM2FVPROC						glUniform2fv          = NULL;
PFNGLUNIFORM1FPROC						glUniform1f           = NULL;
PFNGLUNIFORM1IPROC						glUniform1i           = NULL;
PFNGLUNIFORMMATRIX2FVPROC				glUniformMatrix2fv    = NULL;
PFNGLUNIFORMMATRIX3FVPROC				glUniformMatrix3fv    = NULL;
PFNGLUNIFORMMATRIX4FVPROC				glUniformMatrix4fv    = NULL;
PFNGLGETUNIFORMFVPROC					glGetUniformfv        = NULL;
PFNGLVERTEXATTRIB4FVPROC				glVertexAttrib4fv     = NULL;
PFNGLGETVERTEXATTRIBFVPROC				glGetVertexAttribfv   = NULL;

														// OpenGL 2 query support
PFNGLGENQUERIESPROC                     glGenQueries        = NULL;
PFNGLDELETEQUERIESPROC                  glDeleteQueries     = NULL;
PFNGLISQUERYPROC                        glIsQuery           = NULL;
PFNGLBEGINQUERYPROC                     glBeginQuery        = NULL;
PFNGLENDQUERYPROC                       glEndQuery          = NULL;
PFNGLGETQUERYIVPROC                     glGetQueryiv        = NULL;
PFNGLGETQUERYOBJECTIVPROC               glGetQueryObjectiv  = NULL;
PFNGLGETQUERYOBJECTUIVPROC              glGetQueryObjectuiv = NULL;

														// NV_transform_feedback
PFNGLBEGINTRANSFORMFEEDBACKNVPROC		glBeginTransformFeedbackNV      = NULL;
PFNGLENDTRANSFORMFEEDBACKNVPROC			glEndTransformFeedbackNV        = NULL;
PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC		glTransformFeedbackAttribsNV    = NULL;
PFNGLBINDBUFFERRANGENVPROC				glBindBufferRangeNV             = NULL;
PFNGLBINDBUFFEROFFSETNVPROC				glBindBufferOffsetNV            = NULL;
PFNGLBINDBUFFERBASENVPROC				glBindBufferBaseNV              = NULL;
PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC	glTransformFeedbackVaryingsNV   = NULL;
PFNGLACTIVEVARYINGNVPROC				glActiveVaryingNV               = NULL;
PFNGLGETVARYINGLOCATIONNVPROC			glGetVaryingLocationNV          = NULL;
PFNGLGETACTIVEVARYINGNVPROC				glGetActiveVaryingNV            = NULL;
PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC	glGetTransformFeedbackVaryingNV = NULL;

														// NV_fence
PFNGLDELETEFENCESNVPROC					glDeleteFencesNV = NULL;
PFNGLGENFENCESNVPROC					glGenFencesNV    = NULL;
PFNGLISFENCENVPROC						glIsFenceNV      = NULL;
PFNGLTESTFENCENVPROC					glTestFenceNV    = NULL;
PFNGLGETFENCEIVNVPROC					glGetFenceivNV   = NULL;
PFNGLFINISHFENCENVPROC					glFinishFenceNV  = NULL;
PFNGLSETFENCENVPROC						glSetFenceNV     = NULL;

														// NV__conditional_render
PFNGLBEGINCONDITIONALRENDERNVPROC		glBeginConditionalRenderNV = NULL;
PFNGLENDCONDITIONALRENDERNVPROC			glEndConditionalRenderNV   = NULL;

														// ARB_sampler_objects
PFNGLGENSAMPLERSPROC			glGenSamplers            = NULL;
PFNGLDELETESAMPLERSPROC			glDeleteSamplers         = NULL;
PFNGLISSAMPLERPROC				glIsSampler              = NULL;
PFNGLBINDSAMPLERPROC			glBindSampler            = NULL;
PFNGLSAMPLERPARAMETERIPROC		glSamplerParameteri      = NULL;
PFNGLSAMPLERPARAMETERIVPROC		glSamplerParameteriv     = NULL;
PFNGLSAMPLERPARAMETERFPROC		glSamplerParameterf      = NULL;
PFNGLSAMPLERPARAMETERFVPROC		glSamplerParameterfv     = NULL;
PFNGLSAMPLERPARAMETERIIVPROC	glSamplerParameterIiv    = NULL;
PFNGLSAMPLERPARAMETERIUIVPROC	glSamplerParameterIuiv   = NULL;
PFNGLGETSAMPLERPARAMETERIVPROC	glGetSamplerParameteriv  = NULL;
PFNGLGETSAMPLERPARAMETERIIVPROC	glGetSamplerParameterIiv = NULL;
PFNGLGETSAMPLERPARAMETERFVPROC	glGetSamplerParameterfv  = NULL;
PFNGLGETSAMPLERPARAMETERIFVPROC	glGetSamplerParameterIfv = NULL;

														// ARB_get_program_binary
PFNGLGETPROGRAMBINARYPROC  glGetProgramBinary  = NULL;
PFNGLPROGRAMBINARYPROC     glProgramBinary     = NULL;
PFNGLPROGRAMPARAMETERIPROC glProgramParameteri = NULL;

														// ARB_vertex_array_object
PFNGLBINDVERTEXARRAYPROC		glBindVertexArray    = NULL;
PFNGLDELETEVERTEXARRAYSPROC		glDeleteVertexArrays = NULL;
PFNGLGENVERTEXARRAYSPROC		glGenVertexArrays    = NULL;
PFNGLISVERTEXARRAYPROC			glIsVertexArray      = NULL;

														// ARB_instanced_arrays
PFNGLVERTEXATTRIBDIVISORARBPROC	glVertexAttribDivisor = NULL;

														// ARB_timer_query
PFNGLQUERYCOUNTERPROC			glQueryCounter        = NULL;
PFNGLGETQUERYOBJECTI64VPROC		glGetQueryObjecti64v  = NULL;
PFNGLGETQUERYOBJECTUI64VPROC	glGetQueryObjectui64v = NULL;

														// ARB_sync
PFNGLFENCESYNCPROC		glFenceSync = NULL;
PFNGLISSYNCPROC			glIsSync = NULL;
PFNGLDELETESYNCPROC		glDeleteSync = NULL;
PFNGLCLIENTWAITSYNCPROC	glClientWaitSync = NULL;
PFNGLWAITSYNCPROC		glWaitSync = NULL;
PFNGLGETINTEGER64VPROC	glGetInteger64v = NULL;
PFNGLGETSYNCIVPROC		glGetSynciv = NULL;

														// ARB_separate_shader_objects
PFNGLUSEPROGRAMSTAGESPROC		glUseProgramStages = NULL;
PFNGLACTIVESHADERPROGRAMPROC	glActiveShaderProgram = NULL;
PFNGLCREATESHADERPROGRAMVPROC	glCreateShaderProgramv = NULL;
PFNGLBINDPROGRAMPIPELINEPROC	glBindProgramPipeline = NULL;
PFNGLDELETEPROGRAMPIPELINESPROC	glDeleteProgramPipelines = NULL;
PFNGLGENPROGRAMPIPELINESPROC	glGenProgramPipelines = NULL;
PFNGLISPROGRAMPIPELINEPROC		glIsProgramPipeline = NULL;
PFNGLGETPROGRAMPIPELINEIVPROC	glGetProgramPipelineiv = NULL;
PFNGLPROGRAMUNIFORM1IPROC		glProgramUniform1i = NULL;
PFNGLPROGRAMUNIFORM1IVPROC		glProgramUniform1iv = NULL;
PFNGLPROGRAMUNIFORM1FPROC		glProgramUniform1f = NULL;
PFNGLPROGRAMUNIFORM1FVPROC		glProgramUniform1fv = NULL;
PFNGLPROGRAMUNIFORM1DPROC		glProgramUniform1d = NULL;
PFNGLPROGRAMUNIFORM1DVPROC		glProgramUniform1dv = NULL;
PFNGLPROGRAMUNIFORM1UIPROC		glProgramUniform1ui = NULL;
PFNGLPROGRAMUNIFORM1UIVPROC		glProgramUniform1uiv = NULL;
PFNGLPROGRAMUNIFORM2IPROC		glProgramUniform2i = NULL;
PFNGLPROGRAMUNIFORM2IVPROC		glProgramUniform2iv = NULL;
PFNGLPROGRAMUNIFORM2FPROC		glProgramUniform2f = NULL;
PFNGLPROGRAMUNIFORM2FVPROC		glProgramUniform2fv = NULL;
PFNGLPROGRAMUNIFORM2DPROC		glProgramUniform2d = NULL;
PFNGLPROGRAMUNIFORM2DVPROC		glProgramUniform2dv = NULL;
PFNGLPROGRAMUNIFORM2UIPROC		glProgramUniform2ui = NULL;
PFNGLPROGRAMUNIFORM2UIVPROC		glProgramUniform2uiv = NULL;
PFNGLPROGRAMUNIFORM3IPROC		glProgramUniform3i = NULL;
PFNGLPROGRAMUNIFORM3IVPROC		glProgramUniform3iv = NULL;
PFNGLPROGRAMUNIFORM3FPROC		glProgramUniform3f = NULL;
PFNGLPROGRAMUNIFORM3FVPROC		glProgramUniform3fv = NULL;
PFNGLPROGRAMUNIFORM3DPROC		glProgramUniform3d = NULL;
PFNGLPROGRAMUNIFORM3DVPROC		glProgramUniform3dv = NULL;
PFNGLPROGRAMUNIFORM3UIPROC		glProgramUniform3ui = NULL;
PFNGLPROGRAMUNIFORM3UIVPROC		glProgramUniform3uiv = NULL;
PFNGLPROGRAMUNIFORM4IPROC		glProgramUniform4i = NULL;
PFNGLPROGRAMUNIFORM4IVPROC		glProgramUniform4iv = NULL;
PFNGLPROGRAMUNIFORM4FPROC		glProgramUniform4f = NULL;
PFNGLPROGRAMUNIFORM4FVPROC		glProgramUniform4fv = NULL;
PFNGLPROGRAMUNIFORM4DPROC		glProgramUniform4d = NULL;
PFNGLPROGRAMUNIFORM4DVPROC		glProgramUniform4dv = NULL;
PFNGLPROGRAMUNIFORM4UIPROC		glProgramUniform4ui = NULL;
PFNGLPROGRAMUNIFORM4UIVPROC		glProgramUniform4uiv = NULL;
PFNGLPROGRAMUNIFORMMATRIX2FVPROC	glProgramUniformMatrix2fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX3FVPROC	glProgramUniformMatrix3fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX4FVPROC	glProgramUniformMatrix4fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX2DVPROC	glProgramUniformMatrix2dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX3DVPROC	glProgramUniformMatrix3dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX4DVPROC	glProgramUniformMatrix4dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC	glProgramUniformMatrix2x3fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC	glProgramUniformMatrix3x2fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC	glProgramUniformMatrix2x4fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC	glProgramUniformMatrix4x2fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC	glProgramUniformMatrix3x4fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC	glProgramUniformMatrix4x3fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC	glProgramUniformMatrix2x3dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC	glProgramUniformMatrix3x2dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC	glProgramUniformMatrix2x4dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC	glProgramUniformMatrix4x2dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC	glProgramUniformMatrix3x4dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC	glProgramUniformMatrix4x3dv = NULL;
PFNGLVALIDATEPROGRAMPIPELINEPROC	glValidateProgramPipeline = NULL;
PFNGLGETPROGRAMPIPELINEINFOLOGPROC	glGetProgramPipelineInfoLog = NULL;

											// ARB_transform_feedback3
PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC	glDrawTransformFeedbackStream = NULL;
PFNGLBEGINQUERYINDEXEDPROC				glBeginQueryIndexed = NULL;
PFNGLENDQUERYINDEXEDPROC				glEndQueryIndexed = NULL;
PFNGLGETQUERYINDEXEDIVPROC				glGetQueryIndexediv = NULL;
												
											// ARB_transform_feedback2
PFNGLBINDTRANSFORMFEEDBACKPROC			glBindTransformFeedback = NULL;
PFNGLDELETETRANSFORMFEEDBACKSPROC		glDeleteTransformFeedbacks = NULL;
PFNGLGENTRANSFORMFEEDBACKSPROC			glGenTransformFeedbacks = NULL;
PFNGLISTRANSFORMFEEDBACKPROC			glIsTransformFeedback = NULL;
PFNGLPAUSETRANSFORMFEEDBACKPROC			glPauseTransformFeedback = NULL;
PFNGLRESUMETRANSFORMFEEDBACKPROC		glResumeTransformFeedback = NULL;
PFNGLDRAWTRANSFORMFEEDBACKPROC			glDrawTransformFeedback = NULL;

											// ARB_tessellation_shader
PFNGLPATCHPARAMETERIPROC				glPatchParameteri = NULL;
PFNGLPATCHPARAMETERFVPROC				glPatchParameterfv = NULL;

											// ARB_draw_indirect
PFNGLDRAWARRAYSINDIRECTPROC				glDrawArraysIndirect = NULL;
PFNGLDRAWELEMENTSINDIRECTPROC			glDrawElementsIndirect = NULL;

											// ARB_shading_language_include
PFNGLNAMEDSTRINGARBPROC				glNamedStringARB = NULL;
PFNGLDELETENAMEDSTRINGARBPROC		glDeleteNamedStringARB = NULL;
PFNGLCOMPILESHADERINCLUDEARBPROC	glCompileShaderIncludeARB = NULL;
PFNGLISNAMEDSTRINGARBPROC			glIsNamedStringARB = NULL;
PFNGLGETNAMEDSTRINGARBPROC			glGetNamedStringARB = NULL;
PFNGLGETNAMEDSTRINGIVARBPROC		glGetNamedStringivARB = NULL;

											// ARB_provoking_vertex
PFNGLPROVOKINGVERTEXPROC			glProvokingVertex = NULL;

											// ARB_draw_elements_base_vertex
PFNGLDRAWELEMENTSBASEVERTEXPROC				glDrawElementsBaseVertex = NULL;
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC		glDrawRangeElementsBaseVertex = NULL;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC	glDrawElementsInstancedBaseVertex = NULL;
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC		glMultiDrawElementsBaseVertex = NULL;

											// ARB_copy_buffer
PFNGLCOPYBUFFERSUBDATAPROC		glCopyBufferSubData = NULL;

											// ARB_uniform_buffer_object
PFNGLGETUNIFORMINDICESPROC			glGetUniformIndices = NULL;
PFNGLGETACTIVEUNIFORMSIVPROC		glGetActiveUniformsiv = NULL;
PFNGLGETACTIVEUNIFORMNAMEPROC		glGetActiveUniformName = NULL;
PFNGLGETUNIFORMBLOCKINDEXPROC		glGetUniformBlockIndex = NULL;
PFNGLGETACTIVEUNIFORMBLOCKIVPROC	glGetActiveUniformBlockiv = NULL;
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC	glGetActiveUniformBlockName = NULL;
PFNGLUNIFORMBLOCKBINDINGPROC		glUniformBlockBinding = NULL;

											// ARB_texture_buffer_object
PFNGLTEXBUFFERARBPROC	glTexBufferARB = NULL;

											// ARB_map_buffer_range
PFNGLMAPBUFFERRANGEPROC			glMapBufferRange = NULL;
PFNGLFLUSHMAPPEDBUFFERRANGEPROC	glFlushMappedBufferRange = NULL;

											// ARB_geometry_shader4
PFNGLPROGRAMPARAMETERIARBPROC			glProgramParameteriARB = NULL;
PFNGLFRAMEBUFFERTEXTUREARBPROC			glFramebufferTextureARB = NULL;
PFNGLFRAMEBUFFERTEXTURELAYERARBPROC		glFramebufferTextureLayerARB = NULL;
PFNGLFRAMEBUFFERTEXTUREFACEARBPROC		glFramebufferTextureFaceARB  = NULL;

											// ARB_draw_instanced
PFNGLDRAWARRAYSINSTANCEDARBPROC					glDrawArraysInstancedARB = NULL;
PFNGLDRAWELEMENTSINSTANCEDARBPROC				glDrawElementsInstancedARB = NULL;

											// ARB_draw_buffers
PFNGLDRAWBUFFERSARBPROC			glDrawBuffersARB = NULL;
												
											// ARB_multisample
PFNGLSAMPLECOVERAGEARBPROC		glSampleCoverageARB = NULL;

											// EXT_shader_image_load_store
PFNGLBINDIMAGETEXTUREEXTPROC	glBindImageTextureEXT = NULL;
PFNGLMEMORYBARRIEREXTPROC		glMemoryBarrierEXT    = NULL;

											// ARB_robustness
PFNGLGETGRAPHICSRESETSTATUSARBPROC		glGetGraphicsResetStatusARB = NULL;
PFNGLGETNMAPDVARBPROC					glGetnMapdvARB = NULL;
PFNGLGETNMAPFVARBPROC					glGetnMapfvARB = NULL;
PFNGLGETNMAPIVARBPROC					glGetnMapivARB = NULL;
PFNGLGETNPIXELMAPFVARBPROC				glGetnPixelMapfvARB = NULL;
PFNGLGETNPIXELMAPUIVARBPROC				glGetnPixelMapuivARB = NULL;
PFNGLGETNPIXELMAPUSVARBPROC				glGetnPixelMapusvARB = NULL;
PFNGLGETNPOLYGONSTIPPLEARBPROC			glGetnPolygonStippleARB = NULL;
PFNGLGETNCOLORTABLEARBPROC				glGetnColorTableARB = NULL;
PFNGLGETNCONVOLUTIONFILTERARBPROC		glGetnConvolutionFilterARB = NULL;
PFNGLGETNSEPARABLEFILTERARBPROC			glGetnSeparableFilterARB = NULL;
PFNGLGETNHISTOGRAMARBPROC				glGetnHistogramARB = NULL;
PFNGLGETNMINMAXARBPROC					glGetnMinmaxARB = NULL;
PFNGLGETNTEXIMAGEARBPROC				glGetnTexImageARB = NULL;
PFNGLREADNPIXELSARBPROC					glReadnPixelsARB = NULL;
PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC		glGetnCompressedTexImageARB = NULL;
PFNGLGETNUNIFORMFVARBPROC				glGetnUniformfvARB = NULL;
PFNGLGETNUNIFORMIVARBPROC				glGetnUniformivARB = NULL;
PFNGLGETNUNIFORMUIVARBPROC				glGetnUniformuivARB = NULL;
PFNGLGETNUNIFORMDVARBPROC				glGetnUniformdvARB = NULL;

											// ARB_debug_output
PFNGLDEBUGMESSAGECONTROLARBPROC			glDebugMessageControlARB = NULL;
PFNGLDEBUGMESSAGEINSERTARBPROC			glDebugMessageInsertARB = NULL;
PFNGLDEBUGMESSAGECALLBACKARBPROC		glDebugMessageCallbackARB = NULL;
PFNGLGETDEBUGMESSAGELOGARBPROC			glGetDebugMessageLogARB = NULL;
											
											// ARB_cl_event
PFNGLCREATESYNCFROMCLEVENTARBPROC	glCreateSyncFromCLeventARB = NULL;

											// ARB_viewport_array
PFNGLVIEWPORTARRAYVPROC		glViewportArrayv = NULL;
PFNGLVIEWPORTINDEXEDFPROC	glViewportIndexedf = NULL;
PFNGLVIEWPORTINDEXEDFVPROC	glViewportIndexedfv = NULL;
PFNGLSCISSORARRAYVPROC		glScissorArrayv = NULL;
PFNGLSCISSORINDEXEDPROC		glScissorIndexed = NULL;
PFNGLSCISSORINDEXEDVPROC	glScissorIndexedv = NULL;
PFNGLDEPTHRANGEARRAYVPROC	glDepthRangeArrayv = NULL;
PFNGLDEPTHRANGEINDEXEDPROC	glDepthRangeIndexed = NULL;
PFNGLGETFLOATI_VPROC		glGetFloati_v = NULL;
PFNGLGETDOUBLEI_VPROC		glGetDoublei_v = NULL;

											// EXT_draw_buffers2
PFNGLCOLORMASKINDEXEDEXTPROC	glColorMaskIndexedEXT = NULL;
PFNGLGETBOOLEANINDEXEDVEXTPROC	glGetBooleanIndexedvEXT = NULL;
PFNGLGETINTEGERINDEXEDVEXTPROC	glGetIntegerIndexedvEXT = NULL;
PFNGLENABLEINDEXEDEXTPROC		glEnableIndexedEXT = NULL;
PFNGLDISABLEINDEXEDEXTPROC		glDisableIndexedEXT = NULL;
PFNGLISENABLEDINDEXEDEXTPROC	glIsEnabledIndexedEXT = NULL;

////////////////////////// functions ////////////////////////////

static  bool    isExtensionSupported ( const char * ext, const char * extList )
{
    const char * start = extList;
    const char * ptr;

    while ( ( ptr = strstr ( start, ext ) ) != NULL )
    {
                                            // we've found, ensure name is exactly ext
        const char * end = ptr + strlen ( ext );

        if ( isspace ( *end ) || *end == '\0' )
            return true;

        start = end;
    }

    return false;
}

bool    isExtensionSupported ( const char * ext )
{
    initExtensions ();                      // since we will need it for platform-specific extensions

    const char * extensions = (const char *) glGetString ( GL_EXTENSIONS );

    if ( isExtensionSupported ( ext, extensions ) )
	    return true;

#ifdef  _WIN32                              // check Windoze extensions
    if ( wglGetExtensionsStringARB == NULL )
    	return false;

    return isExtensionSupported ( ext, wglGetExtensionsStringARB ( wglGetCurrentDC () ) );
#else                                       // check GLX extensions
    Display * display = glXGetCurrentDisplay ();
    int       screen  = DefaultScreen        ( display );

    return isExtensionSupported ( ext, glXQueryExtensionsString ( display, screen ) );
#endif
}

const char * getGeneralExtensions ()
{
    initExtensions ();

	return (const char *) glGetString ( GL_EXTENSIONS );
}

const char * getPlatformExtensions ()
{
    initExtensions ();                      // since we will need it for platform-specific extensions

#ifdef  _WIN32                              // check Windoze extensions
    if ( wglGetExtensionsStringARB == NULL )
    	return "";

    return wglGetExtensionsStringARB ( wglGetCurrentDC () );
#else                                       // check GLX extensions
    Display * display = glXGetCurrentDisplay ();
    int       screen  = DefaultScreen        ( display );

    return glXQueryExtensionsString ( display, screen );
#endif
}

void    assertExtensionsSupported ( const char * extList )
{
    char * str = strdup ( extList );

    for ( char * ptr = strtok ( str, " ,;\t" ); ptr != NULL; ptr = strtok ( NULL, " ,;\t" ) )
        if ( !isExtensionSupported ( ptr ) )
        {
            fprintf ( stderr, "Error - extension %s not supported.\n", ptr );

            free ( str );
            exit ( 1   );
        }

    free ( str );
}

//
// hide platform specific in one place
//

static void * getProcAddress ( const char * name )
{
#ifdef  _WIN32
    return (void *)wglGetProcAddress ( name );
#else
    return (void *)glXGetProcAddressARB ( (const GLubyte *)name );
#endif
}

#ifdef  _WIN32
bool    initWin32Extensions ()
{
    wglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC) getProcAddress ( "wglGetExtensionsStringARB" );

    if ( wglGetExtensionsStringARB == NULL )
        return false;

    const char * exts = wglGetExtensionsStringARB ( wglGetCurrentDC () );

    if ( exts == NULL )
        return false;

    if ( strstr ( exts, "WGL_ARB_pbuffer" ) != NULL )
    {
        wglCreatePbufferARB    = (PFNWGLCREATEPBUFFERARBPROC)     wglGetProcAddress ( "wglCreatePbufferARB"    );
        wglGetPbufferDCARB     = (PFNWGLGETPBUFFERDCARBPROC)      wglGetProcAddress ( "wglGetPbufferDCARB"     );
        wglReleasePbufferDCARB = (PFNWGLRELEASEPBUFFERDCARBPROC)  wglGetProcAddress ( "wglReleasePbufferDCARB" );
        wglDestroyPbufferARB   = (PFNWGLDESTROYPBUFFERARBPROC)    wglGetProcAddress ( "wglDestroyPbufferARB"   );
        wglQueryPbufferARB     = (PFNWGLQUERYPBUFFERARBPROC)      wglGetProcAddress ( "wglQueryPbufferARB"     );
    }

    if ( strstr ( exts, "WGL_ARB_pixel_format" ) != NULL )
        wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress ( "wglChoosePixelFormatARB" );

    if ( strstr ( exts, "WGL_ARB_render_texture" ) != NULL )
    {
        wglBindTexImageARB      = (PFNWGLBINDTEXIMAGEARBPROC)     wglGetProcAddress ( "wglBindTexImageARB"     );
        wglReleaseTexImageARB   = (PFNWGLRELEASETEXIMAGEARBPROC)  wglGetProcAddress ( "wglReleaseTexImageARB"  );
        wglSetPbufferAttribARB  = (PFNWGLSETPBUFFERATTRIBARBPROC) wglGetProcAddress ( "wglSetPbufferAttribARB" );
    }

    if ( strstr ( exts, "WGL_EXT_swap_control" ) != NULL )
    {
        wglSwapIntervalEXT      = (PFNWGLSWAPINTERVALEXTPROC)       wglGetProcAddress ( "wglSwapIntervalEXT"    );
        wglGetSwapIntervalEXT   = (PFNWGLGETSWAPINTERVALEXTPROC)    wglGetProcAddress ( "wglGetSwapIntervalEXT" );
    }

    return true;
}
#else
void    initLinuxExtensions ()
{
                                    // GLX_SGIX_pbuffer
    glXCreateGLXPbufferSGIX  = (PFNGLXCREATEGLXPBUFFERSGIXPROC)  getProcAddress ( "glXCreateGLXPbufferSGIX" );
    glXDestroyGLXPbufferSGIX = (PFNGLXDESTROYGLXPBUFFERSGIXPROC) getProcAddress ( "glXDestroyGLXPbufferSGIX" );
    glXQueryGLXPbufferSGIX   = (PFNGLXQUERYGLXPBUFFERSGIXPROC)   getProcAddress ( "glXQueryGLXPbufferSGIX" );

                                    // GLX_SGIX_fbconfig
    glXChooseFBConfigSGIX          = (PFNGLXCHOOSEFBCONFIGSGIXPROC)          getProcAddress ( "glXChooseFBConfigSGIX" );
    glXCreateContextWithConfigSGIX = (PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC) getProcAddress ( "glXCreateContextWithConfigSGIX" );
}
#endif

void    initExtensions ()
{
    static  bool    initialized = false;                    // whether initExtensions has already been called

    if ( initialized )
        return;

#ifdef  _WIN32
    glActiveTextureARB       = (PFNGLACTIVETEXTUREARBPROC)         getProcAddress ( "glActiveTextureARB"       );
    glClientActiveTextureARB = (PFNGLCLIENTACTIVETEXTUREARBPROC)   getProcAddress ( "glClientActiveTextureARB" );
    glMultiTexCoord1f        = (PFNGLMULTITEXCOORD1FARBPROC)       getProcAddress ( "glMultiTexCoord1fARB"     );
    glMultiTexCoord1fv       = (PFNGLMULTITEXCOORD1FVARBPROC)      getProcAddress ( "glMultiTexCoord1fvARB"    );
    glMultiTexCoord2f        = (PFNGLMULTITEXCOORD2FARBPROC)       getProcAddress ( "glMultiTexCoord2fARB"     );
    glMultiTexCoord2fv       = (PFNGLMULTITEXCOORD2FVARBPROC)      getProcAddress ( "glMultiTexCoord2fvARB"    );
    glMultiTexCoord3f        = (PFNGLMULTITEXCOORD3FARBPROC)       getProcAddress ( "glMultiTexCoord3fARB"     );
    glMultiTexCoord3fv       = (PFNGLMULTITEXCOORD3FVARBPROC)      getProcAddress ( "glMultiTexCoord3fvARB"    );
    glMultiTexCoord4f        = (PFNGLMULTITEXCOORD4FARBPROC)       getProcAddress ( "glMultiTexCoord4fARB"     );
    glMultiTexCoord4fv       = (PFNGLMULTITEXCOORD4FVARBPROC)      getProcAddress ( "glMultiTexCoord4fvARB"    );
#endif

    glFogCoordf              = (PFNGLFOGCOORDFEXTPROC)             getProcAddress ( "glFogCoordfEXT"         );

    glSecondaryColor3f       = (PFNGLSECONDARYCOLOR3FPROC)         getProcAddress ( "glSecondaryColor3fEXT"      );
    glSecondaryColor3fv      = (PFNGLSECONDARYCOLOR3FVPROC)        getProcAddress ( "glSecondaryColor3fvEXT"     );
    glSecondaryColorPointer  = (PFNGLSECONDARYCOLORPOINTERPROC)    getProcAddress ( "glSecondaryColorPointerEXT" );

    glCombinerParameterfvNV  = (PFNGLCOMBINERPARAMETERFVNVPROC)    getProcAddress ( "glCombinerParameterfvNV"  );
    glCombinerParameterivNV  = (PFNGLCOMBINERPARAMETERIVNVPROC)    getProcAddress ( "glCombinerParameterivNV"  );
    glCombinerParameterfNV   = (PFNGLCOMBINERPARAMETERFNVPROC)     getProcAddress ( "glCombinerParameterfNV"   );
    glCombinerParameteriNV   = (PFNGLCOMBINERPARAMETERINVPROC)     getProcAddress ( "glCombinerParameteriNV"   );
    glCombinerInputNV        = (PFNGLCOMBINERINPUTNVPROC)          getProcAddress ( "glCombinerInputNV"        );
    glCombinerOutputNV       = (PFNGLCOMBINEROUTPUTNVPROC)         getProcAddress ( "glCombinerOutputNV"       );
    glFinalCombinerInputNV   = (PFNGLFINALCOMBINERINPUTNVPROC)     getProcAddress ( "glFinalCombinerInputNV"   );

    glBindBufferARB           = (PFNGLBINDBUFFERARBPROC)           getProcAddress ( "glBindBufferARB"           );
    glDeleteBuffersARB        = (PFNGLDELETEBUFFERSARBPROC)        getProcAddress ( "glDeleteBuffersARB"        );
    glGenBuffersARB           = (PFNGLGENBUFFERSARBPROC)           getProcAddress ( "glGenBuffersARB"           );
    glIsBufferARB             = (PFNGLISBUFFERARBPROC)             getProcAddress ( "glIsBufferARB"             );
    glBufferDataARB           = (PFNGLBUFFERDATAARBPROC)           getProcAddress ( "glBufferDataARB"           );
    glBufferSubDataARB        = (PFNGLBUFFERSUBDATAARBPROC)        getProcAddress ( "glBufferSubDataARB"        );
    glGetBufferSubDataARB     = (PFNGLGETBUFFERSUBDATAARBPROC)     getProcAddress ( "glGetBufferSubDataARB"     );
    glMapBufferARB            = (PFNGLMAPBUFFERARBPROC)            getProcAddress ( "glMapBufferARB"            );
    glUnmapBufferARB          = (PFNGLUNMAPBUFFERARBPROC)          getProcAddress ( "glUnmapBufferARB"          );
    glGetBufferParameterivARB = (PFNGLGETBUFFERPARAMETERIVARBPROC) getProcAddress ( "glGetBufferParameterivARB" );
    glGetBufferPointervARB    = (PFNGLGETBUFFERPOINTERVARBPROC)    getProcAddress ( "glGetBufferPointervARB"    );

                                    // NV-occlusion query extension
    glGenOcclusionQueriesNV = (PFNGLGENOCCLUSIONQUERIESNVPROC) getProcAddress ( "glGenOcclusionQueriesNV" );
    glBeginOcclusionQueryNV = (PFNGLBEGINOCCLUSIONQUERYNVPROC) getProcAddress ( "glBeginOcclusionQueryNV" );
    glEndOcclusionQueryNV   = (PFNGLENDOCCLUSIONQUERYNVPROC)   getProcAddress ( "glEndOcclusionQueryNV"   );
    glGetOcclusionQueryivNV = (PFNGLGETOCCLUSIONQUERYIVNVPROC) getProcAddress ( "glGetOcclusionQueryivNV" );

                                    // ARB_vertex_program extension
    glGenProgramsARB                = (PFNGLGENPROGRAMSARBPROC)               getProcAddress ( "glGenProgramsARB" );
    glDeleteProgramsARB             = (PFNGLDELETEPROGRAMSARBPROC)            getProcAddress ( "glDeleteProgramsARB" );
    glBindProgramARB                = (PFNGLBINDPROGRAMARBPROC)               getProcAddress ( "glBindProgramARB" );
    glIsProgramARB                  = (PFNGLISPROGRAMARBPROC)                 getProcAddress ( "glIsProgramARB" );
    glProgramStringARB              = (PFNGLPROGRAMSTRINGARBPROC)             getProcAddress ( "glProgramStringARB" );
    glGetProgramivARB               = (PFNGLGETPROGRAMIVARBPROC)              getProcAddress ( "glGetProgramivARB" );
    glVertexAttrib4fARB             = (PFNGLVERTEXATTRIB4FARBPROC)            getProcAddress ( "glVertexAttrib4fARB" );
    glVertexAttrib4fvARB            = (PFNGLVERTEXATTRIB4FVARBPROC)           getProcAddress ( "glVertexAttrib4fvARB" );
    glVertexAttrib3fARB             = (PFNGLVERTEXATTRIB3FARBPROC)            getProcAddress ( "glVertexAttrib3fARB" );
    glVertexAttrib3fvARB            = (PFNGLVERTEXATTRIB3FVARBPROC)           getProcAddress ( "glVertexAttrib3fvARB" );
    glVertexAttribPointerARB        = (PFNGLVERTEXATTRIBPOINTERARBPROC)       getProcAddress ( "glVertexAttribPointerARB" );
    glEnableVertexAttribArrayARB    = (PFNGLENABLEVERTEXATTRIBARRAYARBPROC)   getProcAddress ( "glEnableVertexAttribArrayARB" );
    glDisableVertexAttribArrayARB   = (PFNGLDISABLEVERTEXATTRIBARRAYARBPROC)  getProcAddress ( "glDisableVertexAttribArrayARB" );
    glProgramLocalParameter4fARB    = (PFNGLPROGRAMLOCALPARAMETER4FARBPROC)   getProcAddress ( "glProgramLocalParameter4fARB" );
    glProgramLocalParameter4fvARB   = (PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)  getProcAddress ( "glProgramLocalParameter4fvARB" );
    glGetProgramLocalParameterfvARB = (PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC)getProcAddress ( "glGetProgramLocalParameterfvARB" );
    glProgramEnvParameter4fARB      = (PFNGLPROGRAMENVPARAMETER4FARBPROC)     getProcAddress ( "glProgramEnvParameter4fARB" );
    glProgramEnvParameter4fvARB     = (PFNGLPROGRAMENVPARAMETER4FVARBPROC)    getProcAddress ( "glProgramEnvParameter4fvARB" );
    glGetProgramEnvParameterfvARB   = (PFNGLGETPROGRAMENVPARAMETERFVARBPROC)  getProcAddress ( "glGetProgramEnvParameterfvARB" );

                                    // GL_EXT_texture3D
    glTexImage3DEXT                 =(PFNGLTEXIMAGE3DEXTPROC)                 getProcAddress ( "glTexImage3DEXT" );

                                    // ARB_texture_compression
    glCompressedTexImage3DARB       = (PFNGLCOMPRESSEDTEXIMAGE3DARBPROC)      getProcAddress ( "glCompressedTexImage3DARB"    );
    glCompressedTexImage2DARB       = (PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)      getProcAddress ( "glCompressedTexImage2DARB"    );
    glCompressedTexImage1DARB       = (PFNGLCOMPRESSEDTEXIMAGE1DARBPROC)      getProcAddress ( "glCompressedTexImage1DARB"    );
    glCompressedTexSubImage3DARB    = (PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC)   getProcAddress ( "glCompressedTexSubImage3DARB" );
    glCompressedTexSubImage2DARB    = (PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC)   getProcAddress ( "glCompressedTexSubImage2DARB" );
    glCompressedTexSubImage1DARB    = (PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC)   getProcAddress ( "glCompressedTexSubImage1DARB" );
    glGetCompressedTexImageARB      = (PFNGLGETCOMPRESSEDTEXIMAGEARBPROC)     getProcAddress ( "glGetCompressedTexImageARB"   );

                                    // ARB_point_parameters
    glPointParameterfARB             = (PFNGLPOINTPARAMETERFARBPROC)          getProcAddress ( "glPointParameterfARB" );
    glPointParameterfvARB            = (PFNGLPOINTPARAMETERFVARBPROC)         getProcAddress ( "glPointParameterfvARB" );

                                    // ARB_occlusion_query
    glGenQueriesARB        = (PFNGLGENQUERIESARBPROC)        getProcAddress ( "glGenQueriesARB"        );
    glDeleteQueriesARB     = (PFNGLDELETEQUERIESARBPROC)     getProcAddress ( "glDeleteQueriesARB"     );
    glIsQueryARB           = (PFNGLISQUERYARBPROC)           getProcAddress ( "glIsQueryARB"           );
    glBeginQueryARB        = (PFNGLBEGINQUERYARBPROC)        getProcAddress ( "glBeginQueryARB"        );
    glEndQueryARB          = (PFNGLENDQUERYARBPROC)          getProcAddress ( "glEndQueryARB"          );
    glGetQueryivARB        = (PFNGLGETQUERYIVARBPROC)        getProcAddress ( "glGetQueryivARB"        );
    glGetQueryObjectivARB  = (PFNGLGETQUERYOBJECTIVARBPROC)  getProcAddress ( "glGetQueryObjectivARB"  );
    glGetQueryObjectuivARB = (PFNGLGETQUERYOBJECTUIVARBPROC) getProcAddress ( "glGetQueryObjectuivARB" );

                                    // GLSL-specific extensions
                                    // GL_ARB_shader_object
    glDeleteObjectARB         = (PFNGLDELETEOBJECTARBPROC)         getProcAddress ( "glDeleteObjectARB" );
    glGetHandleARB            = (PFNGLGETHANDLEARBPROC)            getProcAddress ( "glGetHandleARB" );
    glDetachObjectARB         = (PFNGLDETACHOBJECTARBPROC)         getProcAddress ( "glDetachObjectARB" );
    glCreateShaderObjectARB   = (PFNGLCREATESHADEROBJECTARBPROC)   getProcAddress ( "glCreateShaderObjectARB" );
    glShaderSourceARB         = (PFNGLSHADERSOURCEARBPROC)         getProcAddress ( "glShaderSourceARB" );
    glCompileShaderARB        = (PFNGLCOMPILESHADERARBPROC)        getProcAddress ( "glCompileShaderARB" );
    glCreateProgramObjectARB  = (PFNGLCREATEPROGRAMOBJECTARBPROC)  getProcAddress ( "glCreateProgramObjectARB" );
    glAttachObjectARB         = (PFNGLATTACHOBJECTARBPROC)         getProcAddress ( "glAttachObjectARB" );
    glLinkProgramARB          = (PFNGLLINKPROGRAMARBPROC)          getProcAddress ( "glLinkProgramARB" );
    glUseProgramObjectARB     = (PFNGLUSEPROGRAMOBJECTARBPROC)     getProcAddress ( "glUseProgramObjectARB" );
    glValidateProgramARB      = (PFNGLVALIDATEPROGRAMARBPROC)      getProcAddress ( "glValidateProgramARB" );
    glUniform1fARB            = (PFNGLUNIFORM1FARBPROC)            getProcAddress ( "glUniform1fARB" );
    glUniform2fARB            = (PFNGLUNIFORM2FARBPROC)            getProcAddress ( "glUniform2fARB" );
    glUniform3fARB            = (PFNGLUNIFORM3FARBPROC)            getProcAddress ( "glUniform3fARB" );
    glUniform4fARB            = (PFNGLUNIFORM4FARBPROC)            getProcAddress ( "glUniform4fARB" );
    glUniform1iARB            = (PFNGLUNIFORM1IARBPROC)            getProcAddress ( "glUniform1iARB" );
    glUniform2iARB            = (PFNGLUNIFORM2IARBPROC)            getProcAddress ( "glUniform2iARB" );
    glUniform3iARB            = (PFNGLUNIFORM3IARBPROC)            getProcAddress ( "glUniform3iARB" );
    glUniform4iARB            = (PFNGLUNIFORM4IARBPROC)            getProcAddress ( "glUniform4iARB" );
    glUniform1fvARB           = (PFNGLUNIFORM1FVARBPROC)           getProcAddress ( "glUniform1fvARB" );
    glUniform2fvARB           = (PFNGLUNIFORM2FVARBPROC)           getProcAddress ( "glUniform2fvARB" );
    glUniform3fvARB           = (PFNGLUNIFORM3FVARBPROC)           getProcAddress ( "glUniform3fvARB" );
    glUniform4fvARB           = (PFNGLUNIFORM4FVARBPROC)           getProcAddress ( "glUniform4fvARB" );
    glUniform1ivARB           = (PFNGLUNIFORM1IVARBPROC)           getProcAddress ( "glUniform1ivARB" );
    glUniform2ivARB           = (PFNGLUNIFORM2IVARBPROC)           getProcAddress ( "glUniform2ivARB" );
    glUniform3ivARB           = (PFNGLUNIFORM3IVARBPROC)           getProcAddress ( "glUniform3ivARB" );
    glUniform4ivARB           = (PFNGLUNIFORM4IVARBPROC)           getProcAddress ( "glUniform4ivARB" );
    glUniformMatrix2fvARB     = (PFNGLUNIFORMMATRIX2FVARBPROC)     getProcAddress ( "glUniformMatrix2fvARB" );
    glUniformMatrix3fvARB     = (PFNGLUNIFORMMATRIX3FVARBPROC)     getProcAddress ( "glUniformMatrix3fvARB" );
    glUniformMatrix4fvARB     = (PFNGLUNIFORMMATRIX4FVARBPROC)     getProcAddress ( "glUniformMatrix4fvARB" );
    glGetObjectParameterfvARB = (PFNGLGETOBJECTPARAMETERFVARBPROC) getProcAddress ( "glGetObjectParameterfvARB" );
    glGetObjectParameterivARB = (PFNGLGETOBJECTPARAMETERIVARBPROC) getProcAddress ( "glGetObjectParameterivARB" );
    glGetInfoLogARB           = (PFNGLGETINFOLOGARBPROC)           getProcAddress ( "glGetInfoLogARB" );
    glGetAttachedObjectsARB   = (PFNGLGETATTACHEDOBJECTSARBPROC)   getProcAddress ( "glGetAttachedObjectsARB" );
    glGetUniformLocationARB   = (PFNGLGETUNIFORMLOCATIONARBPROC)   getProcAddress ( "glGetUniformLocationARB" );
    glGetActiveUniformARB     = (PFNGLGETACTIVEUNIFORMARBPROC)     getProcAddress ( "glGetActiveUniformARB" );
    glGetUniformfvARB         = (PFNGLGETUNIFORMFVARBPROC)         getProcAddress ( "glGetUniformfvARB" );
    glGetUniformivARB         = (PFNGLGETUNIFORMIVARBPROC)         getProcAddress ( "glGetUniformivARB" );
    glGetShaderSourceARB      = (PFNGLGETSHADERSOURCEARBPROC)      getProcAddress ( "glGetShaderSourceARB" );

                                        // GL_ARB_vertex_shader
    glBindAttribLocationARB   = (PFNGLBINDATTRIBLOCATIONARBPROC)   getProcAddress ( "glBindAttribLocationARB" );
    glGetActiveAttribARB      = (PFNGLGETACTIVEATTRIBARBPROC)      getProcAddress ( "glGetActiveAttribARB"    );
    glGetAttribLocationARB    = (PFNGLGETATTRIBLOCATIONARBPROC)    getProcAddress ( "glGetAttribLocationARB"  );
    glGetVertexAttribfvARB    = (PFNGLGETVERTEXATTRIBFVARBPROC)    getProcAddress ( "glGetVertexAttribfvARB"  );

                                        // EXT_stencil_two_side
    glActiveStencilFaceEXT    = (PFNGLACTIVESTENCILFACEEXTPROC)    getProcAddress ( "glActiveStencilFaceEXT" );

										// EXT_depth_bounds_test
	glDepthBoundsEXT      = (PFNGLDEPTHBOUNDSEXTPROC)          getProcAddress ( "glDepthBoundsEXT" );

										// EXT_framebuffer_object
	glIsRenderbufferEXT                      = (PFNGLISRENDERBUFFEREXTPROC                     ) getProcAddress ( "glIsRenderbufferEXT" );
	glBindRenderbufferEXT                    = (PFNGLBINDRENDERBUFFEREXTPROC                   ) getProcAddress ( "glBindRenderbufferEXT" );
	glDeleteRenderbuffersEXT                 = (PFNGLDELETERENDERBUFFERSEXTPROC                ) getProcAddress ( "glDeleteRenderbuffersEXT" );
	glGenRenderbuffersEXT                    = (PFNGLGENRENDERBUFFERSEXTPROC                   ) getProcAddress ( "glGenRenderbuffersEXT" );
	glRenderbufferStorageEXT                 = (PFNGLRENDERBUFFERSTORAGEEXTPROC                ) getProcAddress ( "glRenderbufferStorageEXT" );
	glGetRenderbufferParameterivEXT          = (PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC         ) getProcAddress ( "glGetRenderbufferParameterivEXT" );
	glIsFramebufferEXT                       = (PFNGLISFRAMEBUFFEREXTPROC                      ) getProcAddress ( "glIsFramebufferEXT" );
	glBindFramebufferEXT                     = (PFNGLBINDFRAMEBUFFEREXTPROC                    ) getProcAddress ( "glBindFramebufferEXT" );
	glDeleteFramebuffersEXT                  = (PFNGLDELETEFRAMEBUFFERSEXTPROC                 ) getProcAddress ( "glDeleteFramebuffersEXT" );
	glGenFramebuffersEXT                     = (PFNGLGENFRAMEBUFFERSEXTPROC                    ) getProcAddress ( "glGenFramebuffersEXT" );
	glCheckFramebufferStatusEXT              = (PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC             ) getProcAddress ( "glCheckFramebufferStatusEXT" );
	glFramebufferTexture1DEXT                = (PFNGLFRAMEBUFFERTEXTURE1DEXTPROC               ) getProcAddress ( "glFramebufferTexture1DEXT" );
	glFramebufferTexture2DEXT                = (PFNGLFRAMEBUFFERTEXTURE2DEXTPROC               ) getProcAddress ( "glFramebufferTexture2DEXT" );
	glFramebufferTexture3DEXT                = (PFNGLFRAMEBUFFERTEXTURE3DEXTPROC               ) getProcAddress ( "glFramebufferTexture3DEXT" );
	glFramebufferRenderbufferEXT             = (PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC			   ) getProcAddress ( "glFramebufferRenderbufferEXT" );
	glGetFramebufferAttachmentParameterivEXT = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC) getProcAddress ( "glGetFramebufferAttachmentParameterivEXT" );
	glGenerateMipmapEXT                      = (PFNGLGENERATEMIPMAPEXTPROC					   ) getProcAddress ( "glGenerateMipmapEXT" );

#ifndef	GL_VERSION_1_3										// ARB_transpose matrix
	glLoadTransposeMatrixfARB	              = (PFNGLLOADTRANSPOSEMATRIXFPROC                 ) getProcAddress ( "glLoadTransposeMatrixfARB" );
	glLoadTransposeMatrixdARB	              = (PFNGLLOADTRANSPOSEMATRIXDPROC                 ) getProcAddress ( "glLoadTransposeMatrixdARB" );
	glMultTransposeMatrixfARB	              = (PFNGLMULTTRANSPOSEMATRIXFPROC                 ) getProcAddress ( "glMultTransposeMatrixfARB" );
	glMultTransposeMatrixdARB	              = (PFNGLMULTTRANSPOSEMATRIXDPROC                 ) getProcAddress ( "glMultTransposeMatrixdARB" );
#endif	

															// ARB_color_buffer_float
	glClampColorARB         = (PFNGLCLAMPCOLORARBPROC)      getProcAddress ( "glClampColorARB" );

#ifdef	_WIN32											// fresh Linux already has 2.0
														// stencil ops from OpenGL 2.0
	glStencilFuncSeparate  = (PFNGLSTENCILFUNCSEPARATEPROC) getProcAddress ( "glStencilFuncSeparate" );
	glStencilOpSeparate    = (PFNGLSTENCILOPSEPARATEPROC)   getProcAddress ( "glStencilOpSeparate" );
	glStencilMaskSeparate  = (PFNGLSTENCILMASKSEPARATEPROC) getProcAddress ( "glStencilMaskSeparate" );

															// blend ops from OPenGL 2.0
	glBlendEquation         = (PFNGLBLENDEQUATIONPROC)         getProcAddress ( "glBlendEquation" );
	glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC) getProcAddress ( "glBlendEquationSeparate" );
	glBlendFuncSeparate     = (PFNGLBLENDFUNCSEPARATEPROC)     getProcAddress ( "glBlendFuncSeparate" );
	glBlendColor            = (PFNGLBLENDCOLORPROC)            getProcAddress ( "glBlendColor" );
#endif

															// draw buffers from OpenGL 2.0
	glDrawBuffers           = (PFNGLDRAWBUFFERSPROC)           getProcAddress ( "glDrawBuffers" );
															// ATI_draw_buffers
	glDrawBuffersATI        = (PFNGLDRAWBUFFERSATIPROC)        getProcAddress ( "glDrawBuffersATI" );
	
															// EXT_texture_integer
	glTexParameterIivEXT      = (PFNGLTEXPARAMETERIIVEXTPROC)     getProcAddress ( "glTexParameterIivEXT" );
	glTexParameterIuivEXT     = (PFNGLTEXPARAMETERIUIVEXTPROC)    getProcAddress ( "glTexParameterIuivEXT" );
	glGetTexParameterIivEXT   = (PFNGLGETTEXPARAMETERIIVEXTPROC)  getProcAddress ( "glGetTexParameterIivEXT" );
	glGetTexParameterIuivEXT  = (PFNGLGETTEXPARAMETERIUIVEXTPROC) getProcAddress ( "glGetTexParameterIuivEXT" );
	glClearColorIiEXT         = (PFNGLCLEARCOLORIIEXTPROC)        getProcAddress ( "glClearColorIiEXT" );
	glClearColorIuiEXT        = (PFNGLCLEARCOLORIUIEXTPROC)       getProcAddress ( "glClearColorIuiEXT" );
															
															// EXT_draw_instanced
	glDrawArraysInstancedEXT    = (PFNGLDRAWARRAYSINSTANCEDEXTPROC)    getProcAddress ( "glDrawArraysInstancedEXT" );
	glDrawElementsInstancedEXT  = (PFNGLDRAWELEMENTSINSTANCEDEXTPROC)  getProcAddress ( "glDrawElementsInstancedEXT" );

															// EXT_texture_buffer_object
	glTexBufferEXT  = (PFNGLTEXBUFFEREXTPROC)  getProcAddress ( "glTexBufferEXT" );
															
															// EXT_gpu_shader4
	glGetUniformuivEXT         = (PFNGLGETUNIFORMUIVEXTPROC)        getProcAddress ( "" );
	glBindFragDataLocationEXT  = (PFNGLBINDFRAGDATALOCATIONEXTPROC) getProcAddress ( "glBindFragDataLocationEXT" );
	glGetFragDataLocationEXT   = (PFNGLGETFRAGDATALOCATIONEXTPROC)  getProcAddress ( "glGetFragDataLocationEXT" );
	glUniform1uiEXT            = (PFNGLUNIFORM1UIEXTPROC)           getProcAddress ( "glUniform1uiEXT" );
	glUniform2uiEXT            = (PFNGLUNIFORM2UIEXTPROC)           getProcAddress ( "glUniform2uiEXT" );
	glUniform3uiEXT            = (PFNGLUNIFORM3UIEXTPROC)           getProcAddress ( "glUniform3uiEXT" );
	glUniform4uiEXT            = (PFNGLUNIFORM4UIEXTPROC)           getProcAddress ( "glUniform4uiEXT" );
	glUniform1uivEXT           = (PFNGLUNIFORM1UIVEXTPROC)          getProcAddress ( "glUniform1uivEXT" );
	glUniform2uivEXT           = (PFNGLUNIFORM2UIVEXTPROC)          getProcAddress ( "glUniform2uivEXT" );
	glUniform3uivEXT           = (PFNGLUNIFORM2UIVEXTPROC)          getProcAddress ( "glUniform3uivEXT" );
	glUniform4uivEXT           = (PFNGLUNIFORM2UIVEXTPROC)          getProcAddress ( "glUniform4uivEXT" );
	glVertexAttribI1iEXT       = (PFNGLVERTEXATTRIBI1IEXTPROC)      getProcAddress ( "glVertexAttribI1iEXT" );
	glVertexAttribI2iEXT       = (PFNGLVERTEXATTRIBI2IEXTPROC)      getProcAddress ( "glVertexAttribI2iEXT" );
	glVertexAttribI3iEXT       = (PFNGLVERTEXATTRIBI3IEXTPROC)      getProcAddress ( "glVertexAttribI3iEXT" );
	glVertexAttribI4iEXT       = (PFNGLVERTEXATTRIBI4IEXTPROC)      getProcAddress ( "glVertexAttribI4iEXT" );
	glVertexAttribI1uiEXT      = (PFNGLVERTEXATTRIBI1UIEXTPROC)     getProcAddress ( "glVertexAttribI1uiEXT" );
	glVertexAttribI2uiEXT      = (PFNGLVERTEXATTRIBI2UIEXTPROC)     getProcAddress ( "glVertexAttribI2uiEXT" );
	glVertexAttribI3uiEXT      = (PFNGLVERTEXATTRIBI3UIEXTPROC)     getProcAddress ( "glVertexAttribI3uiEXT" );
	glVertexAttribI4uiEXT      = (PFNGLVERTEXATTRIBI4UIEXTPROC)     getProcAddress ( "glVertexAttribI4uiEXT" );
	glVertexAttribI1ivEXT      = (PFNGLVERTEXATTRIBI1IVEXTPROC)     getProcAddress ( "glVertexAttribI1ivEXT" );
	glVertexAttribI2ivEXT      = (PFNGLVERTEXATTRIBI2IVEXTPROC)     getProcAddress ( "glVertexAttribI2ivEXT" );
	glVertexAttribI3ivEXT      = (PFNGLVERTEXATTRIBI3IVEXTPROC)     getProcAddress ( "glVertexAttribI3ivEXT" );
	glVertexAttribI4ivEXT      = (PFNGLVERTEXATTRIBI4IVEXTPROC)     getProcAddress ( "glVertexAttribI4ivEXT" );
	glVertexAttribI1uivEXT     = (PFNGLVERTEXATTRIBI1UIVEXTPROC)    getProcAddress ( "glVertexAttribI1uivEXT" );
	glVertexAttribI2uivEXT     = (PFNGLVERTEXATTRIBI2UIVEXTPROC)    getProcAddress ( "glVertexAttribI2uivEXT" );
	glVertexAttribI3uivEXT     = (PFNGLVERTEXATTRIBI3UIVEXTPROC)    getProcAddress ( "glVertexAttribI3uivEXT" );
	glVertexAttribI4uivEXT     = (PFNGLVERTEXATTRIBI4UIVEXTPROC)    getProcAddress ( "glVertexAttribI4uivEXT" );
	glVertexAttribI4bvEXT      = (PFNGLVERTEXATTRIBI4BVEXTPROC)     getProcAddress ( "glVertexAttribI4bvEXT" );
	glVertexAttribI4svEXT      = (PFNGLVERTEXATTRIBI4SVEXTPROC)     getProcAddress ( "glVertexAttribI4svEXT" );
	glVertexAttribI4ubvEXT     = (PFNGLVERTEXATTRIBI4UBVEXTPROC)    getProcAddress ( "glVertexAttribI4ubvEXT" );
	glVertexAttribI4usvEXT     = (PFNGLVERTEXATTRIBI4USVEXTPROC)    getProcAddress ( "glVertexAttribI4usvEXT" );
	glVertexAttribIPointerEXT  = (PFNGLVERTEXATTRIBIPOINTEREXTPROC) getProcAddress ( "glVertexAttribIPointerEXT" );
	glGetVertexAttribIivEXT    = (PFNGLGETVERTEXATTRIBIIVEXTPROC)   getProcAddress ( "glGetVertexAttribIivEXT" );
	glGetVertexAttribIuivEXT   = (PFNGLGETVERTEXATTRIBIUIVEXTPROC)  getProcAddress ( "glGetVertexAttribIuivEXT" );

														// EXT_geometry_shader4
	glProgramParameteriEXT       = (PFNGLPROGRAMPARAMETERIEXTPROC)       getProcAddress ( "glProgramParameteriEXT" );
	glFramebufferTextureEXT      = (PFNGLFRAMEBUFFERTEXTUREEXTPROC)      getProcAddress ( "glFramebufferTextureEXT" );
	glFramebufferTextureLayerEXT = (PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC) getProcAddress ( "glFramebufferTextureLayerEXT" );
	glFramebufferTextureFaceEXT  = (PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC)  getProcAddress ( "glFramebufferTextureFaceEXT" );
	
														// EXT_bindable_uniform
	glUniformBufferEXT        = (PFNGLUNIFORMBUFFEREXTPROC)        getProcAddress ( "glUniformBufferEXT" );
	glGetUniformBufferSizeEXT = (PFNGLGETUNIFORMBUFFERSIZEEXTPROC) getProcAddress ( "glGetUniformBufferSizeEXT" );
	glGetUniformOffsetEXT     = (PFNGLGETUNIFORMOFFSETEXTPROC)     getProcAddress ( "glGetUniformOffsetEXT" );

														// OpenGL 2.0 shader support
	glCompileShader       = (PFNGLCOMPILESHADERPROC)      getProcAddress ( "glCompileShader" );
	glCreateProgram       = (PFNGLCREATEPROGRAMPROC)      getProcAddress ( "glCreateProgram" );
	glCreateShader        = (PFNGLCREATESHADERPROC)       getProcAddress ( "glCreateShader" );
	glDeleteProgram       = (PFNGLDELETEPROGRAMPROC)      getProcAddress ( "glDeleteProgram" );
	glDeleteShader        = (PFNGLDELETESHADERPROC)       getProcAddress ( "glDeleteShader" );
	glDetachShader        = (PFNGLDETACHSHADERPROC)       getProcAddress ( "glDetachShader" );
	glGetProgramInfoLog   = (PFNGLGETPROGRAMINFOLOGPROC)  getProcAddress ( "glGetProgramInfoLog" );
	glGetShaderInfoLog    = (PFNGLGETSHADERINFOLOGPROC)   getProcAddress ( "glGetShaderInfoLog" );
	glGetShaderSource     = (PFNGLGETSHADERSOURCEPROC)    getProcAddress ( "glGetShaderSource" );
	glLinkProgram         = (PFNGLLINKPROGRAMPROC)        getProcAddress ( "glLinkProgram" );
	glShaderSource        = (PFNGLSHADERSOURCEPROC)       getProcAddress ( "glShaderSource" );
	glUseProgram          = (PFNGLUSEPROGRAMPROC)         getProcAddress ( "glUseProgram" );
	glValidateProgram     = (PFNGLVALIDATEPROGRAMPROC)    getProcAddress ( "glValidateProgram" );
	glGetProgramiv        = (PFNGLGETPROGRAMIVPROC)       getProcAddress ( "glGetProgramiv" );
	glGetShaderiv         = (PFNGLGETSHADERIVPROC)        getProcAddress ( "glGetShaderiv" );
	glAttachShader        = (PFNGLATTACHSHADERPROC)       getProcAddress ( "glAttachShader" );
	glGetUniformLocation  = (PFNGLGETUNIFORMLOCATIONPROC) getProcAddress ( "glGetUniformLocation" );
	glGetAttribLocation   = (PFNGLGETATTRIBLOCATIONPROC)  getProcAddress ( "glGetAttribLocation" );
	glUniform4fv          = (PFNGLUNIFORM4FVPROC)         getProcAddress ( "glUniform4fv" );
	glUniform3fv          = (PFNGLUNIFORM3FVPROC)		  getProcAddress ( "glUniform3fv" );
	glUniform2fv          = (PFNGLUNIFORM2FVPROC)		  getProcAddress ( "glUniform2fv" );
	glUniform1f           = (PFNGLUNIFORM1FPROC)		  getProcAddress ( "glUniform1f" );
	glUniform1i           = (PFNGLUNIFORM1IPROC)		  getProcAddress ( "glUniform1i" );
	glGetUniformfv        = (PFNGLGETUNIFORMFVPROC)		  getProcAddress ( "glGetUniformfv" );
	glVertexAttrib4fv     = (PFNGLVERTEXATTRIB4FVPROC)	  getProcAddress ( "glVertexAttrib4fv" );
	glGetVertexAttribfv   = (PFNGLGETVERTEXATTRIBFVPROC)  getProcAddress ( "glGetVertexAttribfv" );
	glUniformMatrix2fv    = (PFNGLUNIFORMMATRIX2FVPROC)   getProcAddress ( "glUniformMatrix2fv" );
	glUniformMatrix3fv    = (PFNGLUNIFORMMATRIX3FVPROC)   getProcAddress ( "glUniformMatrix3fv" );
	glUniformMatrix4fv    = (PFNGLUNIFORMMATRIX4FVPROC)   getProcAddress ( "glUniformMatrix4fv" );

                                    // OpenGL 2 query support
    glGenQueries          = (PFNGLGENQUERIESPROC)        getProcAddress ( "glGenQueries"        );
    glDeleteQueries       = (PFNGLDELETEQUERIESPROC)     getProcAddress ( "glDeleteQueries"     );
    glIsQuery             = (PFNGLISQUERYPROC)           getProcAddress ( "glIsQuery"           );
    glBeginQuery          = (PFNGLBEGINQUERYPROC)        getProcAddress ( "glBeginQuery"        );
    glEndQuery            = (PFNGLENDQUERYPROC)          getProcAddress ( "glEndQuery"          );
    glGetQueryiv          = (PFNGLGETQUERYIVPROC)        getProcAddress ( "glGetQueryiv"        );
    glGetQueryObjectiv    = (PFNGLGETQUERYOBJECTIVPROC)  getProcAddress ( "glGetQueryObjectiv"  );
    glGetQueryObjectuiv   = (PFNGLGETQUERYOBJECTUIVPROC) getProcAddress ( "glGetQueryObjectuiv" );
	
														// NV_transform_feedback
	glBeginTransformFeedbackNV      = (PFNGLBEGINTRANSFORMFEEDBACKNVPROC)      getProcAddress ( "glBeginTransformFeedbackNV" );
	glEndTransformFeedbackNV        = (PFNGLENDTRANSFORMFEEDBACKNVPROC)        getProcAddress ( "glEndTransformFeedbackNV" );
	glTransformFeedbackAttribsNV    = (PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC)    getProcAddress ( "glTransformFeedbackAttribsNV" );
	glBindBufferRangeNV             = (PFNGLBINDBUFFERRANGENVPROC)             getProcAddress ( "glBindBufferRangeNV" );
	glBindBufferOffsetNV            = (PFNGLBINDBUFFEROFFSETNVPROC)            getProcAddress ( "glBindBufferOffsetNV" );
	glBindBufferBaseNV              = (PFNGLBINDBUFFERBASENVPROC)              getProcAddress ( "glBindBufferBaseNV" );
	glTransformFeedbackVaryingsNV   = (PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC)   getProcAddress ( "glTransformFeedbackVaryingsNV" );
	glActiveVaryingNV               = (PFNGLACTIVEVARYINGNVPROC)               getProcAddress ( "glActiveVaryingNV" );
	glGetVaryingLocationNV          = (PFNGLGETVARYINGLOCATIONNVPROC)          getProcAddress ( "glGetVaryingLocationNV" );
	glGetActiveVaryingNV            = (PFNGLGETACTIVEVARYINGNVPROC)            getProcAddress ( "glGetActiveVaryingNV" );
	glGetTransformFeedbackVaryingNV = (PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC) getProcAddress ( "glGetTransformFeedbackVaryingNV" );

														// NV_fence
	glDeleteFencesNV = (PFNGLDELETEFENCESNVPROC)		getProcAddress ( "glDeleteFencesNV" );
	glGenFencesNV    = (PFNGLGENFENCESNVPROC)			getProcAddress ( "glGenFencesNV"    );
	glIsFenceNV      = (PFNGLISFENCENVPROC)				getProcAddress ( "glIsFenceNV"      );
	glTestFenceNV    = (PFNGLTESTFENCENVPROC)			getProcAddress ( "glTestFenceNV "   );
	glGetFenceivNV   = (PFNGLGETFENCEIVNVPROC)			getProcAddress ( "glGetFenceivNV"   );
	glFinishFenceNV  = (PFNGLFINISHFENCENVPROC)			getProcAddress ( "glFinishFenceNV"  );
	glSetFenceNV     = (PFNGLSETFENCENVPROC)			getProcAddress ( "glSetFenceNV"     );

														// NV__conditional_render
	glBeginConditionalRenderNV = (PFNGLBEGINCONDITIONALRENDERNVPROC) getProcAddress ( "glBeginConditionalRenderNV" );
	glEndConditionalRenderNV   = (PFNGLENDCONDITIONALRENDERNVPROC)   getProcAddress ( "glEndConditionalRenderNV"   );
	
														// ARB_get_program_binary
	glGetProgramBinary  = (PFNGLGETPROGRAMBINARYPROC)  getProcAddress ( "glGetProgramBinary" );
	glProgramBinary     = (PFNGLPROGRAMBINARYPROC)     getProcAddress ( "glProgramBinary" );
	glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC) getProcAddress ( "glProgramParameteri" );													

														// ARB_sampler_objects
	glGenSamplers            = (PFNGLGENSAMPLERSPROC)				getProcAddress ( "glGenSamplers" );
	glDeleteSamplers         = (PFNGLDELETESAMPLERSPROC)			getProcAddress ( "glDeleteSamplers" );
	glIsSampler              = (PFNGLISSAMPLERPROC)					getProcAddress ( "glIsSampler" );
	glBindSampler            = (PFNGLBINDSAMPLERPROC)				getProcAddress ( "glBindSampler" );
	glSamplerParameteri      = (PFNGLSAMPLERPARAMETERIPROC)			getProcAddress ( "glSamplerParameteri" );
	glSamplerParameteriv     = (PFNGLSAMPLERPARAMETERIVPROC)		getProcAddress ( "glSamplerParameteriv" );
	glSamplerParameterf      = (PFNGLSAMPLERPARAMETERFPROC)			getProcAddress ( "glSamplerParameterf" );
	glSamplerParameterfv     = (PFNGLSAMPLERPARAMETERFVPROC)		getProcAddress ( "glSamplerParameterfv" );
	glSamplerParameterIiv    = (PFNGLSAMPLERPARAMETERIIVPROC)		getProcAddress ( "glSamplerParameterIiv" );
	glSamplerParameterIuiv   = (PFNGLSAMPLERPARAMETERIUIVPROC)		getProcAddress ( "glSamplerParameterIuiv" );
	glGetSamplerParameteriv  = (PFNGLGETSAMPLERPARAMETERIVPROC)		getProcAddress ( "glGetSamplerParameteriv" );
	glGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC)	getProcAddress ( "glGetSamplerParameterIiv" );
	glGetSamplerParameterfv  = (PFNGLGETSAMPLERPARAMETERFVPROC)		getProcAddress ( "glGetSamplerParameterfv" );
	glGetSamplerParameterIfv = (PFNGLGETSAMPLERPARAMETERIFVPROC)	getProcAddress ( "glGetSamplerParameterIfv" );

														// ARB_vertex_array_object
	glBindVertexArray    = (PFNGLBINDVERTEXARRAYPROC)		getProcAddress ( "glBindVertexArray" );
	glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)	getProcAddress ( "glDeleteVertexArrays" );
	glGenVertexArrays    = (PFNGLGENVERTEXARRAYSPROC)		getProcAddress ( "glGenVertexArrays" );
	glIsVertexArray      = (PFNGLISVERTEXARRAYPROC)			getProcAddress ( "glIsVertexArray" );

														// ARB_instanced_arrays
	glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORARBPROC)	getProcAddress ( "glVertexAttribDivisor" );

														// ARB_timer_query
	glQueryCounter        = (PFNGLQUERYCOUNTERPROC)			getProcAddress ( "glQueryCounter" );
	glGetQueryObjecti64v  = (PFNGLGETQUERYOBJECTI64VPROC)	getProcAddress ( "glGetQueryObjecti64v" );
	glGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64VPROC)	getProcAddress ( "glGetQueryObjectui64v" );

														// ARB_sync
	glFenceSync      = (PFNGLFENCESYNCPROC)			getProcAddress ( "glFenceSync" );
	glIsSync         = (PFNGLISSYNCPROC)			getProcAddress ( "glIsSync" );
	glDeleteSync     = (PFNGLDELETESYNCPROC)		getProcAddress ( "glDeleteSync" );
	glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)	getProcAddress ( "glClientWaitSync" );
	glWaitSync       = (PFNGLWAITSYNCPROC)			getProcAddress ( "glWaitSync" );
	glGetInteger64v  = (PFNGLGETINTEGER64VPROC)		getProcAddress ( "glGetInteger64v" );
	glGetSynciv      = (PFNGLGETSYNCIVPROC)			getProcAddress ( "glGetSynciv" );

														// ARB_separate_shader_objects
	glUseProgramStages          = (PFNGLUSEPROGRAMSTAGESPROC)			getProcAddress ( "glUseProgramStages" );
	glActiveShaderProgram       = (PFNGLACTIVESHADERPROGRAMPROC)		getProcAddress ( "glActiveShaderProgram" );
	glCreateShaderProgramv      = (PFNGLCREATESHADERPROGRAMVPROC)		getProcAddress ( "glCreateShaderProgramv" );
	glBindProgramPipeline       = (PFNGLBINDPROGRAMPIPELINEPROC)		getProcAddress ( "glBindProgramPipeline" );
	glDeleteProgramPipelines    = (PFNGLDELETEPROGRAMPIPELINESPROC)		getProcAddress ( "glDeleteProgramPipelines" );
	glGenProgramPipelines       = (PFNGLGENPROGRAMPIPELINESPROC)		getProcAddress ( "glGenProgramPipelines" );
	glIsProgramPipeline         = (PFNGLISPROGRAMPIPELINEPROC)			getProcAddress ( "glIsProgramPipeline" );
	glGetProgramPipelineiv      = (PFNGLGETPROGRAMPIPELINEIVPROC)		getProcAddress ( "glGetProgramPipelineiv" );
	glProgramUniform1i          = (PFNGLPROGRAMUNIFORM1IPROC)			getProcAddress ( "glProgramUniform1i" );
	glProgramUniform1iv         = (PFNGLPROGRAMUNIFORM1IVPROC)			getProcAddress ( "glProgramUniform1iv" );
	glProgramUniform1f          = (PFNGLPROGRAMUNIFORM1FPROC)			getProcAddress ( "glProgramUniform1f" );
	glProgramUniform1fv         = (PFNGLPROGRAMUNIFORM1FVPROC)			getProcAddress ( "glProgramUniform1fv" );
	glProgramUniform1d          = (PFNGLPROGRAMUNIFORM1DPROC)			getProcAddress ( "glProgramUniform1d" );
	glProgramUniform1dv         = (PFNGLPROGRAMUNIFORM1DVPROC)			getProcAddress ( "glProgramUniform1dv" );
	glProgramUniform1ui         = (PFNGLPROGRAMUNIFORM1UIPROC)			getProcAddress ( "glProgramUniform1ui" );
	glProgramUniform1uiv        = (PFNGLPROGRAMUNIFORM1UIVPROC)			getProcAddress ( "glProgramUniform1uiv" );
	glProgramUniform2i          = (PFNGLPROGRAMUNIFORM2IPROC)			getProcAddress ( "glProgramUniform2i" );
	glProgramUniform2iv         = (PFNGLPROGRAMUNIFORM2IVPROC)			getProcAddress ( "glProgramUniform2iv" );
	glProgramUniform2f          = (PFNGLPROGRAMUNIFORM2FPROC)			getProcAddress ( "glProgramUniform2f" );
	glProgramUniform2fv         = (PFNGLPROGRAMUNIFORM2FVPROC)			getProcAddress ( "glProgramUniform2fv" );
	glProgramUniform2d          = (PFNGLPROGRAMUNIFORM2DPROC)			getProcAddress ( "glProgramUniform2d" );
	glProgramUniform2dv         = (PFNGLPROGRAMUNIFORM2DVPROC)			getProcAddress ( "glProgramUniform2dv" );
	glProgramUniform2ui         = (PFNGLPROGRAMUNIFORM2UIPROC)			getProcAddress ( "glProgramUniform2ui" );
	glProgramUniform2uiv        = (PFNGLPROGRAMUNIFORM2UIVPROC)			getProcAddress ( "glProgramUniform2uiv" );
	glProgramUniform3i          = (PFNGLPROGRAMUNIFORM3IPROC)			getProcAddress ( "glProgramUniform3i" );
	glProgramUniform3iv         = (PFNGLPROGRAMUNIFORM3IVPROC)			getProcAddress ( "glProgramUniform3iv" );
	glProgramUniform3f          = (PFNGLPROGRAMUNIFORM3FPROC)			getProcAddress ( "glProgramUniform3f" );
	glProgramUniform3fv         = (PFNGLPROGRAMUNIFORM3FVPROC)			getProcAddress ( "glProgramUniform3fv" );
	glProgramUniform3d          = (PFNGLPROGRAMUNIFORM3DPROC)			getProcAddress ( "glProgramUniform3d" );
	glProgramUniform3dv         = (PFNGLPROGRAMUNIFORM3DVPROC)			getProcAddress ( "glProgramUniform3dv" );
	glProgramUniform3ui         = (PFNGLPROGRAMUNIFORM3UIPROC)			getProcAddress ( "glProgramUniform3ui" );
	glProgramUniform3uiv        = (PFNGLPROGRAMUNIFORM3UIVPROC)			getProcAddress ( "glProgramUniform3uiv" );
	glProgramUniform4i          = (PFNGLPROGRAMUNIFORM4IPROC)			getProcAddress ( "glProgramUniform4i" );
	glProgramUniform4iv         = (PFNGLPROGRAMUNIFORM4IVPROC)			getProcAddress ( "glProgramUniform4iv" );
	glProgramUniform4f          = (PFNGLPROGRAMUNIFORM4FPROC)			getProcAddress ( "glProgramUniform4f" );
	glProgramUniform4fv         = (PFNGLPROGRAMUNIFORM4FVPROC)			getProcAddress ( "glProgramUniform4fv" );
	glProgramUniform4d          = (PFNGLPROGRAMUNIFORM4DPROC)			getProcAddress ( "glProgramUniform4d" );
	glProgramUniform4dv         = (PFNGLPROGRAMUNIFORM4DVPROC)			getProcAddress ( "glProgramUniform4dv" );
	glProgramUniform4ui         = (PFNGLPROGRAMUNIFORM4UIPROC)			getProcAddress ( "glProgramUniform4ui" );
	glProgramUniform4uiv        = (PFNGLPROGRAMUNIFORM4UIVPROC)			getProcAddress ( "glProgramUniform4uiv" );
	glProgramUniformMatrix2fv   = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)	getProcAddress ( "glProgramUniformMatrix2fv" );
	glProgramUniformMatrix3fv   = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)	getProcAddress ( "glProgramUniformMatrix3fv" );
	glProgramUniformMatrix4fv   = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)	getProcAddress ( "glProgramUniformMatrix4fv" );
	glProgramUniformMatrix2dv   = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC)	getProcAddress ( "glProgramUniformMatrix2dv" );
	glProgramUniformMatrix3dv   = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC)	getProcAddress ( "glProgramUniformMatrix3dv" );
	glProgramUniformMatrix4dv   = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC)	getProcAddress ( "glProgramUniformMatrix4dv" );
	glProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)	getProcAddress ( "glProgramUniformMatrix2x3fv" );
	glProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)	getProcAddress ( "glProgramUniformMatrix3x2fv" );
	glProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)	getProcAddress ( "glProgramUniformMatrix2x4fv" );
	glProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)	getProcAddress ( "glProgramUniformMatrix4x2fv" );
	glProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)	getProcAddress ( "glProgramUniformMatrix3x4fv" );
	glProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)	getProcAddress ( "glProgramUniformMatrix4x3fv" );
	glProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)	getProcAddress ( "glProgramUniformMatrix2x3dv" );
	glProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)	getProcAddress ( "glProgramUniformMatrix3x2dv" );
	glProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)	getProcAddress ( "glProgramUniformMatrix2x4dv" );
	glProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)	getProcAddress ( "glProgramUniformMatrix4x2dv" );
	glProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)	getProcAddress ( "glProgramUniformMatrix3x4dv" );
	glProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)	getProcAddress ( "glProgramUniformMatrix4x3dv" );
	glValidateProgramPipeline   = (PFNGLVALIDATEPROGRAMPIPELINEPROC)	getProcAddress ( "glValidateProgramPipeline" );
	glGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC)	getProcAddress ( "glGetProgramPipelineInfoLog" );

											// ARB_transform_feedback3
	glDrawTransformFeedbackStream = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)	getProcAddress ( "glDrawTransformFeedbackStream" );
	glBeginQueryIndexed           = (PFNGLBEGINQUERYINDEXEDPROC)			getProcAddress ( "glBeginQueryIndexed" );
	glEndQueryIndexed             = (PFNGLENDQUERYINDEXEDPROC)				getProcAddress ( "glEndQueryIndexed" );
	glGetQueryIndexediv           = (PFNGLGETQUERYINDEXEDIVPROC)			getProcAddress ( "glGetQueryIndexediv" );
												
											// ARB_transform_feedback2
	glBindTransformFeedback    = (PFNGLBINDTRANSFORMFEEDBACKPROC)			getProcAddress ( "glBindTransformFeedback" );
	glDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC)		getProcAddress ( "glDeleteTransformFeedbacks" );
	glGenTransformFeedbacks    = (PFNGLGENTRANSFORMFEEDBACKSPROC)			getProcAddress ( "glGenTransformFeedbacks" );
	glIsTransformFeedback      = (PFNGLISTRANSFORMFEEDBACKPROC)				getProcAddress ( "glIsTransformFeedback" );
	glPauseTransformFeedback   = (PFNGLPAUSETRANSFORMFEEDBACKPROC)			getProcAddress ( "glPauseTransformFeedback" );
	glResumeTransformFeedback  = (PFNGLRESUMETRANSFORMFEEDBACKPROC)			getProcAddress ( "glResumeTransformFeedback" );
	glDrawTransformFeedback    = (PFNGLDRAWTRANSFORMFEEDBACKPROC)			getProcAddress ( "glDrawTransformFeedback" );

											// ARB_tessellation_shader
	glPatchParameteri          = (PFNGLPATCHPARAMETERIPROC)					getProcAddress ( "glPatchParameteri" );
	glPatchParameterfv         = (PFNGLPATCHPARAMETERFVPROC)				getProcAddress ( "glPatchParameterfv" );

											// ARB_draw_indirect
	glDrawArraysIndirect       = (PFNGLDRAWARRAYSINDIRECTPROC)				getProcAddress ( "glDrawArraysIndirect" );
	glDrawElementsIndirect     = (PFNGLDRAWELEMENTSINDIRECTPROC)			getProcAddress ( "glDrawElementsIndirect" );

											// ARB_shading_language_include
	glNamedStringARB          = (PFNGLNAMEDSTRINGARBPROC)				getProcAddress ( "glNamedStringARB" );
	glDeleteNamedStringARB    = (PFNGLDELETENAMEDSTRINGARBPROC)			getProcAddress ( "glDeleteNamedStringARB" );
	glCompileShaderIncludeARB = (PFNGLCOMPILESHADERINCLUDEARBPROC)		getProcAddress ( "glCompileShaderIncludeARB" );
	glIsNamedStringARB        = (PFNGLISNAMEDSTRINGARBPROC)				getProcAddress ( "glIsNamedStringARB" );
	glGetNamedStringARB       = (PFNGLGETNAMEDSTRINGARBPROC)			getProcAddress ( "glGetNamedStringARB" );
	glGetNamedStringivARB     = (PFNGLGETNAMEDSTRINGIVARBPROC)			getProcAddress ( "glGetNamedStringivARB" );

											// ARB_provoking_vertex
	glProvokingVertex         = (PFNGLPROVOKINGVERTEXPROC)				getProcAddress ( "glProvokingVertex" );

											// ARB_draw_elements_base_vertex
	glDrawElementsBaseVertex          = (PFNGLDRAWELEMENTSBASEVERTEXPROC)			getProcAddress ( "glDrawElementsBaseVertex" );
	glDrawRangeElementsBaseVertex     = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)		getProcAddress ( "glDrawRangeElementsBaseVertex" );
	glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)	getProcAddress ( "glDrawElementsInstancedBaseVertex" );
	glMultiDrawElementsBaseVertex     = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)		getProcAddress ( "glMultiDrawElementsBaseVertex" );

											// ARB_copy_buffer
	glCopyBufferSubData               = (PFNGLCOPYBUFFERSUBDATAPROC)				getProcAddress ( "glCopyBufferSubData" );

											// ARB_uniform_buffer_object
	glGetUniformIndices          = (PFNGLGETUNIFORMINDICESPROC)			getProcAddress ( "glGetUniformIndices" );
	glGetActiveUniformsiv        = (PFNGLGETACTIVEUNIFORMSIVPROC)		getProcAddress ( "glGetActiveUniformsiv" );
	glGetActiveUniformName       = (PFNGLGETACTIVEUNIFORMNAMEPROC)		getProcAddress ( "glGetActiveUniformName" );
	glGetUniformBlockIndex       = (PFNGLGETUNIFORMBLOCKINDEXPROC)		getProcAddress ( "glGetUniformBlockIndex" );
	glGetActiveUniformBlockiv    = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)	getProcAddress ( "glGetActiveUniformBlockiv" );
	glGetActiveUniformBlockName  = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)	getProcAddress ( "glGetActiveUniformBlockName" );
	glUniformBlockBinding        = (PFNGLUNIFORMBLOCKBINDINGPROC)		getProcAddress ( "glUniformBlockBinding" );

											// ARB_texture_buffer_object
	glTexBufferARB               = (PFNGLTEXBUFFERARBPROC)	getProcAddress ( "glTexBufferARB" );

											// ARB_map_buffer_range
	glMapBufferRange             = (PFNGLMAPBUFFERRANGEPROC)			getProcAddress ( "glMapBufferRange" );
	glFlushMappedBufferRange     = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)	getProcAddress ( "glFlushMappedBufferRange" );

											// ARB_geometry_shader4
	glProgramParameteriARB       = (PFNGLPROGRAMPARAMETERIARBPROC)			getProcAddress ( "glProgramParameteriARB" );
	glFramebufferTextureARB      = (PFNGLFRAMEBUFFERTEXTUREARBPROC)			getProcAddress ( "glFramebufferTextureARB" );
	glFramebufferTextureLayerARB = (PFNGLFRAMEBUFFERTEXTURELAYERARBPROC)	getProcAddress ( "glFramebufferTextureLayerARB" );
	glFramebufferTextureFaceARB  = (PFNGLFRAMEBUFFERTEXTUREFACEARBPROC)		getProcAddress ( "glFramebufferTextureFaceARB" );

											// ARB_draw_instanced
	glDrawArraysInstancedARB     = (PFNGLDRAWARRAYSINSTANCEDARBPROC)		getProcAddress ( "glDrawArraysInstancedARB" );
	glDrawElementsInstancedARB   = (PFNGLDRAWELEMENTSINSTANCEDARBPROC)		getProcAddress ( "glDrawElementsInstancedARB" );

											// ARB_draw_buffers
	glDrawBuffersARB      = (PFNGLDRAWBUFFERSARBPROC)		getProcAddress ( "glDrawBuffersARB" );
												
											// ARB_multisample
	glSampleCoverageARB   = (PFNGLSAMPLECOVERAGEARBPROC)	getProcAddress ( "glSampleCoverageARB" );

											// EXT_shader_image_load_store
	glBindImageTextureEXT = (PFNGLBINDIMAGETEXTUREEXTPROC)	getProcAddress ( "glBindImageTextureEXT" );
	glMemoryBarrierEXT    = (PFNGLMEMORYBARRIEREXTPROC)		getProcAddress ( "glMemoryBarrierEXT" );

											// ARB_robustness
	glGetGraphicsResetStatusARB = (PFNGLGETGRAPHICSRESETSTATUSARBPROC)		getProcAddress ( "glGetGraphicsResetStatusARB" );
	glGetnMapdvARB              = (PFNGLGETNMAPDVARBPROC)					getProcAddress ( "glGetnMapdvARB" );
	glGetnMapfvARB              = (PFNGLGETNMAPFVARBPROC)					getProcAddress ( "glGetnMapfvARB" );
	glGetnMapivARB              = (PFNGLGETNMAPIVARBPROC)					getProcAddress ( "glGetnMapivARB" );
	glGetnPixelMapfvARB         = (PFNGLGETNPIXELMAPFVARBPROC)				getProcAddress ( "glGetnPixelMapfvARB" );
	glGetnPixelMapuivARB        = (PFNGLGETNPIXELMAPUIVARBPROC)				getProcAddress ( "glGetnPixelMapuivARB" );
	glGetnPixelMapusvARB        = (PFNGLGETNPIXELMAPUSVARBPROC)				getProcAddress ( "glGetnPixelMapusvARB" );
	glGetnPolygonStippleARB     = (PFNGLGETNPOLYGONSTIPPLEARBPROC)			getProcAddress ( "glGetnPolygonStippleARB" );
	glGetnColorTableARB         = (PFNGLGETNCOLORTABLEARBPROC)				getProcAddress ( "glGetnColorTableARB" );
	glGetnConvolutionFilterARB  = (PFNGLGETNCONVOLUTIONFILTERARBPROC)		getProcAddress ( "glGetnConvolutionFilterARB" );
	glGetnSeparableFilterARB    = (PFNGLGETNSEPARABLEFILTERARBPROC)			getProcAddress ( "glGetnSeparableFilterARB" );
	glGetnHistogramARB          = (PFNGLGETNHISTOGRAMARBPROC)				getProcAddress ( "glGetnHistogramARB" );
	glGetnMinmaxARB             = (PFNGLGETNMINMAXARBPROC)					getProcAddress ( "glGetnMinmaxARB" );
	glGetnTexImageARB           = (PFNGLGETNTEXIMAGEARBPROC)				getProcAddress ( "glGetnTexImageARB" );
	glReadnPixelsARB            = (PFNGLREADNPIXELSARBPROC)					getProcAddress ( "glReadnPixelsARB" );
	glGetnCompressedTexImageARB = (PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC)		getProcAddress ( "glGetnCompressedTexImageARB" );
	glGetnUniformfvARB          = (PFNGLGETNUNIFORMFVARBPROC)				getProcAddress ( "glGetnUniformfvARB" );
	glGetnUniformivARB          = (PFNGLGETNUNIFORMIVARBPROC)				getProcAddress ( "glGetnUniformivARB" );
	glGetnUniformuivARB         = (PFNGLGETNUNIFORMUIVARBPROC)				getProcAddress ( "glGetnUniformuivARB" );
	glGetnUniformdvARB          = (PFNGLGETNUNIFORMDVARBPROC)				getProcAddress ( "glGetnUniformdvARB" );

											// ARB_debug_output
	glDebugMessageControlARB   = (PFNGLDEBUGMESSAGECONTROLARBPROC)			getProcAddress ( "glDebugMessageControlARB" );
	glDebugMessageInsertARB    = (PFNGLDEBUGMESSAGEINSERTARBPROC)			getProcAddress ( "glDebugMessageInsertARB" );
	glDebugMessageCallbackARB  = (PFNGLDEBUGMESSAGECALLBACKARBPROC)			getProcAddress ( "glDebugMessageCallbackARB" );
	glGetDebugMessageLogARB    = (PFNGLGETDEBUGMESSAGELOGARBPROC)			getProcAddress ( "glGetDebugMessageLogARB" );
											
											// ARB_cl_event
	glCreateSyncFromCLeventARB = (PFNGLCREATESYNCFROMCLEVENTARBPROC)		getProcAddress ( "glCreateSyncFromCLeventARB" );

											// ARB_viewport_array
	glViewportArrayv           = (PFNGLVIEWPORTARRAYVPROC)		getProcAddress ( "glViewportArrayv" );
	glViewportIndexedf         = (PFNGLVIEWPORTINDEXEDFPROC)	getProcAddress ( "glViewportIndexedf" );
	glViewportIndexedfv        = (PFNGLVIEWPORTINDEXEDFVPROC)	getProcAddress ( "glViewportIndexedfv" );
	glScissorArrayv            = (PFNGLSCISSORARRAYVPROC)		getProcAddress ( "glScissorArrayv" );
	glScissorIndexed           = (PFNGLSCISSORINDEXEDPROC)		getProcAddress ( "glScissorIndexed" );
	glScissorIndexedv          = (PFNGLSCISSORINDEXEDVPROC)		getProcAddress ( "glScissorIndexedv" );
	glDepthRangeArrayv         = (PFNGLDEPTHRANGEARRAYVPROC)	getProcAddress ( "glDepthRangeArrayv" );
	glDepthRangeIndexed        = (PFNGLDEPTHRANGEINDEXEDPROC)	getProcAddress ( "glDepthRangeIndexed" );
	glGetFloati_v              = (PFNGLGETFLOATI_VPROC)			getProcAddress ( "glGetFloati_v" );
	glGetDoublei_v             = (PFNGLGETDOUBLEI_VPROC)		getProcAddress ( "glGetDoublei_v" );

											// EXT_draw_buffers2
	glColorMaskIndexedEXT   = (PFNGLCOLORMASKINDEXEDEXTPROC)	getProcAddress ( "glColorMaskIndexedEXT" );
	glGetBooleanIndexedvEXT = (PFNGLGETBOOLEANINDEXEDVEXTPROC)	getProcAddress ( "glGetBooleanIndexedvEXT" );
	glGetIntegerIndexedvEXT = (PFNGLGETINTEGERINDEXEDVEXTPROC)	getProcAddress ( "glGetIntegerIndexedvEXT" );
	glEnableIndexedEXT      = (PFNGLENABLEINDEXEDEXTPROC)		getProcAddress ( "glEnableIndexedEXT" );
	glDisableIndexedEXT     = (PFNGLDISABLEINDEXEDEXTPROC)		getProcAddress ( "glDisableIndexedEXT" );
	glIsEnabledIndexedEXT   = (PFNGLISENABLEDINDEXEDEXTPROC)	getProcAddress ( "glIsEnabledIndexedEXT" );

#ifdef  _WIN32
    initWin32Extensions ();
#else
    initLinuxExtensions ();
#endif

    initialized = true;
}

void    printfInfo ()               // print info about card, driver, version & etc
{
    const char * vendor    = (const char *)glGetString ( GL_VENDOR   );
    const char * renderer  = (const char *)glGetString ( GL_RENDERER );
    const char * version   = (const char *)glGetString ( GL_VERSION  );

    printf ( "Graphics card and driver information:\n" );
    printf ( "Vendor:   %s\nRenderer: %s\nVersion:  %s\n", vendor, renderer, version );

    if ( isExtensionSupported ( "GL_ARB_multitexture" ) )
    {
        int maxTextureUnits;

        glGetIntegerv ( GL_MAX_TEXTURE_UNITS_ARB,    &maxTextureUnits );

        printf ( "ARB_multitexture supported.\nMax texture units %d.\n", maxTextureUnits );


    }
    if ( isExtensionSupported ( "GL_NV_register_combiners" ) )
    {
        int maxCombiners;

        glGetIntegerv ( GL_MAX_GENERAL_COMBINERS_NV, &maxCombiners    );

        printf ( "NV_register_combiners supported.\nMax general combiners %d.\n", maxCombiners );
    }

    if ( isExtensionSupported ( "GL_ARB_vertex_buffer_object" ) )
        printf ( "VBO supported.\n" );

    if ( isExtensionSupported ( "GL_NV_occlusion_query" ) )
        printf ( "NV_occlusion_query extension supported.\n" );

    if ( isExtensionSupported ( "GL_SGIS_generate_mipmap" ) )
        printf ( "GL_SGIS_generate_mipmap extension supported.\n" );

    if ( isExtensionSupported ( "GL_ARB_vertex_program" ) )
        printf ( "GL_ARB_vertex_program extension supported.\n" );
}

