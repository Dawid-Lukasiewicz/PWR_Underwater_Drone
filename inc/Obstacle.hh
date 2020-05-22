#ifndef OBSTACLE_HH
#define OBSTACLE_HH

#include "Draw3D_api_interface.hh"
#include "SMacierz.hh"

using Vector3D = SWektor<double,3>;

class Obstacle
{
protected:
    std::shared_ptr<drawNS::Draw3DAPI> GnuPtr;
public:
    Obstacle(std::shared_ptr<drawNS::Draw3DAPI> gnuptr)
    : GnuPtr(gnuptr){}
    virtual ~Obstacle() {}
};

#endif