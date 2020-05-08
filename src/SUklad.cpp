#include "SUklad.hh"

template<class T, int SIZE>
SUklad<T,SIZE>::SUklad ()
{
    Wek = SWektor<T,SIZE>();
    Mac = SMacierz<T,SIZE>();
}

template<class T, int SIZE>
SUklad<T,SIZE>::SUklad (const SMacierz<T,SIZE> & M1, const SWektor<T,SIZE> & W1)
{
    Wek = W1;
    Mac = M1;
}

template<class T, int SIZE>
SUklad<T,SIZE>::~SUklad ()
{}

template<class T, int SIZE>
SWektor<T,SIZE> & SUklad<T,SIZE>::GetVector()
{
    return Wek;
}

template<class T, int SIZE>
SMacierz<T,SIZE> & SUklad<T,SIZE>::GetMatrix()
{
    return Mac;
}

template<class T, int SIZE>
SWektor<T,SIZE> SUklad<T,SIZE>::Solve() const
{
    T stala;
    stala=1;
    SMacierz<T,SIZE> kopiaM = Mac;
    SWektor<T,SIZE> kopiaW = Wek;
    for(int i=0; i<kopiaM.Pobierz_Wiersz(); i++)//Zerowanie macierzy poniżej przekątnej
    {
        if(kopiaM[i][i]<E)
        {
            int j;
            for(j=i; j<kopiaM.Pobierz_Wiersz(); j++)
            {

                if(kopiaM[j][i]>E)
                {
                    SWektor<T,SIZE> Pom = kopiaM[i]; 
                    T liczba = kopiaW[i];
                    kopiaM[i] = kopiaM[j];
                    kopiaW[i] = kopiaW[j];
                    kopiaM[j] = Pom;
                    kopiaW[j] = liczba;
                    break;
                }
            }
            if(j == kopiaM.Pobierz_Wiersz())
                {
                    std::cerr << "Wyznacznik macierzy rowny zero" << std::endl;
                    exit(1);
                }
        }
        for(int j=i+1; j<kopiaM.Pobierz_Wiersz(); j++)
        {
            if(kopiaM[j][i] < E)
                continue;
            T wielokrotnosc = kopiaM[j][i]/kopiaM[i][i];
            kopiaM[j] -= kopiaM[i] * wielokrotnosc;
            kopiaW[j] -= kopiaW[i] * wielokrotnosc;
        }
    }
    for(int i = kopiaM.Pobierz_Wiersz()-1; i>=0; i--)//Zerowanie macierzy powyżej przekątnej
    {
        for(int j=i-1; j>=0; j--)
        {
            if(kopiaM[j][i]<E)
                continue;
            T wielokrotnosc = kopiaM[j][i]/kopiaM[i][i];
            kopiaM[j] -= kopiaM[i] * wielokrotnosc;
            kopiaW[j] -= kopiaW[i] * wielokrotnosc;
        }
    }
    for(int i=0; i<kopiaM.Pobierz_Wiersz(); i++)//Zerowanie przekątnej
    {
        T wielokrotnosc = stala/kopiaM[i][i];
        kopiaM[i][i] = kopiaM[i][i] * wielokrotnosc;
        kopiaW[i] = kopiaW[i] * wielokrotnosc;
    }
    return kopiaW;
}
template<class T, int SIZE>
std::istream& operator >> (std::istream &Strm, 
                        SUklad<T,SIZE>  &UklRown)
{
    if(UklRown.GetMatrix().Pobierz_Wiersz() == UklRown.GetVector().Pobierz_Wymiar())
    {
        Strm >> UklRown.GetVector();
        Strm >> UklRown.GetMatrix();
        return Strm;
    }
    else
    {
        std::cerr << "Niezgodne rozmiary" << std::endl;
        exit(1);
    }
}

template<class T, int SIZE>
std::ostream& operator << (std::ostream    &Strm,
                            SUklad<T,SIZE> &UklRown)
{
    int modulo = 0;
    if(UklRown.GetMatrix().Pobierz_Wiersz()%2 == 1)
        modulo = UklRown.GetMatrix().Pobierz_Wiersz()/2 + 1;
    else
        modulo = UklRown.GetMatrix().Pobierz_Wiersz()/2;
    for(int i=0; i<UklRown.GetMatrix().Pobierz_Wiersz(); i++)
    {
        if(i+1 != modulo)
        {
            Strm << std::setw(5) << UklRown.GetMatrix()[i] << " |X" << i+1 << "|" 
            << "   " << "|" << UklRown.GetVector()[i] << "|"
            << std::endl;
        }
        else
        {
            Strm << std::setw(5) << UklRown.GetMatrix()[i] << " |X" << i+1 << "|" 
            << " = " << "|" << UklRown.GetVector()[i] << "|"
            << std::endl;
        }

    }
    return Strm; 
}