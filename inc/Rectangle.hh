#include"Figure.hh"

#ifndef RECTANGLE
#define RECTANGLE

class Rectangle : public Figure
{
    protected:
    Vector3D Nodes[8];
    

    public:
    Rectangle(const Vector3D *nodes, const Vector3D &center, const MatrixRot &rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr);
    void draw() override;
    void move(double length, double angle) override;
    void moveUpDown(double length, double angle) override;
    void rotate(double angle) override;
};

#endif