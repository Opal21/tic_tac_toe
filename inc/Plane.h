#ifndef TIC_TAC_TOE_PLANE_H
#define TIC_TAC_TOE_PLANE_H


class Plane
{
public:
    Plane();
    explicit Plane(int size);

    bool IsEmpty();
    bool IsFull();
    void PrintPlane() const;
    char DecideWinner() const;
    char DecideTurn();
    int get_size() const;

    char** plane_;

private:
    int size_;
};


#endif //TIC_TAC_TOE_PLANE_H
