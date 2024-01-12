#pragma once
#include <raylib.h>
#include <vector>
#include <iostream>
#include <string>
#include "mainmenu.h"


#define screenWidth 500
#define screenHeight 600

class Player {
public:

    Rectangle rect;
    float velocity = 250.0f;
    int score = 0;
    float w = 75.0f;
    float h = 10.0f;

};

class Ball {

public:
    Vector2 pos;
    Vector2 acceleration{ 1.0f, 1.0f };
    float velocity;
    float radius = 5.0f;

};

class Brick {
public:
    Rectangle rect;
    Color color;
    float w = 50.0f;
    float h = 20.0f;
};


class Map {
   
    screens sc;
    std::vector<Brick> bricks;
    Player player;
    Ball ball;
    Brick aBrick;
    std::string sscore;

    void UpdateGame();

public:

    void setScreen(screens src);
    screens getScreen();
    Map();
    void makeBricks(int ,int );
    void drawMap();
    
};