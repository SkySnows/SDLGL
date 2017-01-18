#include "main.h"
#include <VRGLES/SDL_GLES.h>
#include <iostream>
#include "SDL_events.h"
using namespace std;

SDL_Window * mainwindow;
SDL_GLContext maincontext;
static SDL_GLES* render = NULL;
int main(int argc, char* argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        return 1;
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    SetupPixelFormat();
    render = new SDL_GLES();
    Init();
    MainLoop();
    return 0;
}
void Init(){

    SDL_DisplayMode mode;
    SDL_GetDesktopDisplayMode(0, &mode);
    mainwindow = SDL_CreateWindow("VRSDK", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);


    SDL_SetWindowFullscreen(mainwindow, SDL_TRUE);

    maincontext = SDL_GL_CreateContext(mainwindow);

    glClear(GL_COLOR_BUFFER_BIT);

    render->createGLScreen(512,512);

    SDL_GL_SetSwapInterval(1);
}

void MainLoop(){
 bool done = false;
    SDL_Event event;
    while( !done){
        while( SDL_PollEvent(&event)){
            switch ( event.type ){
                case SDL_QUIT :
                case SDL_WINDOWEVENT_CLOSE :
                    done = true;
                    Quit(0);
                    break;
                case SDL_KEYDOWN :
                     HandleKeyPressEvent(&event.key.keysym);
                     break;
                case SDL_WINDOWEVENT_SIZE_CHANGED:
                    render->ChangeGLScreen(512,512);
                    break;
                default:
                    break;
            }
        }
        render->DrawGLScreen();
        SDL_GL_SwapWindow(mainwindow);
        SDL_Delay(10);
    }
}
void SetupPixelFormat(void)
{
}
void Quit(int ret_val){
   SDL_Quit();
   exit(ret_val);
}
void HandleKeyPressEvent(SDL_Keysym* keysym){
     switch(keysym->sym){
        case SDLK_AC_BACK://android退出按钮的监听
              Quit(0);
              break;
     }
}