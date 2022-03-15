#include "arreglo.h"
#include <iostream>
using namespace std;

// funcion para ingreso de datos 
void ingreso_datos(arreglo &a, arreglo &b){
  int aux;
  cout<<" ingresa el tamaño de a:";cin>>aux;
  a.settam(aux);
  cout<<" ingreso de los datos del arreglo a\n";
  cin>>a;


  cout<<"\n ingresa el tamaño de b:";cin>>aux;
  b.settam(aux);
  cout<<" ingreso de los datos del arreglo a\n";
  cin>>b;
}

// validar el tamaño de los arreglos para realizar las operaciones aritmeticas entre ellos
bool igual_tamanio(arreglo &a, arreglo &b){
  if(a.tamanio()==b.tamanio()){
    return true;
  }
  else{
    return false;
  }
}
int main(){
  int go=1;
  arreglo a,b,resp;
  while(go==1){
    int op;
    cout<<"arreglo a\n";
    cout<<a;
    cout<<"arreglo b\n";
    cout<<b;
    cout<<"\n\n operaciones con arreglos ?\n";
    cout<<" 1 ingreso de datos de arreglo a y b \n";
    cout<<" 2 concatenar \n";
    cout<<" 3 sumar \n";
    cout<<" 4 restar \n";
    cout<<" 5 multiplicar \n";
    cout<<" 6 promedios de los arreglos a y b \n";

    cout<<" ingrese su opcion:";cin>>op;
    while(op<1 || op>6){
       cout<<" valor ingresado no valido \n";
       cout<<" ingrese su opcion nuevamente:";cin>>op;
    }

    switch(op) {
      case 1: 
        ingreso_datos(a,b);
      break;
      case 2: 
        cout<<"\n CONCATE3NACION \n";
        cout<<" al concatenar los arreglos tenemos \n";
        cout<<"arreglo a \n";
        cout<<a;
        cout<<"arreglo b \n";
        cout<<b;
        resp=a.concatenar(b);
        cout<<"tenmos: \n";
        cout<<resp;
      break;

      case 3:
        cout<<"\n\n SUMA \n";
        cout<<" al a + b tenemos\n";
        resp=a+b;
        cout<<resp;
      break;
      
      case 4:
        cout<<"\n\n RESTA \n";
        cout<<" al a - b tenemos\n";
        resp=a-b;
        cout<<resp;
        
      break;
      case 5:
        cout<<"\n\n MULTIPLICACION \n";
        cout<<" al cuma a * b tenemos\n";
        resp=a*b;
        cout<<resp;
      break;

      case 6:
        cout<<"\n\n PROMEDIOS ";
        cout<<"\n arreglo a:"<<a.promedio();
        cout<<"\n arreglo b:"<<b.promedio();
      break;
    }
    cout<<"\n que desea hacer?\n 1-> volver al menu \n 2 salir del menu\n ----->";cin>>go;
      
  }
  

   
    return 0;
}