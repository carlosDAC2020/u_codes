#include <iostream>
#include "complejo.h"
using namespace std;

int main() {
  Complejo a, b, res;
  int go=1, op;

  do{
    cout<<"\n  calculadora de numeros complejos \n";
    cout<<" ingreso de datos \n";
    cout<<" numero A ";
    cin>>a;
    cout<<" numero B ";
    cin>>b;

    cout<<"\n que operacion desea realizar ?\n";
    cout<<" 1 sumar \n";
    cout<<" 2 restar \n";
    cout<<" 3 multiplicar \n";
    cout<<" 4 dividir \n";

    cout<<" ingrese su opcion:";cin>>op;
    while(op<1 || op>4){
       cout<<" valor ingresado no valido \n";
       cout<<" ingrese su opcion nuevamente:";cin>>op;
    }
    
  cout<<"\n\n respuesta \n";
  switch(op) {
      case 1: 
        res=a+b;
        cout<<a<<" + "<<b<<" = "<<res<<endl;
      break;
      case 2: 
        res=a-b;
        cout<<a<<" - "<<b<<" = "<<res<<endl;
      break;
      case 3:
        res=a*b;
        cout<<a<<" * "<<b<<" = "<<res<<endl;
      break;
      case 4:
        res=a/b; 
        cout<<a<<" / "<<b<<" = "<<res<<endl;
      break;
    }
    cout<<"\n\n que desea hacer?\n 1-->volver al menu \n 2-->salir del programa \n ---> ";
    cin>>go;
  }
  while(go==1);
  

  return 0;
}