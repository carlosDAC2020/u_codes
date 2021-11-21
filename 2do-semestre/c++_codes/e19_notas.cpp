/*
carlos daniel agamez palomino T00059006
*/


#include <iostream>
using namespace std;

int main(){
    // declaracion de variables
    float  n1, n2, n3, min_parcial, parcial, nota_definitiva;
    cout<<" solicitamos las notas \n";
    // ingreso y validacion de notas
    cout<<"--------------------------------------------\n";
    cout<<"\n ingrese la nota del corte 1:";cin>>n1;
    while(n1<0 || n1>5){
        cout<<" \n valor ingresado es erroneo!!! \n";
        cout<<" ingrese la nota del corte 1 nuevamente: ";cin>>n1;
    }
    cout<<"--------------------------------------------\n";
    cout<<"\n ingrese la nota del corte 2:";cin>>n2;
    while(n2<0 || n2>5){
        cout<<" \n valor ingresado es erroneo!!! \n";
        cout<<" ingrese la nota del corte 2 nuevamente: ";cin>>n2;
    }
    cout<<"--------------------------------------------\n";
    cout<<"\n ingrese la nota del corte 3:";cin>>n3;
    while(n3<0 || n3>5){
        cout<<" \n valor ingresado es erroneo!!! \n";
        cout<<" ingrese la nota del corte 3 nuevamente: ";cin>>n3;
    }
    min_parcial = (3.0 - (n1*0.25) - (n2*0.25) - (n3*0.2)) / 3.0;
    cout<< "\n Necesita sacar: " << min_parcial << " para ganar la materia con la nota minima aprobatoria. \n";
    cout<<"--------------------------------------------\n";
    cout<<"\n ingrese la nota del parcial:";cin>>parcial;
    while(parcial<0 || parcial>5){
        cout<<" \n valor ingresado es erroneo!!! \n";
        cout<<" ingrese la nota del parcial nuevamente: ";cin>>parcial;
    }
    
    nota_definitiva = (n1 * 0.25) + (n2 * 0.25) + (n3 * 0.2) + (parcial * 0.3);

    if (nota_definitiva >= 3.0){
        cout << "\nSu nota definitiva: " << nota_definitiva;
        cout << "\nAprobo la materia. Felicitaciones. ";
    }
    else{
        cout << "\nSu nota definitiva: " << nota_definitiva;
        cout << "\nNo aprobo la materia.\nLo siento mucho. ";
    }


    return 0;
}

/* el siguente bloque seria una opcion para la solicitud de las notas
    teneido como diferencia que en esta nos evitamos repetir las lines
    del ingreso de las notas y sus correspondientes validaciones 
    
    tal ves esta opcion sea algo mas confusa de echo me costo mucho hacerla 
    pero si le soy sincero profe queria evaluar una forma de evitar escirbir
    las mimas lineas varias veces 
    disculpe la flojera no me gusta repetir las cosas jajajajajaja */ 
    /*int  nota;
    for (int i=1; i<=4; i++){
        cout<<"--------------------------------------------\n";
        nota=-1;
        // este ciclo while auto valida las notas a la par en que se ingresan
        while(nota<0 || nota>5){
            // ingreso de las notas 
            if(i<4){// esto en caso de las notas de los cortes
                cout<<" nota del corte"<<i<<": ";cin>>nota;
            }
            else{// esto en el caso de la nota del parcail
                cout<<" nota del parcial: ";cin>>nota;
            }
            // validacion de a que nota pertenece
            switch(i){
                case 1: n1=nota;
                cout<<"nota1:"<<n1<<"\n";
                break;
                case 2: n2=nota;
                cout<<"nota2:"<<n2<<"\n";
                break;
                case 3: n3=nota;
                cout<<"nota3:"<<n3<<"\n";
                break;
                default: parcial=nota;
            }
            // impreciion en el caso de que la nota ingresada sea invalida
            if(nota<0 || nota>5){
                cout<<"\n valor ingresado no valido porfavor editar!!\n"; 
            }
        }
        // imprecion para indicar la nota necesaria del parcaial para ganar 
        if(i==3){// esta solo se realizara despues de validar el ingreso de la nota 3
                if(nota>=0 || nota<=5){
                    min_parcial = (3.0 - (n1*0.25) - (n2*0.25) - (n3*0.2)) / 3.0;
                    cout << "\n Necesita sacar: " << min_parcial << " para ganar la materia con la nota minima aprobatoria. \n";
                }
            }

    }*/
    // puede  situarlo entre la declaracion de las variables y de la operacion de la nota final y obtendra los mismos resultados ;)

