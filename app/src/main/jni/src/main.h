//
// Created by Administrator on 2017/1/9 0009.
//

#ifndef ANDROIDTST2_MAIN_H
#define ANDROIDTST2_MAIN_H

#include "SDL.h"
#include <stdio.h>
#include "VRGLES/Render.h"
#include "VRGLES/Object.h"
#include <stdbool.h>
#include <stdlib.h>
#include <SDL_opengles2.h>
#include <string.h>
#include <GLES2/gl2.h>
#include "android_log.h"
#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 512
#define SCREEN_DEPTH 16
extern int VideoFlags;
extern SDL_Surface * MainWindow;
typedef unsigned int UINT;


void Init();//初始化SDL
void MainLoop();//控制主程序循环绘制
void SetupPixelFormat(void);
void ToggleFullScreen();//屏幕操纵
void CreateMyWindow(const char * strWindowName, int width, int heigh, int VideoFlags);//创建窗口
void SetupPixelFormat();
void Quit(int ret_val);//退出SDL渲染
void HandleKeyPressEvent(SDL_Keysym* keysym );

#endif //ANDROIDTST2_MAIN_H
