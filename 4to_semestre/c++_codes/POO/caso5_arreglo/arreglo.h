#ifndef ARREGLO_H
#define ARREGLO_H

#include <iostream>
using namespace std;

class arreglo
{
  friend ostream &operator << (ostream &, const arreglo &);
  friend istream &operator >> (istream &, arreglo &);
public:
  arreglo(int = 4); //Constructor
  arreglo(const arreglo &); //Constructor de copia
  ~arreglo(); //Destructor
  void settam(int);
  int tamanio() const;
  const arreglo &operator= (const arreglo &);
  int operator== (const arreglo &) const;
  int operator!= (const arreglo &derecha) const
  {
    return !(*this == derecha);
  }
  // metodo para concatenar
  arreglo concatenar(const arreglo &) const;
  // suma
  arreglo operator+ (const arreglo &) const;
// resta
  arreglo operator- (const arreglo &) const;
// multiplicacion
  arreglo operator* (const arreglo &) const;
// promedio
float promedio()const;
private:
  int tam;
  int *ptr;
};

#endif // ARREGLO_H