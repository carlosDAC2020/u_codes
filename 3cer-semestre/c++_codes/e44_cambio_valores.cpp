
#include <iostream>

using namespace std;  


int main() { 
    int a ,b, aux;
    cout<<" intercambio de valores de dos variables "<<endl;
    cout<<" ingresa el valor de a:";cin>>a; 
    cout<<" ingresa el valor de b:";cin>>b; 

    cout<<"\n\n valores ingresados \n";
    cout<<" a:"<<a<<endl;
    cout<<" b:"<<b<<endl;

    // intercambio de variables
    aux=a;
    a=b;
    b=aux;

    cout<<"\n\n valores ingresados intercambiados \n";
    cout<<" a:"<<a<<endl;
    cout<<" b:"<<b<<endl;
    
    return 0; 
}