#include <stdio.h>
#include <SDL2/SDL.h>

#include "4mb/app.h"

int main(int argc, char* argv[])
{
    // create standard AppBuilder
    AppBuilder app_builder = {
        .app_name = "4mb test",
        .window = {
            .x = 640,
            .y = 480
        }
    };

    CreateApp(&app_builder);
    StartApp();
    CloseApp();
}