#ifndef BOX_HH
#define BOX_HH

#include"Obstacle.hh"
#include"Rectangle.hh"
#include"InterfaceDrone.hh"

class Box : public Obstacle, public Rectangle
{
private:
    double Ray;
public:
    Box(const Vector3D *nodes, const Vector3D &center, const MatrixRot &rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr,const std::string & color);
    ~Box();
    bool collision(const InterfaceDrone & MovingDrone)override;
    void draw() override;
};
#endif