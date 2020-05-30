#ifndef ROTATOR_HH
#define ROTATOR_HH

#include "SixPrism.hh"

class Rotator : public SixPrism
{

    MatrixRot RotatorMatrix;
    
public:
    Rotator(const Vector3D node, const Vector3D & center, const MatrixRot & rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr,const std::string & color);
    ~Rotator();
    void draw(const MatrixRot &MatRot, const Vector3D & attach);
    MatrixRot propulsion();
    Vector3D & GetCenter();
    std::shared_ptr<drawNS::Draw3DAPI> Get_GnuPtr();
};

#endif