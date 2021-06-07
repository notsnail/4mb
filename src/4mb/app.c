#include "app.h"

#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "events.h"

static SDL_Window* window = NULL;

void CreateApp(AppBuilder* builder)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(
        builder->app_name,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        builder->window.x,
        builder->window.y,
        SDL_WINDOW_SHOWN
    );

    if (window == NULL)
    {
        printf("window: failed to initialize.\n");
        exit(-1);
    }
}

void CloseApp()
{
    SDL_Quit();
}

void StartApp()
{
    while (!HasExitBeenRequested())
    {
        PollEvents();
    }
}