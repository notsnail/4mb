#include "video.h"

#include <SDL2/SDL.h>
#include <stdio.h>

#include "app.h"

// static vars
static SDL_Renderer* renderer;

static SDL_Texture* render_texture;

// functions
void InitVideo(void* window_ptr, i32 w, i32 h)
{
    renderer = SDL_CreateRenderer((SDL_Window*) window_ptr, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        printf("failed to create renderer.\n");
        ForceCloseApp(-2);
    }

    render_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);
    if (render_texture == NULL)
    {
        printf("failed to create render texture.\n");
        ForceCloseApp(-3);
    }
}

void CloseVideo()
{
    SDL_DestroyTexture(render_texture);
    SDL_DestroyRenderer(renderer);
}

void BeginDrawing()
{
    SDL_SetRenderTarget(renderer, render_texture);
}

void EndDrawing()
{
    SDL_SetRenderTarget(renderer, NULL);

    // draw texture to screen
    SDL_RenderCopy(
        renderer, 
        render_texture,
        NULL,
        NULL
    );
    SDL_RenderPresent(renderer);
}

void VideoClear(Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
}