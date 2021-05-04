//
// Created by marci on 23/04/2021.
//

#include <iostream>
#include "inc/Plane.h"

Plane::Plane() : size_(3), plane_(nullptr) {}

Plane::Plane(int size) : size_(size), plane_(new char* [size])
{
    for (int i=0; i < size_; i++)
    {
        plane_[i] = new char [size_];
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

int Plane::get_size()
{
    return this->size_;
}

void Plane::PrintPlane()
{
    std::cout << "Current plane: " << std::endl;
    std::cout << "---------" << std::endl << "| " << plane_[0][0] << plane_[0][1] << plane_[0][2]
              << plane_[0][2] << " |" << std::endl <<  "| " << plane_[1][0] << plane_[1][1]
              << plane_[1][2] << " |" << std::endl <<  "| " << plane_[2][0] << plane_[2][1]
              << plane_[2][2] << " |" << std::endl;
}
