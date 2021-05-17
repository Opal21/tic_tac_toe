#include <iostream>
#include "user.hpp"

char User::get_player_sign() const
{
    return this->player_sign;
}

Player::Player(char player_sign)
{
    this->player_sign = player_sign;
}

Move Player::decide_move(const Plane& plane) const 
{
    char col, row;
    std::cout << plane << std::endl;
    std::cout << "Enter the coordinates: " << std::endl;
    std::cin >> col >> row;
    return Move(col, row, this->get_player_sign());
}

Bot::Bot(char player_sign)
{
    this->player_sign = player_sign;
}

Move Bot::decide_move(const Plane &plane) const
{
    char col, row;
    return Move(col,row, this->get_player_sign());
}

Game::Game(int size, int x_player_mode, int o_player_mode) : plane(size), l_sign(' ')
{
    if (x_player_mode)
    {
        this->players[0] = new Bot('X');
    }
    else
    {
        this->players[0] = new Player('X');
    }
    if (o_player_mode)
    {
        this->players[1] = new Bot('O');
    }
    else
    {
        this->players[1] = new Player('O');
    }
}

Game::~Game() = default;

bool Game::is_finished() const
{
    if (plane.who_won() != ' ' || plane.is_full()) {return true;}
    else {return false;}
}

Plane Game::last_plane() const
{
    return Plane(this->plane);
}

char Game::last_sign() const
{
    return this->l_sign;
}

void Game::forward()
{

}
