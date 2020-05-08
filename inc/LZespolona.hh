#ifndef ZESPOLONA_HH
#define ZESPOLONA_HH
#define E 0.0000001
#include<iostream>
#include<cmath>

class  Zespolona {
  double   Re;    
  double   Im;    

public:
Zespolona(); //Konstruktor bez parametryczny
Zespolona (double Re, double Im); //Konstruktor dwu-parametryczny
const double & GetRe()const;
const double & GetIm()const;
double & SetRe();
double & SetIm();
//Zespolona abs();
Zespolona  operator + (const Zespolona & Skl1)const;
Zespolona  operator += (const Zespolona & Skl1);
Zespolona  operator - (const Zespolona & Skl1)const;
Zespolona  operator -= (const Zespolona & Skl1);
Zespolona  operator * (const Zespolona & Skl1)const;
Zespolona  operator *= (const Zespolona & Skl1);
Zespolona  operator * (const double & Skl1)const;
Zespolona  operator *= (const double & Skl1);
Zespolona  operator / (const Zespolona & Skl1)const;
Zespolona  operator / (const double & Skl1)const;
Zespolona  operator /= (const Zespolona & Skl1);
Zespolona operator = (const Zespolona & Skl1);
Zespolona operator = (double Skl1);
bool operator == (const Zespolona & Skl1)const;
bool operator != (const Zespolona & Skl1)const;
bool operator > (const Zespolona & Skl1)const;
bool operator >= (const Zespolona & Skl1)const;
bool operator < (const Zespolona & Skl1)const;
bool operator <= (const Zespolona & Skl1)const;
bool operator > (const double & Skl1)const;
bool operator >= (const double & Skl1)const;
bool operator < (const double & Skl1)const;
bool operator <= (const double & Skl1)const;

double modul()const;
Zespolona sprzezenie()const;

};
std::ostream & operator << (std::ostream & str, const Zespolona &out);
std::istream & operator >> (std::istream & str, Zespolona &in);

#endif
