#include <iostream>
#include <string>
using namespace std;

int main(){
    // declaracion de variables a utilizar 
    string codigo;
    int tipo, n_paginas;
    float precio_libro=0, valor_inventario=0;

    int go=1, l=1;
    // usamos un ciclo while ya que no sabemos exactamente cuantos libros vamos a contabilizaar 
    while(go==1){
        // solicitamos datos del libro al usuario 
        cout<<" datos del libro "<<l<<"\n";
        cout<<" codigo: ";cin>>codigo;
        cout<<" tipo: ";cin>>tipo;
        while(tipo<1 || tipo>4){
            cout<<"\n valor ingresado no valido ingresa el tipo nuevamente\n";
            cout<<" tipo: ";cin>>tipo;
        }
        cout<<" # paginas: ";cin>>n_paginas;
        // asignamos el precio total del libro segun su tipo 
        switch(tipo){
            case 1: precio_libro = 10000 + (50 * n_paginas);
                    break;
            case 2: precio_libro = 15000 + (70 * n_paginas);
                    break;
            case 3: precio_libro = 20000 + (90 * n_paginas);
                    break;
            default:precio_libro = 25000 + (120 * n_paginas);
        }
        // vamos calculando el valor del inventario
        valor_inventario+=precio_libro;
        // imprecion de los resultados
        cout<<"\nEl precio del libro"<<l<<" es: $"<<precio_libro;
        cout<<"\nEl valor del inventario es: $"<<valor_inventario;
        // preguntamos al usuario si tiene mas libros para evaluar
        cout<<"\n desea seguir contabilizando libros?\n 1 para si\n !=1 para no\n -->";cin>>go;
        l+=1;
    }

    return 0;
}