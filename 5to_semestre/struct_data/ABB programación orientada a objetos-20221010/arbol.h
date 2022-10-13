#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>
using namespace std;

typedef struct nodo{
     int nro;
     struct nodo *izq, *der;
}*ABB;

class arbol 
{
  public:
    arbol();
    ABB getraiz();
    ABB crearNodo(int);
    void insertar(ABB &, int);
    void preOrden(ABB);
    void enOrden(ABB);
    void postOrden(ABB);
    bool busquedaRec(ABB, int);
    ABB unirABB(ABB, ABB);
    void elimina(ABB &, int);
    bool validar(ABB &, int);
  private:
    ABB raiz;
};

#endif