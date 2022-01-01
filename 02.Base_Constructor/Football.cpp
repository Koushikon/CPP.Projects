#include "Football.h"

Football::Football() : numy{0}
{
    cout << "Football cons... " << endl;
}
Football::Football(int y) : numy{y * 2}
{
    cout << "Football 1-args cons... " << numy << endl;
}
Football::~Football()
{
    cout << "Football des... " << endl;
}