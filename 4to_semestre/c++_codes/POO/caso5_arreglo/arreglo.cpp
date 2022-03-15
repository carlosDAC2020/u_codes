#include "arreglo.h"
#include <iostream>
using namespace std;

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

void arreglo::settam(int ta){
  tam=ta;
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
    salida  << a.ptr[i]<< ", ";
    if((i+1) % 4 == 0) salida << endl;
  }
  if((i+1) % 4 == 0) salida << endl;
  return salida;
}

arreglo arreglo::concatenar(const arreglo &a) const{
  // tamaño del constructoir a retornar
  int auxtam=this->tam+a.tam;
  // constructor a retornar
  arreglo resp(auxtam);

  for (int i=0; i<this->tam; i++){
    resp.ptr[i]= ptr[i];
  }
  for(int i=this->tam, z=0;i<auxtam;i++, z++){
    resp.ptr[i]= a.ptr[z];
  }
  return resp;
}

// suma
  arreglo arreglo::operator+ (const arreglo &a) const{
    arreglo resp;
    for(int i=0; i<tam;i++){
      resp.ptr[i]=ptr[i]+a.ptr[i];
    }
    return resp;
  }

// resta
  arreglo arreglo::operator- (const arreglo &a) const{
    arreglo resp;
    for(int i=0; i<tam;i++){
      resp.ptr[i]=ptr[i]-a.ptr[i];
    }
    return resp;
  }

// multiplicacion
  arreglo arreglo::operator* (const arreglo &a) const{
    arreglo resp;
    for(int i=0; i<tam;i++){
      resp.ptr[i]=ptr[i]*a.ptr[i];
    }
    return resp;
  }

// promedio 
float arreglo::promedio()const{
    int sum=0;
    for(int i=0; i<tam; i++){
      sum+=ptr[i];
    }
    return sum/tam;
}