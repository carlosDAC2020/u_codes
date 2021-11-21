/*
imprimir n numeros primos
*/
#include <iostream>
using namespace std;

// funcion para saber si un numrto es primo o no 
bool es_primo(int n){
    if (n==2){// si el nuemro tomado como parametro es 2 de una se asume q es primo
        return true;
    }
    for (int i=2; i<n; i++){
        if (n%i==0){// evalaumos si el nuemro es divicible por los mumeros anteriores a el 
            return false;
        }
    }
    return true;// si el numero en la evaluacion anterior del siclo resulta no ser divicible por ninguno entonces es primo
}

int main(){
    // declaramos variable
    int num,con=0,aux=1;
    bool primo;
    cout<<"imprimamos cantidad n de numeros"<<endl;
    cout<<"ingresa un numero:";cin>>num;

    cout<<endl<<"numeros primos"<<endl;
    
    while(con<=num){
        primo= es_primo(aux);
        if(primo==true){
            cout<<"--"<<aux<<endl;
            con+=1;
        }
        aux+=1;
    }
    return 0;
}