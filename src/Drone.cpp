#include"Drone.hh"


Drone::Drone(const Vector3D *nodes, const Vector3D &center, const MatrixRot &rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr)
: Rectangle(nodes, center, rotation, gnuptr)
{
    Head=0;
}

Drone::~Drone()
{}

void Drone::draw()
{
    using namespace std;
    
    Rectangle::draw();
    GnuPtr->erase_shape(Head);
    Head=GnuPtr->draw_polyhedron(vector<vector<drawNS::Point3D>>
    {{(Center+Rotation*Nodes[1]).P3D(),(Center+Rotation*Nodes[2]).P3D()},
    {(Center+Rotation*Nodes[5]).P3D(),(Center+Rotation*Nodes[6]).P3D()}
    },
    "red");
    GnuPtr->redraw();
}
/*
void Drone::rotate(double angle)
{
    Rectangle::rotate(angle);
}
*/

void Drone::move_to(const Vector3D & vec)
{
    Center = vec;
    GnuPtr->erase_shape(Head);
    draw();
}

void Drone::move_to(double x,double y,double z)
{
    Center[0]=x;
    Center[1]=y;
    Center[2]=z;
    GnuPtr->erase_shape(Head);
    draw();
}

void Drone::move_right(double length)
{
    rotate(90);
    move(length,0);
    draw();
    //GnuPtr->erase_shape(Head);
}

void Drone::move_left(double length)
{
    rotate(-90);
    move(length,0);
    draw();
    //GnuPtr->erase_shape(Head);
}

void Drone::move_forward(double length)
{
    move(length,0);
    draw();
    //GnuPtr->erase_shape(Head);
}

void Drone::move_back(double length)
{
    rotate(180);
    move(length,0);
    draw();
    //GnuPtr->erase_shape(Head);
}

void Drone::interface()
{

}