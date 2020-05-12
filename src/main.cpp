#include <iostream>
#include <fstream>
#include "SWektor.hh"
#include "SMacierz.hh"
#include "Rectangle.hh"
#include "Drone.hh"
 
using namespace std;
using Vector3D = SWektor<double,ROZMIAR>;

void wait4key() {
  do {
    std::cout << "\n Press m key to continue..." << std::endl;
  } while(std::cin.get() != 'm');
}

int main()
{   
  double angle, length;
    std::ifstream plik;
    plik.open("plik_dane.txt", std::fstream::out);
    MatrixRot Mac;
    Vector3D Vec, Vec2[8];
    for(int i=0; i<8; i++)
        plik >> Vec2[i];
    plik.close();
    std::shared_ptr<drawNS::APIGnuPlot3D> g = std::make_shared<drawNS::APIGnuPlot3D>(80,-80,80,-80,80,-80,-1);
    Drone Drone1 (Vec2, Vec, Mac, g);
    Drone1.draw();
    char znak;
    do{
      cout<<endl;
      cout<<"W - Do przodu pod kątem"<<endl;
      cout<<"w - Do przodu"<<endl;
      cout<<"s - Do tyłu"<<endl;
      cout<<"a - W lewo"<<endl;
      cout<<"d - W prawo"<<endl;
      cout<<"r - Do góry"<<endl;
      cout<<"f - W dół"<<endl;
      cout<<"q - Wyjście"<<endl;
      cout<<"z - Obrót"<<endl;
      //cin.ignore(1000,'/n');
      cin>>znak;
      switch (znak)
      {
      case 'w':
        cout<<"Długość przesunięcia: ";
        cin>>length;
        Drone1.move_forward(length);
        break;
      
      case 's':
        cout<<"Długość przesunięcia: ";
        cin>>length;
        Drone1.move_back(length);
        break;

      case 'a':
        cout<<"Długość przesunięcia: ";
        cin>>length;
        Drone1.move_left(length);
        break;
      
      case 'd':
        cout<<"Długość przesunięcia: ";
        cin>>length;
        Drone1.move_back(length);
        break;

      case 'W':
        cout<<"Długość przesunięcia i kątX: ";
        cin>>length>>angle;
        Drone1.moveUpDown(length,angle);
        break;

      case 'r':
        cout<<"Długość w górę: ";
        cin>>length;
        Drone1.moveUpDown(length,90);
        break;

      case 'f':
        cout<<"Długość w dół: ";
        cin>>length;
        Drone1.moveUpDown(length,-90);
        break;

      case 'z':
        cout<<"Obrót: ";
        cin>>angle;
        Drone1.rotate(angle);
        break;

      case 'q':
        break;

      default:
        cout<<"Nie wybrano opcji"<<endl;
        break;
      }
    }
      while(znak!='q');
    return 0;
}