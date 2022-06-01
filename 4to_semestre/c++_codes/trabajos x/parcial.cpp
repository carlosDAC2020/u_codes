
// sammi monsalve gonzalez t00063539

#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


const int n=30;

struct persona{
    string cedula;
    string nombre;
    int sexo;
    int tipo;
    double salario;
};

persona list_empleados[n];

void entrada_datos(int cant_e){
    cout<<" solicitamos los datos a loa encuestados \n";
    // solucitamos los datos usando un ciclo for 
    for (int i = 0; i < cant_e; i++){
        cout<<"\n Encuestado "<<i+1<<endl;
        cout<<" cedula:";cin>>list_empleados[i].cedula;
        cout<<" nombre:";cin>>list_empleados[i].nombre;
        // solicitamos y validamos el sexo del encuestado
        do
        {
            cout<<" sexo \n 1=femenino \n 2=masculino \n ingrese el valor->";cin>>list_empleados[i].sexo;
        }
         while (list_empleados[i].sexo<1 || list_empleados[i].sexo>2);
        
        // solicitamos y validamos el salario del encuestado
        do
        {
            cout<<" salario:";cin>>list_empleados[i].salario;
        } 
        while (list_empleados[i].salario<0);
        
        // solicitamos y validamos el tipo de empleado
        do
        {
           
            cout<<" tipo de empleado \n 1 = por contrato \n 2 = prestacion de servicios \n ingrese vslor ->";cin>>list_empleados[i].tipo;
        }
        while (list_empleados[i].tipo<1 || list_empleados[i].tipo>2);

        cout<<"\n-------------------------------------------------------------";
    }
}

void estadisticas(int cant_e){

    cout<<"\n ESTADISTICAS GENERALES \n";

    // variables auxiliares a utilizar 
    int cant_m=0, cant_h=0;
    int cant_t_1=0, cant_t_2=0;
    int cant_e_2m=0;

    // usamos un bucle for para el procedimiento 
    for (int i = 0; i < cant_e; i++){
        // porcentaje de hombres y mujeres 
        if(list_empleados[i].sexo==1){
            cant_m+=1;
        }
        else{
            cant_h+=1;
        }
        
        // porcentajes de cada tipo de encuestad0s
        if(list_empleados[i].tipo==1){
            cant_t_1+=1;
        }
        else{
            cant_t_2+=1;
        }

        // Cantidad de personas con ingresos de más de 2 millones
        if (list_empleados[i].salario>20000000){
            cant_e_2m+=1;
        }
        
    }
    // Porcentaje de mujeres:
    cout<<" porcentaje de mujeres "<<(cant_m * 100)/cant_e<<endl;
    // Porcentaje de hombres:
    cout<<" porcentaje de hombres "<<(cant_h * 100)/cant_e<<endl;

    cout<<"  Cantidad de empleados con contrato: "<<cant_t_1<<endl;

    cout<<"  Cantidad de empleados por prestación de servicios: "<<cant_t_2<<endl;

    cout<<"  Cantidad de personas con ingresos de más de 2 millones: "<<cant_e_2m<<endl;
    
}

void lista_empleados(int cant_e){
    for (int i = 0; i < cant_e; i++){
        cout<<" encustado "<<i+1<<endl;
        cout<<" cedula:"<<list_empleados[i].cedula<<endl;
        cout<<" nombre:"<<list_empleados[i].cedula<<endl;
        cout<<" cedula:";
        if (list_empleados[i].sexo==1){
            cout<<"F"<<endl;
        }
        else{
            cout<<"M"<<endl;
        }
        cout<<" tipo de empleado:";
        if (list_empleados[i].tipo==1){
            cout<<" por contrato"<<endl;
        }
        else{
            cout<<" por prestacion de servicios "<<endl;
        }
        cout<<" salario:"<<list_empleados[i].salario;
         cout<<"\n-------------------------------------------------------------";
    }
}


int main(){
    int cant, go=1;

    while (go=1){
         cout<<"\n ENCUESTA EMPRESARIAL \n";
        cout<<" que desea hacer ? \n";
		cout<<"--->1 ingreso de datos \n";
		cout<<"--->2 mostrar estadisticas \n";
		cout<<"--->3 lista de encuestados \n";

		int option;
		cout<<" escoja el numero de su opcion:";cin>>option;
		while (option>3 || option<1){
			cout<<"\n valor ingresado no valido\n";
			cout<<" escoja el numero de su opcion nuevamente:";cin>>option;
		}

        if (option==1){ // ingreso de datos  
            do
            {
                if (cant>n){
                    cout<<"\n la cantidad ingresada no puede ser mayor a 30 empleados !!\n";
                }
                
                cout<<" cantidad de personas a encuestar:";cin>>cant;
            } while (cant>n);

            entrada_datos(cant);
		}

		else if (option==2){ // mostrar estadisticas 
            estadisticas(cant);
		}

		else { // lista de encuestados 
            cout<<"\n lista de encuestados \n";
            lista_empleados(cant);
		}
        cout<<"\n que decea hacer? \n 1--> volver al menu de inicio  \n !=1--> salir del programa \n ---->";cin>>go;

    }
    
    return 0;
}