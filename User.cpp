#include <iostream>
#include "user.hpp"

Player::Player(char player_color)
{
    this->player_color = player_color;
}

Move Player::pass_control(Plane plane) const
{
    return Move(0, 0, 0, 0);
}

Bot::Bot(char player_color)
{
    this->player_color = player_color;
}

Move Bot::pass_control(const Plane &plane) const
{
    return Move(0,0,0,0);
}

Game::Game(int size, int x_player_mode, int o_player_mode) : plane(size)
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

Game::~Game()
{
    delete players[0];
    delete players[1];
}

bool Game::finished() const
{
    return plane.finished();
}

Plane Game::last_plane() const
{
    return Plane(this->plane);
}

char Game::last_color() const
{
    return this->l_color;
}

void Game::forward()
{

}

char User::color() const
{
    return this->player_color;
}
