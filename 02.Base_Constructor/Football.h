#pragma once
#include "Ball.h"

class Football : public Ball
{
    // using Ball::Ball;  // Not work until now
    int numy;

public:
    Football();
    Football(int y);
    ~Football();
};