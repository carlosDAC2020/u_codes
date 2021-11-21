/*
enunciado
  a partir de una lista en desorden la ordenamos de mayor a menor y veceberza 
*/
#include <iostream>
using namespace std;

int main(){
    // declaramos variables a utilizar 
    int n, valor;
    cout<<" cantidad de elemntos de la lista:";cin>>n;
    int lista[n];

    // incecion de elementos a la lista 
    cout<<"\n\n lista \n";
    for(int i=0; i<=n-1;i++){
        cout<<"ingresa un valor:";cin>>valor;
        lista[i]=valor;
    }
    int op=1;
    while(op==1){
        cout<<"\n\n de que forma la deseas ordenar\n";
        cout<<"--1 de menor a ,mayor\n";
        cout<<"--2 de mayor a menor\n";

        int opt;
        cout<<" dijite su opcion:";cin>>opt;
        while(opt>2){
            cout<<"\nopcion dijitada no valida \n dijite su opcion nuevamente:";cin>>opt;
        }
        int l_ordenada[n];// en esta lista se ordenaran los valores de la lista original segun lo ordenado por el usuario
        for(int i=0; i<=n-1; i++){
            l_ordenada[i]=lista[i]; // pasamos los elemnetos dde la lista en desorden a otra 
        }

        int aux; // variable auxiliar resiclable

        // evaluamos la opcion deceada
        if (opt==1){
            cout<<"\n\n ordenamiento de menor a mayor\n";
            for (int i=0; i<=n-2; i++){ // procedimiento de ordenamiento
                for (int y=0; y<=n-2; y++){
                    if(l_ordenada[y] > l_ordenada[y+1]){
                        aux= l_ordenada[y];
                        l_ordenada[y]= l_ordenada[y+1];
                        l_ordenada[y+1]= aux;
                    }
                }
            }
            // impreciones de las listas 
            cout<<"\n lista inicial\n";
            for(int i=0; i<=n-1; i++){
                cout<<lista[i]<<" ";
            }
            cout<<"\n lista ordenada\n";
            for(int i=0; i<=n-1; i++){
                cout<<l_ordenada[i]<<" ";
            }
        }
        else {
            cout<<"\n\n ordenamiento de mayor a menor\n";
            for (int i=0; i<=n-2; i++){ // procedimiento de ordenamiento
                for (int y=0; y<=n-2; y++){
                    if(l_ordenada[y] < l_ordenada[y+1]){
                        aux= l_ordenada[y];
                        l_ordenada[y]= l_ordenada[y+1];
                        l_ordenada[y+1]= aux;
                    }
                }
            }
            cout<<"\n lista inicial\n";
            for(int i=0; i<=n-1; i++){
                cout<<lista[i]<<" ";
            }
            cout<<"\n lista ordenada\n";
            for(int i=0; i<=n-1; i++){
                cout<<l_ordenada[i]<<" ";
            }
        }
        cout<<"\ndesea volver al menu?\n-- 1 para si\n-- 2 para no\n elija:";cin>>op;
    }
    return 0;
}