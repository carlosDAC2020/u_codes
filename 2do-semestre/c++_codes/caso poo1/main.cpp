#include <iostream>
#include "racional.h"
using namespace std;

int main(){
  Racional A, B, C(5,3);
  int n1, n2;
  cout<<" digite el numerador "<<endl;
  cin>>n1;
  cout<<" digite el denominador "<<endl;
  cin>>n2;

  // asiganamos valores a A
  A.getnum(n1);
  A.getden(n2);

  // hallamos B sumando A + C
  B=A.suma(C);

  // imprimimos el resultado 
  cout<<endl;
  A.imprime();
  cout<<" + ";
  C.imprime();
  cout<<" = ";
  B.imprime();
    return 0;
}