#include <iostream>
#include <cstdlib>
#include <ctime>
#include "user.hpp"
#include "plane.hpp"
#include "Game.hpp"

int main()
{
    int game_size, x_player, o_player;
    srand(time(nullptr));
    std::cout << "Enter game size, X player type and O player type: " << std::endl;
    std::cin >> game_size >> x_player >> o_player;
    Game game(game_size, x_player, o_player);
    while (game.forward())
    {

    }
    return 0;
}
