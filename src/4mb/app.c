#include "app.h"

#include <SDL2/SDL.h>

#include "def.h"
#include "events.h"
#include "scene.h"
#include "video.h"

static SDL_Window* window = NULL;

void InitializeApp(AppBuilder* builder)
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

    window = SDL_CreateWindow(
        builder->app_name,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        builder->window.dim.x,
        builder->window.dim.y,
        SDL_WINDOW_SHOWN
    );

    if (window == NULL)
    {
        printf("window: failed to initialize.\n");
        ForceCloseApp(-1);
    }

    InitVideo(
        window,
        builder->window.dim.x,
        builder->window.dim.y
    );
}

void StartApp()
{
    InitializeEvents();

    while (!HasExitBeenRequested())
    {
        PollEvents();
        UpdateScene(GetDeltaTime());

        BeginDrawing();
        DrawScene();
        EndDrawing();
        
    }
}

void CloseApp()
{
    UnloadScene(); // unload bound scene

    CloseVideo();
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void ForceCloseApp(i32 code)
{
    CloseApp();
    exit(code);
}