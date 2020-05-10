#ifndef DRONE
#define DRONE

#include"Rectangle.hh"

class Drone : public Rectangle
{
    double Face;

    public:
    void move_right(double lenght);
    void move_left(double lenght);
    void move_forward(double lenght);
    void move_back(double length);

};

#endif