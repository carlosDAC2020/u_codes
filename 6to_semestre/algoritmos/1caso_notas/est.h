#ifndef EST_H
#define EST_H
#include <iostream>
using namespace std;

struct nodo {
  int code;
  struct nodo *sig;
 };

class lista{
public:
  lista();
  void pedirDatos();
  void entrarDatos(string);
  void imprimirResultados();
private:
  struct nodo *prim, *ultm, *nuevo;
  int cant_ganados=0, cant_perdidos=0, cant_est=0;
  float prom_general=0;
};

#endif
