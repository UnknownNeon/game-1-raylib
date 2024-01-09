#pragma once
#include <raylib.h>
#include <vector>

class Player {

public:
    Rectangle rect;
    float velocity = 250.0f;
    int score = 0;
    float w = 75.0f;
    float h = 10.0f;

   // player():velocity(250.0f),score(0), w(75), h(10){}

   

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