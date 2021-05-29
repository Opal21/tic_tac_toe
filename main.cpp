#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"

int main()
{
    srand(time(nullptr));
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
