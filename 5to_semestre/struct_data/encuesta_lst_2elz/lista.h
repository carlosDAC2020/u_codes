#ifndef LISTA_H
#define LISTA_H
#include <iostream>
using namespace std;

struct nodo {
    string name, code;
    int sexo; 
    char tipo ;
    double salario;
    struct nodo *sig, *ant;
};

class lista{
public:
  lista();
  void pedirDatos();
  void entrarDatos(string, string, int , char, double);
  void quitarDatos();
  void borrarDatos(string);
  int validar(string);
  void mostra_stadisticas();
  void imprimir1();
private:
  struct nodo *prim, *ultm, *nuevo;
};

#endif