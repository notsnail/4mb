#include "events.h"

#include <SDL2/SDL.h>
#include "def.h"

static bool request_exit = false;

void PollEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT: RequestExit(); break;
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