#pragma once
#include "GameComponent.h"

using namespace std;

enum Direction
{
    Left,
    Right,
    Up,
    Down,
};
//Declare array of matching strings in order to print direction
static const char* enum_str[] =
{ "Left", "Right", "Up", "Down" };

class DrawableGameComponent :
    public GameComponent
{
public:
    Direction direction = Right;
    DrawableGameComponent(int x, int y) {};
    const int SCREEN_HEIGHT = 80;
    const int SCREEN_WIDTH = 20;
    void Update();
private:
    void ChangeDirection();
    void Draw();
    int x = 0;
    int y = 0;
};

