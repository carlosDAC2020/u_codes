#include <iostream>
using namespace std;

/*
PROBADO ;)
saber cuantas veces se repite un numero ingresado por el usuario
en 10 numeros posteriormente ingresados por el usuario
*/

int main() {
    // declaramos el numero a buscar y la cantidad de veces que se repite
    int cant_num_rep=0, num, n_aux;

    // solicitamos el numero a buscar
    cout<<" dijita el numero a buscar :";cin>>num;

    // ingreso de los los 10 numeros 
    cout<<" ingreso de los numeros  \n";
    for (int i = 1; i <=10; i++)
    {
        cout<<" num "<<i<<" :";cin>>n_aux;
        // evaluamos si el numero ingresado es igual al q estamos buscando 
        if (n_aux==num)
        {
            cant_num_rep+=1;
        }
        
    }

    cout<<"\n el numero ingresado se repite :"<<cant_num_rep<<" veces";
    
    return 0;
}