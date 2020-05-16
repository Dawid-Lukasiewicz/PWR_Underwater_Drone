#include <iostream>
#include <fstream>
#include "SWektor.hh"
#include "SMacierz.hh"
#include "Rectangle.hh"
#include "Drone.hh"
#include "Rotator.hh"
 
using namespace std;
using Vector3D = SWektor<double,ROZMIAR>;

void wait4key() {
  do {
    std::cout << "\n Press m key to continue..." << std::endl;
  } while(std::cin.get() != 'm');
}

int main()
{   
    double angle, length,tab[3]={15,0,0};
    std::ifstream plik;
    MatrixRot Mac;
    Vector3D Vec, Vec2[8],Vec4(tab);

    plik.open("plik_body.txt", std::fstream::out);
    for(int i=0; i<8; i++)
        plik >> Vec2[i];
    plik.close();

    double dVec3[3];

    plik.open("plik_rotators.txt", std::fstream::out);
    for(int i=0; i<3; i++)
        plik >> dVec3[i];
    plik.close();
    
    Vector3D Vec3(dVec3);
    
    std::shared_ptr<drawNS::APIGnuPlot3D> g = std::make_shared<drawNS::APIGnuPlot3D>(80,-80,80,-80,80,-80,-1);
    std::shared_ptr<Rotator> Rotator1 = std::make_shared<Rotator>(dVec3,Vec,Mac,g);

    //SixPrism y(Vec3,Vec4,Mac,g);
    //SixPrism Prism(Vec3, Vec, Mac, g);
    Drone Drone1 (Rotator1,Vec2, Vec, Mac, g);
    
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
        Drone1.moveUpDown(length,90.0);
        break;

      case 'f':
        cout<<"Długość w dół: ";
        cin>>length;
        Drone1.moveUpDown(length,-90.0);
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