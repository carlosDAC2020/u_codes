#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
using namespace std;
#define Aini 1900
#define Afin 2022

void validarFecha(int F[]);
int anioBisiesto(int verificaAnio);

class empleado 
{
  friend istream &operator>>(istream &, empleado &);
  public:
    empleado(string = " ", string = " ", string = " ", int[] = 0, long = 0);
    ~empleado();
    void ponCedula(string);
    void ponNombre(string);
    void ponApellido(string);
    void ponFechaNac(int[]);
    void salarioBasico(long);
    virtual void imprimir() const;
    virtual long neto() const;
  protected:
    string cedula;
    string nombre;
    string apellido;
    int fechaN[3];
    long basico;
};

#endif