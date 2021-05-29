#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"
#include "user.hpp"
#include "plane.hpp"

int main()
{
    srand(time(NULL));
    int size = 4;
    std::cout << "Size of arena: ";
    std::cin >> size;
    Game game(size, 1, 2);
    while (game.forward())
    {
        game.save("file.txt");
        game.load("file.txt");
    }
    return 0;
}
