#include"SWektor.hh"

#ifndef VECTOR.HH
#define VECTOR.HH

class Vector :public SWektor<double, ROZMIAR>
{
    public:
    explicit Vector(SWektor<double,ROZMIAR> &Vec);
};

#endif