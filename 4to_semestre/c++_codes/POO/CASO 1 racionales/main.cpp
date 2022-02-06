#include <iostream>
#include "racional.h"
using namespace std;

int main(){
  // contruimos los objetos 
  Racional A, B, sum, res, multi, div;
  // variables para asiganr los valores de numerador y denominador 
  int n1, n2;
//-----------------------------------------
  cout<<" fraccion A \n";
  cout<<" digite el numerador "<<endl;
  cin>>n1;
  cout<<" digite el denominador "<<endl;
  cin>>n2;

  // asiganamos valores a A
  A.getnum(n1);
  A.getden(n2);
//-----------------------------------------
  cout<<"\n fraccion B \n";
  cout<<" digite el numerador "<<endl;
  cin>>n1;
  cout<<" digite el denominador "<<endl;
  cin>>n2;

  // asiganamos valores a B
  B.getnum(n1);
  B.getden(n2);

// proceso de suma -----------------------------------------
  cout<<"\n suma de fracciones \n";
  sum=A.suma(B);
  A.imprime();
  cout<<" + ";
  B.imprime();
  cout<<" = ";
  sum.imprime();

// proceso de resta -----------------------------------------
  cout<<"\n resta de fracciones \n";
  res=A.resta(B);
  A.imprime();
  cout<<" - ";
  B.imprime();
  cout<<" = ";
  res.imprime();

// proceso de multiplicacion -----------------------------------------
  cout<<"\n multiplicacion de fracciones \n";
  multi=A.multiplicacion(B);
  A.imprime();
  cout<<" * ";
  B.imprime();
  cout<<" = ";
  multi.imprime();

// proceso de divicon -----------------------------------------
  cout<<"\n divicion de fracciones \n";
  // hallamos D restando A - C
  div=A.divicion(B);
  A.imprime();
  cout<<" / ";
  B.imprime();
  cout<<" = ";
  div.imprime();

  

  return 0;
}