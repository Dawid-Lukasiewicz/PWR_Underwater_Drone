#ifndef SWEKTOR_HH
#define SWEKTOR_HH
#define E 0.0000001  
#define ROZMIAR 3

#include <cmath>
#include <iostream>
#include <iomanip>
//#include "LZespolona.hh"
#include "Draw3D_api_interface.hh"

template<class T, int SIZE>
class SWektor 
{
  int Wymiar = ROZMIAR;
  T dane[SIZE];

  public:
  
  SWektor();                                      //Kontruktor bezparametryczny
  SWektor(T *dane);                               //Kontruktor dwuparametryczny
  ~SWektor();                                     //Destruktor
  T operator *(const SWektor & W2)const;          //Iloczyn skalarny
  SWektor operator =(const T & W2);               //Przypisanie wartości pod każdą zmienną wektora
  SWektor operator +=(const SWektor & W2);        //Dodawanie wektorów do istniejącego wektora
  SWektor operator +(const SWektor & W2)const;    //Dodawanie wektorów
  SWektor operator -=(const SWektor & W2);        //Odejmowanie wektorów od istniejącego wektora
  SWektor operator -(const SWektor & W2)const;    //Odejmowanie wektorów
  SWektor operator *(const T & stala)const;       //Mnożenie wektora przez liczbę
  bool operator ==(const SWektor & W2)const;
  bool operator !=(const SWektor & W2)const;
  const T & operator[] (int indeks)const;         //Zwraca liczbę wskazaną indeksem i nie zmienia jej
  T & operator[] (int indeks);                    //Zwraca liczbę wskazaną indeksem
  int Pobierz_Wymiar() const;                     //Zwraca liczbę wymiaru/rozmiaru wektora
  const T & Pobierz_dane() const;                 //Zwraca adres na tablicę zmiennych przechowywaną przez wektor
  const drawNS::Point3D P3D()const;
};
template<class T, int SIZE>
std::istream& operator >> (std::istream &Strm, SWektor<T, SIZE> &Wek);

template<class T, int SIZE>
std::ostream& operator << (std::ostream &Strm, const SWektor<T, SIZE> &Wek);
/*
template<class T, int SIZE>
double dlugosc(SWektor<T,SIZE> & W2);
*/
#endif 