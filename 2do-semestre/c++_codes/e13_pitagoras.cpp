/* enunciados
aplicacion del teorema de pitagoras
*/
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int go=1;
    while(go==1){
        // declaramos varibles
        float hipotenusa, cat_opuesto, cat_adyacente;

        cout<<" aplicssion general del teorema de pitsgoras \n";
        cout<<" probemoslo al encontarar una de las siguientes opciones \n";
        cout<<" 1) hipotenusa\n 2) cateto opuesto\n 3) cateto adyacenet\n";

        // solicitamos la opcion al usuario
        int op ;
        cout<<"\n cual de las 3 opciones deceas encotar?: ";cin>>op;

        // validamos la opcion ingresada
        while(op<1 || op>3){
            cout<<"\n opcion ingresada no valida!!\n";
            cout<<" ingresa la opcion que deceas encotar nuevamente: ";cin>>op;
        }

        // evaluamos la opcion ingresada y aplicamos el teorema de pitagoras o su despeje correspondiente
        if(op==1){
            cout<<"\n hallaemos la hipotenusa \n";
            cout<<" valor del cateto opuesto: ";cin>>cat_opuesto;
            cout<<" valor del cateto adyacente: ";cin>>cat_adyacente;
            hipotenusa=sqrt( (pow(cat_adyacente,2)) + (pow(cat_opuesto,2)) );
            cout<<" la hipotenusa es igual a "<<hipotenusa;
        }
        else if(op==2){
            cout<<"\n hallaemos el cateto opuesto \n";
            cout<<" valor de la hipotenusa: ";cin>>hipotenusa;
            cout<<" valor del cateto adyacente: ";cin>>cat_adyacente;
            cat_opuesto=sqrt( (pow(hipotenusa,2)) - (pow(cat_adyacente,2)) );
            cout<<" el cateto opuesto es igual a "<<cat_opuesto;
        }
        else{
            cout<<"\n hallaemos el cateto adyacente \n";
            cout<<" valor de la hipotenusa: ";cin>>hipotenusa;
            cout<<" valor del cateto opuesto: ";cin>>cat_opuesto;
            cat_adyacente=sqrt( (pow(hipotenusa,2)) - (pow(cat_opuesto,2)) );
            cout<<" el cateto adyacente es igual a "<<cat_adyacente;
        }
        cout<<" \n desea probar el programa otra vez? \n 1 para si\n != para no\n ---> ";cin>>go;
    }

    cout<<"\n\n HASTA LA PROXIMAAA :) !!!!"; 
    
    return 0;
}
