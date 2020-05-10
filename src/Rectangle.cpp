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
    double dane[3]={length/100,0,0};
    Vector3D move(dane);
    MatrixRot PomRot(angle);
    PomRot*=Rotation;
    for (int i=0; i<100; i++)
    {
        Center+=PomRot*move;
        GnuPtr->erase_shape(Id);
        draw();
    }
    
}

void Rectangle::rotate(double angle)
{
    MatrixRot PomRot(angle/100), POM;    
    for (int i=0; i<100; i++)
    {
        Rotation*=PomRot;
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
    GnuPtr->erase_shape(Id);
    Id=GnuPtr->draw_polyhedron(vector<vector<drawNS::Point3D>>{{P[0].P3D(),P[1].P3D(),
    P[2].P3D(),P[3].P3D()},{P[4].P3D(),P[5].P3D(),P[6].P3D(),P[7].P3D()}},"green");
    GnuPtr->redraw();
}