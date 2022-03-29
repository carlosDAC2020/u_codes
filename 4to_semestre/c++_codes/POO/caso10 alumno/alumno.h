#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
using namespace std;

class alumno
{
public:
    alumno(string, string, string, double, int);
    ~alumno();
    void ponCodigo(string);
    void ponNombre(string);
    void ponDireccion(string);
    double devCostoPeriodo() const;
    int devCantidadPeriodos() const;
    /* Escribe el prototipo de la funcion virtual imprime*/
    virtual void imprime() const;
    /* Escribe el prototipo de la funcion virtual PrecioPrograma*/
    virtual double PrecioPrograma();
protected:
    string codigo;
    string nombre;
    string direccion;
    long double costoPeriodo;
    int cantidadPeriodos;
};

#endif // ALUMNO_H
