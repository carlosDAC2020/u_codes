#include <iostream>
using namespace std;

/*
PROBADO;)
promedio de edad de n personas 
*/

int main() {
    int cant_per, edad, sum=0;

    // ingreso del numero de personas a preguntar su edad 
    cout<<" dijita la cantida n de personas a preguntar su edad :";cin>>cant_per;

    // ingreso de los numeros 
    cout<<" ingreso de la edades  \n";
    for (int i = 1; i <=cant_per; i++)
    {
        cout<<" persona "<<i<<" :";cin>>edad;
        sum+=edad;
    }

    float prom=sum/cant_per;
    cout<<"\n el promedio de edades de las personas es de :"<<prom;
    
    return 0;
}