#include "Rotator.hh"

Rotator::Rotator(const Vector3D node, const Vector3D & center, const MatrixRot & rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr)
: SixPrism(node,center,rotation,gnuptr)
{

    double tab[3][3]={{0,0,1},{0,1,0},{-1,0,0}};
    SMacierz<double,ROZMIAR> Mac(tab);
    MatrixRot MacRot(Mac);
    RotatorMatrix = MacRot;
    for (int i=0; i<12; i++)
    {
        Nodes[i]=MacRot*Nodes[i];
    }
    
    //Rotation*=MacRot;

}

Rotator::~Rotator()
{

}

void Rotator::draw(const Vector3D & attach)
{
    //SixPrism::draw();
    using namespace std;
    Vector3D P[12];
    for (int i=0; i<6; i++)
    {
        P[i]=attach+Center+Nodes[i];
        P[i+6]=attach+Center+Nodes[i+6];
    }
    GnuPtr->erase_shape(Id);
    Id=GnuPtr->draw_polyhedron(vector<vector<drawNS::Point3D>>
    {{P[0].P3D(),P[1].P3D(),P[2].P3D(),P[3].P3D(),P[4].P3D(),P[5].P3D()},
    {P[6].P3D(),P[7].P3D(),P[8].P3D(),P[9].P3D(),P[10].P3D(),P[11].P3D()}},
    "blue");
    
}

void Rotator::rotate(double & angle, const Vector3D & attach)
{
    MatrixRot PomRot(angle/100);
    Vector3D point=attach;
    std::cout<<"point przed: "<<point<<std::endl;
    for (int i=0; i<100; i++)
    {
        point=PomRot*point;
        Rotation*=PomRot;
        GnuPtr->erase_shape(Id);
        draw(point);
    }
    std::cout<<"point po: "<<point<<std::endl;
}

Vector3D & Rotator::GetCenter()
{
    return Center;
}

std::shared_ptr<drawNS::Draw3DAPI> Rotator::Get_GnuPtr()
{
    return GnuPtr;
}