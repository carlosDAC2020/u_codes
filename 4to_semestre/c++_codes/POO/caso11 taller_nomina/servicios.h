#ifndef SERVICIOS_H
#define SERVICIOS_H
#include "empleado.h"

class servicios: public empleado 
{
    friend istream &operator>>(istream &, servicios &);
  public:
    void PonHorasExtras (double);
    double baseHorasExtras();
    virtual void imprimir() const;
    virtual long neto() const;
  private:
    double horas_extra;
};

#endif