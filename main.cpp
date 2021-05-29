#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"
#include "user.hpp"
#include "plane.hpp"

int main()
{
    int game_size, x_player, o_player;
    srand(time(NULL));
    std::cout << "Enter game size, X player type and O player type: " << std::endl;
    std::cin >> game_size >> x_player >> o_player;
    Game game(game_size, x_player, o_player);
    while (game.forward())
    {
        game.save("file.txt");
        game.load("file.txt");
    }
    return 0;
}
