#pragma once

#include "def.h"

typedef struct
{
    const char* app_name; // also used as window title;
    struct 
    {
        Vector2 dim;
        bool resizable;
    } window;
    Vector2 viewport;
} AppBuilder;

extern void InitializeApp(AppBuilder* builder);

extern void StartApp();
extern void CloseApp();
extern void ForceCloseApp();