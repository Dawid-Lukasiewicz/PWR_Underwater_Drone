#include"SMacierz.hh"

template<class T, int SIZE>
SMacierz<T, SIZE>::SMacierz()
{
    for (int i=0; i<Rozmiar; i++)
    {
        Wek[i] = SWektor<T, SIZE>();
    }
}

template<class T, int SIZE>
SMacierz<T, SIZE>::SMacierz(SWektor<T, SIZE> *Nowy)
{
    for (int i=0; i<Rozmiar; i++)
    {
        Wek[i] = Nowy[i];
    }
}

template<class T, int SIZE>
SMacierz<T, SIZE>::~SMacierz()
{}

template<class T, int SIZE>
const SWektor<T, SIZE> & SMacierz<T, SIZE>::operator[] (int indeks)const
{
    if(indeks>=0 && indeks<=Rozmiar)
        return Wek[indeks];
    else
    {
        std::cerr << "Indeks wykracza poza tablicę" << std::endl;
        exit(1);
    }
}

template<class T, int SIZE>
SWektor<T, SIZE> & SMacierz<T, SIZE>::operator[] (int indeks)
{
    if(indeks>=0 && indeks<=Rozmiar)
        return Wek[indeks];
    else
    {
        std::cerr << "Indeks wykracza poza tablicę" << std::endl;
        exit(1);
    }
}

template<class T, int SIZE>
SMacierz<T, SIZE> SMacierz<T, SIZE>::operator + (const SMacierz<T, SIZE> & M)const
{
    if(Rozmiar == M.Rozmiar && 
    Wek[0].Pobierz_Wymiar() == M[0].Pobierz_Wymiar())
    {
        SMacierz<T, SIZE> dodaj;
        for(int i=0; i<Rozmiar; i++)
        {
            dodaj[i] = Wek[i] + M[i];    
        }
        return dodaj;
    }
    else
    {
        std::cout << "Macierze różnych rozmiarów" << std::endl;
        exit(1);
    }
}

template<class T, int SIZE>
SMacierz<T, SIZE> SMacierz<T, SIZE>::operator - (const SMacierz<T, SIZE> & M)const
{
    if(Rozmiar == M.Rozmiar && 
    Wek[0].Pobierz_Wymiar() == M[0].Pobierz_Wymiar())
    {
        SMacierz<T, SIZE> odejmij;
        for(int i=0; i<Rozmiar; i++)
        {
            odejmij[i] = Wek[i] - M[i];    
        }
        return odejmij;
    }
    else
    {
        std::cout << "Macierze różnych rozmiarów" << std::endl;
        exit(1);
    }
}

template<class T, int SIZE>
SMacierz<T, SIZE> SMacierz<T, SIZE>::operator *(const SMacierz<T, SIZE> & M)const
{
    SMacierz<T, SIZE> mnozenie;
    if(Wek[0].Pobierz_Wymiar() == M.Rozmiar)
    {
        for(int i=0; i<M.Rozmiar; i++)
        {
            for(int j=0; j<M[0].Pobierz_Wymiar(); j++)
            {
                mnozenie[i][j] = Wek[i] * M.Pobierz_Wektor(j);
            }
        }
        return mnozenie;
    }
    else
    {
        std::cerr << "Niezgodne wymiary macierzy" << std::endl;
        exit(1);
    }
}

template<class T, int SIZE>
SMacierz<T,SIZE> SMacierz<T,SIZE>::operator *(const T & M)const
{
    SMacierz<T,SIZE> mnozenie;
    for(int i=0; i<Rozmiar; i++)
    {
        mnozenie[i] = Wek[i]*M;
    }
    return mnozenie;
}

template<class T, int SIZE>
SWektor<T, SIZE> SMacierz<T, SIZE>::operator *(const SWektor<T, SIZE> & W)const
{
    if(Rozmiar == W.Pobierz_Wymiar())
    {
        SWektor<T, SIZE> mnozenie;
        for(int i=0; i<Rozmiar; i++)
        {
            mnozenie[i] = Wek[i]*W;
        }
        return mnozenie;
    }
    else
    {
        std::cerr << "Nieprawidłowe rozmiary" << std::endl;
        exit(1);
    }
}

template<class T, int SIZE>
int SMacierz<T,SIZE>::Pobierz_Wiersz()const
{
    return Rozmiar;
}

template<class T, int SIZE>
const SWektor<T, SIZE> SMacierz<T,SIZE>::Pobierz_Wektor(int indeks)const
{
    if(indeks>=0 && indeks<=Wek[0].Pobierz_Wymiar())
        return Wek[indeks];
    else
    {
        std::cerr << "Błąd" << std::endl;
        exit(1);
    }
}

template<class T, int SIZE>
SMacierz<T,SIZE> SMacierz<T,SIZE>::transponowanie()const
{
    SMacierz<T,SIZE> transpozycja;
    for(int i=0; i<Wek[0].Pobierz_Wymiar(); i++)
    {
        transpozycja[i] = (*this).Pobierz_Wektor(i);
    }
    return transpozycja;
}

template<class T, int SIZE>
T SMacierz<T,SIZE>::Wyznacznik_Gaussa() const
{
    T det;
    det = 1;
    SMacierz<T,SIZE> M;
    M = *this;
    if(Rozmiar != Wek[0].Pobierz_Wymiar())
    {
        std::cerr << "Macierz niekwadratowa" << std::endl;
        exit(1);
    }
    else if(Rozmiar == 1)
    {
        return Wek[0][0];
    }
    else if(Rozmiar == 2)
    {
        return Wek[0][0] * Wek[1][1] - Wek[0][1] * Wek[1][0];
    }
    else
    {
        for(int i=0; i<M.Rozmiar; i++)//Przestawianie wierszy
        {
            if(M[i][i]<E)
            {
                int j;
                for(j=i; j<M.Rozmiar; j++)
                {

                    if(M[j][i]>E)
                    {
                        SWektor<T,SIZE> Pom = M[i]; 
                        M[i] = M[j];
                        M[j] = Pom;
                        det = det*-1;
                        break;
                    }
                }
                if(j == Rozmiar)//Jeśli nie ma żadnej niezerowej w kolumnie, det=0
                    {
                        det = det*0;
                        return det;
                    }
            }
            for(int j=i+1; j<M.Rozmiar; j++) //Zerowanie wierszy
            {
                if(M[i][i]<E)
                    continue;
                
                T wielokrotnosc = M[j][i]/M[i][i];
                M[j] -= M[i] * wielokrotnosc;
            }
        }
        for(int i=0; i<M.Rozmiar; i++)
            det *= M[i][i];
        return det;
    }
}

template<class T, int SIZE>
std::istream& operator >> (std::istream &Strm, SMacierz<T, SIZE> &Mac)
{
    for(int i=0; i<Mac.Pobierz_Wiersz(); i++)
    {
        //std::cout << "Wiersz: " << i+1 << std::endl;
        for(int j=0; j<Mac[i].Pobierz_Wymiar(); j++)
        {
            Strm >> Mac[i][j];
        }
    }
    return Strm;
}
template<class T, int SIZE>
std::ostream& operator << (std::ostream &Strm, const SMacierz<T, SIZE> &Mac)
{
    for(int i=0; i<Mac.Pobierz_Wiersz(); i++)
    {
        Strm << "| ";
        for(int j=0; j<Mac[0].Pobierz_Wymiar(); j++)
        {
            if(j < Mac[0].Pobierz_Wymiar() - 1)
            Strm << Mac[i][j] << " ";
            else
            Strm << Mac[i][j];
        }
        Strm << " |" << std::endl;
    }
    return Strm;
}