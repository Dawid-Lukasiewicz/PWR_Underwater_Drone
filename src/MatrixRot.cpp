#include"MatrixRot.hh"

MatrixRot::MatrixRot()
{
    Wek[0][0]=1.0;      Wek[0][1]=0.0;       Wek[0][2]=0.0;
    Wek[1][0]=0.0;      Wek[1][1]=1.0;       Wek[1][2]=0.0;
    Wek[2][0]=0.0;      Wek[2][1]=0.0;       Wek[2][2]=1.0;
}

MatrixRot::MatrixRot(double angle)
{  
    
    if(angle==0||angle==360||angle==-360)
    {
        Wek[0][0]=1.0; Wek[0][1]=0.0; Wek[0][2]=0.0;
        Wek[1][0]=0.0; Wek[1][1]=1.0; Wek[1][2]=0.0;
        Wek[2][0]=0.0; Wek[2][1]=0.0; Wek[2][2]=1.0;
    }
    else if(angle==90)
    {
        Wek[0][0]=0.0; Wek[0][1]=-1.0; Wek[0][2]=0.0;
        Wek[1][0]=1.0; Wek[1][1]=0.0;  Wek[1][2]=0.0;
        Wek[2][0]=0.0; Wek[2][1]=0.0;  Wek[2][2]=1.0;
    }
    else if(angle==-90)
    {
        Wek[0][0]=0.0; Wek[0][1]=1.0; Wek[0][2]=0.0;
        Wek[1][0]=-1.0; Wek[1][1]=0.0;  Wek[1][2]=0.0;
        Wek[2][0]=0.0; Wek[2][1]=0.0;  Wek[2][2]=1.0;
    }
    else if(angle==180)
    {
        Wek[0][0]=-1.0;Wek[0][1]=0.0;  Wek[0][2]=0.0;
        Wek[1][0]=0.0; Wek[1][1]=-1.0; Wek[1][2]=0.0;
        Wek[2][0]=0.0; Wek[2][1]=0.0;  Wek[2][2]=1.0;
    }
    else if(angle==270)
    {
        Wek[0][0]=0.0;Wek[0][1]=1.0;  Wek[0][2]=0.0;
        Wek[1][0]=-1.0; Wek[1][1]=0.0; Wek[1][2]=0.0;
        Wek[2][0]=0.0; Wek[2][1]=0.0;  Wek[2][2]=1.0;
    }
    else
    {
        double pi=3.14, rad=pi*angle/180;
        Wek[0][0]=cos(rad); Wek[0][1]=-sin(rad); Wek[0][2]=0.0;
        Wek[1][0]=sin(rad); Wek[1][1]=cos(rad);  Wek[1][2]=0.0;
        Wek[2][0]=0.0;      Wek[2][1]=0.0;       Wek[2][2]=1.0;
    }
    

}

MatrixRot::MatrixRot(const SMacierz<double,ROZMIAR> & nowa)
{
    if(abs(nowa.Wyznacznik_Gaussa())<E&&nowa.transponowanie()*nowa==nowa*nowa.transponowanie())
    {
        std::cerr<<"Nie jest to macierz obrotu"<<std::endl;
        exit(1);
    }
    for(int i=0; i<ROZMIAR; i++)
        Wek[i]=nowa[i];
}

MatrixRot::~MatrixRot()
{
}