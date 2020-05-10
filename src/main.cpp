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
    std::ifstream plik;
    plik.open("plik_dane.txt", std::fstream::out);
    MatrixRot Mac;
    Vector3D Vec, Vec2[8];
    for(int i=0; i<8; i++)
        plik >> Vec2[i];
    plik.close();
    std::shared_ptr<drawNS::APIGnuPlot3D> g = std::make_shared<drawNS::APIGnuPlot3D>(100,-100,100,-100,100,-100,-1);
    Rectangle A (Vec2, Vec, Mac, g);
    A.draw();
    wait4key();
    A.move(100,45);
    wait4key();
    A.rotate(45);
    wait4key();
    //A.draw();
    //wait4key();
    return 0;
}