#include"MatrixRot.hh"

MatrixRot::MatrixRot()
{
    Wek[0][0]=cos(0.0); Wek[0][1]=-sin(0.0); Wek[0][2]=0.0;
    Wek[1][0]=sin(0.0); Wek[1][1]=cos(0.0); Wek[1][2]=0.0;
    Wek[2][0]=0.0;      Wek[2][1]=0.0;      Wek[2][2]=1.0;
}

MatrixRot::MatrixRot(const SMacierz<double,ROZMIAR> & nowa)
{
    if(abs(nowa.Wyznacznik_Gaussa())<E)
    {
        std::cerr<<"Nie jest to macierz obrotu"<<std::endl;
        exit(1);
    }
    for(int i=0; i<ROZMIAR; i++)
        Wek[0]=nowa[0];
}

MatrixRot::~MatrixRot()
{
}