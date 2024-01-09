//The raylib library must be installed to run raylib code
#include <vector>
#include <iostream>
#include "raylib.h"

void UpdateGame();
void DrawGame();
void gameStartup();

struct Ball {
    Vector2 pos;
    Vector2 acceleration{ 1.0f, 1.0f };
    float velocity;
    float radius = 5.0f;
};

struct Brick {
    Rectangle rect;
    Color color;
    float w = 50.0f;
    float h = 20.0f;
};

struct Player {
        Rectangle rect;
        float velocity = 250.0f;
        int score = 0;
        float w = 75.0f;
        float h = 10.0f;
    }; // This is the struct for the player i,e the bar


Player player;
Ball ball;

std::vector<Brick> bricks;

    int main(void)
    {
        const int screenWidth = 500;
        const int screenHeight = 600;

        InitWindow(screenWidth, screenHeight, "brick breaker game");
        SetTargetFPS(60); 

        gameStartup();

        while (!WindowShouldClose())    // Detect window close button or ESC key
        {
            // Update
            void UpdateGame();

            // Draw
            BeginDrawing();

            ClearBackground(BLUE);
            DrawGame();

            EndDrawing();
        }

        CloseWindow();        

        return 0;
    }

    void gameStartup() {
        
        //Loading the player Presets
        player.rect = Rectangle{ 250.0f, 540.0f, player.w, player.h };
        player.score = 0;

        // loading the ball data
        ball.pos = Vector2{ 300, 300 };
        ball.velocity = 300.0f;

        Brick newBrick;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                newBrick.rect = Rectangle{
                    float(40 + (i * 55)),
                    float(50 + (j * 26)),
                    newBrick.w,
                    newBrick.h
                };
                newBrick.color = RED;
                bricks.push_back(newBrick);
            }
        }
    }

    void UpdateGame() {
        float frameTime = GetFrameTime();

        if (IsKeyDown(KEY_A)) {
            player.rect.x += player.velocity * frameTime;
        }
        if (IsKeyDown(KEY_D)) {
            player.rect.x -= player.velocity * frameTime;
        }
    }

    void DrawGame() {

        Brick brick;
        for (int i = 0; i < bricks.size(); i++) {
            brick = bricks[i];
            DrawRectangle(
                brick.rect.x,
                brick.rect.y,
                brick.rect.width,
                brick.rect.height,
                brick.color
            );
        }

        DrawCircle(ball.pos.x, ball.pos.y, ball.radius, RAYWHITE);
    }