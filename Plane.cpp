#include <iostream>
#include "plane.hpp"

Plane::Plane(unsigned int size) : size_(size)
{
    for (int i = 0; i < this->size_; i++)
    {
        for (int j = 0; j < this->size_; j++)
        {
            this->data[i][j] = ' ';
        }
    }
}

Plane::Plane(const Plane &ob) : size_(ob.get_size())
{
    for (int i = 0; i < this->size_; i++)
    {
        for (int j = 0; j < this->size_; j++)
        {
            this->data[i][j] = ob.get_sign_at(i, j);
        }
    }
}

Plane::Plane(const Plane &&ob) : size_(ob.get_size())
{
    for (int i = 0; i < this->size_; i++)
    {
        for (int j = 0; j < this->size_; j++)
        {
            this->data[i][j] = ob.get_sign_at(i, j);
        }
    }
}

Plane &Plane::operator=(const Plane &ob)
{
    this->size_ = ob.get_size();
    for (int i = 0; i < this->size_; i++)
    {
        for (int j = 0; j < this->size_; j++)
        {
            this->data[i][j] = ob.get_sign_at(i, j);
        }
    }
    return *this;
}

unsigned int Plane::get_size() const
{
    return this->size_;
}

char Plane::get_sign_at(int column, int row) const
{
    return this->data.at(column).at(row);
}

std::vector<Move> Plane::evaluate(char player_color) const
{
    return std::vector<Move>();
}

bool Plane::is_full() const
{
    for (int i = 0; i < this->size_; i++)
    {
        for (int j = 0; j < this->size_; j++)
        {
            if (this->data[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

bool Plane::make_move(const Move &m)
{
    if (this->get_sign_at(m.col, m.row) == ' ')
    {
        this->data.at(m.col).at(m.row) = m.sign;
        return true;
    }
    else
    {
        std::cout << "This place is already taken. Choose another one!" << std::endl;
        return false;
    }
}

char Plane::who_won() const
{
    for (int i = 0; i < 3; i++)
    {
        if (this->get_sign_at(i, 0) == this->get_sign_at(i, 1) == this->get_sign_at(i, 2))
        {
            if (this->get_sign_at(i, 0) == 'O') {return 'O';}
            else if(this->get_sign_at(i, 0) == 'X') {return 'X';}
        }
        else if (this->get_sign_at(0, i) == this->get_sign_at(1, i) == this->get_sign_at(2, i))
        {
            if (this->get_sign_at(0, i) == 'O') {return 'O';}
            else if(this->get_sign_at(0, i) == 'X') {return 'X';}
        }

        else if (this->get_sign_at(0, 0) == this->get_sign_at(1, 1) == this->get_sign_at(2, 2)
              or this->get_sign_at(0, 2) == this->get_sign_at(1, 1) == this->get_sign_at(2, 0))
        {
            if (this->get_sign_at(1, 1) == 'O') {return 'O';}
            else if (this->get_sign_at(1, 1) == 'X') {return 'X';}
        }
        else {return ' ';} //Draw
    }
}

std::ostream& operator << (std::ostream& stream, const Plane& plane)
{
    std::cout << "Current plane: " << std::endl;
    std::cout << "-----" << std::endl << "| "
              << plane.get_sign_at(0, 0) << plane.get_sign_at(0, 1) << plane.get_sign_at(0, 2)
              << " |" << std::endl <<  "| "
              << plane.get_sign_at(1, 0) << plane.get_sign_at(1, 1) << plane.get_sign_at(1, 2)
              << " |" << std::endl <<  "| "
              << plane.get_sign_at(2, 0) << plane.get_sign_at(2, 1)<< plane.get_sign_at(2, 2)
              << " |" << std::endl << "-----" << std::endl;
    return stream;
}

Move::Move(int k, int w, char color)
{
    this->col = k;
    this->row = w;
    this->sign = color;
}

Move::Move(const Move &ob)
{
    this->col = ob.col;
    this->row = ob.row;
    this->sign = ob.sign;
}

Move::Move(const Move &&ob)
{
    this->col = ob.col;
    this->row = ob.row;
    this->sign = ob.sign;
}
