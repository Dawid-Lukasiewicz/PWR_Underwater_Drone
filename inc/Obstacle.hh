#ifndef OBSTACLE_HH
#define OBSTACLE_HH

#include "Draw3D_api_interface.hh"
#include "SMacierz.hh"
#include "InterfaceDrone.hh"

using Vector3D = SWektor<double,3>;

class Obstacle
{
public:
    Obstacle(){}
    virtual ~Obstacle() {}
    virtual bool collision(const InterfaceDrone & MovingDrone)=0;
    virtual void draw() {}
};

#endif