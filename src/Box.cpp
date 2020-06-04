#include"Box.hh"

Box::Box(const Vector3D *nodes, const Vector3D &center, const MatrixRot &rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr,const std::string & color)
: Rectangle(nodes,center,rotation,gnuptr,color), Ray(nodes[0].dlugosc()) 
{

}

Box::~Box()
{
}

bool Box::collision(const InterfaceDrone & MovingDrone)
{
    double ray=MovingDrone.GetRay();
    Vector3D center=MovingDrone.GetCenter();
    bool Stop=false;
    for(int i=0; i<8; i++)
    {
        //std::cout<<"Z: "<<(Nodes[0]+Center)[2];
        //std::cout<<"  "<<(Nodes[4]+Center)[2]<<std::endl;
        //std::cout<<"Dron: "<<(MovingDrone.GetNodes(i)+center)[2]<<std::endl;
        if((Nodes[0]+Center)[0]+8>(MovingDrone.GetNodes(i)+center)[0]&&(Nodes[2]+Center)[0]-8<(MovingDrone.GetNodes(i)+center)[0])
        {
            if((Nodes[1]+Center)[1]-8<(MovingDrone.GetNodes(i)+center)[1]&&(Nodes[3]+Center)[1]+8>(MovingDrone.GetNodes(i)+center)[1])
            {
                if((Nodes[0]+Center)[2]+8>(MovingDrone.GetNodes(i)+center)[2]&&(Nodes[4]+Center)[2]-8<(MovingDrone.GetNodes(i)+center)[2])
                {
                    std::cout<<std::endl;
                    std::cout<<"Kolizja z przeszkodą"<<std::endl;
                    std::cout<<std::endl;
                    Stop=true;
                    break;
                }    
            }
        }
    }
    return Stop;
}

void Box::draw()
{
    Rectangle::draw();
    GnuPtr->redraw();
}