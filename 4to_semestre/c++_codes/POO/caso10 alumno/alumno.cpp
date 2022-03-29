#include "alumno.h"

alumno::alumno(string cod, string nom, string dr, double cp, int p)
{
    ponCodigo( cod );
    ponNombre( nom );
    ponDireccion( dr );
    costoPeriodo = ( cp > 0.0 ? cp : 0.0 );
    cantidadPeriodos = ( p > 0 ? p : 0 );
}

alumno::~alumno()
{
}

void alumno::ponCodigo(string cod)
{
    codigo = cod;
}

void alumno::ponNombre(string nom)
{
    nombre = nom;
}

void alumno::ponDireccion(string dr)
{
    direccion = dr;
}

double alumno::devCostoPeriodo() const
{
    return costoPeriodo;
}

int alumno::devCantidadPeriodos() const
{
    return cantidadPeriodos;
}

void alumno::imprime() const
{
    cout << "\tCodigo No: " << codigo;
    cout << "\n\tNombre del alumno: " << nombre;
    cout << "\n\tDireccion: " << direccion;
    cout << "\n\tCosto Periodo: " << devCostoPeriodo();
    cout << "\n\tCantidad de Periodos a Cursar: " << devCantidadPeriodos();
}

double alumno::PrecioPrograma()
{
    return 0.0;
}
