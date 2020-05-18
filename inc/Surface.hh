#ifndef SURFACE_HH
#define SURFACE_HH

#include "Obstacle.hh"

using namespace std;

class Surface :public Obstacle
{
private:
    Vector3D PointZ[7][7];
public:
    Surface(shared_ptr<drawNS::Draw3DAPI> gnuptr, Vector3D pointZ[7][7]);
    ~Surface();
    void draw();
};

#endif
