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
    // Iterate over every element
    return false;
}

int Plane::get_size() const
{
    return this->size_;
}

void Plane::PrintPlane() const
{
    std::cout << "Current plane: " << std::endl;
    std::cout << "---------" << std::endl << "| " << plane_[0][0] << plane_[0][1] << plane_[0][2]
              << plane_[0][2] << " |" << std::endl <<  "| " << plane_[1][0] << plane_[1][1]
              << plane_[1][2] << " |" << std::endl <<  "| " << plane_[2][0] << plane_[2][1]
              << plane_[2][2] << " |" << std::endl << "---------" << std::endl;
}

char Plane::DecideWinner() const
{
    for (int i = 0; i < 3; i++)
    {
        if (plane_[i][0] == plane_[i][1] == plane_[i][2])
        {
            if (plane_[i][0] == 'O')
            {
                return 'O';
            }

            else if(plane_[i][0] == 'X')
            {
                return 'X';
            }
        }
        else if (plane_[0][i] == plane_[1][i] == plane_[2][i])
        {
            if (plane_[0][i] == 'O') {return 'O';}

            else if(plane_[0][i] == 'X') {return 'X';}
        }

        else if (plane_[0][0] == plane_[1][1] == plane_[2][2] or plane_[0][2] == plane_[1][1] ==
        plane_[2][0])
        {
            if (plane_[1][1] == 'O') {return 'O';}
            else if (plane_[1][1] == 'X') {return 'X';}
        }
        else {return 'D';} //Draw

    }
}

char Plane::DecideTurn() {}
