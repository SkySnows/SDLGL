# ORGE_LQ
## 目前这个案例只是在android端使用sdl+OpenGLES实现的一个小demo，后面会陆续支持ios，window，linus。
### 1.android编译：
###   在android studio中Terminal中cd到app/src/main目录，使用命令行ndk-build，编译出来so库（在lib目录下），将之拷贝到jniLibs目录下，然后在android手机上运行即可。
### 这个demo目前借助SDL来抽出来了OpenGL的三个函数，这样方便后面的扩展。
