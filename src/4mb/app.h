#pragma once

#include "def.h"

typedef struct
{
    const char* app_name;
    Vector2 window;
} AppBuilder;

extern void CreateApp(AppBuilder* builder);
extern void CloseApp();

extern void StartApp();