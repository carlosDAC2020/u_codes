#include <iostream>
#include <string>
using namespace std;

int main(){
    string nombre, apellido, preferencias="";
    int edad, sexo, opcion ;

    cout<<" datos personales \n ";
    cout<<" nombre: ";cin>>nombre;
    cout<<" apellido: ";cin>>apellido;
    cout<<" edad: ";cin>>edad;

    cout<<"   sexo\n 1 hombre\n 2 mujer\n --> ";cin>>sexo;
    while(sexo<1 || sexo>2){
        cout<<"\n\n valor ingresado no valido \n";
        cout<<" ingresa el sexo nuevamente. ";cin>>sexo;
    }

    cout<<"  preferencias\n";
    cout<<" 1 deportes \n 2 musica \n 3 historia \n 4 matematicas \n 5 dormir \n";
    cout<<" eliga el numero de su opcion: ";cin>>opcion;
    while(opcion<1 || opcion>5){
        cout<<"\n\n valor ingresado no valido \n";
        cout<<" ingresa la opcion de  su preferencia nuevamente. ";cin>>opcion;
    }
    if (opcion==1){
        preferencias="deportes";
    }
    else if(opcion==2){
        preferencias="musica";
    }
    else if(opcion==3){
        preferencias="historia";
    }
    else if(opcion==4){
        preferencias="matematicas";
    }
    else {
        preferencias="dormir";
    }
    
    cout<<"\n MENSAJE\n";
    cout<<" estimado/a "<<nombre<<" "<<apellido<<" su preferencia es "<<preferencias<<" y tu edad "<<edad<<" años\n entonces usted debe hacerlo nunca es tarde para ser feliz";
    
    return 0;
}