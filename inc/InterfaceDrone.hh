#ifndef INTERFACE_DRONE
#define INTERFACE_DRONE

#include"Figure.hh"
#include "Obstacle.hh"

class InterfaceDrone
{
    public:
    ~InterfaceDrone() {}
    virtual void move(double length) {}
    virtual void moveUpDown(double length, double angle) {}
    virtual void rotate(double angle) {}
    virtual Vector3D GetCenter()const=0;
    virtual double GetRay()const=0;
    virtual Vector3D GetNodes(int indeks)const=0;
    //virtual bool collision(Figure & MovingFigure);
};
#endif