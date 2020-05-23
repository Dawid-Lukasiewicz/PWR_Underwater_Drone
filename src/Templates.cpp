#ifndef TEMPLATE
#define TEMPLATE
#include "SWektor.cpp"
#include "SMacierz.cpp"
#include "SUklad.cpp"
#include "LZespolona.hh"

//Specjalizacje

template<>
const drawNS::Point3D SWektor<Zespolona,ROZMIAR>::P3D()const
{
    drawNS::Point3D point(dane[0].GetRe(),dane[1].GetRe(),dane[2].GetRe());
    return point;
}

template<>
double SWektor<Zespolona, ROZMIAR>::dlugosc()const
{
  double suma=0;
  for(int i=0; i<Wymiar; i++)
  {
    suma+=pow(dane[i].modul(),2);
  }
  return sqrt(suma);
}

//Układ równań
template class SUklad<Zespolona, ROZMIAR>;
template class SUklad<double, ROZMIAR>;
template std::istream& operator >> (std::istream &Strm, 
                        SUklad<Zespolona,ROZMIAR>  &UklRown);
template std::istream& operator >> (std::istream &Strm, 
                        SUklad<double,ROZMIAR>  &UklRown);
template std::ostream& operator << (std::ostream      &Strm,
                         SUklad<Zespolona,ROZMIAR> &UklRown);
template std::ostream& operator << (std::ostream      &Strm,
                        SUklad<double,ROZMIAR> &UklRown);
//Macierze
template class SMacierz<Zespolona, ROZMIAR>;
template class SMacierz<double, ROZMIAR>;
template std::istream& operator >> (std::istream &Strm, SMacierz<double, ROZMIAR> &Mac);
template std::ostream& operator << (std::ostream &Strm, const SMacierz<double, ROZMIAR> &Mac);
template std::istream& operator >> (std::istream &Strm, SMacierz<Zespolona, ROZMIAR> &Mac);
template std::ostream& operator << (std::ostream &Strm, const SMacierz<Zespolona, ROZMIAR> &Mac);
//Wektor
template class SWektor<Zespolona,ROZMIAR>;
template class SWektor<double,ROZMIAR>;
template std::istream& operator >> (std::istream &Strm, SWektor<Zespolona,ROZMIAR> &Wek);
template std::istream& operator >> (std::istream &Strm, SWektor<double,ROZMIAR> &Wek);
template std::ostream& operator << (std::ostream &Strm, const SWektor<Zespolona,ROZMIAR> &Wek);
template std::ostream& operator << (std::ostream &Strm, const SWektor<double,ROZMIAR> &Wek);

#endif