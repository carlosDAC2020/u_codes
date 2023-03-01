#include <iostream>
using namespace std;

/*
PROBADO ;)
cantidad de numeros pares e impares en 10 numeros ingresados por el usuario 
*/

int main() {
    int cant_par=0, num;

    // ingreso de los numeros 
    cout<<" ingreso de los numeros  \n";
    for (int i = 1; i <=10; i++)
    {
        cout<<" persona "<<i<<" :";cin>>num;
        // evaluamos si un numero es par 
        if (num%2==0)
        {
            cant_par+=1;// sumamos 1 al contador 
        }
        
    }

    // mostramos los resulatdos 
    cout<<" cab¿ntidad de numeros pares :"<<cant_par<<endl;
    cout<<" cab¿ntidad de numeros impares :"<<10-cant_par<<endl;
    
    return 0;
}