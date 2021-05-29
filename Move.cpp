
#include "Move.hpp"

Move::Move(int k, int w, char color)
{
    this->col = k;
    this->row = w;
    this->sign = color;
}

Move::Move() : col(-1), row(-1), sign(-1) {}
Move::Move(const Move&) = default;
Move& Move::operator = (const Move&) = default;
