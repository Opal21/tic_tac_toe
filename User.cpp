#include <iostream>
#include "user.hpp"

Player::Player(User player_color)
{

}

Move Player::pass_control(Plane plane) const
{
    return Move(0, 0, 0, 0);
}

char Player::color() const
{
    return User::color();
}

Bot::Bot(char player_color)
{

}

Move Bot::pass_control(const Plane &plane) const
{
    return User::pass_control(plane);
}

char Bot::color() const
{
    return User::color();
}

Game::Game(int size, int x_player_mode, int o_player_mode)
{

}

Game::~Game() = default;

bool Game::finished() const
{
    return false;
}

Plane Game::last_plane() const
{
    return Plane(this->plane.size());
}

char Game::last_color() const
{
    return this->l_color;
}

void Game::forward()
{

}
