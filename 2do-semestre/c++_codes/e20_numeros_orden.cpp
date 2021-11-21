

#include <iostream>
using namespace std;

int main(){
    // declaracion de variables
    int  a, b, c;
    // ingresamos los valores de a b y c
    cout<<" ingresa el valor de a:";cin>>a;
    cout<<" ingresa el valor de a:";cin>>a;
    while(b==a){ // con los ciclos while validamos que no halla ningun numero repetiso
        cout<<"\n ingresa un valor diferente de a\n";
        cout<<" ingresa el valor de b:";cin>>b;
    }
    cout<<" ingresa el valor de c:";cin>>c;
    while(c==a || c==b){
        cout<<"\n ingresa un valor diferente de a y b\n";
        cout<<" ingresa el valor de c:";cin>>c;
    }
    // realizamos el ordenamiento de los numeros usando las condicionales if 
    cout<<"\n numeros ingresados en orden decendente \n";
    if(a>b || a>c){
        if(b>c){
            cout<<a<<">"<<b<<">"<<c;
        }
        else{
            cout<<a<<">"<<c<<">"<<b;
        }
    }
    else if(b>a || b>c){
        if(a>c){
            cout<<b<<">"<<a<<">"<<c;
        }
        else{
            cout<<b<<">"<<c<<">"<<a;
        }
    }
    else{
        if(a>b){
            cout<<c<<">"<<a<<">"<<b;
        }
        else{
            cout<<c<<">"<<b<<">"<<a;
        }
    }
    return 0;
}
