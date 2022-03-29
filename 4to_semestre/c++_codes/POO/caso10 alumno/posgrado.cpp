#include "posgrado.h"

// constructor
posgrado::posgrado(string cod, string nom, string dr, double cp, int p, string to, float pp)
    : alumno( cod, nom, dr, cp, p )
{
    ponTituloObtenidoPregrado( to );
    ponPromedioPregrado( pp );
}

posgrado::~posgrado()
{
}

void posgrado::ponTituloObtenidoPregrado(string to)
{
    tituloObtenido = to;
}

void posgrado::ponPromedioPregrado( float pp )
{
    promedioPregrado = (pp < 0.0 || pp > 5.0 ? 0.0 : pp);
}

void posgrado::imprime() const
{
    alumno::imprime();
    cout << "\n\tTitulo Obtenido en Pregrado: " << tituloObtenido;
    cout << "\n\tPromedio Obtenido en Pregrado: " << promedioPregrado;
}

double posgrado::PrecioPrograma()
{
    double precio;
    if (promedioPregrado > 4.0)
        precio = (devCostoPeriodo() * devCantidadPeriodos())*0.8;
    else
        precio = devCostoPeriodo() * devCantidadPeriodos();
    return precio;
}
