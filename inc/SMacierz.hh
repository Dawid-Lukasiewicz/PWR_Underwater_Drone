#ifndef SMACIERZ_HH
#define SMACIERZ_HH

#include "SWektor.hh"
#include "LZespolona.hh"

template <class T, int SIZE>
class SMacierz
{
    int Rozmiar = ROZMIAR;
    SWektor<T, SIZE> Wek[SIZE];

    public:

    SMacierz();                                                     //Konstruktor bezparametryczny
    SMacierz(SWektor<T, SIZE> *tab);                                //Kontruktor przyjmujący tablicę wektorów jako argument
    ~SMacierz();                                                    //Destruktor
    SMacierz operator + (const SMacierz & M)const;                  //Dodawanie macierzy
    SMacierz operator -(const SMacierz & M)const;                   //Odejmowanie macierzy
	SMacierz operator *(const SMacierz & M)const;                   //Mnożenie macierzy
    SMacierz operator *(const T & M)const;                          //Macierz pomnożona przez liczbę
    SWektor<T, SIZE> operator *(const SWektor<T, SIZE> & W)const;   //Mnożenie macierzy prze wektor
	SMacierz transponowanie()const;                                 //Zwraca macierz transponowaną                                    ///
    T Wyznacznik_Gaussa() const;                                    //Zwraca wyznacznik
    const SWektor<T, SIZE> & operator[] (int indeks) const;         //Odnoszenie się do poszczególnych pól
	SWektor<T, SIZE> & operator[] (int indeks);                     //Możliwość wpisania danych do konkretnego pola
    int Pobierz_Wiersz()const;                                      //Pobranie rozmiaru macierzy
    const SWektor<T, SIZE> Pobierz_Wektor(int indeks)const;         //Zwraca wskazany wektor
};
template<class T, int SIZE>
std::istream& operator >> (std::istream &Strm, SMacierz<T, SIZE> &Mac); //Wpisywanie

template<class T, int SIZE>
std::ostream& operator << (std::ostream &Strm, const SMacierz<T, SIZE> &Mac); //Odczyt
#endif