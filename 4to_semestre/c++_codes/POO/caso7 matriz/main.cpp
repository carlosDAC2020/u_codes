#include "matriz.h"
#include <iostream>
using namespace std;

int main(){
    int go=1;
    matriz a,b;
    while(go==1){
        int op;
        cout<<"\n\n operaciones con matrises \n";
        cout<<" 1 ingreso de datos de matrices a y b \n";
        cout<<" 2 suma \n";
        cout<<" 3 producto escalar \n";
        cout<<" 4 producto de matrices \n";
        
        cout<<" ingrese su opcion:";cin>>op;
        while(op<1 || op>4){
        cout<<" valor ingresado no valido \n";
        cout<<" ingrese su opcion nuevamente:";cin>>op;
        }

        if(op==1){
           
            cout<<"\n ingreso de datos de la matriz a \n";
            a.pedir_datos();
            a.setMatriz();
            
            cout<<"\n ingreso de datos de la matriz b \n";
            b.pedir_datos();
            b.setMatriz();
        }

        else if(op==2){
          matriz sum;
          cout<<"\n suma de la matrizes a+b\n";
          cout<<"matriz a\n";
          a.getMatrix();

          cout<<"\nmatriz a\n";
          a.getMatrix();

          cout<<"'n resulatdos de la suma\n";
          sum=a+b;
          sum.getMatrix();
        }

        else if(op==3){
          matriz pe;
          cout<<"'n producto escara de a\n";
          pe=a.producto_escalar();
          cout<<" obtenemos la matrix\n";
          pe.getMatrix();

          cout<<"'n producto escara de b\n";
          pe=a.producto_escalar();
          cout<<" obtenemos la matrix\n";
          pe.getMatrix();
        }

        else{
          matriz prdt;
          cout<<"\n producto de matrizes (a*b)\n";
          cout<<"matriz a\n";
          a.getMatrix();

          cout<<"\nmatriz a\n";
          a.getMatrix();

          prdt= a*b;
          cout<<"\n obtenemos la matriz \n",
          prdt.getMatrix();
        }
        cout<<"\n que desea hacer?\n 1-> volver al menu \n 2 salir del menu\n ----->";cin>>go;
    }
    return 0;
}
