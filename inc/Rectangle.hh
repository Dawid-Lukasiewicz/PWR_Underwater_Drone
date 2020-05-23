#include"Figure.hh"

#ifndef RECTANGLE
#define RECTANGLE

class Rectangle : public Figure
{
    protected:
    Vector3D Nodes[8];
    

    public:
    Rectangle() = delete;
    Rectangle(const Vector3D *nodes, const Vector3D &center, const MatrixRot &rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr);
    ~Rectangle();
    void draw() override;
    void move(double length) override;
    void move_to(const Vector3D & vec)override;
    void move_to(double x,double y,double z)override;
    void moveUpDown(double length, double angle) override;
    void rotate(double angle) override;
    MatrixRot const GetRotation() const;
};

#endif