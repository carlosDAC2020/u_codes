#ifndef SEMILLA_H
#define SEMILLA_H

#include <iostream>
#include <vector>
using namespace std;

class semilla
{
  friend istream &operator>>(istream &, semilla &);
  friend ostream &operator<<(ostream &, const semilla &);
  friend void obtenerDatos (int, vector<semilla> &);
  friend void imprimirDatos (int, const vector<semilla> &);
  friend void PromMayor (int est, vector<semilla> &);
public:
  semilla(int = 8);
  ~semilla();
  float Promedio();
  void imprimirNom();
  void imprimirProm();
private:
  string Nombre;
  int Dias;
  float *Horas;
};

#endif // SEMILLA_H