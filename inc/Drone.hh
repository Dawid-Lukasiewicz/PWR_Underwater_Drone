#ifndef DRONE
#define DRONE

#include"Rectangle.hh"

class Drone : public Rectangle
{
    double Head;

    public:
    Drone() = delete;
    Drone(const Vector3D *nodes, const Vector3D &center, const MatrixRot &rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr);
    ~Drone();
    //void move(double length, double angle);
    //void rotate(double angle);
    void move_to(const Vector3D & vec);
    void move_to(double x,double y,double z);
    void move_right(double lenght);
    void move_left(double lenght);
    void move_forward(double lenght);
    void move_back(double length);
    void interface();
    void draw()override;

};

#endif