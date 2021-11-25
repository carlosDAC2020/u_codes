#include <iostream>
using namespace std;
const int n=500;

//Funcion STRUCT
struct persona {
  string nombre;
  string cedula;
  int sexo;
  int tipo;
  double salario;
};

persona list_empleados[n];


    // entrada de datos
void ingreso_datos(int x){
    for (int i=0; i < x; i++){
        cout<<"\n empleado "<<i+1<<endl;
        cout<<" nombre: ";cin>>list_empleados[i].nombre;

        cout<<" cedula: ";cin>>list_empleados[i].cedula;

        cout<<" sexo \n 1->femenino\n 2->masculino \n ingrese el numero correspondiente: ";cin>>list_empleados[i].sexo;
        // validacion del ingreso del sexo 
        while (list_empleados[i].sexo<1 || list_empleados[i].sexo>2){
            cout<<" valor ingresado erroneamnete \n";
            cout<<" ingrese su sexo nuevamente: ";cin>>list_empleados[i].sexo;
        }
        
        cout<<" tipo de contrato \n 1-> C\n 2-> S \n ingrese el numero correspondiente: ";cin>>list_empleados[i].tipo;
        // validacion del ingreso del tipo 
        while (list_empleados[i].tipo<1 || list_empleados[i].tipo>2){
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
    int cant_ganan_2M=0;

    for(int i=0; i<x; i++){
        // identificamos hombres y mujeres
        if(list_empleados[i].sexo==1){
            cant_mujeres+=1;
        }
        else{
            cant_hombres+=1;
        }

        // identificamos los tipos de empleados 
        if(list_empleados[i].tipo==1){
            cant_t_c+=1;
        }
        else{
            cant_t_s+=1;
        }

        // indentificamos a personas que ganen mas de 2 millones 
        if (list_empleados[i].salario>=2000000){
            cant_ganan_2M+=1;
        }
        
    }
    // porcentage de hombres
    cout<<"\n el procentaje de hombres es de :"<<(cant_hombres*100)/x<<endl;
    // porcentaje de mujeres 
    cout<<" el procentaje de mujeres es de :"<<(cant_mujeres*100)/x<<endl;
    // cantidad de emplesdos con contrato tipo c
    cout<<" la cantidad de empleados con contrato tipo c es de: "<<cant_t_c<<endl;
    // cantidad de empleados por prestasion de servicios tipo s
    cout<<" la cantidad de emplerados por prestacion de servicios tipo s es de: "<<cant_t_s<<endl;
    // cantidad de  personas con ingresos mayores a 2 millones 
    cout<<" cantidad de empleados que ganan mas de 2 millones: "<<cant_ganan_2M<<endl;

}

    // mostrar lista de encuestados 
void list_encuestados(int x){
    
}

int main() {
  int cant;
  cout<<" cantidad de personas a encuestar: ";cin>>cant;

  ingreso_datos(cant);

  estadisticas(cant);

  return 0;
}