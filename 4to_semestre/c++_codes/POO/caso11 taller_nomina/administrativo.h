#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include "empleado.h"

class administrativo: public empleado 
{
    friend istream &operator>>(istream &, administrativo &);
    friend ostream &operator<<(ostream &, const administrativo &);
    friend void imprimir_lista_administrativo (int, vector<administrativo> &);
    friend long nomina_total_administrativos (int, vector<administrativo> &);
  public:
    administrativo(string = " ", string = " ", string = " ", int[] = 0, long = 0 , int=0);
    ~administrativo();
    void PonCargo (int);
    long boni_cargo() const;
    virtual void imprimir() const;
    virtual long neto() const;
  private:
    int cargo;
};

#endif