
#include "Game.hpp"
#include <string>
#include <fstream>
#include "lib.hpp"

#define HEADER "GAME"
#define HEADER_REV "EMAG"
#define HEADER_LENGTH 4

Game::Game(int size, int x_player_mode, int o_player_mode) : plane(size), l_sign(' ')
{
    this->players[0] = x_player_mode ? (User*) new Bot('X') : (User*) new Player('X');
    this->players[1] = o_player_mode ? (User*) new Bot('O') : (User*) new Player('O');
}

Game::~Game()
{
    delete players[0];
    delete players[1];
}

bool Game::is_finished() const
{
    if (plane.who_won() != ' ' || plane.is_full()) { return true; }
    else { return false; }
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

bool Game::save(std::string filename) const
{
    std::ofstream file(filename);
    if (!file.is_open()) { std::cout << "Unable to open savefile (saving): " << filename << std::endl; return false; }
    save_header(file, HEADER, HEADER_LENGTH);

    int mode_x = this->players[0]->UserMode();
    int mode_o = this->players[1]->UserMode();
    char last_sign = this->last_sign();
    Plane last_plane = this->last_plane();

    file.write((char*)&mode_x, sizeof(mode_x));
    file.write((char*)&mode_o, sizeof(mode_o));
    file.write((char*)&last_sign, sizeof(last_sign));
    file << last_plane;

    save_header(file, HEADER_REV, HEADER_LENGTH);
    if (!file.good()) { std::cout << "Error occured during saving of game. Aborting" << std::endl; return false; }

    file.close();
    return true;
}


bool Game::load(std::string filename) 
{
    std::ifstream file(filename);
    if (!file.is_open()) { std::cout << "Unable to open savefile (loading): " << filename << std::endl; return false; }
    assertm(check_header(file, HEADER, HEADER_LENGTH), "Failed while loading game header.");

    int mode_x = 0, mode_o = 0;
    char last_sign = 0;
    Plane tmp(1);

    file.read((char*)&mode_x, sizeof(mode_x));
    file.read((char*)&mode_o, sizeof(mode_o));
    file.read((char*)&last_sign, sizeof(last_sign));
    file >> tmp;

    assertm(check_header(file, HEADER_REV, HEADER_LENGTH), "Failed while loading game header.");
    if (!file.good()) { std::cout << "Error occured during loading of game. Aborting" << std::endl; return false; }

    if (this->players[0] != NULL)    {   delete this->players[0];    }
    if (this->players[1] != NULL) { delete this->players[1]; }
    this->players[0] = mode_x ? (User*) new Bot('X') : (User*) new Player('X');
    this->players[1] = mode_o ? (User*) new Bot('O') : (User*) new Player('O');
    this->l_sign = last_sign;
    this->plane = tmp;

    file.close();
    return true;
}