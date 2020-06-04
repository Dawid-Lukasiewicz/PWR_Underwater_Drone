#ifndef OBSTACLE_HH
#define OBSTACLE_HH

#include "Draw3D_api_interface.hh"
#include "SMacierz.hh"
#include "InterfaceDrone.hh"

using Vector3D = SWektor<double,3>;

/*!
* \brief Wirtualna klasa przeszkoda
*/
class Obstacle
{
public:
    /*!
    * \brief Konstruktor
    */
    Obstacle(){}
    /*!
    * \brief Destruktor
    */
    virtual ~Obstacle() {}
    /*!
    * \brief Sprawdzanie kolizji z poruszającym się dronem
    * \param MovingDrone Poruszający się dron
    */
    virtual bool collision(const InterfaceDrone & MovingDrone)=0;
    /*!
    * \brief Rysowanie obiektu dziedziczącego po Obstacle
    * 
    * Potrzebny do umożliwienia rysowania obiektów z listy przeszkód
    */
    virtual void draw() {}
};

#endif