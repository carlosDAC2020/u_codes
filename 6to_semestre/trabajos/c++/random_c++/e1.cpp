#include <iostream>
using namespace std;

/*
PROBADO ;)
sumatoria de n numeros ingresados 
*/

int main() {
    int cant_num, num, sum=0;

    // ingreso de numeros 
    cout<<" dijita la cantida n de numeros que ingresaras:";cin>>cant_num;

    // ingreso de los numeros 
    cout<<" ingreso de los"<<cant_num<<" numeros \n";
    for (int i = 1; i <=cant_num; i++)
    {
        cout<<" num "<<i<<" :";cin>>num;
        sum+=num;
    }

    cout<<"\n la sumatoria de los numeros ingresados es "<<sum;
    

    return 0;
}
