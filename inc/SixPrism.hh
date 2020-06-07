#ifndef SIXPRISM_HH
#define SIXPRISM_HH

#include "Figure.hh"

class SixPrism : public Figure
{
protected:
Vector3D Nodes[12];
    
public:
    SixPrism() = delete;
    SixPrism(const Vector3D node, const Vector3D & center, const MatrixRot & rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr,const std::string & color);
    ~SixPrism();
    void draw() override;
    void move(double length) override;
    void moveUpDown(double length, double angle) override;
    void rotate(double angle) override;
    void rotateY(double angle)override;
    void rotateX(double angle)override;
    //int AmountFigures() override;
};

//int SixPrism::HowManyFigures=0;

#endif