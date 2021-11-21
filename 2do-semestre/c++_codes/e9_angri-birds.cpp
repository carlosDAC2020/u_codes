/*
enunciado
desarrolle un algoritmo donde calcule la velocudad de lanzamiento
necesaria para que un angri bird lanzado desde el piso 
con una incllinacion de 40° sobrepase un onjetivo dispuesto a 503
metros de distancia, teniendo en cuenta que se rije mediamte
el calculo del movimiento parabolico uniforme
*/
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main(){
    //declaramos variables 
    int  angulo=45;
    float gravedad=9.8,vel_inicial, dist_object=503.0, dist_alcanzada;
    string pregunta="si";

    while(pregunta=="si"){
        int option;

        cout<<"quw prefieres usar para hayar la velocidad inicial?\n";
        cout<<"1 prueba con distintos valores n veces\n";
        cout<<"2 usa un rango de valores\n";

        // solicitasmos al usuario su opcion deceada para resolver el problema
        cout<<"ingresa aqui tu opcion deceada:";cin>>option;
        /*while(option!=1 || option!=2){// validacion 
            cout<<"\n ingreso un valor no valido\n";
            cout<<"ingresa aqui tu opcion deceada (1 o 2):";cin>>option;
        }*/
        // opcion 1
        if(option==1){
            int intentos;
            cout<<"\n opcion 1\n ingresa varios valores de velocidad inicial para probarlos\n";
            cout<<"ingresa el numero de intentos a realizar:";cin>>intentos;
            // procedemos a realizar intentos
            for (int i=1; i<=intentos; i++){
                cout<<"\nintento"<<i<<endl;
                // pedimos valor de la velocidad inicial 
                cout<<"velocidad inicial:";cin>>vel_inicial;
                // procedemos a encontar la distancia alcanzada usando la formula del movimiento parabolico
                dist_alcanzada=(pow(vel_inicial,2) / gravedad) * sin(2*angulo);

                cout<<"la distancia alcanzada fue de "<<dist_alcanzada<<" m\n";

                /* dependiendo el resultado de la distancia alcanzada evaluamos 
                si llega a superar o no el objetivo
                */
                if (dist_alcanzada > dist_object || dist_alcanzada<503.99){
                    cout<<"felicidades ha alcanzado el objetivo\n";
                }
                else if (dist_alcanzada < dist_object ){
                    cout<<"no alcanzo el objetivo \nle faltaron "<<dist_object - dist_alcanzada<<" metros\n";
                }
                else{
                     cout<<"ha sobrepasado el objetivo por "<<dist_alcanzada - dist_object<<" metros\n";
                }
            }
        }
        // opcion 2
        else{
            cout<<"\n usemos un rango de valores para la velocidad inicial y ver si damos con el objetivo \n";
            float n1, n2;
            /*pedimos al usuario un valor inicial y final para el rango de valores 
            a utilizar 
            */
            cout<<"ingresa el valor inicial:";cin>>n1;
            cout<<"ingresa el valor final:";cin>>n2;
            // validamos q el valor final sea mayor al valor inicial
            while(n2 < n1){
                cout<<"\n el valor final debe ser menor al valor inicial\n";
                cout<<"ingresa el valor final:";cin>>n2;
            }
            // declaramos variables auxiliares 
            int valores=0; // cantidad total de valores
            int herrados=0; // cantidad total de valores herrados 
            float vel_correcta; // variable que toma la velocidad necesaria para llegar al objetivo
            float dist_correcta; // distancia que se alcansa con la velocidad correcta

            // evaluamos dicho rango de valores
            while(n1 <= n2){
                // se toms como valor de velocidad inicial el primer valor del rango
                vel_inicial=n1;
                // encontramos la distancia alcanzada
                dist_alcanzada=(pow(vel_inicial,2) / gravedad) * sin(2*angulo);
                /*
                en el momneto en que la velocidad alcanzada sea igual al del objetivo
                se ejecutara lo siguiente
                */
                if (dist_alcanzada > dist_object || dist_alcanzada<503.3){
                    vel_correcta= vel_inicial;
                    dist_correcta= dist_alcanzada;
                }
                else{
                    herrados+=1; // se contabilizan la cantidad de valores q no llegan al objetivo
                }

                valores+=1; // se contabilizan la cantidad de valores del rango
                n1+=0.1; // a esta variable se le ira sumando 0.1 hasta llegar al valor final del rango
            }

            if (herrados != valores){
                cout<<"\n la vdelocidad necesaria para que el Angri Bird alcance al objetivo debe ser de:"<<vel_correcta<<"Km/h\n";
                cout<<"la distancia  recorrida fue de:"<<dist_correcta<<"m\n";
            }
            else{
                cout<<"\n en el rango in gresado no se encontro ningun valor de velocidad correcta\n";
            }
        }
        cout<<"\ndesea volver al menu inicial (si o n0)";cin>>pregunta;

    }
   

    return 0;
}