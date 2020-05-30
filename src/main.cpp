#include <iostream>
#include <fstream>
#include "SWektor.hh"
#include "SMacierz.hh"
#include "Rectangle.hh"
#include "Drone.hh"
#include "Rotator.hh"
#include "Surface.hh"
#include "Box.hh"
#include "Scene.hh"

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
    double dRotatorVec[3];
    std::ifstream plik;
    MatrixRot MacObrotu;
    Vector3D VecNodes[8], VecInSwitch;

    plik.open("plik_body.txt", std::fstream::out);
    for(int i=0; i<8; i++)
        plik >> VecNodes[i];
    plik.close();

    plik.open("plik_rotators.txt", std::fstream::out);
    for(int i=0; i<3; i++)
        plik >> dRotatorVec[i];
    plik.close();
    Vector3D RotatorVec(dRotatorVec);
    

    std::shared_ptr<drawNS::APIGnuPlot3D> g = std::make_shared<drawNS::APIGnuPlot3D>(100,-100,100,-100,100,-100,-1);
    /*Inicjalizacja wriników*/
    double dDron2[3]={60,20,0}, dDron3[3]={-70,65,0};
    Vector3D CenterVec1, CenterVec2(dDron2),CenterVec3(dDron3);
    std::shared_ptr<Rotator> Rotator1 = std::make_shared<Rotator>(RotatorVec,CenterVec1,MacObrotu,g,"green");
    std::shared_ptr<Rotator> Rotator2 = std::make_shared<Rotator>(RotatorVec,CenterVec2,MacObrotu,g,"red");
    std::shared_ptr<Rotator> Rotator3 = std::make_shared<Rotator>(RotatorVec,CenterVec3,MacObrotu,g,"purple");

    /*Inicjalizacja powierzchni*/
    double TabSurf[3]={-100,-100,100};
    Vector3D Surftab1(TabSurf);
    TabSurf[2]=-100;
    Vector3D Surftab2(TabSurf);

    /*Inicjalizacja przeszkód/pudełek*/
    double BoxVec[3]={80,60,50};
    Vector3D BoxCenter1(BoxVec);
    BoxVec[0]=-70;
    BoxVec[1]=0;
    Vector3D BoxCenter2(BoxVec);
    //Box Box1(VecNodes,BoxCenter,MacObrotu,g,"yellow");

    /*Inicjalizacja Drona*/
    vector<shared_ptr<Drone>>DroneVector
    {
      make_shared<Drone>(Rotator1,VecNodes,CenterVec1,MacObrotu,g,"green"),
      make_shared<Drone>(Rotator2,VecNodes,CenterVec2,MacObrotu,g,"red"),
      make_shared<Drone>(Rotator3,VecNodes,CenterVec3,MacObrotu,g,"purple")
    };
    vector<shared_ptr<Box>>BoxesVector
    {
      make_shared<Box>(VecNodes,BoxCenter1,MacObrotu,g,"yellow"),
      make_shared<Box>(VecNodes,BoxCenter2,MacObrotu,g,"yellow")
    };
    vector<shared_ptr<Surface>>SurfaceVector
    {
      make_shared<Surface>(g,Surftab1,"black"),
      make_shared<Surface>(g,Surftab2,"blue")
    };
    
    /*Konieci inicjalizacji*/
    //Drone1.draw();
    //Drone2.draw();
    Scene MainScene(DroneVector,BoxesVector,SurfaceVector);
    MainScene.Draw();
    char znak;
    int X;
    cout<<"Wybierz drona"<<endl;
    cout<<"0 - zielony"<<endl;
    cout<<"1 - czerwony"<<endl;
    cout<<"2 - fioletowy"<<endl;
    cin>>X;
    do{
      /*cout<<"w - Do przodu"<<endl;
      cout<<"s - Do tyłu"<<endl;
      cout<<"a - W lewo"<<endl;
      cout<<"d - W prawo"<<endl;
      cout<<"r - Do góry"<<endl;
      cout<<"f - W dół"<<endl;
      cout<<"h - Teleportacja"<<endl;*/
      cout<<endl;
      cout<<"W - Do przodu pod kątem"<<endl;
      cout<<"z - Obrót"<<endl;
      cout<<"p - Zmiana drona"<<endl;
      cout<<"q - Wyjście"<<endl;

      cin>>znak;
      switch (znak)
      {
        /*
      case 'w':
        cout<<"Długość przesunięcia: ";
        cin>>length;
        Drone1.Drone::move(length);
        break;
      
      case 's':
        cout<<"Długość przesunięcia: ";
        cin>>length;
        Drone1.Drone::rotate(180);
        Drone1.Drone::move(length);
        break;

      case 'a':
        cout<<"Długość przesunięcia: ";
        cin>>length;
        Drone1.Drone::rotate(-90);
        Drone1.Drone::move(length);
        break;
      
      case 'd':
        cout<<"Długość przesunięcia: ";
        cin>>length;
        Drone1.Drone::rotate(90);
        Drone1.Drone::move(length);
        break;

      case 'W':
        cout<<"Długość przesunięcia i kątX: ";
        cin>>length>>angle;
        Drone1.Drone::moveUpDown(length,angle);
        break;

      case 'r':
        cout<<"Długość w górę: ";
        cin>>length;
        Drone1.Drone::moveUpDown(length,90.0);
        break;

      case 'f':
        cout<<"Długość w dół: ";
        cin>>length;
        Drone1.Drone::moveUpDown(length,-90.0);
        break;

      case 'z':
        cout<<"Obrót: ";
        cin>>angle;
        Drone1.Drone::rotate(angle);
        break;

      case 'h':
        cout<<"Teleportacja na koordynaty: ";
        cin>>VecInSwitch;
        Drone1.Drone::move_to(VecInSwitch);
        break;
        */
      case 'W':
        cout<<"Długość przesunięcia i kątX: ";
        cin>>length>>angle;
        MainScene.MoveDrone(length,angle,X);
        break;

      case 'z':
        cout<<"Obrót: ";
        cin>>angle;
        MainScene.RotateDrone(angle,X);
        break;

      case 'p':
        cout<<"Wybierz drona"<<endl;
        cout<<"0 - zielony"<<endl;
        cout<<"1 - czerwony"<<endl;
        cout<<"2 - fioletowy"<<endl;
        cin>>X;
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