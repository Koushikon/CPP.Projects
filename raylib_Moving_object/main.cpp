#include "raylib.h"

int main(void)
{
    const int screenWidth{1200};
    const int screenHeight{600};

    InitWindow(screenWidth, screenHeight, "✔ basic window");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    int circle_x{400};
    int circle_y{225};
    int circle_radius{100};

    int rect_x{50};
    int rect_y{25};
    int rect_width{150};
    int rect_height{100};

    bool circle_switch{false};
    bool rect_switch{false};

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(WHITE);

        DrawText("W - for Up\nS - for Down,\nA - for Left,\nD - for Right,\nSpace - for Bigger and Smaller\n", 190, 200, 20, LIGHTGRAY);

        DrawCircle(circle_x, circle_y, circle_radius, RED);

        DrawRectangle(rect_x, rect_y, rect_width, rect_height, GREEN);

        // Going to right of the screen
        if (IsKeyDown(KEY_D))
        {
            rect_x += 10;
        }

        // Going to left of the screen
        if (IsKeyDown(KEY_A))
        {
            rect_x -= 10;
        }

        // Going to left of the screen
        if (IsKeyDown(KEY_S))
        {
            rect_y += 10;
        }

        // Going to left of the screen
        if (IsKeyDown(KEY_W))
        {
            rect_y -= 10;
        }

        if (IsKeyDown(KEY_SPACE))
        {
            if (rect_switch)
            {
                rect_width -= 10;
                rect_height -= 10;
            }
            else
            {
                rect_width += 10;
                rect_height += 10;
            }
        }

        if (rect_width >= 300)
            rect_switch = true;
        else if (rect_width <= 150)
            rect_switch = false;

        // Circle gets bigger and smaller when program is running
        (circle_switch) ? circle_radius -= 10 : circle_radius += 10;
        if (circle_radius >= 200)
            circle_switch = true;
        else if (circle_radius <= 0)
            circle_switch = false;

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}