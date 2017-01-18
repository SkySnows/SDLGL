//
// Created by Administrator on 2016/11/17.
//

#ifndef VRNEWSDK_SHADERUTIL_H
#define VRNEWSDK_SHADERUTIL_H

#include <GLES2/gl2.h>
//if return true GL is occurred
extern bool checkGlError(const char* funcName);
extern GLuint createShader(GLenum shaderType , const char* src);
extern GLuint createProgram(const char* vtxString,const char* fragString);
class ShaderUtil{

};


#endif //VRNEWSDK_MATERIAL_H
