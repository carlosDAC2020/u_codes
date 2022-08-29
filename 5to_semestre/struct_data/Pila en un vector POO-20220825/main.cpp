#include "Pila.h"

int main()
{
  Pila intPila(5);
  int intValor = 1;
  cout<<"\nInsertando elementos\n";
  while (intPila.insertar(intValor)){
    cout << intValor << " ";
    intValor += 1;
  }
  cout<<"\nLa Pila esta llena.No se insertó el " << intValor;
  cout<<"\n\nExtrayendo elementos de intPila\n";
  while (intPila.extraer(intValor))
    cout << intValor << " ";
  cout<<"\nLa Pila esta vacia. No se puede extraer\n";
  return 0;
}

