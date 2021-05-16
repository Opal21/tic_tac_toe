#include <iostream>
#include "plane.hpp"

Plane::Plane(unsigned int size) : s(size)
{
    for (int i = 0; i < this->s; i++)
    {
        for (int j = 0; j < this->s; j++)
        {
            this->data[i][j] = ' ';
        }
    }
}

Plane::Plane(const Plane &ob) {

}

Plane::Plane(const Plane &&ob) {

}

Plane &Plane::operator=(const Plane &ob) {

}

unsigned int Plane::size() const
{
    return this->s;
}

char Plane::at(int k, int w) const
{
    return this->data[k][w];
}

std::vector<Move> Plane::evaluate(char player_color) const {
    return std::vector<Move>();
}

bool Plane::finished() const
{
    for (int i = 0; i < this->s; i++)
    {
        for (int j = 0; j < this->s; j++)
        {
            if (this->data[i][j] == ' ')
            {
                return false;
            }
        }
    }

}

bool Plane::apply(const Move &m)
{
    if (this->at(m.k, m.w) == ' ')
    {
        this->data[m.k][m.w] == m.color;
        return true;
    }
    else
    {
        return false;
    }
}

Move::Move(int k, int w, char color, double value) {

}

Move::Move(const Move &ob) {

}

Move::Move(const Move &&ob) {

}
