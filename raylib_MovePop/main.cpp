#include "raylib.h"

int main(void)
{
    const int screenWidth{800};
    const int screenHeight{600};

    InitWindow(screenWidth, screenHeight, "✔ Game window");

    unsigned short square_X{0}, square_Y{400};
    unsigned short square{50};
    unsigned short move{10}, burst{6};

    unsigned short square2_X{0}, square2_Y{400};

    int circle_x{150};
    int circle_y{100};
    int circle_radius{50};

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    int crcl_direction1{5}, crcl_direction2{5};

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawRectangle(square_X, square_Y, square, square, WHITE);
        DrawCircle(circle_x, circle_y, circle_radius, YELLOW);

        // Circle Going up and down of the screen
        circle_x += crcl_direction1;
        if (circle_x >= screenWidth - circle_radius || circle_x <= circle_radius)
        {
            crcl_direction1 = -crcl_direction1;
        }

        circle_y += crcl_direction2;
        if (circle_y >= screenHeight - circle_radius || circle_y <= circle_radius)
        {
            crcl_direction2 = -crcl_direction2;
        }

        // Square Move Grows and Boom
        if (IsKeyDown(KEY_D) && square_X < screenWidth - square)
        {
            square_X += move;
        }

        if (IsKeyDown(KEY_A) && square_X > 0)
        {
            square_X -= move;
        }

        if (IsKeyDown(KEY_S) && square_Y < screenHeight - square)
        {
            square_Y += move;
        }

        if (IsKeyDown(KEY_W) && square_Y > 0)
        {
            square_Y -= move;
        }

        // Square Boom 💥
        if (square < 175)
        {
            square2_X = square_X + 60;
            square2_Y = square_Y + 60;
            if (IsKeyDown(KEY_X))
            {
                square += burst;
                square_X -= burst / 2;
                square_Y -= burst / 2;
            }
        }
        else
        {
            square_X = square2_X;
            square_Y = square2_Y;
            square = 50;
        }

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}