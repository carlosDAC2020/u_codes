#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>
using namespace std;

class Complejo{
    friend ostream &operator<<(ostream &, const Complejo &);
    friend istream &operator>>(istream &, Complejo &);
  public:
    Complejo();
    Complejo(double, double);
    Complejo(Complejo &);
    double getreal()const;
    double getimaginario() const;
    Complejo operator+(const Complejo &) const;
    Complejo operator-(const Complejo &) const;
    Complejo operator*(const Complejo &) const;
    Complejo operator/(const Complejo &) const;
    void imprimepolar() const;
  private:
    double imaginario, real ;
};

#endif // COMPLEJO_H