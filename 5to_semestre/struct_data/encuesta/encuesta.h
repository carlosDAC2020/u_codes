#ifndef ENCUESTA_H
#define ENCUESTA_H
#include <iostream>
#include <cmath>
using namespace std;

struct nodo {
  string codigo, nombre;
  int edad, sexo;
  float ingresosA;
  struct nodo *sig;
 };

class encuesta{
public:
  encuesta();
  void pedirDatos();
  void entrarDatos(string, string, int, int, float);
  void quitarDatos();
  void borrarDatos(string);
  int validar(string);
  void promEdad();
  void promIngresos();
  void porcentajes();
  void imprimir();
private:
  struct nodo *prim, *ultm, *nuevo;
};

#endif
