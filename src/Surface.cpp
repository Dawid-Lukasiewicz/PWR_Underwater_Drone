#include "Surface.hh"
Surface::Surface(std::shared_ptr<drawNS::Draw3DAPI> gnuptr, Vector3D pointZ[7][7])
: Obstacle(gnuptr)
{
    for(int i; i<7; i++)
    {
        for(int j; j<7; j++)
            PointZ[i][j]=pointZ[i][j];
    }
}

Surface::~Surface()
{
}

void Surface::draw()
{
    using namespace std;

    vector<vector<drawNS::Point3D>> points;
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<7; j++)
        {
            points[i].push_back(PointZ[i][j].P3D());
        }
    }
    

    GnuPtr->draw_surface(points);
    GnuPtr->redraw();
    /*
    for (int i=0; i<10; i++)
    {
        drawNS::Point3D p(PointZ[0], 10.0*i+PointZ[1], PointZ[2]);
        points[0].push_back(p);
        for (int j=0; j<20; j++)
        {
            //drawNS::Point3D y(PointZ[0], 10.0*i+PointZ[1], PointZ[2]);
            unique_ptr<drawNS::Point3D> y = make_unique<drawNS::Point3D>(PointZ[0], 10.0*i+PointZ[1], PointZ[2]);
            points[1].push_back(y);
        }
    }
    vector<vector<drawNS::Point3D>> points2;
    for(drawNS::Point3D &i : points2[0])
    {

    }
    */
    
}