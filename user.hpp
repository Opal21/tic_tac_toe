#ifndef USER_HPP
#define USER_HPP

#include "plane.hpp"
#include <iostream>
#include <string>

class User 
{
protected:
		char player_sign{};
public:
    [[nodiscard]] virtual Move decide_move(const Plane& plane) const = 0;
    [[nodiscard]] char get_player_sign() const;
};

class Player : public User
{
private:

public:
    explicit Player(char player_sign);
    [[nodiscard]] Move decide_move(const Plane& plane) const;
};

class Bot : public User
{
private:

public:
    explicit Bot(char player_sign);
    [[nodiscard]] Move decide_move(const Plane& plane) const;
};

class Game
{
private:
    Plane plane;
    User* players[2]{}; // two players - we can put Player or Bot inside
    char l_sign{};
    Game(const Game &game);
    Game(const Game &&game) noexcept ;
    Game& operator = (const Game& game);
public:
    Game(int size, int x_player_mode, int o_player_mode); // player_mode=0-human, other-computer
    ~Game();
    [[nodiscard]] bool is_finished() const; // check if game is finished
    [[nodiscard]] Plane last_plane() const;
    [[nodiscard]] char last_sign() const;
    void forward();
    // bool save(std::string filename) const; // save current state of game to file
    // bool load(std::string filename); // load state of game from file
};

#endif