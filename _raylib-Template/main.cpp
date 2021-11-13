#include "raylib.h"

int main(void)
{
    const int screenWidth{800};
    const int screenHeight{600};

    InitWindow(screenWidth, screenHeight, "✔ basic window");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(WHITE);

        /**
         * 
         * Code Here... 
         * 
         */


        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}