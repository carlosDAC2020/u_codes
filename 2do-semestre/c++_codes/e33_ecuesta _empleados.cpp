#include <iostream>
using namespace std;
const int n=500;

//Funcion STRUCT
struct persona {
  string nombre;
  string cedula;
  char sexo;
  char tipo;
  double salario;
};

persona list_empleados[n]


    // entrada de datos
void ingreso_datos(int x){
    for (int i=0; i < x; i++){
        cout<<" empleado "<<i+1<<endl;
        cout<<" nombre: ";cin>>list_empleados[i].nombre;

        cout<<" cedula: ";cin>>list_empleados[i].cedula;

        cout<<" sexo (f o m): ";cin>>list_empleados[i].sexo;
        // validacion del ingreso del sexo 
        while (list_empleados[i].sexo!="f" || list_empleados[i].sexo="F" || list_empleados[i].sexo="m" || list_empleados[i].sexo="M"){
            cout<<" valor ingresado erroneamnete \n";
            cout<<" ingrese su sexo nuevamente: ";cin>>list_empleados[i].sexo;
        }
        
        cout<<" tipo (c o s): ";cin>>list_empleados[i].tipo;
        // validacion del ingreso del tipo 
        while (list_empleados[i].tipo!="c" || list_empleados[i].tipo="C" || list_empleados[i].tipo="s" || list_empleados[i].tipo="M}S"){
            cout<<" valor ingresado erroneamnete \n";
            cout<<" ingrese su tipo nuevamente: ";cin>>list_empleados[i].tipo;
        }

        cout<<" salario: ";cin>>list_empleados[i].salario;
    }
}

    // mostrar estadisticas generales 
void estadisticas(int x){
        // cantidades de cada sexo
    int cant_hombres=0, cant_mujeres=0;
        // cantidades de cada tipo de empleado
    int cant_t_c=0, cant_t_s=0;
        // gannan dos milones o mas 
    int cant_ganan_2M=0

    for(int i=0; i<x; i++){
        // identificamos hombres y mujeres
        if(list_empleados[i].sexo=="f" || list_empleados[i].sexo=="F"){
            cant_mujeres+=1;
        }
        else{
            cant_hombres+=1;
        }

    }


    // porcentage de hombres
    // porcentaje de mujeres 
    // cantidad de emplesdos con contrato tipo c
    // cantidad de empleados por prestasion de servicios tipo s
    // cantidad de  personas con ingresos mayores a 2 millones 

}

    // mostrar lista de encuestados 
void list_encuestados(int x){

}

int main() {
  int cant;
  cout<<" cantidad de personas a encuestar: ";cin>>cant;

  ingreso_datos(cant);
  return 0;
}