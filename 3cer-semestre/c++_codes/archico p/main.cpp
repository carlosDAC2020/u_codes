/*
estudiante : Luis Angel Tapia
codigo: T00064276
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;  

struct estudiante{
    string codigo;
    string nombre;
    string apellido;
    string programa;
    float promedio=0.0;
};

struct matrs{
    string name;
    float nota;
};


estudiante est[100];

void menu(){
    cout<<" MENU "<<endl;
    cout<<" 1 --> pedir informacion "<<endl;
    cout<<" 2 --> calcular promedios e imprimir imformacion de un estudiante "<<endl;
}


void llenar(int n){
    ofstream datos_estudiantes; 
	datos_estudiantes.open("datos_estudiantes.csv", ios::out);

    for(int i=0; i<n; i++){
        datos_estudiantes<<est[i].codigo<<";"<<est[i].nombre<<";"<<est[i].apellido<<";"<<est[i].programa<<";"<<est[i].promedio<<endl;
    }
    datos_estudiantes.close();
}

void pedir_datos(int n){
    cout<<"\n solicitud de datos\n";
    for(int i=0; i<n; i++){
        cout<<" estudisnte "<<i+1<<endl;
        cout<<" codigo :";cin>>est[i].codigo;
        cout<<" nombre :";cin>>est[i].nombre;
        cout<<" apellido :";cin>>est[i].apellido;
        cout<<" programa :";cin>>est[i].programa;
    }
    

}



void calculo_promedio(int n){
    string code;
    int id, cant_materias, sum_creditos=0, sum_n_x_c=0, n_creditos;
    float nota_f, prom_ponderado;
    cout<<" codigo del estudiante a calcular el promedio:";cin>>code;
    for(int i=0; i<n; i++){
        if(est[i].codigo==code){
            id=i;
        }
    }
    cout<<" hola "<<est[id].nombre<<" "<<est[id].apellido<<" calculemos tu promedio\n";
    cout<<" ingresa cantidad de materias a evaluar:";cin>>cant_materias;

    matrs list_materias[cant_materias];

    for (int i = 0; i < cant_materias; i++){
        cout<<"\n materia "<<i+1<<endl;
        cout<<" nombre:";cin>>list_materias[i].name;
        cout<<" numero de creditos:";cin>>n_creditos;
        sum_creditos+=n_creditos;
        cout<<" nota final:";cin>>nota_f;
        list_materias[i].nota=nota_f;
        while (nota_f<0 || nota_f>5){
            cout<<"\n valor ingresado herroneo \n";
            cout<<" ingrese la nota final nuevamenete:";cin>>nota_f;
        }
        sum_n_x_c+=nota_f*n_creditos;
    }
    prom_ponderado=sum_n_x_c/sum_creditos;

    est[id].promedio=prom_ponderado;

    cout<<" "<<est[id].codigo<<"   "<<est[id].nombre<<" "<<est[id].apellido<<endl;
    cout<<" que esta en el programa de "<<est[id].programa<<endl;
    cout<<"\n tuvo las siguientes notas este semestre \n";
    cout<<" materia        nota \n";
    for (int i = 0; i < cant_materias; i++){
       cout<<list_materias[i].name<<"     "<<list_materias[i].nota<<endl;
    }
    cout<<"\n el promedio genral del estudisnte fue de "<<est[id].promedio<<endl;
}

int main() { 
    int cant, op, go=1;
    while (go==1){
        menu();
        cout<<"\n ingrese el numero de la opcion que decea realizar:";cin>>op;
        while(op>4 || op<1){
            cout<<" valor ingresado erroneo \n";
            cout<<"\n ingrese el numero de la opcion que decea realizar nuevamente:";cin>>op;
        }

        if (op==1){
            cout<<"\n cantidad de estudiantes a evaluar :";cin>>cant;
            pedir_datos(cant);
        }
        else if (op==2){
            calculo_promedio(cant);
        }
        
        

        // guardamos la informacion en un archico
        llenar(cant);

        cout<<"\n 1 para vover al menu :";cin>>cant;
    }
    
    
    return 0; 
}