#pragma once
#include "defs.h"

class Move
{
public:
    Move();
    ~Move();
    void move();
    void update();
    void turnNorth();
    void turnSouth();
    void turnWest();
    void turnEast();
    int x, y;
private:
    int dx, dy;
    int speed;
};