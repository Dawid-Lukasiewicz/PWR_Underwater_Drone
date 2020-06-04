#include"Drone.hh"


Drone::Drone(std::shared_ptr<Rotator> rotator1, const Vector3D *nodes, const Vector3D &center, const MatrixRot &rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr,const std::string & color)
: Rectangle(nodes, center, rotation, gnuptr, color)
{
    RotatorPtr[0]=rotator1;
    std::shared_ptr<Rotator> rotator2=std::make_shared<Rotator>(*rotator1);
    RotatorPtr[1]=rotator2;
    Head=0;
    //Ustawienie centrum wirników
    Vector3D Pom1=Nodes[0],Pom2=Nodes[3];
    Pom1[1]=Nodes[0][1]/1.5;
    Pom2[1]=Nodes[3][1]/1.5;
    Pom1[2]=0;
    Pom2[2]=0;
    RotatorPtr[0]->GetCenter()=Pom1;
    RotatorPtr[1]->GetCenter()=Pom2;
    //Obliczenie promienia
    Ray=Nodes[0].dlugosc();
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
    Color);
    Rectangle::draw();
    RotatorPtr[0]->Rotator::draw(Rotation,Center);
    RotatorPtr[1]->Rotator::draw(Rotation,Center);
    GnuPtr->redraw();
}

void Drone::rotate(double angle)
{

    MatrixRot PomRot(angle);    
    Rectangle::rotate(angle);
    RotatorPtr[0]->SixPrism::rotate(angle);
    RotatorPtr[1]->SixPrism::rotate(angle);
    Drone::draw();
}

void Drone::move(double length)
{
    double length1=length/100;
    for(int i=0; i<100; i++)
    {
        Rectangle::move(length1);
        usleep(25000);
        draw();
    }
}

void Drone::move_to(const Vector3D & vec)
{
    GnuPtr->erase_shape(Head);
    Rectangle::move_to(vec);
}

void Drone::move_to(double x,double y,double z)
{
    GnuPtr->erase_shape(Head);
    Rectangle::move_to(x,y, z);
}

void Drone::moveUpDown(double length, double angle)
{    
    Rectangle::moveUpDown(length,angle);
    draw();    
}

Vector3D Drone::GetCenter()const
{
    return Center;
}

double Drone::GetRay()const
{
    return Ray;
}

Vector3D Drone::GetNodes(int indeks)const
{
    //std::cout<<"indeks: "<<indeks<<std::endl;
    if(indeks>=0&&indeks<8)
        return Nodes[indeks];
    else
    {
        std::cout<<"Wykroczono za indeks (Drone::GetNodes(int indeks))"<<std::endl;
        exit(0);
    }
}

bool Drone::collision(const InterfaceDrone & MovingDrone)
{
    if((Center-MovingDrone.GetCenter()).dlugosc()<Ray+MovingDrone.GetRay())
    {
        std::cout<<std::endl;
        std::cout<<"Kolizja z innym dronem"<<std::endl;
        std::cout<<std::endl;
        return true;
    }
    else
        return false;
}