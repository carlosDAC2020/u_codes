#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <iostream>
using namespace std;

class Pila{
public:
  Pila (int = 10);
  ~Pila() { delete [] pilaPtr; }
  bool insertar (const int &);
  bool extraer (int &);
  bool estaVacia() const { return superior == -1; }
  bool estaLlena() const { return superior == tamanio - 1; }
private:
  int tamanio, superior, *pilaPtr;
};
Pila::Pila(int s) {
  tamanio = s > 0 ? s : 10;
  superior = -1;
  pilaPtr = new int[tamanio];
}
bool Pila::insertar ( const int &insertarValor ) {
  if (!estaLlena()) {
    pilaPtr[++superior] = insertarValor;
    return true;
  }
  return false;
}
bool Pila::extraer( int &extraerValor ) {
  if (!estaVacia()) {
    extraerValor = pilaPtr[superior--];
    return true;
  }
  return false;
}
#endif // PILA_H_INCLUDED
