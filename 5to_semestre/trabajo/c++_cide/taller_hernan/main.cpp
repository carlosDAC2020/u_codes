#include <iostream>
#include <fstream> 
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
using namespace std;

struct trabajador{
    string cod;
    float horas_trabajadas[100];
};
trabajador lst_trbj[100];
int cant_trabajadores=0;
int jornadas=0;

int menu();
void ingreso_datos();
void horas_por_hombre();
void horas_por_jornada();
void horas_total_trabajadas();

int main() {

    int go=1;
	while (go<7){
        switch (menu()) {
            case 1: 
                ingreso_datos();
            break;
            case 2: 
                horas_por_hombre();
            break;
            case 3:
                horas_por_jornada();
            break;
            case 4:
                horas_total_trabajadas();
            break;
            case 5:
                go=5; 
            break;
            default: ;
        }
    }
    return 0;
}


int menu(){
    cout<<"\n REGISTRO DE TRANAJADORES \n";
    cout<<"--->1 ingreso de notas de los trabajadoires \n";
    cout<<"--->2 El total de horas trabajadas por cada hombre.   \n";
    cout<<"--->3 El total de horas trabajadas en cada jornada.  \n";
    cout<<"--->4 El total de horas trabajadas por todos los hombres en toda la obra.  \n";
    cout<<"--->5 salir del progarma \n";

    int option;
    cout<<" escoja el numero de su opcion:";cin>>option;
    while (option>5 || option<1){
        cout<<"\n valor ingresado no valido\n";
        cout<<" escoja el numero de su opcion nuevamente:";cin>>option;
    }
    return option;
}


void ingreso_datos(){
    cout<<"\n\n INGRESO DE DATOS  \n";
    cout<<" numero de empleados: ";cin>>cant_trabajadores;
    cout<<" numero de jornadas trabajadas: ";cin>>jornadas;

    for (int i = 0; i < cant_trabajadores; i++)
    {
        cout<<"\n Empleado "<<i+1<<endl;
        cout<<" Codigo: ";cin>>lst_trbj[i].cod;
        cout<<" Horas trabajadas \n";
        for (int j = 0; j < jornadas; j++)
        {
            cout<<" jornada "<<j+1<<": ";cin>>lst_trbj[i].horas_trabajadas[j];
        }
    }
    
    // declaramos el arvhivo jornadas.csv para guardar los datos 
    ofstream archivo; 
	archivo.open("jornadas.csv", ios::out);
    if (archivo.fail()) {
		exit(1);
	} 

    // escribimos los datos en el archivo
    for (int  i = 0; i < cant_trabajadores; i++){
        // escrubimos el codigo 
        archivo<<lst_trbj[i].cod<<";";
        // escribimos las horas trabajadas por cada jornada 
        for (int j = 0; j < jornadas; j++)
        {
            archivo<<lst_trbj[i].horas_trabajadas[j]<<",";
        }
        archivo<<endl;
    }
    archivo.close();
}


void horas_por_hombre(){

    float sum_horas;
    
    cout<<"\n\n TOATL HORAS POR TRABAJADOR \n";
    cout<<" Codigo    toatal horas trabajadas\n";
    for (int i = 0; i < cant_trabajadores; i++)
    {
        cout<<lst_trbj[i].cod<<": ";
        sum_horas=0;
        for (int j = 0; j < jornadas; j++)
        {
            sum_horas+=lst_trbj[i].horas_trabajadas[j];
        }
        cout<<sum_horas<<endl;
    }
}

void horas_por_jornada(){

    float sum_horas;

    cout<<"\n\n TOATL HORAS POR JORNADA \n";
    for (int j = 0; j < cant_trabajadores; j++)
    {
        cout<<"jornada "<<j+1<<": ";
        sum_horas=0;
        for (int i = 0; i < cant_trabajadores; i++)
        {
            sum_horas+=lst_trbj[i].horas_trabajadas[j];
        }
        cout<<sum_horas<<endl;
    }
}

void horas_total_trabajadas(){
    float sum_horas=0;

    for (int j = 0; j < cant_trabajadores; j++)
    {   
        for (int i = 0; i < cant_trabajadores; i++)
        {
            sum_horas+=lst_trbj[i].horas_trabajadas[j];
        }
    }
    cout<<"\n\n TOATL HORAS TRABAJADAS EN LA OBRA : "<<sum_horas<<" horas"<<endl;
}
