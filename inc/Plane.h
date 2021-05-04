//
// Created by marci on 23/04/2021.
//

#ifndef TIC_TAC_TOE_PLANE_H
#define TIC_TAC_TOE_PLANE_H


class Plane
{
public:
    Plane();
    explicit Plane(int size);

    bool IsEmpty();
    bool IsFull();
    void PrintPlane();
    char DecideWinner();
    char DecideTurn();

    void set_size(int new_size);
    int get_size();

    char** plane_;

private:
    int size_;
};


#endif //TIC_TAC_TOE_PLANE_H
