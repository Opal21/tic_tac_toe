#include <iostream>
#include <cstdlib>
#include <fstream>
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
    int col, row;
    std::cout << "Player " << this->player_sign << std::endl << plane << std::endl;
    std::cout << "Enter the coordinates: " << std::endl;
    std::cin >> col >> row;
    return Move(col, row, this->get_player_sign());
}

int Player::UserMode() const
{
    return 0;
}

Bot::Bot(char player_sign)
{
    this->player_sign = player_sign;
}

int Bot::loss(const int& min, const int& max) const
{
    return rand() % (max - min + 1) + min;
}

int Bot::UserMode() const
{
    return 1;
}

Move Bot::decide_move(const Plane &plane) const
{
    int col = -1, row = -1;
    do {
        col = this->loss(0, plane.get_size() - 1);
        row = this->loss(0, plane.get_size() - 1);
    } while (plane.get_sign_at(col, row) != ' ');
    return Move(col,row, this->get_player_sign());
}
