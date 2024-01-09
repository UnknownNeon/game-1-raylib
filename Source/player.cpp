#include "player.h"

void Map::UpdateGame()
{
    float frameTime = GetFrameTime();

    if (IsKeyDown(KEY_A)) {
        player.rect.x += player.velocity * frameTime;
    }
    if (IsKeyDown(KEY_D)) {
        player.rect.x -= player.velocity * frameTime;
    }
}

Map::Map()
{

    //Loading the player Presets
    player.rect = Rectangle{ 250.0f, 540.0f, player.w, player.h };
    player.score = 0;

    // loading the ball data
    ball.pos = Vector2{ 300, 300 };
    ball.velocity = 300.0f;

}

void Map::makeBricks(int row , int col)
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            aBrick.rect = Rectangle{
                float(40 + (i * 55)),
                float(50 + (j * 26)),
                aBrick.w,
                aBrick.h
            };
            aBrick.color = RED;
            this->bricks.push_back(aBrick);
        }
    }
}

void Map::drawMap()
{
    UpdateGame();
    BeginDrawing();
    ClearBackground(BLUE);

    for (int i = 0; i < bricks.size(); i++) {
        this->aBrick = bricks[i];
        DrawRectangle(
            this->aBrick.rect.x,
            this->aBrick.rect.y,
            this->aBrick.rect.width,
            this->aBrick.rect.height,
            this->aBrick.color
        );
    }

    DrawCircle(ball.pos.x, ball.pos.y, ball.radius, RAYWHITE);

    EndDrawing();

}
