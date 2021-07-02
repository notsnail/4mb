#include "4mb/app.h"
#include "4mb/scene.h"

#include "test_scene.h"

int main(int argc, char* argv[])
{
    // create standard AppBuilder
    AppBuilder app_builder = {
        .app_name = "4mb test",
        .window = {
            .dim = {
                .x = 640,
                .y = 480
            },
            .resizable = false
        }
    };

    InitializeApp(&app_builder);
    RegisterScene(0, &TestScene);

    StartApp();
    CloseApp();
}