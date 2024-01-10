//The raylib library must be installed to run raylib code
#include "player.h"


    int main(void)
    {

        InitWindow(screenWidth, screenHeight, "brick breaker game");
        SetTargetFPS(60);


        Map map;
        map.makeBricks(8, 8);

        while (!WindowShouldClose())    // Detect window close button or ESC key
        {
            map.drawMap();
        }

        CloseWindow();

        return 0;
    }