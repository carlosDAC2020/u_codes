#include "complejo.h"
#include <iostream>
#include <math.h>
using namespace std;

// comstructor
Complejo::Complejo() {
    real = 0;
    imaginario = 0;
}
Complejo::Complejo(double re, double im) {
    real = re;
    imaginario = im;
}

// constructor copia 
 Complejo::Complejo(Complejo &a){
  real= a.real;
  imaginario= a.imaginario;
 }

//Método imprimir
ostream &operator<<(ostream &salida, const Complejo &a) {
    salida<<a.real<<" + ("<<a.imaginario<<")i";
    return salida;
}

// solicitud de datos 
istream &operator>>(istream &entrada, Complejo &a) {
    cout << "\nDigite la parte real: ";
    entrada >> a.real;
    do {
        cout << "\nDigite la parte imaginaria: ";
        entrada >> a.imaginario;
    } while (a.imaginario == 0);

    return entrada;
}

//Método suma
Complejo Complejo::operator+(const Complejo &a) const {
    Complejo res;
    res.real= real + a.real;
    res.imaginario= imaginario + a.imaginario;
    return res;
}


//Método resta
Complejo Complejo::operator-(const Complejo &a) const {
    Complejo res;
    res.real= real - a.real;
    res.imaginario= imaginario - a.imaginario;
    return res;
}

// metodo multiplicacion
Complejo Complejo::operator*(const Complejo &a) const {
    Complejo res;
    res.real= (real*a.real)-(imaginario*a.imaginario);
    res.imaginario= (real*a.imaginario) + (imaginario*a.real);
    return res;
}

// metodo dividir
Complejo Complejo::operator/(const Complejo &a) const{
  double den ;
  Complejo res, num;

  num.real= (real*a.real) + (imaginario*a.imaginario);
  num.imaginario= (imaginario*a.real)-(real*a.imaginario);
  den= pow(a.real,2) + (pow(a.imaginario,2)*(-1));

  res.real= num.real/den;
  res.imaginario= num.imaginario/den;
 

  return res;
}

