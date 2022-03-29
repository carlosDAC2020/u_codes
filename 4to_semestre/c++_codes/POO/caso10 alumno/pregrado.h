#ifndef PREGRADO_H
#define PREGRADO_H
#include "alumno.h"

class pregrado : public alumno
{
public:
    pregrado( string, string, string, double, int, string, int = 0);
    ~pregrado();
    void ponPrograma( string);
    void ponPuntajeIcfes( int );
    virtual void imprime() const;
    virtual double PrecioPrograma();
private:
    string programa;
    int puntajeIcfes;
};

#endif // PREGRADO_H
