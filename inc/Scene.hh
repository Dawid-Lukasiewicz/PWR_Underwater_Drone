#ifndef SCENE_HH
#define SCENE_HH

#include"Drone.hh"
#include"Surface.hh"
#include"Drone.hh"
#include"Box.hh"
using namespace std;

class Scene
{
private:
    vector<shared_ptr<Drone>> drones;
    vector<shared_ptr<Obstacle>> boxes;
    //vector<shared_ptr<Surface>> surface;
public:
    Scene(vector<shared_ptr<Drone>> & d,vector<shared_ptr<Obstacle>> & o): drones(d), boxes(o){}
    //Scene(vector<shared_ptr<Drone>> & d,vector<shared_ptr<Box>> & o, vector<shared_ptr<Surface>> s): drones(d), boxes(o), surface(s){}
    ~Scene();
    void MoveDrone(double length, double angle, int X);
    void RotateDrone(double angle, int X);
    void Draw();
    
};


#endif