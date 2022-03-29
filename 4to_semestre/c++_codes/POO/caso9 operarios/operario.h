#ifndef OPERARIO_H
#define OPERARIO_H

#include <iostream>
#include <vector>
using namespace std;
#define OS 80000
#define OP 60000
#define OE 100000

class operario 
{
  friend istream &operator>>(istream &, operario &);
  friend ostream &operator<<(ostream &, const operario &);
  friend void obtenerDatos (int, int, vector<operario> &);
  friend void imprimirOperarios (int, const vector<operario> &);
  friend long bonificacionTotal(int, vector<operario> &);
  friend long nominaTotal(int, vector<operario> &);
  public:
    operario(int = 8);
    ~operario();
    const operario &operator=(const operario &derecha);
    float promedio() const;
    long base() const;
    long bonificacion() const;
    long extras() const;
    long neto() const;
  private:
    string nombre;
    int dias;
    int cargo;
    long *horas;
};
#endif //OPERARIO_H
