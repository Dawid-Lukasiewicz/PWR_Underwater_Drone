#include"Drone.hh"


Drone::Drone(std::shared_ptr<Rotator> rotator1, const Vector3D *nodes, const Vector3D &center, const MatrixRot &rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr)
: Rectangle(nodes, center, rotation, gnuptr)
{
    RotatorPtr[0]=rotator1;
    std::shared_ptr<Rotator> rotator2=std::make_shared<Rotator>(*rotator1);
    RotatorPtr[1]=rotator2;
    Head=0;
    //Ustawienie centrum wirników
    Vector3D Pom1=Nodes[0],Pom2=Nodes[3];
    Pom1[1]=Nodes[0][1]/1.5;
    Pom2[1]=Nodes[3][1]/1.5;
    Pom1[2]=Center[2];
    Pom2[2]=Center[2];
    RotatorPtr[0]->GetCenter()=Pom1;
    RotatorPtr[1]->GetCenter()=Pom2;
}

Drone::~Drone()
{}

void Drone::draw()
{
    using namespace std;

    
    GnuPtr->erase_shape(Head);
    
    Head=GnuPtr->draw_polyhedron(vector<vector<drawNS::Point3D>>
    {{(Center+Rotation*Nodes[1]).P3D(),(Center+Rotation*Nodes[2]).P3D()},
    {(Center+Rotation*Nodes[5]).P3D(),(Center+Rotation*Nodes[6]).P3D()},
    {(Center+Rotation*Nodes[1]).P3D(),(Center+Rotation*Nodes[6]).P3D()},
    {(Center+Rotation*Nodes[2]).P3D(),(Center+Rotation*Nodes[5]).P3D()}},
    "red");
    Rectangle::draw();
    RotatorPtr[0]->Rotator::draw(Center);
    RotatorPtr[1]->Rotator::draw(Center);
    GnuPtr->redraw();
    //std::cout<<"Center: "<<Center<<std::endl;
}

void Drone::rotate(double angle)
{
    double angle2=angle/100;
    MatrixRot PomRot(angle2);    
    for (int i=0; i<100; i++)
    {

        //Rotation*=PomRot;
        Rectangle::rotate(angle2);
        RotatorPtr[0]->SixPrism::rotate(angle2);
        RotatorPtr[1]->SixPrism::rotate(angle2);
        Drone::draw();
    }
    
}

void Drone::move(double length)
{
    
    double length1=length/100;
    for(int i=0; i<100; i++)
    {
        Rectangle::move(length1);
        //RotatorPtr[0]->move(length1);
        //RotatorPtr[1]->move(length1);
        draw();
    }
}

void Drone::moveUpDown(double length, double angle)
{
    double length1=length/100;
    for (int i=0; i<100; i++)
    {
        Rectangle::moveUpDown(length1,angle);
        //RotatorPtr[0]->moveUpDown(length1,angle1);
        //RotatorPtr[1]->moveUpDown(length1,angle1);
        draw();    
    }
    
    
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