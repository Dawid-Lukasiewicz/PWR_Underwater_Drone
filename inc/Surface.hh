#ifndef SURFACE_HH
#define SURFACE_HH

#include "Obstacle.hh"

using namespace std;

class Surface :public Obstacle
{
private:
    vector<vector<drawNS::Point3D>> PointsSurf;
    shared_ptr<drawNS::Draw3DAPI> GnuPtr;
    std::string Color;
public:
    Surface(shared_ptr<drawNS::Draw3DAPI> gnuptr, Vector3D pointZ,std::string color);
    ~Surface();
    void draw();
    bool collision(const InterfaceDrone & MovingDrone);
};

#endif
