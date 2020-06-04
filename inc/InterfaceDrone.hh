#ifndef INTERFACE_DRONE
#define INTERFACE_DRONE

#include"Figure.hh"
#include "Obstacle.hh"

/*!
* \brief Wirtualna klasa drona
*/
class InterfaceDrone
{
    public:
    /*!
    * \brief Destruktor
    */
    ~InterfaceDrone() {}
    /*!
    * \brief Poruszanie dronem do przodu i do tyłu
    * \param length Długość przesunięcia 
    */
    virtual void move(double length) {}
    /*!
    * \brief Poruszaniem dronem do przodu pod kątem
    * \param length Długość przesunięcia
    * \param angle Kąt przesunięcia
    */
    virtual void moveUpDown(double length, double angle) {}
    /*!
    * \brief  Obrót drona
    * \param angle Kąt obrotu
    */
    virtual void rotate(double angle) {}
    /*!
    * \brief Zwraca wektor środka drona 
    */
    virtual Vector3D GetCenter()const=0;
    /*!
    * \brief Zwraca promień drona 
    */
    virtual double GetRay()const=0;
    /*!
    * \brief Zwraca wskazany wektor na wierzchołek drona
    * \param indeks Indeks pożądanego wierzchołka 
    */
    virtual Vector3D GetNodes(int indeks)const=0;
};
#endif