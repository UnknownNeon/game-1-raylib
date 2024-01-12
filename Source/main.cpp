//The raylib library must be installed to run raylib code
#include "player.h"


    int main(void)
    {

        InitWindow(screenWidth, screenHeight, "brick breaker game");
        SetTargetFPS(60);

        Map map;
        map.makeBricks(8, 8);
        map.setScreen(title);

        while (!WindowShouldClose())    // Detect window close button or ESC key
        {
            switch (map.getScreen()) {
            case title:
            default:

                BeginDrawing();
                DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
                DrawText("PRESS ENTER or CLICK to JUMP to GAMEPLAY", 20, 120, 20, BLACK);
                DrawText("MADE IN VENUS !", 20, screenHeight - 20 , 20, BLACK);
                EndDrawing();
                // Press enter to change to GAMEPLAY screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    map.setScreen(game);

                }break;

            case game:
                //To gameplay screen
                map.drawMap();
                break;

            case end:

                BeginDrawing();
                DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
                DrawText("DEATH",screenWidth / 2, screenHeight / 2, 20, WHITE);
                DrawText("press to restart game or esc to end", 15, screenHeight - 20, 20, GREEN);
                EndDrawing();
                if ( IsGestureDetected(GESTURE_TAP))
                {
                    map.setScreen(game);

                }
                
                break;

            }

        }

        CloseWindow();

        return 0;
    }