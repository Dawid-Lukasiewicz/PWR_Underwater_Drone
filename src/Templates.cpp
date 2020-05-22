#ifndef TEMPLATE
#define TEMPLATE
#include "SWektor.cpp"
#include "SMacierz.cpp"
#include "SUklad.cpp"
#include "LZespolona.hh"

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