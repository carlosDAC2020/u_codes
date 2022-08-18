#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <cmath>
using namespace std;

struct nodo {
  string codigo;
  float estatura, peso;
  struct nodo *sig;
 };

class lista{
public:
  lista();
  void pedirDatos();
  void entrarDatos(string, float, float);
  void quitarDatos();
  void borrarDatos(string);
  int validar(string);
  void correlacion();
  void imprimir();
private:
  struct nodo *prim, *ultm, *nuevo;
};

#endif
