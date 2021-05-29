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
    int loss(const int& min, const int& max) const;
public:
    explicit Bot(char player_sign);
    [[nodiscard]] Move decide_move(const Plane& plane) const;
};

#endif