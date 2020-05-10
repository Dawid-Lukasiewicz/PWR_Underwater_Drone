#include"Rectangle.hh"
//#include

Rectangle::Rectangle(const Vector3D *nodes, const Vector3D &center, const MatrixRot &rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr)
: Figure(rotation, center, gnuptr)
{
    
    for(int i=0; i<8; i++)
    {
        Nodes[i] = nodes[i];
    }
}

void Rectangle::move(double length, double angle)
{
    MatrixRot PomRot = Rotation;
    double pi=3.14, rot, dane[3]={length/100,0,0};
    rot=pi*angle/180;
    PomRot[0][0]=cos(rot);
    PomRot[0][1]=-sin(rot);
    PomRot[1][0]=sin(rot);
    PomRot[1][1]=cos(rot);
    Vector3D move(dane);
    for (int i=0; i<100; i++)
    {
        Center+=PomRot*move;
        GnuPtr->erase_shape(Id);
        draw();
    }
    
}

void Rectangle::rotate(double angle)
{
    MatrixRot PomRot = Rotation;
    double pi=3.14, rot=pi*angle/180;
    
    PomRot[0][0]=cos(rot);
    PomRot[0][1]=-sin(rot);
    PomRot[1][0]=sin(rot);
    PomRot[1][1]=cos(rot);

    for (int i=0; i<8; i++)
    {
        std::cout<<"Przed: "<<Nodes[i]<<std::endl;
        Nodes[i]=PomRot*Nodes[i];
        std::cout<<"Po: "<<Nodes[i]<<std::endl;
        GnuPtr->erase_shape(Id);
        draw();
    }
    
}

void Rectangle::draw()
{
    using namespace std;
    
    Vector3D P[8];
    for (int i=0; i<8; i++)
    {
        P[i]=Center+Rotation*Nodes[i]; 
    }
    Id=GnuPtr->draw_polyhedron(vector<vector<drawNS::Point3D>>{{P[0].P3D(),P[1].P3D(),
    P[2].P3D(),P[3].P3D()},{P[4].P3D(),P[5].P3D(),P[6].P3D(),P[7].P3D()}},"green");
    GnuPtr->redraw();
}