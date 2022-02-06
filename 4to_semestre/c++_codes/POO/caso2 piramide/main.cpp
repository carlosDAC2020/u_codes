#include <iostream>
#include "piramide.h"
#include <math.h>
using namespace std;

int main(){
    // cramos el objeto
    Piramide a;

    // variables auxiliares para asignar los atributos al objeto
    float aux_altura, aux_lado_base;

    // solicitud de datos al usuario
    cout<<" ingresa los datos de la piramide \n";
    cout<<"altura: ";cin>>aux_altura; 
    cout<<"lado de la base: ";cin>>aux_lado_base; 
    
    // asignacion de los valores de los atributos por medio de los metodos get
    a.getaltura(aux_altura);
    a.getlasdo_base(aux_lado_base);

    // imprimimos los datos del objeto
    a.imprime();

    return 0;
}