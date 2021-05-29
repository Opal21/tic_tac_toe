#ifndef USER_HPP
#define USER_HPP

#include "plane.hpp"
#include <iostream>

class User 
{
protected:
		char player_sign{};
public:
    [[nodiscard]] virtual Move decide_move(const Plane& plane) const = 0;
    [[nodiscard]] virtual int UserMode() const = 0;
    [[nodiscard]] char get_player_sign() const;
};

class Player : public User
{
private:

public:
    explicit Player(char player_sign);
    [[nodiscard]] Move decide_move(const Plane& plane) const;
    [[nodiscard]] int UserMode() const;
};

class Bot : public User
{
private:
    [[nodiscard]] static int loss(const int& min, const int& max) ;
public:
    explicit Bot(char player_sign);
    [[nodiscard]] Move decide_move(const Plane& plane) const;
    [[nodiscard]] int UserMode() const;
};

#endif