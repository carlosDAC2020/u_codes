#include <iostream>

using namespace std;

//Tipo de función nombre de la función (Parámetros de entrada función){
//cuerpo de la función

//}

//Filosofia de programación o paradigma de programación que sirve para optimizar el recurso computacional: 

//Existe dos casos:
//Caso base que es el que define cuando debe parar la recursividad
//Caso recusivo que es donde la función se hace el auto-llamado 

//Las funciones que pueden ser recursivas dependerá de que la función tenga un caracter ciclico, repetitivo. 

//2*4=2+2+2+2
//a*b=a+a+a+....bveces 

//5!=5*4*3*2*1

//Parámetros por valor 

int factorial_num(int a){
    if(a==1){
        return 1;
    }
    else{
        return a*factorial_num(a-1);
    }
}

void pedir_factorial(int w){
cout<<"Digite dato para calcular factorial"<<endl;
cin>>w;

}

int main() {
    int num1;
    pedir_factorial(num1);
    cout<<"El factorial es:"<<factorial_num(num1)<<endl;
    return 0;
}