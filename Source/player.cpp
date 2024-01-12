#include "player.h"

void Map::UpdateGame()
{
    float frameTime = GetFrameTime();

    if (IsKeyDown(KEY_A)) {
        player.rect.x -= player.velocity * frameTime;
    }
    if (IsKeyDown(KEY_D)) {
        player.rect.x += player.velocity * frameTime;
    }


    if (player.rect.x > (screenWidth - player.rect.width)) {
        player.rect.x = screenWidth - player.rect.width;
    }
    if (player.rect.x < 0) {
        player.rect.x = 0;
    }
    //std::cout << "[Player.x Coordinate :]" << player.rect.x << std::endl;

    //updating ball position
    ball.pos.x = ball.pos.x + ((ball.velocity * ball.acceleration.x) * frameTime);
    ball.pos.y = ball.pos.y + ((ball.velocity * ball.acceleration.y) * frameTime);

    if (ball.pos.x > screenWidth || ball.pos.x < 10) {
        ball.acceleration.x = ball.acceleration.x * -1;
    }
    if ( ball.pos.y < 10) {
        ball.acceleration.y = ball.acceleration.y * -1;
    }
    if (ball.pos.y > screenHeight) {
        this->sc = end;
    }

    Brick brick;
    for (int i = 0; i < bricks.size(); i++) {
        brick = bricks[i];
        if (CheckCollisionCircleRec(ball.pos, ball.radius, brick.rect)) {
            ball.acceleration.y *= -1;
            bricks.erase(bricks.begin() + i);
            player.score += 1;
            break;
        }
    }

    if (CheckCollisionCircleRec(ball.pos, ball.radius, player.rect)) {
        ball.acceleration.y *= -1;
    }

     sscore = std::to_string(player.score);
}


void Map::setScreen(screens src)
{
    this->sc = src;
}

Map::Map()
{
    sscore = "Start game";

    //Loading the player Presets
    player.rect = Rectangle{ 250.0f, 540.0f, player.w, player.h };
    player.score = 0;

    // loading the ball data
    ball.pos = Vector2{ 300, 300 };
    ball.velocity = 300.0f;

}

screens Map::getScreen()
{
    return this->sc;
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

    
    DrawText(sscore.c_str(), 20, 20, 30, BLACK);
    
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
    DrawRectangle(player.rect.x, player.rect.y, player.rect.width, player.rect.height, YELLOW);
 
    EndDrawing();

}
