#ifndef SERVICIOS_H
#define SERVICIOS_H
#include "empleado.h"

class servicios: public empleado 
{
    friend istream &operator>>(istream &, servicios &);
    friend ostream &operator<<(ostream &, const servicios &);
    friend void imprimir_lista_servicios (int, vector<servicios> &);
    friend long nomina_total_servicios (int, vector<servicios> &);
  public:
    servicios(string = " ", string = " ", string = " ", int[] = 0, long = 0, long=0.0);
    ~servicios();
    void PonHorasExtras (long);
    long baseHorasExtras() const;
    virtual void imprimir() const;
    virtual long neto() const;
  private:
    long horas_extra;
};

#endif