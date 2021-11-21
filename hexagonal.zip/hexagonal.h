#ifndef HEXAGONAL_H
#define HEXAGONAL_H
#include <iostream>
#include <cmath>
using namespace std;

class hexagonal
{
  public:
  hexagonal(float = 0.0, float = 0.0);
  hexagonal(const hexagonal &);
  void setlado(float);
  void setaltura(float);
  float getlado() const;
  float getaltura() const;
  float apotemaBase() const;
  float apotema() const;
  float areaBase() const;
  float areaTrianguloLateral() const;
  float areaLateral() const;
  float areaTotal() const;
  float volumen() const;
  void imprime() const;
  private:
  float altura;
  float lado;
};

#endif