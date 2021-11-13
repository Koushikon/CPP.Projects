#include "raylib.h"

int main(void)
{
    const int screenWidth{800};
    const int screenHeight{600};

    InitWindow(screenWidth, screenHeight, "✔ Game window");

    unsigned short square_X{0}, square_Y{400};
    unsigned short square{50};
    unsigned short move{10};

    int circle_x{150};
    int circle_y{100};
    int circle_radius{50};

    int l_circle_X{circle_x - circle_radius};
    int r_circle_X{circle_x + circle_radius};
    int u_circle_Y{circle_y - circle_radius};
    int b_circle_Y{circle_y + circle_radius};

    int l_square_X{square_X};
    int r_square_X{square_X + square};
    int u_square_Y{square_Y};
    int b_square_Y{square_Y + square};

    bool Collision_with_X{(b_square_Y >= u_circle_Y) &&
                          (u_square_Y <= b_circle_Y) &&
                          (r_square_X >= l_circle_X) &&
                          (l_square_X <= r_circle_X)};

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    int crcl_direction1{5}, crcl_direction2{5};

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(BLACK);

        if (Collision_with_X && square < 175)
        {
            DrawText("Game Over!", 330, 295, 25, RED);
        }
        else
        {
            // Update the edges
            l_circle_X = circle_x - circle_radius;
            r_circle_X = circle_x + circle_radius;
            u_circle_Y = circle_y - circle_radius;
            b_circle_Y = circle_y + circle_radius;
            l_square_X = square_X;
            r_square_X = square_X + square;
            u_square_Y = square_Y;
            b_square_Y = square_Y + square;

            // Update collision with square
            Collision_with_X = (b_square_Y >= u_circle_Y) &&
                               (u_square_Y <= b_circle_Y) &&
                               (r_square_X >= l_circle_X) &&
                               (l_square_X <= r_circle_X);

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
        }

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}