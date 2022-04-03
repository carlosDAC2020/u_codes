#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include "empleado.h"

class administrativo: public empleado 
{
    friend istream &operator>>(istream &, administrativo &);
  public:
    void PonCargo (int);
    long boni_cargo() const;
    virtual void imprimir() const;
    virtual long neto() const;
  private:
    int cargo;
};

#endif