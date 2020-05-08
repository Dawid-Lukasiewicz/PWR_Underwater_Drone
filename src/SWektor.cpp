#include"SWektor.hh"

template<class T, int SIZE>
SWektor<T, SIZE>::SWektor()
{
    for (int i=0; i<Wymiar; i++)
    {
        dane[i] = 0.0;
    }
}
template<class T, int SIZE>
SWektor<T, SIZE>::SWektor(T *tab)
{
    for (int i=0; i<Wymiar; i++)
    {
        dane[i] = tab[i];
    }
}

template<class T, int SIZE>
SWektor<T, SIZE>::~SWektor()
{}

template<class T, int SIZE>
T & SWektor<T, SIZE>::operator[] (int indeks)
{
    if(indeks >= 0 && indeks <= Wymiar - 1)
        return dane[indeks];
    else
    {
        std::cerr << "Indeks wykracza poza tablicę" << std::endl;
        exit(1);
    }
}

template<class T, int SIZE>
const T & SWektor<T, SIZE>::operator[] (int indeks)const
{
    if(indeks >= 0 && indeks <= Wymiar - 1)
        return dane[indeks];
    else
    {
        std::cerr << "Indeks wykracza poza tablicę" << std::endl;
        exit(1);
    }
}

template<class T, int SIZE>
SWektor<T, SIZE> SWektor<T, SIZE>::operator =(const T & W2)
{
    for (int i=0; i<Wymiar; i++)
    {
        dane[i] = W2;
    }
    return *this;
}

template<class T, int SIZE>
SWektor<T, SIZE> SWektor<T, SIZE>::operator +(const SWektor<T,SIZE> & W2) const
{
    if(W2.Wymiar == Wymiar)
    {
        T *dodaj = new T[Wymiar];

        for(int i=0; i<Wymiar; i++)
        {
            dodaj[i] = 0;
            dodaj[i] = W2[i] + dane[i]; 
        }
    return SWektor(dodaj);
    }
    else
    {
        std::cout << "Wektory o innych wymiarach" << std::endl;
        exit(1);
    }
}

template<class T, int SIZE>
SWektor<T, SIZE> SWektor<T, SIZE>::operator +=(const SWektor<T,SIZE> & W2)
{
    *this = *this + W2;
    return *this;
}

template<class T, int SIZE>
SWektor<T, SIZE> SWektor<T, SIZE>::operator -(const SWektor<T,SIZE> & W2) const
{
    if(W2.Wymiar == Wymiar)
    {
        T *odejmij = new T[Wymiar];

        for(int i=0; i<Wymiar; i++)
        {
            odejmij[i] = 0;
            odejmij[i] = dane[i] - W2[i]; 
        }
    return SWektor(odejmij);
    }
    else
    {
        std::cout << "Wektory o innych wymiarach" << std::endl;
        exit(1);
    }
}

template<class T, int SIZE>
SWektor<T, SIZE> SWektor<T, SIZE>::operator -=(const SWektor<T,SIZE> & W2)
{
    *this = *this - W2;
    return *this;
}

template<class T, int SIZE>
SWektor<T, SIZE> SWektor<T, SIZE>::operator *(const T & stala)const
{
    SWektor mnozenie;
    for(int i=0; i<Wymiar; i++)
    {
        mnozenie[i] = stala * dane[i];
    }
    return mnozenie;
}

template<class T, int SIZE>
int SWektor<T, SIZE>::Pobierz_Wymiar() const
{
    return Wymiar;
}

template<class T, int SIZE>
const T & SWektor<T, SIZE>::Pobierz_dane() const
{
    return *dane;
}

template<class T, int SIZE>
T SWektor<T, SIZE>::operator *(const SWektor & W2)const
{
    T skalar;
    skalar = 0.0;
    for (int i=0; i < Wymiar; i++)
    {
        skalar += W2[i]*dane[i];
    }
    return skalar;
}

template<class T, int SIZE>
double dlugosc(SWektor<T,SIZE> & W2)
{
    double suma=0;
    for (int i=0; i<ROZMIAR; i++)
    {
        suma += pow(W2[i],2);
    }
    return sqrt(suma);
}

template<class T, int SIZE>
std::istream& operator >> (std::istream &Strm, SWektor<T, SIZE> &Wek)
{
    
    for(int i=0; i<ROZMIAR; i++)
    {
        Strm >> Wek[i];
    }
    return Strm;
}

template<class T, int SIZE>
std::ostream& operator << (std::ostream &Strm, const SWektor<T, SIZE> &Wek)
{
    Strm << "|";
    for(int i=0; i<Wek.Pobierz_Wymiar(); i++)
    {
        if(i != Wek.Pobierz_Wymiar()-1)
            Strm << Wek[i] << " ";
        else
            Strm << Wek[i];
        
    }   
    Strm << "|";
    return Strm;
}