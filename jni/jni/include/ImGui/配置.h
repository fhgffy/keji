#ifndef NATIVESURFACE_DRAW_H
#define NATIVESURFACE_DRAW_H

#include <iostream>
#include <thread>
#include <chrono>
#include <EGL/egl.h>
#include <GLES/gl.h>
#include <dlfcn.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstdio>
#include <cstring>
#include <cerrno>
#include <android/native_window.h>
#include "native_surface.h"
#include "imgui.h"
#include "OPPOFont.h"
#include "imgui_internal.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_android.h"
#include "timer.h"
typedef char UTF8;
using namespace std;
using namespace std::chrono_literals;
struct FVector2D
{
    float X;
    float Y;

      FVector2D()
    {
        this->X = 0;
        this->Y = 0;
    }

    FVector2D(float x, float y)
    {
        this->X = x;
        this->Y = y;
    }
};
struct FVector
{
    float X;
    float Y;
    float Z;

      FVector()
    {
        this->X = 0;
        this->Y = 0;
        this->Z = 0;
    }

    FVector(float x, float y, float z)
    {
        this->X = x;
        this->Y = y;
        this->Z = z;
    }

};
struct Screen {
    float ScreenX;
    float ScreenY;
};
#include <Func.h>
extern void *handle;
extern EGLDisplay display;
extern EGLConfig config;
extern EGLSurface surface;
extern NativeWindowType native_window;
extern EGLContext context;
extern int FPS;
extern timer FPS限制;
extern float FPF显示;
extern Screen full_screen;
extern int Orientation;
extern uintptr_t Gmin;
extern uintptr_t Gmin;
extern int screen_x, screen_y;
extern float 触摸位置X, 触摸位置Y;
extern int init_screen_x, init_screen_y;
extern bool g_Initialized;

string exec(string command);
int init_egl(int _screen_x,int _screen_y, bool log = false);
void screen_config();
void shutdown();
void tick();
void ImGui_init();
void DrawPlayer();
void AimBotAuto(ImDrawList *Draw);
void Getxfctouch();
void Getxfctouch2();
void *AimCalcu();
int DrawInt();
#endif
