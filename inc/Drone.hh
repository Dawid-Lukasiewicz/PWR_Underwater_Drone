#ifndef DRONE
#define DRONE

#include"Rectangle.hh"
#include"Rotator.hh"
#include"Obstacle.hh"
#include"InterfaceDrone.hh"

class Drone : public Rectangle, public Obstacle, public InterfaceDrone
{
    double Head;
    double Ray;
    
    std::shared_ptr<Rotator> RotatorPtr[2];

    public:
    Drone() = delete;
    Drone(std::shared_ptr<Rotator> rotator1, const Vector3D *nodes, const Vector3D &center, const MatrixRot &rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr,const std::string & color);
    ~Drone();
    void move(double length)override;
    void moveUpDown(double length, double angle)override;
    void rotate(double angle)override;
    void move_to(const Vector3D & vec)override;
    void move_to(double x,double y,double z)override;
    void draw()override;
    Vector3D GetCenter()const override;
    double GetRay()const override;
    bool collision(const InterfaceDrone & MovingDrone)override;
};

#endif