#include "pregrado.h"

// constructor
pregrado::pregrado(string cod, string nom, string dr, double cp, int p, string prog, int pi)
: alumno( cod, nom, dr, cp, p )
{
    ponPrograma( prog );
    ponPuntajeIcfes( pi );
}

pregrado::~pregrado()
{
}

void pregrado::ponPrograma(string prog)
{
    programa = prog;
}

void pregrado::ponPuntajeIcfes( int pi )
{
    puntajeIcfes = (pi < 0 ? 0 : pi);
}

void pregrado::imprime() const
{
    alumno::imprime();
    cout << "\n\tPrograma: " << programa;
    cout << "\n\tPuntaje Icfes: " << puntajeIcfes;
}

double pregrado::PrecioPrograma()
{
  double precio;
  if (puntajeIcfes > 300)
     precio = (devCostoPeriodo() * devCantidadPeriodos())*0.9;
  else
     precio = devCostoPeriodo() * devCantidadPeriodos();
  return precio;
}
