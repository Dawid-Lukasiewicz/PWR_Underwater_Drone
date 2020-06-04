#ifndef SCENE_HH
#define SCENE_HH

#include"Drone.hh"
#include"Surface.hh"
#include"Drone.hh"
#include"Box.hh"
using namespace std;

/*!
* \brief Klasa scena, w niej znajdują się wszystkie obiekty i każda akcja będzie z niej pochodziła
*/
class Scene
{
private:
    /*!
    * \brief Ilość klatek rysowania
    * 
    * Im większa wartość tym dłuższy procec
    */  
    int Speed;
    /*!
    * \brief Lista wskaźników na drony
    */  
    vector<shared_ptr<Drone>> drones;
    /*!
    * \brief Lista wskaźników na przeszkody
    */
    vector<shared_ptr<Obstacle>> obstacles;
public:
    /*!
    * \brief Konstruktor
    * \param d Lista wskaźników na drony
    * \param o Lista wskaźników na przeszkody
    */
    Scene(vector<shared_ptr<Drone>> & d,vector<shared_ptr<Obstacle>> & o): Speed(100), drones(d), obstacles(o){}
    /*!
    * \brief Destruktor
    */
    ~Scene();
    /*!
    * \brief Poruszanie wskazanym dronem
    * \param length Długość przesunięcia
    * \param angle Kąt przesunięcia
    * \param X Indeks drona
    */
    void MoveDrone(double length, double angle, int X);
    /*!
    * \brief Obrót wskazanym dronem
    * \param angle Kąt obrotu
    * \param X Indeks drona
    */
    void RotateDrone(double angle, int X);
    /*!
    * \brief Rysowanie wszystkich obiektów z listy przeszkód
    */
    void Draw();
    /*!
    * \brief Zmiana prędkości poruszania się dronów
    * \param speed Prędkość na jaką chcemy zmienić
    */
    void ChangeSpeed(int speed);
    
};


#endif