#include<iostream>
#include"Vector.hh"
#include"Matrix.hh"
#include"Draw3D_api_interface.hh"

class Figure : public drawNS::Draw3DAPI
{
    protected:
    Matrix rotation;
    Vector center;

    public:
    Figure(Matrix rot, Vector center);
    virtual void draw() const;
};