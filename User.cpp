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

int Bot::loss(const int& min, const int& max)
{
    return rand() % (max - min + 1) + min;
}

int Bot::UserMode() const
{
    return 1;
}

Move Bot::decide_move(const Plane &plane) const
{
    std::vector<Move> possible_moves = plane.get_possible_moves(this->get_player_sign());
    Move output = possible_moves.at(loss(0, possible_moves.size() - 1));
    return output;
}
