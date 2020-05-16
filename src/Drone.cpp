#include"Drone.hh"


Drone::Drone(std::shared_ptr<Rotator> rotator1, const Vector3D *nodes, const Vector3D &center, const MatrixRot &rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr)
: Rectangle(nodes, center, rotation, gnuptr)
{
    RotatorPtr[0]=rotator1;
    std::shared_ptr<Rotator> rotator2=std::make_shared<Rotator>(*rotator1);
    RotatorPtr[1]=rotator2;
    Head=0;

    //Ustawienie centrum wirników
    Vector3D Pom1,Pom2;
    Pom1[0]=Nodes[0][0];
    Pom1[1]=Nodes[0][1]/2.0;
    Pom1[2]=Center[2];
    Pom2[0]=Nodes[0][0];
    Pom2[1]=-Nodes[0][1]/2.0;
    Pom2[2]=Center[2];

    RotatorPtr[0]->GetCenter()+=Center+Pom1;
    RotatorPtr[1]->GetCenter()+=Center+Pom2;
}

Drone::~Drone()
{}

void Drone::draw()
{
    using namespace std;

    Rectangle::draw();
    GnuPtr->erase_shape(Head);
    //std::cout<<"RotatorPtr[0] "<<RotatorPtr[0]->GetCenter()<<std::endl;

    Head=GnuPtr->draw_polyhedron(vector<vector<drawNS::Point3D>>
    {{(Center+Rotation*Nodes[1]).P3D(),(Center+Rotation*Nodes[2]).P3D()},
    {(Center+Rotation*Nodes[5]).P3D(),(Center+Rotation*Nodes[6]).P3D()},
    {(Center+Rotation*Nodes[1]).P3D(),(Center+Rotation*Nodes[6]).P3D()},
    {(Center+Rotation*Nodes[2]).P3D(),(Center+Rotation*Nodes[5]).P3D()}},
    "red");
    RotatorPtr[0]->draw(Center+Nodes[0]*0.3);
    RotatorPtr[1]->draw(Center+Nodes[3]*0.3);
    GnuPtr->redraw();
}

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

void Drone::rotate(double angle)
{
    Rectangle::rotate(angle);
    RotatorPtr[0]->rotate(angle,Center+Nodes[0]*0.3);
    RotatorPtr[0]->rotate(angle,Center+Nodes[3]*0.3);
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