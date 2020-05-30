#ifndef FIGURE
#define FIGURE

#include<iostream>
#include <string>
#include <unistd.h>
#include"MatrixRot.hh"
#include"Dr3D_gnuplot_api.hh"
#include"Draw3D_api_interface.hh"



using Vector3D = SWektor<double,3>;

/*!
* \brief Wirtualna klasa Figura
*/
class Figure
{
    
    protected:
    
    std::string Color;
    /*!
    * \brief Macierz rotacji figury
    */
    MatrixRot Rotation;
    /*!
    * \brief Środek figury
    */
    Vector3D Center;
    /*!
    * \brief Share pointer na klasę drawNS::Draw3DAPI
    */
    std::shared_ptr<drawNS::Draw3DAPI> GnuPtr;
    /*!
    * \brief Identyfikator narysowanej figury
    */
    double Id;

    public:
    /*!
    * \brief Konstruktor
    * \param rot Macierz rotacji
    * \param center Środek figury
    * \param gnuptr wskaźnik na drawnNS::Point3D 
    */
    Figure(const MatrixRot &rot, const Vector3D &center, std::shared_ptr<drawNS::Draw3DAPI> gnuptr,const std::string & color)
    : Rotation(rot), Center(center), GnuPtr(gnuptr), Color(color) , Id(0){}
    /*!
    * \brief Destruktor
    */
    virtual ~Figure() {}
    /*!
    * \brief Rysowanie figury
    */
    virtual void draw() {}
    /*!
    * \brief przesunięcie figury po prostej
    * \param length Długość przesunięcia
    */
    virtual void move(double length) {}
    /*!
    * \brief Natychmiastowe narysowanie figury w podanym miejscu
    * \param vec Wektor nowcyh współrzędnych
    */
    virtual void move_to(const Vector3D & vec) {}
    /*!
    * \brief Natychmiastowe narysowanie figury w podanym miejscu
    * \param x Koordynaty X
    * \param y Koordynaty Y
    * \param z Koordynaty Z
    */
    virtual void move_to(double x,double y,double z) {}
    /*!
    * \brief przesunięcie figury pod kątem
    * \param length Długość przesunięcia
    * \param angle Kąt przesunięcia
    */
    virtual void moveUpDown(double length, double angle) {}
    //virtual void moveZ(double length, double angle) {}
    /*!
    * \brief Obrót figury wokół jego własnej osi Z
    * \param angle Kąt obrotu
    */
    virtual void rotate(double angle) {}
    /*!
    * \brief Zwraca środek figury
    */
    virtual Vector3D & GetCenter() =0;
};

#endif