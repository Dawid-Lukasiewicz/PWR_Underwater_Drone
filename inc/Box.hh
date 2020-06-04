#ifndef BOX_HH
#define BOX_HH

#include"Obstacle.hh"
#include"Rectangle.hh"
#include"InterfaceDrone.hh"

/*!
* \brief Klasa pudło, jako przeszkoda 
*/
class Box : public Obstacle, public Rectangle
{
private:
    /*!
    * \brief Promien
    */
    //double Ray;
public:
    /*!
    * \brief Konstruktor
    * \param nodes Tablica wektorów na wierzchołki
    * \param center Wektor na środek pudła
    * \param rotation Macierz obrotu pudła
    * \param gnuptr Wskaźnik na łącze z Gnuplotem
    * \param color String określający kolor pudła
    */
    Box(const Vector3D *nodes, const Vector3D &center, const MatrixRot &rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr,const std::string & color);
    /*!
    * \brief Destruktor
    */
    ~Box();
    /*!
    * \brief Sprawdzanie kolizji z poruszającym się dronem
    * \param MovingDrone Poruszający się dron
    */
    bool collision(const InterfaceDrone & MovingDrone)override;
    /*!
    * \brief Rysowanie pudła
    */
    void draw() override;
};
#endif