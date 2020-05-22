#include "Surface.hh"
Surface::Surface(std::shared_ptr<drawNS::Draw3DAPI> gnuptr, Vector3D *pointZ)
: Obstacle(gnuptr)
{
    for(int i; i<49; i++)
    {
        PointZ[i]=pointZ[i];
    }
}

Surface::~Surface()
{
}

void Surface::draw()
{
    GnuPtr->draw_surface(vector<vector<drawNS::Point3D>>
    {{PointZ[0].P3D(),PointZ[1].P3D(),PointZ[2].P3D(),PointZ[3].P3D(),PointZ[4].P3D(),PointZ[5].P3D(),PointZ[6].P3D()},
    {PointZ[7].P3D(),PointZ[8].P3D(),PointZ[9].P3D(),PointZ[10].P3D(),PointZ[11].P3D(),PointZ[12].P3D(),PointZ[13].P3D()},
    {PointZ[14].P3D(),PointZ[15].P3D(),PointZ[16].P3D(),PointZ[17].P3D(),PointZ[18].P3D(),PointZ[19].P3D(),PointZ[20].P3D()},
    {PointZ[21].P3D(),PointZ[22].P3D(),PointZ[23].P3D(),PointZ[24].P3D(),PointZ[25].P3D(),PointZ[26].P3D(),PointZ[27].P3D()},
    {PointZ[28].P3D(),PointZ[29].P3D(),PointZ[30].P3D(),PointZ[31].P3D(),PointZ[32].P3D(),PointZ[33].P3D(),PointZ[34].P3D()},
    {PointZ[35].P3D(),PointZ[36].P3D(),PointZ[37].P3D(),PointZ[38].P3D(),PointZ[39].P3D(),PointZ[40].P3D(),PointZ[41].P3D()},
    {PointZ[42].P3D(),PointZ[43].P3D(),PointZ[44].P3D(),PointZ[45].P3D(),PointZ[46].P3D(),PointZ[47].P3D(),PointZ[48].P3D()}});
    GnuPtr->redraw();
    /*
    for(const std::vector<drawNS::Point3D> & p : PointsSurf)
    {
        std::cout<<"Here i am: "<<endl;
        for(const drawNS::Point3D & o : p)
        std::cout<<"x: "<<o[0]<<" "<<"y: "<<o[1]<<" "<<"z: "<<o[2]<<" "<<std::endl;
    }

    for (int i=0; i<10; i++)
    {
        pointZ.push_back(drawNS::Point3D p(PointZ[0], 10.0*i+PointZ[1], PointZ[2]));
        for (int j=0; j<10; j++)
        {
            points[i].push_back(drawNS::Point3D y(PointZ[0], 10.0*i+PointZ[1], PointZ[2]));
        }
    }
    */
    
}