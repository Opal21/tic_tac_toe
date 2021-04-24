//
// Created by marci on 23/04/2021.
//

#include "Plane.h"

Plane::Plane() : size_(3), plane_(nullptr) {}

Plane::Plane(int size) : size_(size), plane_(new char [size_])
{
    for (int i=0; i < this->size_; i++)
    {
        this->plane_[i] = 95;
    }
}

bool Plane::IsEmpty()
{
    return false;
}

bool Plane::IsFull()
{
    return false;
}

int Plane::DecideTurn()
{
    return 0;
}

void Plane::set_size(int new_size)
{
    this->size_=new_size;
}

int Plane::get_size() const
{
    return this->size_;
}
