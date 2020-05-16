#include "Rotator.hh"

Rotator::Rotator(const Vector3D node, const Vector3D & center, const MatrixRot & rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr)
: SixPrism(node,center,rotation,gnuptr)
{

    double tab[3][3]={{0,0,1},{0,1,0},{-1,0,0}};
    SMacierz<double,ROZMIAR> Mac(tab);
    MatrixRot MacRot(Mac);
    RotatorMatrix = MacRot;
    //Rotation*=MacRot;

}

Rotator::~Rotator()
{

}

void Rotator::draw()
{
    
    using namespace std;
    //std::cout<<"Rotacja przed: "<<std::endl<<Rotation<<std::endl;
    MatrixRot PomRot(60.0), PomRot2=Rotation;
    Vector3D P[12];
    //std::cout<<"Rotacja przed: "<<std::endl<<Rotation<<std::endl;
    for (int i=0; i<6; i++)
    {
        PomRot2*=PomRot;
        P[i]=Center+PomRot2*Node;
        P[i+6]=Center+PomRot2*Node;
        P[i+6][2]=-Node[2];
        P[i]=RotatorMatrix*P[i];
        P[i+6]=RotatorMatrix*P[i+6];
    }
    //std::cout<<"Rotacja po: "<<std::endl<<Rotation<<std::endl;
    GnuPtr->erase_shape(Id);
    Id=GnuPtr->draw_polyhedron(vector<vector<drawNS::Point3D>>
    {{P[0].P3D(),P[1].P3D(),P[2].P3D(),P[3].P3D(),P[4].P3D(),P[5].P3D()},
    {P[6].P3D(),P[7].P3D(),P[8].P3D(),P[9].P3D(),P[10].P3D(),P[11].P3D()}},
    "blue");
    GnuPtr->redraw();
}

Vector3D & Rotator::GetCenter()
{
    return Center;
}

std::shared_ptr<drawNS::Draw3DAPI> Rotator::Get_GnuPtr()
{
    return GnuPtr;
}