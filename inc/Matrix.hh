#include"SMacierz.hh"

class Matrix :public SMacierz<double,ROZMIAR>
{
    public:
    explicit Matrix(SMacierz<double,ROZMIAR> & Mat);
};