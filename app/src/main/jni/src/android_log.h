//
// Created by Administrator on 2017/1/9 0009.
//

#ifndef ANDROIDTST2_ANDROID_LOG_H
#define ANDROIDTST2_ANDROID_LOG_H

#include <android/log.h>
#define DEBUG 1

#define LOG_TAG "VRSDK"
#define ALOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#if DEBUG
#define ALOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#else
#define ALOGV(...)
#endif


#endif //ANDROIDTST2_ANDROID_LOG_H
