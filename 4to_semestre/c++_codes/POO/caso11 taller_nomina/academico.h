#ifndef ACADEMICO_H
#define ACADEMICO_H
#include "empleado.h"

class academico: public empleado 
{
    friend istream &operator>>(istream &, academico &);
  public:
    void PonNiveldeEstudio (int);
    void PonPuntajeInvestigacion (int);
    long boni_nivel_estudio()const;
    long boni_puntaje_investigacion() const;
    virtual void imprimir() const;
    virtual long neto() const;
  private:
    int nivel_estudio;
    int puntaje_investigacion;
};


#endif