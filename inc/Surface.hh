#ifndef SURFACE_HH
#define SURFACE_HH

#include "Obstacle.hh"

using namespace std;

/*!
* \brief Klasa powierzchnia
*/
class Surface :public Obstacle
{
private:
    /*!
    * \brief Podwójna lista współrzędnych punktów powierzchni
    */
    vector<vector<drawNS::Point3D>> PointsSurf;
    /*!
    * \brief Wskaźnik na łącze Gnuplota
    */
    shared_ptr<drawNS::Draw3DAPI> GnuPtr;
    /*!
    * \brief Kolor powierzchni
    */
    std::string Color;
public:
    /*!
    * \brief Konstruktor
    * \param gnuptr Wskaźnik na łącze Gnuplota
    * \param color String określający kolor drona
    */
    Surface(shared_ptr<drawNS::Draw3DAPI> gnuptr, Vector3D pointZ,std::string color);
    /*!
    * \brief Destruktor
    */
    ~Surface();
    /*!
    * \brief Rysowanie powierzchni
    */
    void draw();
    /*!
    * \brief Sprawdzanie kolizji powierzchni z poruszającym się dronem
    * \param MovingDrone Poruszający się dron
    */
    bool collision(const InterfaceDrone & MovingDrone);
};

#endif
