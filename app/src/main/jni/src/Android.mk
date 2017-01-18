LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include

# Add your application source files here...
LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c\
    main.cpp\
    VRGLES/Object.cpp\
    VRGLES/Render.cpp\
    VRGLES/SDL_GLES.cpp\
    VRGLES/Materials/ShaderUtil.cpp\

LOCAL_SHARED_LIBRARIES := SDL2

LOCAL_LDLIBS := -lGLESv2 -llog -landroid -lEGL -lz
include $(BUILD_SHARED_LIBRARY)
