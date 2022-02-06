#include "racional.h"
#include <iostream>
using namespace std;

// metodo constructor 
Racional::Racional(int n, int d)
{
  num=n;
  den=(d==0? 1:d);
}

// metodo imprime 
void Racional::imprime(){
  cout<<num<<"/"<<den;
}

// metodos get para solicitar valores 
void Racional::getnum(int n){
    num=n;
}

void Racional::getden(int d){
    den=(d==0? 1:d);
}

// metodo suma de fracciones 
Racional Racional::suma(Racional &a){
    Racional resp;
    resp.num=(num*a.den)+(den*a.num);
    resp.den=(den*a.den);
    return resp;
}

// metodo resta de fracciones 
Racional Racional::resta(Racional &a){
    Racional resp;
    resp.num=(num*a.den)-(den*a.num);
    resp.den=(den*a.den);
    return resp;
}

// metodo multiplicacion de fracciones 
Racional Racional::multiplicacion(Racional &a){
    Racional resp;
    resp.num=a.num*num;
    resp.den=a.den*den;
    return resp;
}

// metodo divicion de fracciones 
Racional Racional::divicion(Racional &a){
    Racional resp;
    resp.num=num*a.den;
    resp.den=den*a.num;
    return resp;
}

