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
    {{(Center+Rotation*Nodes[2]).P3D(),(Center+Rotation*Nodes[3]).P3D()},
    {(Center+Rotation*Nodes[6]).P3D(),(Center+Rotation*Nodes[7]).P3D()}},"red");
    GnuPtr->redraw();
}
/*
void Drone::rotate(double angle)
{
    Rectangle::rotate(angle);
}
*/
void Drone::move_right(double length)
{
    move(length,-90);
    draw();
    //GnuPtr->erase_shape(Head);
}

void Drone::move_left(double length)
{
    move(length,90);
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
    move(length, 180);
    draw();
    //GnuPtr->erase_shape(Head);
}

void Drone::interface()
{

}