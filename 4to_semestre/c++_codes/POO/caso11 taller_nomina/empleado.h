#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <vector>
using namespace std;
#define Aini 1900
#define Afin 2022

//void validarFecha(int F[]);
//int anioBisiesto(int verificaAnio);

//string mess[] = {" ","Ene","Feb","Mar","Abr","May","Jun","Jul","Ago","Sep","Oct","Nov","Dic"};
//int dias[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class empleado 
{
  friend istream &operator>>(istream &, empleado &);
  friend ostream &operator<<(ostream &, const empleado &);
  public:
    empleado(string = " ", string = " ", string = " ", int[] = 0, long = 0);
    ~empleado();
    void ponCedula(string);
    void ponNombre(string);
    void ponApellido(string);
    //void ponFechaNac(int[]);
    void salarioBasico(long);
    virtual void imprimir() const;
    virtual long neto() const;
  protected:
    string cedula;
    string nombre;
    string apellido;
    //int fechaN[3];
    long basico;
};

#endif