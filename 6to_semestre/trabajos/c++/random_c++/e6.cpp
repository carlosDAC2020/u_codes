#include <iostream>
using namespace std;

/*
PROBADO ;)
analisis de 10 pares de numeros 
    mayor numero de cada par
    menor numero de cada par 
    sumatoria de todos los menores 
*/

int main() {
    // declaramos las variables de los pares de nuemros y la sumatoria de los menores en 0
    int a,b,sum_men=0;

    // ingreso de los 10 pares de valores 
    cout<<"\n ingresa los pares de numeros \n";
    for (int i = 0; i <=10; i++)
    {
        cout<<"\n par "<<i<<endl;
        cout<<" num A:";cin>>a;
        cout<<" num B:";cin>>b;

        // obtenemos cual numero es mayor o menor 
        if (a-b==0)
        {
            cout<<" los numeros son igualoes \n";
        }
        
        else if (a-b>0)
        {
            cout<<" el mayor es el "<<a<<endl;
            cout<<" el menor es el "<<b<<endl;
            sum_men+=b;
        }
        else{
            cout<<" el mayor es el "<<b<<endl;
            cout<<" el menor es el "<<a<<endl;
            sum_men+=a;
        }
    }

    cout<<"\n la sumatoria de los numeros menores fue de "<<sum_men;
    
    

    return 0;
}