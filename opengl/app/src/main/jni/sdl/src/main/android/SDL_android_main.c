/*
    SDL_android_main.c, placed in the public domain by Sam Lantinga  3/13/14
*/
#include "../../SDL_internal.h"

#ifdef __ANDROID__

/* Include the SDL main definition header */
#include "SDL_main.h"

/*******************************************************************************
                 Functions called by JNI
*******************************************************************************/
#include <jni.h>

/* Called before SDL_main() to initialize JNI bindings in SDL library */
extern void SDL_Android_Init(JNIEnv* env, jclass cls);

/* Start up the SDL app */
void Java_org_libsdl_app_SDLActivity_nativeInit(JNIEnv* env, jclass cls, jobject obj)
{
    /* This interface could expand with ABI negotiation, calbacks, etc. */
    SDL_Android_Init(env, cls);

    SDL_SetMainReady();

    /* Run the application code! */
    int status;
    char *argv[2];
    argv[0] = SDL_strdup("SDL_app");
    argv[1] = NULL;
    status = SDL_main(1, argv);
	
	SDL_Log("Hola \n");

    /* Do not issue an exit or the whole application will terminate instead of just the SDL thread */
    /* exit(status); */
}

    void Java_org_libsdl_app_SDLActivity_nativeLowMemory(JNIEnv* env, jclass cls, jobject obj){}
    void Java_org_libsdl_app_SDLActivity_nativeQuit(JNIEnv* env, jclass cls, jobject obj){}
    void Java_org_libsdl_app_SDLActivity_nativePause(JNIEnv* env, jclass cls, jobject obj){}
    void Java_org_libsdl_app_SDLActivity_nativeResume(JNIEnv* env, jclass cls, jobject obj){}
    void Java_org_libsdl_app_SDLActivity_onNativeResize(JNIEnv* env, jclass cls, jobject obj, jint x, jint y, jint format){}
    jint Java_org_libsdl_app_SDLActivity_onNativePadDown(JNIEnv* env, jclass cls, jobject obj, jint device_id, jint keycode){}
    jint Java_org_libsdl_app_SDLActivity_onNativePadUp(JNIEnv* env, jclass cls, jobject obj, jint device_id, jint keycode){}
    void Java_org_libsdl_app_SDLActivity_onNativeJoy(JNIEnv* env, jclass cls, jobject obj, jint device_id, jint axis, jfloat value){}
    void Java_org_libsdl_app_SDLActivity_onNativeHat(JNIEnv* env, jclass cls, jobject obj, jint device_id, jint hat_id, jint x, jint y){}
    void Java_org_libsdl_app_SDLActivity_onNativeKeyDown(JNIEnv* env, jclass cls, jobject obj, jint keycode){}
    void Java_org_libsdl_app_SDLActivity_onNativeKeyUp(JNIEnv* env, jclass cls, jobject obj, jint keycode){}
    void Java_org_libsdl_app_SDLActivity_onNativeKeyboardFocusLost(JNIEnv* env, jclass cls, jobject obj){}
    void Java_org_libsdl_app_SDLActivity_onNativeTouch(JNIEnv* env, jclass cls, jobject obj, jint touchDevId, jint pointerFingerId, jint action, jfloat x, jfloat y, jfloat p){}
    void Java_org_libsdl_app_SDLActivity_onNativeSurfaceChanged(JNIEnv* env, jclass cls, jobject obj){}
    void Java_org_libsdl_app_SDLActivity_onNativeSurfaceDestroyed(JNIEnv* env, jclass cls, jobject obj){}
    void Java_org_libsdl_app_SDLActivity_nativeFlipBuffers(JNIEnv* env, jclass cls, jobject obj){}
    jint Java_org_libsdl_app_SDLActivity_nativeAddJoystick(JNIEnv* env, jclass cls, jobject obj, jint device_id, jstring name, jint is_accelerometer, jint nbuttons, jint naxes, jint nhats, jint nballs){}
    jint Java_org_libsdl_app_SDLActivity_nativeRemoveJoystick(JNIEnv* env, jclass cls, jobject obj, jint device_id){}

#endif /* __ANDROID__ */

/* vi: set ts=4 sw=4 expandtab: */
