#ifndef POSGRADO_H
#define POSGRADO_H
#include "alumno.h"

class posgrado : public alumno
{
public:
    posgrado(string, string, string, double, int, string, float = 0.0);
    ~posgrado();
    void ponTituloObtenidoPregrado( string );
    void ponPromedioPregrado( float );
    virtual void imprime() const;
    virtual double PrecioPrograma();
private:
    string tituloObtenido;
    float promedioPregrado;
};

#endif // POSGRADO_H
