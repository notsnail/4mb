#pragma once

#include "def.h"

// defines
#define FOURMB_MAX_SCENES 8

// types
typedef int (*_SceneInitFunc)(); // returns nonzero on error
typedef void (*_SceneUpdateFunc)(f32 delta_time);
typedef void (*_SceneGenericFunc)();

// structures
typedef struct
{
    _SceneInitFunc init;
    _SceneGenericFunc unload;
    _SceneUpdateFunc update;
    _SceneGenericFunc draw;

    bool initialized;
} Scene;


// functions
extern void RegisterScene(i32 index, Scene* scene);
extern void BindScene(i32 index);

extern void InitScene();
extern void UnloadScene();
extern void UpdateScene(f32 delta);
extern void DrawScene();