#include "arreglo.h"

arreglo::arreglo(int ta)
{
  tam = (ta > 0 ? ta : 4);
  ptr = new int[tam]; //Crear espacio para arreglo
  for(int i = 0; i < tam; i++)
    ptr[i] = 0;
}

arreglo::arreglo(const arreglo &copia)
{
  tam = copia.tam;
  ptr = new int[tam];
  for(int i = 0; i < tam; i++)
    ptr[i] = copia.ptr[i];
}

arreglo::~arreglo()
{
  delete []ptr;
}

int arreglo::tamanio() const
{
  return tam;
}

const arreglo &arreglo::operator= (const arreglo &derecha)
{
  if(&derecha != this)
  {
    if(tam != derecha.tam)
    {
      delete []ptr;
      tam = derecha.tam;
      ptr = new int[tam];
    }
    for(int i = 0; i < tam; i++)
      ptr[i] = derecha.ptr[i];
  }
  return *this;
}

int arreglo::operator== (const arreglo &derecha) const
{
  if(tam != derecha.tam)
    return 0;
  for(int i = 0; i < tam; i++)
    if(ptr[i] != derecha.ptr[i])
      return 0;
  return 1;
}

istream &operator>>(istream &entrada, arreglo &a)
{
  for(int i = 0; i < a.tam; i++)
  {
    cout << "[" << i+1 << "]: ";
    entrada >> a.ptr[i];
  }
  return entrada;
}

ostream &operator<<(ostream &salida, const arreglo &a)
{
  int i;
  for(i = 0; i < a.tam; i++)
  {
    salida << ", " << a.ptr[i];
    if((i+1) % 4 == 0) salida << endl;
  }
  if((i+1) % 4 == 0) salida << endl;
  return salida;
}