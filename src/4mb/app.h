#pragma once

#include "def.h"

typedef struct
{
    const char* app_name;
    Vector2 window;
} AppBuilder;

extern void InitializeApp(AppBuilder* builder);

extern void StartApp();
extern void CloseApp();
extern void ForceCloseApp();