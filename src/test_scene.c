#include "test_scene.h"

#include <stdio.h>

#include "4mb/events.h"

static int Init()
{
    printf("init function called\n");
    return 0;
}

static void Unload()
{
    printf("unload function called\n");
}

static void Update(f32 delta)
{
    // printf("delta: %f\n", delta);
    if (IsKeyDown(KEY_A))
    {
        printf("key a pressed.\n");
    }

}

static void Draw()
{

}

Scene TestScene = {
    .init = Init,
    .unload = Unload,
    .update = Update,
    .draw = Draw
};