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

void Racional::getnum(int n){
    num=n;
}

void Racional::getden(int d){
    den=(d==0? 1:d);
}

Racional Racional::suma(Racional &a){
    Racional resp;
    resp.num=(num*a.den)+(den*a.num);
    resp.den=(den*a.den);
    return resp;
}
