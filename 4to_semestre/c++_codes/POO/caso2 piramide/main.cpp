#include <iostream>
#include "piramide.h"
#include <math.h>
using namespace std;


void ingreso_datos(Piramide &a){
   // variables auxiliares para asignar los atributos al objeto
    float aux_altura, aux_lado;

    // solicitud de datos al usuario
    cout<<" ingresa los datos de la piramide \n";
    cout<<"altura : ";cin>>aux_altura; 
    cout<<"lado : ";cin>>aux_lado; 
    
    // asignacion de los valores de los atributos por medio de los metodos get
    a.setaltura(aux_altura);
    a.setlado(aux_lado);
}

void mostrar_atributos(Piramide &a){
    cout<<" atributos de la piramide \n";
    cout<<" lado: "<<a.getlado()<<endl;
    cout<<" altura: "<<a.getaltura()<<endl;
}



int main(){
    // cramos el objeto
    Piramide p1;
    int go=4,op;
    while(go==4){
      cout<<" \n\n piramide rectangular \n";
      cout<<" que desea hacer? \n";
      cout<<" 1-- ingreso de datos de la piramide \n";
      cout<<" 2-- mostrar atributos  del objeto \n";
      cout<<" 3-- imprimir datos del objeto  \n";
      cout<<" 4-- salir del programa  \n";

      cout<<" ingrese su opcion: ";cin>>op;
      while(op<1 or op>4){
        cout<<" opcion ingresado imvalida \n";
        cout<<" ingrese su opcion nuevamente: ";cin>>op;
      }


      if(op==1){
        ingreso_datos(p1);
      }
      else if(op==2){
        mostrar_atributos(p1);
      }
      else if(op==3){
        p1.imprime();
      }
      else{
        go=op;
      }
    }
      
  
    return 0;
}