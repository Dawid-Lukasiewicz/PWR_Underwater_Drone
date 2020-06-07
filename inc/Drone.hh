#ifndef DRONE
#define DRONE

#include"Rectangle.hh"
#include"Rotator.hh"
#include"Obstacle.hh"
#include"InterfaceDrone.hh"

/*!
* \brief Klasa Drone, przedstawia drona
*/
class Drone : public Rectangle, public InterfaceDrone, public Obstacle
{
    protected:
    
    /*!
    * \brief Identyfikator głowy drona 
    */
    double Head;
    /*!
    * \brief Promień drona 
    */
    double Ray;
    /*!
    * \brief tablica wskaźników na wirniki (klasa Rotator) 
    */
    std::shared_ptr<Rotator> RotatorPtr[2];

    public:
    
    /*!
    * \brief Brak kontruktora bezparametrycznego 
    */
    Drone() = delete;
    /*!
    * \brief Kontruktor Drona
    * \param rotator1 Wskaźnik na jeden z wirników, drugi jest kopiowany
    * \param nodes Tablica wektorów na wierzchołki
    * \param center Wektor na środek drona
    * \param rotation Macierz obrotu drona
    * \param gnuptr Wskaźnik na łącze z Gnuplotem
    * \param color String określający kolor drona
    */
    Drone(std::shared_ptr<Rotator> rotator1, const Vector3D *nodes, const Vector3D &center, const MatrixRot &rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr,const std::string & color);
    /*!
    * \brief Dentruktor 
    */
    ~Drone();
    /*!
    * \brief Poruszanie dronem do przodu i do tyłu
    * \param length Długość przesunięcia 
    */
    void move(double length)override;
    /*!
    * \brief Poruszaniem dronem do przodu pod kątem
    * \param length Długość przesunięcia
    * \param angle Kąt przesunięcia
    */
    void moveUpDown(double length, double angle)override;
    /*!
    * \brief  Obrót drona
    * \param angle Kąt obrotu
    */
    void rotate(double angle)override;
    /*!
    * \brief  Obrót drona wokół osi y
    * \param angle Kąt obrotu
    */
    void rotateY(double angle)override;
    /*!
    * \brief  Obrót drona wokół osi x
    * \param angle Kąt obrotu
    */
    void rotateX(double angle)override;
    /*!
    * \brief Natychmiastowe przesunięcie drona na wskazane miejsce
    * \param vec Wektor współrzędnych 
    */
    void move_to(const Vector3D & vec)override;
    /*!
    * \brief Natychmiastowe przesunięcie drona na wskazane miejsce
    * \param x Koordynaty X
    * \param y Koordynaty Y
    * \param z Koordynaty Z 
    */
    void move_to(double x,double y,double z)override;
    /*!
    * \brief Rysowanie drona 
    */
    void draw()override;
    /*!
    * \brief Zwraca wektor środka drona 
    */
    Vector3D GetCenter()const override;
    /*!
    * \brief Zwraca promień drona 
    */
    double GetRay()const override;
    /*!
    * \brief Zwraca wskazany wektor na wierzchołek drona
    * \param indeks Indeks pożądanego wierzchołka 
    */
    Vector3D GetNodes(int indeks)const override;
    /*!
    * \brief Sprawdzanie kolizji z poruszającym się dronem
    * \param MovingDrone Poruszający się dron
    */
    bool collision(const InterfaceDrone & MovingDrone)override;
    //static int Amount;
    //static int & GetAmount();
};

#endif