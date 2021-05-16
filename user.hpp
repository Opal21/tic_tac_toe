
#ifndef USER_HPP
#define USER_HPP

#include "plane.hpp"
#include <iostream>
#include <string>

class User 
{
protected:
		char player_color;
public:
    virtual Move pass_control(const Plane& plane) const;
    char color() const;
};

class Player : public User
{
private:

public:
    Player(char player_color);
    Move pass_control(Plane plane) const;
};

class Bot : public User
{
	private:
		
	public:
		Bot(char player_color);
		Move pass_control(const Plane& plane) const;
};

class Game
{
private:
    Plane plane;
    User* players[2]; // two players - we can put Player or Bot inside using polymorphy
    char l_color;
    Game(const Game &game);
    Game(const Game &&game);
    Game& operator = (const Game& game);
public:
    Game(int size, // size of plane
         int x_player_mode, int o_player_mode); // player_mode = 0 means human, other values means computer (possibly with numerous levels
    ~Game(); // destructor, to free memory of players
    bool finished() const; // check if game is finished
    Plane last_plane() const;
    char last_color() const;
    void forward();
    // ideas, we don't need to make them tho
    // bool save(std::string filename) const; // save current state of game to file
    // bool load(std::string filename); // load state of game from file
};

#endif