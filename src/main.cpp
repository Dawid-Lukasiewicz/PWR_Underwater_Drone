#include <iostream>
#include <fstream>
#include "Drone.hh"
#include "Rotator.hh"
#include "Surface.hh"
#include "Box.hh"
#include "Scene.hh"

using namespace std;
using Vector3D = SWektor<double,ROZMIAR>;
/*
void wait4key() {
  do {
    std::cout << "\n Press m key to continue..." << std::endl;
  } while(std::cin.get() != 'm');
}
*/
int main()
{   
    //Drone::Amount=0;
    double angle, length;
    int speed;
    std::shared_ptr<drawNS::APIGnuPlot3D> g = std::make_shared<drawNS::APIGnuPlot3D>(150,-150,150,-150,150,-150,-1);

    /*Inicjalizacja wriników*/
    double dDron2[3]={0,90,0}, dDron3[3]={60,-90,20};
    Vector3D CenterVec1, CenterVec2(dDron2),CenterVec3(dDron3);
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
    std::shared_ptr<Rotator> Rotator1 = std::make_shared<Rotator>(RotatorVec,CenterVec1,MacObrotu,g,"green");
    std::shared_ptr<Rotator> Rotator2 = std::make_shared<Rotator>(RotatorVec,CenterVec2,MacObrotu,g,"red");
    std::shared_ptr<Rotator> Rotator3 = std::make_shared<Rotator>(RotatorVec,CenterVec3,MacObrotu,g,"purple");

    /*Inicjalizacja powierzchni*/
    double TabSurf[3]={-150,-150,100};
    Vector3D Surftab1(TabSurf);
    TabSurf[2]=-100;
    Vector3D Surftab2(TabSurf);
    
    /*Inicjalizacja przeszkód/pudełek*/
    double BoxVec[3]={80,60,50};
    Vector3D BoxCenter1(BoxVec);
    BoxVec[0]=-85;
    BoxVec[1]=60;
    Vector3D BoxCenter2(BoxVec),BoxNodes[8];
    plik.open("Boxes_body.txt", std::fstream::out);
    for(int i=0; i<8; i++)
        plik >> BoxNodes[i];
    plik.close();
    vector<shared_ptr<Obstacle>>BoxesVector
    {
      shared_ptr<Obstacle>(new Drone(Rotator1,VecNodes,CenterVec1,MacObrotu,g,"green")),
      shared_ptr<Obstacle>(new Drone(Rotator2,VecNodes,CenterVec2,MacObrotu,g,"red")),
      shared_ptr<Obstacle>(new Drone(Rotator3,VecNodes,CenterVec3,MacObrotu,g,"purple")),
      shared_ptr<Obstacle>(new Box(BoxNodes,BoxCenter1,MacObrotu,g,"yellow")),
      shared_ptr<Obstacle>(new Box(BoxNodes,BoxCenter2,MacObrotu,g,"yellow")),
      shared_ptr<Obstacle>(new Surface(g,Surftab1,"black")),
      shared_ptr<Obstacle>(new Surface(g,Surftab2,"blue"))
    };
    plik.open("Boxes2_body.txt", std::fstream::out);
    for(int i=0; i<8; i++)
        plik >> BoxNodes[i];
    plik.close();
    BoxCenter2[0]=-70;BoxCenter2[1]=-50;BoxCenter2[2]=50;
    BoxesVector.push_back(make_shared<Box>(BoxNodes,BoxCenter2,MacObrotu,g,"yellow"));

    /*Inicjalizacja Drona*/
    vector<shared_ptr<Drone>>DroneVector;
    DroneVector.push_back(dynamic_pointer_cast<Drone>(BoxesVector[0]));
    DroneVector.push_back(dynamic_pointer_cast<Drone>(BoxesVector[1]));
    DroneVector.push_back(dynamic_pointer_cast<Drone>(BoxesVector[2]));

    /***********************
    Konieci inicjalizacji
    ***********************/

    Scene MainScene(DroneVector,BoxesVector);
    MainScene.Draw();
    cout<<"***************************"<<endl;
    cout<<"Ilość: "<<Vector3D::AmountVector()<<endl;
    cout<<"Całkowita ilość wektorów: "<<Vector3D::AllAmountVector()<<endl;
    cout<<"***************************"<<endl;
    char znak;
    int X;
    bool GitGut;
    cout<<"Wybierz drona"<<endl;
    cout<<"0 - zielony"<<endl;
    cout<<"1 - czerwony"<<endl;
    cout<<"2 - fioletowy"<<endl;
    do
    {
      cin>>X;
      if((X!=0&&X!=1&&X!=2)||cin.fail()==1)
      {
        GitGut=true;
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Zły numer drona"<<endl;
      }
      else
      {
        GitGut=false;
      }
      
    }
      while(GitGut);
    do{
      cout<<"***************************"<<endl;
      cout<<"Ilość wektorów: "<<Vector3D::AmountVector()<<endl;
      cout<<"Całkowita ilość wektorów: "<<Vector3D::AllAmountVector()<<endl;
      //cout<<"Ilość dronów: "<<Drone::GetAmount()<<endl;
      cout<<"***************************"<<endl;
      cout<<"W - Do przodu pod kątem"<<endl;
      cout<<"w,a,s,d - Obrót i do przodu"<<endl;
      cout<<"z - Obrót w osi Z"<<endl;
      cout<<"y - Obrót w osi Y"<<endl;
      cout<<"x - Obrót w osi Y"<<endl;
      cout<<"p - Zmiana drona"<<endl;
      cout<<"q - Wyjście"<<endl;
      cout<<"t - Zmiana częstotliwości rysowania"<<endl;
      cout<<endl;

      cin>>znak;
      switch (znak)
      {
      case 'W':
        cout<<"Długość przesunięcia i kątX: ";
        cin>>length>>angle;
        MainScene.MoveDroneUpDown(length,angle,X);
        break;

      case 'w':
        cout<<"Długość przesunięcia: ";
        cin>>length;
        MainScene.MoveDrone(length,X);
        break;
      
      case 's':
        cout<<"Długość przesunięcia: ";
        cin>>length;
        MainScene.RotateDrone(180,X,'z');
        MainScene.MoveDrone(length,X);
        break;

      case 'a':
        cout<<"Długość przesunięcia: ";
        cin>>length;
        MainScene.RotateDrone(-90,X,'z');
        MainScene.MoveDrone(length,X);
        break;
      
      case 'd':
        cout<<"Długość przesunięcia: ";
        cin>>length;
        MainScene.RotateDrone(90,X,'z');
        MainScene.MoveDrone(length,X);
        break;

      case 'z':
        cout<<"Obrót: ";
        cin>>angle;
        MainScene.RotateDrone(angle,X,'z');
        break;

      case 'y':
        cout<<"Obrót: ";
        cin>>angle;
        MainScene.RotateDrone(angle,X,'y');
        break;

      case 'x':
        cout<<"Obrót: ";
        cin>>angle;
        MainScene.RotateDrone(angle,X,'x');
        break;

      case 'p':
        cout<<"Wybierz drona"<<endl;
        cout<<"0 - zielony"<<endl;
        cout<<"1 - czerwony"<<endl;
        cout<<"2 - fioletowy"<<endl;
        do
        {
          cin>>X;
          if((X!=0&&X!=1&&X!=2)||cin.fail()==1)
          {
            GitGut=true;
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Zły numer drona"<<endl;
          }
          else
          {
            GitGut=false;
          }
        }while(GitGut);
        break;

      case 't':
        cout<<"Podaj ilość klatek (OPTYMALNA WARTOŚĆ 100): ";
        cin>>speed;
        MainScene.ChangeSpeed(speed);
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