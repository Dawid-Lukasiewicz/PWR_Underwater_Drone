#include "Surface.hh"
Surface::Surface(std::shared_ptr<drawNS::Draw3DAPI> gnuptr, Vector3D pointZ,std::string color)
: GnuPtr(gnuptr),Color(color)
{
    std::vector<drawNS::Point3D> tmpV;
    for(int i=0; i<9; i++)
    {
        tmpV.clear();
        for(int j=0; j<9; j++)
        {
            tmpV.push_back(drawNS::Point3D(40*i+pointZ[0], 40.0*j+pointZ[1], pointZ[2]));
        }
        PointsSurf.push_back(tmpV);
    }
}

Surface::~Surface()
{
}

void Surface::draw()
{
    GnuPtr->draw_surface(PointsSurf,Color);
    GnuPtr->redraw();
}

bool Surface::collision(const InterfaceDrone & MovingDrone)
{
    //std::cout<<"Center: "<<MovingDrone.GetCenter()<<std::endl;std::cout<<++kata<<std::endl;
    //std::cout<<"Pojemność0: "<<PointsSurf.size()<<std::endl;
    double ada=0,kata=0;
    bool Stop=false;
    for(vector<drawNS::Point3D> & i : PointsSurf)
    {   
        for(drawNS::Point3D & j : i)
        {   
            if(std::abs(j[2]-MovingDrone.GetCenter()[2])<MovingDrone.GetRay()&&
            (MovingDrone.GetCenter()[0]<j[0]+MovingDrone.GetRay()&&
            MovingDrone.GetCenter()[0]>j[0]-MovingDrone.GetRay())&&
            (MovingDrone.GetCenter()[1]<j[1]+MovingDrone.GetRay()&&
            MovingDrone.GetCenter()[1]>j[1]-MovingDrone.GetRay()))
            {
                std::cout<<"Zderzenie z powierzchnią"<<std::endl;
                Stop=true;
                break;
            }
        }
        if(Stop==true)
            break;
    }
    return Stop;
}