#include <iostream>

using namespace std;



// en el caso de de sacar el factorial cde un numero empleamos la recursividad 
// de la siguiente manera


int factorial_num(int a){ // declaramos una funcion que reciba como para metro un numero entero
    if(a==1){ // en caso de que el valor del parametro sea 1 la funcion retornara automaticamente 1
        return 1;
    }
    else{
        // aqui aplicamos la recursividad 
        // aqui la funcion es llamada a si misma pero pasandole un numero menor 
        // y asi sucecivamente hasta llegar a 1 deteniendo el autollamado
        // se realiza el retorno de los valores tomados por cada llamdo de la funcion 
        // realizanso asi las correpondientes multiplicaciones de dichos valores 
        // obteniedo asi el valor final a retornar por la funcion que inicio todo
        return a*factorial_num(a-1);
    }
}

// solicitamos el numero al cual le sacaremos el factorial
void pedir_factorial(int &w){ // aplicamos el termino de prametro por refencia para asignar el valor a la variable pasada como parametro
    cout<<"Digite dato para calcular factorial"<<endl;
    cin>>w;
}

int main() {
    // declaracion de variable a factorizar
    int num1;
    // imvocamos la funcion para asiganr un valor a la variable a factorizar 
    pedir_factorial(num1);
    // mostramos el resultado en pantalla utilizando la funcion declarada anteriormente 
    // para hallar el factorial de un numero usando recursividad 
    cout<<"El factorial es:"<<factorial_num(num1)<<endl;
    return 0;
}