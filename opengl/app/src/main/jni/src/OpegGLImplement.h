#ifndef __OPENGL_IMPLEMENT_H__
#define __OPENGL_IMPLEMENT_H__
#include "Config.h"
#ifdef _WIN32
#include "SDL_opengl.h"
#else
#include "SDL_opengles2.h"
#include "freeglut/freeglut.h"
#endif
#include "SDL.h"
#include <stdio.h>
#include <string>
#include <fstream>


class OpenGlImplement
{
#ifdef _WIN32
	PFNGLCREATEPROGRAMPROC glCreateProgram;
	PFNGLATTACHSHADERPROC glAttachShader;
	PFNGLLINKPROGRAMPROC glLinkProgram;
	PFNGLUSEPROGRAMPROC glUseProgram;
	PFNGLCREATESHADERPROC glCreateShader;
	PFNGLSHADERSOURCEPROC glShaderSource;
	PFNGLCOMPILESHADERPROC glCompileShader;
	PFNGLBINDBUFFERPROC glBindBuffer;
	PFNGLGENBUFFERSPROC glGenBuffers;
	PFNGLBUFFERDATAPROC glBufferData;
	PFNGLDELETEPROGRAMPROC glDeleteProgram;
	PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
	PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
	PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
	PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
	PFNGLGETPROGRAMIVPROC glGetProgramiv;
	PFNGLGETSHADERIVPROC glGetShaderiv;
	PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
	PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
	PFNGLISSHADERPROC glIsShader;
	PFNGLISPROGRAMPROC glIsProgram;
	PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
	PFNGLACTIVETEXTUREPROC glActiveTexture;
	PFNGLUNIFORM1IPROC glUniform1i;
#endif
	SDL_Window *window;
	#ifdef _WIN32
	std::string readFile(const char *filePath);
	#endif
public:
	OpenGlImplement();
	~OpenGlImplement();

	void setSDLWindow(SDL_Window *window);
	void InitGL();
	void InitShaders();
	void InitBuffers(GLuint* vertexBufferObject, GLuint* indexBufferObject, GLuint* textureBufferObject, GLfloat* vexterPositions, GLuint vertexDataLen, GLuint* indexData, GLuint indexDataLen, GLfloat* textureData, GLuint textureDataLen);
	void QuitShaders();
	void Draw(GLuint* vertexBufferObject, GLuint* indexBufferObject, GLuint* textureBufferObject, GLuint textureObject, GLfloat translate_x, GLfloat translate_y, GLfloat translate_z, GLfloat rotate_x, GLfloat rotate_y, GLfloat rotate_z, GLfloat scale_x, GLfloat scale_y, GLfloat scale_z, GLuint size);
	void DrawStart();
	void DrawEnd();
	
	GLfloat ConvertCOORDf(GLfloat coord);
	GLfloat ConvertCOORDInvf(GLfloat coord);
	GLuint LoadTexture(SDL_Surface * surface, GLuint x, GLuint y, GLuint w, GLuint h);

	GLuint shaderProgram;	
	GLint vertexPositionAttribute;
	GLint vertexTextureCoordAttribute;
	GLint samplerUniform;

};
#endif