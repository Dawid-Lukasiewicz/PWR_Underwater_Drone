#include "Rectangle.hh"
#include "SWektor.hh"
#include "SMacierz.hh"
#include <iostream>
#include <fstream>
 
using namespace std;
using Vector3D = SWektor<double,ROZMIAR>;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != 'm');
}

int main()
{
    cout<<"Here i am1"<<endl;
    Matrix3D Mac;
    Vector3D Vec, Vec2[8];
    for(int i=0; i<8; i++)
    {
        cin >> Vec2[i];
    }
    cout<<"Here i am2"<<endl;
    std::shared_ptr<drawNS::APIGnuPlot3D> g = std::make_shared<drawNS::APIGnuPlot3D>(100,-100,100,-100,100,-100,-1);
    Rectangle A (Vec2, Vec, Mac, g);
    cout<<"Here i am3"<<endl;
    A.draw();
    cout<<"Here i am4"<<endl;
    wait4key();
    return 0;
}