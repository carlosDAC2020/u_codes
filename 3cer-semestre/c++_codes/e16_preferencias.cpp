/*
preguntarle a n cantidad de usuarios por sus poreferencia 
y obteber la cantidad de personas por cada preferencia 
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    string nombre, apellido, preferencias="";
    int edad, opcion , cant_p, cant_p1=0, cant_p2=0, cant_p3=0, cant_p4=0, cant_p5=0;

    cout<<" ENCUESTA DE PREFERENCIAS \n";
    cout<<" canntidad de personas a pregunatar: ";cin>>cant_p;

    for (int i = 1; i <= cant_p; i++)
    {
        cout<<" datos persona "<<i<<endl;
        cout<<" nombre: ";cin>>nombre;
        cout<<" apellido: ";cin>>apellido;
        cout<<" edad: ";cin>>edad;

        cout<<"  preferencias\n";
        cout<<" 1 deportes \n 2 musica \n 3 historia \n 4 matematicas \n 5 dormir \n";
        cout<<" eliga el numero de su opcion: ";cin>>opcion;
        while(opcion<1 || opcion>5){
            cout<<"\n\n valor ingresado no valido \n";
            cout<<" ingresa la opcion de  su preferencia nuevamente. ";cin>>opcion;
        }
        if (opcion==1){
            preferencias="deportes";
            cant_p1+=1;
        }
        else if(opcion==2){
            preferencias="musica";
            cant_p2+=1;
        }
        else if(opcion==3){
            preferencias="historia";
            cant_p3+=1;
        }
        else if(opcion==4){
            preferencias="matematicas";
            cant_p4+=1;
        }
        else {
            preferencias="dormir";
            cant_p5+=1;
        }
        
        cout<<"\n MENSAJE\n";
        cout<<" estimado/a "<<nombre<<" "<<apellido<<" su preferencia es "<<preferencias<<" y tu edad "<<edad<<" años\n";
        
        cout<<"---------------------------------------\n";
    }

    cout<<" CANTIDAD DE PERSONAS PRO PREFERENCIA \n";
    cout<<"  Deportes: "<<cant_p1<<endl;
    cout<<"  Musica: "<<cant_p2<<endl;
    cout<<"  Historia: "<<cant_p3<<endl;
    cout<<"  Matematicas: "<<cant_p4<<endl;
    cout<<"  Dormir: "<<cant_p5<<endl;

    return 0;
}