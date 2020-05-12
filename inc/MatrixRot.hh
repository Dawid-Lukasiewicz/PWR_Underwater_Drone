#ifndef MATRIXROT
#define MATRIXROT

#include"SMacierz.hh"

class MatrixRot :public SMacierz<double,ROZMIAR>
{
public:
    MatrixRot();
    MatrixRot(double angle);
    MatrixRot(const SMacierz<double,ROZMIAR> & nowa);
    ~MatrixRot();
    
};
#endif