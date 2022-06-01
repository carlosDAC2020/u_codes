#ifndef CUENTA_H
#define CUENTA_H
#include <iostream>
#include <fstream> 
#include <cmath> 
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <stdio.h>
#include <vector>
using namespace std;

class cuenta{
    friend ostream &operator<<(ostream &, const cuenta &);
    friend void nueva_cuenta(int & , vector<cuenta> &, cuenta &);
    friend int lectura_asigancion_datos ( vector<cuenta> &);
    friend void guardar_datos (int, vector<cuenta> &);
    friend int loguin(int ,vector<cuenta> &, int &);
    friend void lista_clientes(int, vector<cuenta> &);
  public:
    cuenta(string = " ", string = " ", string = " ", int = 0, int = 0, float =0.0);
    ~cuenta();
    // sets 
    void setnombre(string);
    void setapellido(string);
    void setcedula(string);
    void setnum_cuenta(int);
    void setclave(int);
    void setsaldo(float);
    // gets
    string getnombre();
    string getapellido();
    string getcedula();
    int getnum_cuenta();
    int getclave();
    float getsaldo();

    void imprime();
    void trasnferencia(int ,vector<cuenta> &);
    void retiro();
    void recarga();

  protected:
    string nombre;
    string apellido;
    string cedula;
    int num_cuenta;
    int clave;
    float saldo;
};

#endif