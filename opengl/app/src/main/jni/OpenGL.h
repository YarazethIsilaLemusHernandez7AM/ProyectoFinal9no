#ifndef __OPENGL_H__
#define __OPENGL_H__
#ifndef _WIN32
#include "SDL_opengles2.h"
   #define GL_SMOOTH 1
   #define GL_PERSPECTIVE_CORRECTION_HINT 1
   #define GL_PROJECTION 1
   
   void glFrustum(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f){}
   void glTranslatef(GLfloat a, GLfloat b, GLfloat c){}
   void glLoadIdentity(){}
   void glMatrixMode(GLint a){}
   void glHint(GLint a, GLint b){}
   void glShadeModel(GLint a){}
#endif
#endif