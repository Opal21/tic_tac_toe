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

char Plane::DecideWinner()
{
    for (int i = 0; i < 3; i++)
    {
        if (plane_[i][0] == plane_[i][1] == plane_[i][2])
        {
            if (plane_[i][0] == 79)
            {
                return 79; // Letter "O" in ASCII
                break;
            }

            else if(plane_[i][0] == 88)
            {
                return 88; // Letter "X" in ASCII
                break;
            }
        }
        else if (plane_[0][i] == plane_[1][i] == plane_[2][i])
        {
            if (plane_[0][i] == 79)
            {
                return 79; // Letter "O" in ASCII
                break;
            }

            else if(plane_[0][i] == 88)
            {
                return 88; // Letter "X" in ASCII
                break;
            }
        }

        else if (plane_[0][0] == plane_[1][1] == plane_[2][2] or plane_[0][2] == plane_[1][1] == \
                plane_[2][0])
        {
            if (plane_[1][1] == 79){return 79;}
            else if (plane_[1][1] == 88){return 88;}
        }
        else {return 68;}

    }
}

char Plane::DecideTurn() {}
