#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>
using namespace std;


typedef struct nodo{
    int cedula;
    string Nombre;
    string Apellido;
    int NoMovil;
    int profesion;
    int fch_nacimiento[3]={0,0,0};
    int edad;
    string city_residencia;
    struct nodo *izq, *der;
}*ABB;


class arbol 
{
  public:
    arbol();
    ABB getraiz();
    ABB crearNodo(int, string, string, int, int, int *, string);
    void insertar(ABB &, int, string, string, int, int, int *, string);
    void preOrden(ABB);
    void enOrden(ABB);
    void postOrden(ABB);
    ABB busquedaRec(ABB, int);
    ABB unirABB(ABB, ABB);
    void elimina(ABB &, int);
    bool validar(ABB &, int);
    void buscar_egresados(ABB, int);
    void buscar_por_ciudad(ABB , string);
    void buscar_por_profesion(ABB, int);
    void buscar_por_rango_edad(ABB, int, int);
    void imprimir_egresado(ABB);
  private:
    ABB raiz;
};

#endif