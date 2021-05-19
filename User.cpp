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
    int col, row;
    std::cout << "Player " << this->player_sign << std::endl << plane << std::endl;
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
    int col = 0, row = 0;
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

Game::~Game()
{
    delete players[0];
    delete players[1];
}

bool Game::is_finished() const
{
    if (plane.who_won() != ' ' || plane.is_full()) {return true;}
    else {return false;}
}

Plane Game::last_plane() const
{
    return this->plane;
}

char Game::last_sign() const
{
    return this->l_sign;
}

bool Game::forward()
{
    if (!this->is_finished())
    {
        while (true)
        {
            Move move; char sign_backup = this->l_sign;
            if (this->l_sign == 'X') // if last player was X
            {
                move = this->players[1]->decide_move(this->plane); // then O moves
                this->l_sign = 'O';
            }
            else // otherwise
            {
                move = this->players[0]->decide_move(this->plane); // then X moves
                this->l_sign = 'X';
            }
            if (!this->plane.make_move(move))
            {
                std::cout << "Invalid move, try again" << std::endl;
                this->l_sign = sign_backup;
                continue;
            }
            return true;
        }
    }
    else
    {
        if (this->plane.who_won() == ' ')
        {
            std::cout << "Game ends with draw" << std::endl << this->plane;
            return false;
        }
        else
        {
            std::cout << this->plane.who_won() << " has won!" << std::endl << this->plane << std::endl;
            return false;
        }
    }
}
