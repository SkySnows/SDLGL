//
// Created by Administrator on 2017/1/10 0010.
//
#include "VRGLES/SDL_GLES.h"
#include "android_log.h"
#include <SDL_opengles2.h>
#include <GLES2/gl2.h>
#include "VRGLES/Materials/ShaderUtil.h"
static const char VERTEX_SHADER[] =
        "attribute vec4 vPosition;\n"
                "void main() {\n"
                "  gl_Position = vPosition;\n"
                "}\n";

static const char FRAGMENT_SHADER[] =
        "precision mediump float;\n"
                "void main() {\n"
                "  gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0);\n"
                "}\n";
const  GLfloat mVdata[] = {-0.5f, 0.5f,0,//0
                           -0.5f, -0.5f,0,//1
                           0.5f, -0.5f,0 ,//2
                           0.5f, 0.5f,0};//3
const GLint mIdata[] = {0,1,2,2,3,0};//后面
GLuint mVB;
GLuint mIB;
int icount = 6;
GLuint  mProgram;
//    const EGLContext  mEglContext;
GLuint mPostionHandle;


void SDL_GLES::createGLScreen(int width, int height){
    mProgram = createProgram(VERTEX_SHADER, FRAGMENT_SHADER);
    mPostionHandle = glGetAttribLocation(mProgram,"vPosition");

    glGenBuffers(1,&mVB);
    glBindBuffer(GL_ARRAY_BUFFER,mVB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(mVdata),&mVdata,GL_STATIC_DRAW);

    glGenBuffers(1,&mIB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,mIB);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mIdata),&mIdata,GL_STATIC_DRAW);
//    glViewport(0, 0, 500, 500);

    glBindBuffer(GL_ARRAY_BUFFER,0);

}

void SDL_GLES::ChangeGLScreen(int width, int height){

}

void SDL_GLES::DrawGLScreen(){
    glClearColor(0.5,0.5,0.5,1);
    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    //ALOGE("渲染");
    glUseProgram(mProgram);

    glBindBuffer(GL_ARRAY_BUFFER,mVB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,mIB);

    glVertexAttribPointer(mPostionHandle, 3, GL_FLOAT, GL_FALSE, 3*4, NULL);
    glEnableVertexAttribArray(mPostionHandle);


    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);

    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}
