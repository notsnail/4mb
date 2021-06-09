#include "events.h"

#include <SDL2/SDL.h>
#include "def.h"

// generic vars
static bool request_exit = false;

// delta time vars
static u64 dnow;
static u64 dlast;

static d32 delta_time;

// keyboard-related vars and structs
typedef struct
{
    bool pressed, down;
} KeyStruct;

static KeyStruct keyboard_array[NUM_KEYBOARDKEY];

// recommended to be last part of initialization
void InitializeEvents()
{
    // initialize keyboard array
    for (i32 i = 0; i < NUM_KEYBOARDKEY; i++)
    {
        keyboard_array[i].down = false;
        keyboard_array[i].pressed = false;
    }

    // set up delta time stuff
    dnow = SDL_GetPerformanceCounter();
    dlast = 0;
    delta_time = 0;
}

void PollEvents()
{
    // update delta time
    dlast = dnow;
    dnow = SDL_GetPerformanceCounter();
    delta_time = (d32) ((dnow - dlast) * 1000 / (d32) SDL_GetPerformanceFrequency());

    // process events

    // ready keyboard down vars
    for (i32 i = 0; i < NUM_KEYBOARDKEY; i++)
    {
        keyboard_array[i].pressed = false;
    }


    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT: RequestExit(); break;
            case SDL_KEYDOWN:
                keyboard_array[event.key.keysym.scancode].down = true;
                keyboard_array[event.key.keysym.scancode].pressed = true;
                break;
            case SDL_KEYUP:
                keyboard_array[event.key.keysym.scancode].down = false;
                break;
        }
    }
}

void RequestExit()
{
    request_exit = true;
}

bool HasExitBeenRequested()
{
    return request_exit;
}

d32 GetDeltaTime()
{
    return delta_time;
}

bool IsKeyDown(i32 key)
{
    if (key >= NUM_KEYBOARDKEY || key < 0)
    {
        return false;
    }

    return keyboard_array[key].down;
}

bool IsKeyPressed(i32 key)
{
    if (key >= NUM_KEYBOARDKEY || key < 0)
    {
        return false;
    }
}