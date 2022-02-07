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
    /* hallaremos y mostramos los atributos del objeto piramide
    q pasamos como parametro a la funcion por medio de los emtodos de este*/

    // declaramos variables auxiliares para los atributos
    float base, area_rectangular, area_lateral, area_total, volumen;

    // area de la base 
    base=a.base();
    // area rectangular
    area_rectangular=a.area_triangulos();
    // area lateral
    area_lateral=a.area_lateral(area_rectangular);
    // area total
    area_total=a.area_total(base,area_lateral);
    //volumen
    volumen=a.volumen(base);

    // imprimimos atributos 
    a.imprime();
    cout<<" base:"<<base<<"\n";
    cout<<" area  rectangular :"<<area_rectangular<<"\n";
    cout<<" area lateral :"<<area_lateral<<"\n";
    cout<<" area total :"<<area_total<<"\n";
    cout<<" volumen :"<<volumen<<"\n";
}

int main(){
    // cramos el objeto
    Piramide p1;
    int go=3,op;
    while(go==3){
      cout<<" piramide rectangular \n";
      cout<<" que desea hacer? \n";
      cout<<" 1-- ingreso de datos de la piramide \n";
      cout<<" 2-- mostrar atributos  de la piramide \n";
      cout<<" 3-- salir del programa  \n";

      cout<<" ingrese su opcion: ";cin>>op;
      while(op<1 or op>3){
        cout<<" opcion ingresado imvalida \n";
        cout<<" ingrese su opcion nuevamente: ";cin>>op;
      }


      if(op==1){
        ingreso_datos(p1);
      }
      else if(op==2){
        mostrar_atributos(p1);
      }
      else{
        go=op+1;
      }
    }
      
  
    return 0;
}