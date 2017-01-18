//
// Created by Administrator on 2017/1/10 0010.
//

#ifndef ANDROIDTST2_SDL_GLES_H
#define ANDROIDTST2_SDL_GLES_H

class SDL_GLES{
public:
    void createGLScreen(int width, int height);//创建opengl的场景
    void ChangeGLScreen(int width, int height);//窗口大小改变
    void DrawGLScreen();//绘制opengl函数
};
#endif //ANDROIDTST2_SDL_OPENGLES_H
