#pragma once

#include "def.h"

typedef struct
{
    u8 r, g, b, a;
} Color;

// generic functions
extern void InitVideo(void* window_ptr, i32 w, i32 h);
extern void CloseVideo();

// drawing functions
extern void BeginDrawing();
extern void EndDrawing();
extern void VideoClear(Color clear_color);