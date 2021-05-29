#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"
#include "user.hpp"
#include "plane.hpp"

int main()
{
    srand(time(NULL));
    Game game(4, 1, 2);
    while (game.forward())
    {
        game.save("file.txt");
        game.load("file.txt");
    }
    return 0;
}
