#ifndef DRONE
#define DRONE

#include"Rectangle.hh"
#include"Rotator.hh"

class Drone : public Rectangle
{
    double Head;
    std::shared_ptr<Rotator> RotatorPtr[2];

    public:
    Drone() = delete;
    Drone(std::shared_ptr<Rotator> rotator1, const Vector3D *nodes, const Vector3D &center, const MatrixRot &rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr);
    ~Drone();
    void move(double length)override;
    void moveUpDown(double length, double angle)override;
    void rotate(double angle)override;
    void move_to(const Vector3D & vec);
    void move_to(double x,double y,double z);
    void draw()override;
};

#endif