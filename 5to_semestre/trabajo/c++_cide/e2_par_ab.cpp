#include <iostream>
using namespace std;


int main() {
    int a,b, may, men, sum_men=0, sum_may=0;
    float prom_may;

    cout<<"\n ingreso de losvalores de a y b \n";
    for(int i=1; i<=5; i++){
        cout<<" par "<<i<<endl;
        cout<<"\n ingresa el valor de a:";cin>>a;
        cout<<"\n ingresa el valor de b:";cin>>b;

        cout<<" respuesta 1\n";
        if (a<b)
        {
            men=a;
        }
        else
        {
            men=b;
        }
        cout<<" el numero menor es :"<<men<<endl;
        sum_men+=men;
        
        cout<<" respuesta 2\n";
        if (a>b)
        {
            may=a;
        }
        else
        {
            may=b;
        }
        cout<<" el numero mayor es :"<<men<<endl;
        sum_may+=may;
    }

    cout<<"\n\n  respuesta 3\n";
    cout<<" suma de los menores:"<<sum_men<<endl;

    prom_may=sum_may/5;
    cout<<"\n\n  respuesta 4\n";
    cout<<" promedio de los mayores:"<<prom_may<<endl;

    
    return 0;
}

