#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"

int main()
{
    srand(time(nullptr));
    int x_player, y_player, size = 4;
    std::cout << "Enter the size of arena: ";
    std::cin >> size;
    std::cout << "Enter player types (X, O): ";
    std::cin >> x_player >> y_player;
    Game game(size, x_player, y_player);
    while (game.forward())
    {
        game.save("file.txt");
        game.load("file.txt");
    }
    return 0;
}
