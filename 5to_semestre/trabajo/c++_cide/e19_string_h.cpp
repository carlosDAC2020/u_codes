

/*
Escribir un programa que lea una cadena y determine si es un palíndromo o no, 
es decir que se leen igual al reves informando del resultado. 

por ejemplo 
    oso 
    nadan
    oro
    radar
    seres
    solos
    narran
    reconocer
*/
#include <iostream>
#include <string.h>
using namespace std;

char palabra[34];
char auxp[34];

int main()
{
    // solicitamos la palabra
    cout<<" ingresa una palabra: ";cin>>palabra;

    // invertimos la palabra 
    int x=0;
    for (int i = strlen (palabra)-1; i >=0; i--)
    {
        auxp[x] = palabra[i];
        x+=1;
    }

    if (strcmp ( palabra, auxp )==0)
    {
        cout<<" la palabra "<<palabra<<" es un palindromo \n";
    }
    else{
        cout<<" la palabra "<<palabra<<" no es un palindromo \n";
    }
    

    return 0;
}