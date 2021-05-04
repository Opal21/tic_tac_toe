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
    int DecideTurn();
    void PrintPlane();

    void set_size(int new_size);
    int get_size();

private:
    int size_;
    char** plane_;
};


#endif //TIC_TAC_TOE_PLANE_H
