LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := app
LOCAL_SRC_FILES := \
	C:\Users\yara\AndroidStudioProjects\opengl\app\src\main\jni\Android.mk \
	C:\Users\yara\AndroidStudioProjects\opengl\app\src\main\jni\Application.mk \
	C:\Users\yara\AndroidStudioProjects\opengl\app\src\main\jni\jniapi.cpp \
	C:\Users\yara\AndroidStudioProjects\opengl\app\src\main\jni\renderer.cpp \

LOCAL_C_INCLUDES += C:\Users\yara\AndroidStudioProjects\opengl\app\src\main\jni
LOCAL_C_INCLUDES += C:\Users\yara\AndroidStudioProjects\opengl\app\src\debug\jni

include $(BUILD_SHARED_LIBRARY)
