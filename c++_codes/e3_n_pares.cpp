/*
enunciado
imprime los numeros pares entre 1 y n
*/
#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"imprime los numeros pares entre 1 y n"<<endl;
    cout<<"ingresa el vaslor de n:";cin>>n;
    cout<<"impresion"<<endl;
    for(int i=0; i<=n; i++){
        if(i%2==0){ // la condicon para emprimir e los numeros pares se tiene en cuenta que el si n se divide entre 2 el resto de dicha divicion sea cero
            cout<<"--"<<i<<endl;
        }
    }
    return 0;
}