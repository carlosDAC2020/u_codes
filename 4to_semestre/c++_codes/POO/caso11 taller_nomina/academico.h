#ifndef ACADEMICO_H
#define ACADEMICO_H
#include "empleado.h"

class academico: public empleado 
{
    friend istream &operator>>(istream &, academico &);
    friend ostream &operator<<(ostream &, const academico &);
    friend void imprimir_lista_academicos (int, vector<academico> &);
    friend long nomina_total_academicos(int, vector<academico> &);
  public:
    academico(string = " ", string = " ", string = " ",/* int[] = 0*/ long = 0 , int=0, int=0);
    ~academico();
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