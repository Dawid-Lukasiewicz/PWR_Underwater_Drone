#ifndef SIXPRISM_HH
#define SIXPRISM_HH

#include "Figure.hh"

class SixPrism : public Figure
{
protected:
Vector3D Node;
    
public:
    SixPrism() = delete;
    SixPrism(const Vector3D node, const Vector3D & center, const MatrixRot & rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr);
    ~SixPrism();
    void draw() override;
    void move(double length, double angle) override;
    void moveUpDown(double length, double angle) override;
    void rotate(double angle) override;
};

#endif