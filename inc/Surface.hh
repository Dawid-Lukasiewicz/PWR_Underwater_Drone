#ifndef SURFACE_HH
#define SURFACE_HH

#include "Obstacle.hh"

using namespace std;

class Surface :public Obstacle
{
private:
    vector<vector<drawNS::Point3D>> PointsSurf;
public:
    Surface(shared_ptr<drawNS::Draw3DAPI> gnuptr, Vector3D pointZ);
    ~Surface();
    void draw(string & color);
};

#endif
