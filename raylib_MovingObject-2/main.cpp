#include "raylib.h"

int main(void)
{
    const int screenWidth{800};
    const int screenHeight{600};

    InitWindow(screenWidth, screenHeight, "✔ basic window");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    int rect_x{10};
    int rect_y{10};
    int rect_width{780};
    int rect_height{580};

    int rect_x_2{450};
    int rect_y_2{400};
    int rect_width_2{150};
    int rect_height_2{100};

    int circle_x{150};
    int circle_y{100};
    int circle_radius{50};

    int crcl_direction1{10}, crcl_direction2{10};
    int rect_direction1{10}, rect_direction2{10};

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(WHITE);

        DrawRectangle(rect_x, rect_y, rect_width, rect_height, LIGHTGRAY);

        DrawText("just For Fun", 250, 200, 20, BLACK);

        DrawRectangle(rect_x_2, rect_y_2, rect_width_2, rect_height_2, BLUE);

        DrawCircle(circle_x, circle_y, circle_radius, GREEN);

        // Rectangle Going up and down of the screen
        rect_x_2 += rect_direction1;
        if (rect_x_2 >= 650 || rect_x_2 <= 0){
            rect_direction1 = -rect_direction1;
        }

        rect_y_2 += rect_direction2;
        if (rect_y_2 >= 500|| rect_y_2 <= 0)
        {
            rect_direction2 = -rect_direction2;
        }

        // Circle Going up and down of the screen
        circle_x += crcl_direction1;
        if (circle_x >= 700 || circle_x <= 0){
            crcl_direction1 = -crcl_direction1;
        }

        circle_y += crcl_direction2;
        if (circle_y >= 500|| circle_y <= 0)
        {
            crcl_direction2 = -crcl_direction2;
        }

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}