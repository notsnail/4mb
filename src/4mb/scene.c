#include "scene.h"

#include "app.h"

// static variables
static Scene* scenes[FOURMB_MAX_SCENES];
static int current_scene = 0;

// functions
void RegisterScene(i32 index, Scene* scene)
{
    scenes[index] = scene;
    if (index == current_scene) InitScene();
}

void BindScene(i32 index)
{
    UnloadScene();
    current_scene = index;

    if (index < 0 || index >= FOURMB_MAX_SCENES)
    {
        ForceCloseApp(0);
    }

    InitScene();
}

// backend
void InitScene()
{
    scenes[current_scene]->init();
    scenes[current_scene]->initialized = true;
}

void UnloadScene()
{
    scenes[current_scene]->unload();
    scenes[current_scene]->initialized = false;
}

void UpdateScene(f32 delta)
{
    scenes[current_scene]->update(delta);
}

void DrawScene()
{
    scenes[current_scene]->draw();
}
