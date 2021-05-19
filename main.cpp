#include <iostream>
#include <cstdlib>
#include <ctime>
#include "user.hpp"
#include "plane.hpp"

int main()
{
    srand(time(NULL));
    Game game(4, 2, 1);
    while (game.forward())
    {

    }
    return 0;
}
