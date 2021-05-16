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
    return <#initializer#>;
}

unsigned int Plane::size() const {
    return 0;
}

char Plane::at(int k, int w) const {
    return 0;
}

std::vector<Move> Plane::evaluate(char player_color) const {
    return std::vector<Move>();
}

bool Plane::finished() const {
    return false;
}

bool Plane::apply(const Move &m) {
    return false;
}

Move::Move(int k, int w, char color, double value) {

}

Move::Move(const Move &ob) {

}

Move::Move(const Move &&ob) {

}
