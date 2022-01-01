#include "Ball.h"

Ball::Ball() : numx{0}
{
    cout << "Ball cons... " << endl;
}

Ball::Ball(int x) : numx{x}
{
    cout << "Ball 1-args cons... " << numx << endl;
}
Ball::~Ball()
{
    cout << "Ball des... " << endl;
}