#include <iostream>
using namespace std;

/*
PROBADO ;)
suma de n numeros usando cilos for y whille
*/

int main() {

    int cant_num, num, sum=0;

    // ingreso de numeros 
    cout<<" dijita la cantida n de numeros que ingresaras:";cin>>cant_num;

    // ingreso de los numeros y obtencion de la suma usando el for  usando el for 
    cout<<"\n usando el for \n";
    for (int i = 1; i <=cant_num; i++)
    {
        cout<<" num "<<i<<" :";cin>>num;
        sum+=num;
    }

    cout<<"\n la sumatoria de los numeros ingresados es "<<sum<<endl;


    // ingreso de los numeros y obtencion de la suma usando el for  usando el whille
    int i=1;
    sum=0;
    cout<<"\n usando el whille \n";
    while (i<=cant_num)
    {
        cout<<" num "<<i<<" :";cin>>num;
        sum+=num;
        i++;
    }
    cout<<"\n la sumatoria de los numeros ingresados es "<<sum;
    
    return 0;
}