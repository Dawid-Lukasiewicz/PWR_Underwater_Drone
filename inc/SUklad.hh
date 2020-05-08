#ifndef SUKLAD_HH
#define SUKLAD_HH

#include "SMacierz.hh"
template<class T, int SIZE>
class SUklad
{
    SWektor<T,SIZE> Wek;
    SMacierz<T,SIZE> Mac;

    public:

    SUklad ();                                                          //Kontruktor bezparametryczny
    SUklad (const SMacierz<T,SIZE> & M1, const SWektor<T,SIZE> & W1);   //Konstruktor przyjmujący jako argument wektor i macierz
    ~SUklad ();                                                         //Destruktor
    SWektor<T,SIZE> & GetVector();                                      //Pobranie wektora
    SMacierz<T,SIZE> & GetMatrix();                                     //Pobranie macierzy
    SWektor<T,SIZE> Solve() const;                                      //Rozwiązanie układu równań
};

template<class T, int SIZE>
std::istream& operator >> (std::istream&Strm, 
                        SUklad<T,SIZE> &UklRown);

template<class T, int SIZE>
std::ostream& operator << (std::ostream    &Strm,
                            SUklad<T,SIZE> &UklRown);
#endif