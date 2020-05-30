#include"Box.hh"

Box::Box(const Vector3D *nodes, const Vector3D &center, const MatrixRot &rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr,const std::string & color)
: Rectangle(nodes,center,rotation,gnuptr,color), Ray(nodes[0].dlugosc()) {}

Box::~Box()
{
}

bool Box::collision(const InterfaceDrone & MovingDrone)
{
    if((Center-MovingDrone.GetCenter()).dlugosc()<Ray+MovingDrone.GetRay())
    {
        std::cout<<std::endl;
        std::cout<<"Kolizja z przeszkodą"<<std::endl;
        std::cout<<std::endl;
        return true;
    }
    else
        return false;
}