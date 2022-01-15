#include<iostream>
// las librerias siguinttes nos permitiran usar numeros aleatorios en un rango dado 
// esto con fines practicos a la hora de probar el codigo 
#include <stdlib.h>
#include <time.h>
using namespace std;

// funciones a utilizar 

void ingreso_codigos(string codes[], int cant){ 
    cout<<"\n ingreso de codigos de los estudiantes \n";
    for(int i=0; i<cant; i++){
        cout<<"\n estudiante "<<i+1<<endl;
        cout<<" ingrese su codigo:";cin>>codes[i];
    }
}

const int m=1000;
void ingreso_horas(int horas[][m], int filas, int columnas ){
    // variable que almacenara valores para asignarlos en la matriz
	int valor; 
	// funciones para obtener numeros aleatorios
	srand(time(NULL));
	// asignamos avalores a la matriz usando un bucle for anidado
	for (int fl=0; fl<filas; fl++){
		for (int col=0; col<columnas; col++){
			// asignamos un numero aleatorio al valor
			valor=1 + rand() % (11-1); // el rango de los valores seran del 1 al 10
			// añadimos el valor a la matriz
			horas[fl][col]=valor;
		}
	}
}

void print_tabla(int horas[][m], int filas, int columnas){
    cout<<"\n\n                dias de investogacion \n";
    cout<<" estudiante  | ";
    for(int i=0; i<columnas; i++){
        cout<<"  "<<i+1<<"   ";
    }
    cout<<endl;
    for(int f=0; f<filas; f++){
        cout<<"  "<<f+1<<"        ";
        for(int c=0; c<columnas; c++){
            cout<<"     "<<horas[f][c]<"  ";
        }
        cout<<endl;
    }
}

void print_codigos(string codes[], int cant){
    cout<<"\n-------------------------------\n";
    cout<<" estudiante | codigo    \n";
    cout<<"-------------------------------\n";
    for(int i=0; i<cant; i++){
        cout<<"   "<<i+1<<"          "<<codes[i]<<endl;
    }
}


void lista_ordenada(int horas[][m], string codes[], int filas, int columnas){
    // lista de las horas totales de investigacion por cada estudiante
    int h_t_x_estudiante[filas];
    int sum_f;
    // obtenemos las horas totales de investigacion de cada estudiante
	for (int f=0; f<=filas-1;f++){
		sum_f=0;
		for (int c=0; c<=columnas-1; c++){
			sum_f+=horas[f][c];
			}
		h_t_x_estudiante[f]=sum_f;
    }

    // pasamos a ordenar la lista de horas totales obtenidas por cada estudiante de forma acendente 
    // usando el metodo de ordenamiendo burbuja

    string codesB[filas];
    for(int i=0; i<filas; i++){ // pasamos los codigos de los estudiantes a una lista auxiliar 
        codesB[i]=codes[i];
    }

    int aux_a;
    string aux_b;
    for(int i=0; i<filas; i++){
        for(int j=0; j<filas; j++){
            if(h_t_x_estudiante[j] > h_t_x_estudiante[j+1]){
                // ordenamiento de las horas
                aux_a=h_t_x_estudiante[j];
                h_t_x_estudiante[j]= h_t_x_estudiante[j+1];
                h_t_x_estudiante[j+1]=aux_a;
                // ordenamiento de los codigos de los estudiantes
                aux_b=codesB[j];
                codesB[j]= codesB[j+1];
                codesB[j+1]=aux_b;
            }
        }
    } 
    
    // imprimimos la lista
    cout<<"\n\n codigo | horas de investigacion \n";
    for(int i=0; i<filas; i++){
        cout<<" "<<codesB[i]<<"     "<<h_t_x_estudiante[i]<<endl;
    }
    
}

void horas_totales_investigacion(int horas[][m], int filas, int columnas){
    int sum_horas=0;
    for (int f=0; f<=filas-1;f++){
		for (int c=0; c<=columnas-1; c++){
			sum_horas+=horas[f][c];
		}
    }
    cout<<"\n\n el total de horas de investigacion en este estudio fue de: "<<sum_horas<<endl;
}


int main(){
    // declaramos la variable a utilizar
    int n_e; // numero de estudiantes
    int dias_trabajo;

    // ingreso de numero de estudiantes y dias de investigacion
    cout<<"   PROYECTO DE INVESTIGACION \n";
    cout<<" cantidad de estudiantes: ";cin>>n_e;
    cout<<" cantidad de dias de investigacion: ";cin>>dias_trabajo;

    // declaramos vectores a utilizar 
    string codigos[n_e];
    int horas_investigacion[n_e][m];


    // solicitamos los codigos de los estudiantes 
    ingreso_codigos(codigos, n_e);
    
    // ingreso de horas de investigacion de los estudiantes por cada dia del estudion
    ingreso_horas(horas_investigacion, n_e, dias_trabajo);


    int pregunta=1;
	while (pregunta==1){
		cout<<"\n\n que datos de la inbestigacion decea ver ?";
		cout<<"\n--->1 horas de investigacion de cada estudiante por cada dia";
        cout<<"\n--->2 codigos de cada estudiante que paricipo en la investigacion";
		cout<<"\n--->3 lista general de horas totales de investigacion por cada estudiante ordenada en forma acendente";
		cout<<"\n--->4 horas de investigacion totales en el semillero ";
        int option;
		cout<<"\n escoja el numero de su opcion:";cin>>option;
		while (option>4 || option<1){
			cout<<"\n valor ingresado no valido\n";
			cout<<"\n escoja el numero de su opcion nuevamente:";cin>>option;
        }
        if (option==1){
			print_tabla(horas_investigacion, n_e, dias_trabajo);
		}
		else if (option==2){
            print_codigos(codigos, n_e);
		}
		else if (option==3){
            lista_ordenada(horas_investigacion, codigos, n_e, dias_trabajo);
		}
        else{
            horas_totales_investigacion(horas_investigacion, n_e, dias_trabajo);
        }
         cout<<"\n\n desea volver al menu \n-- 1 si\n--!=1 no";
		cout<<"\n responda:";cin>>pregunta;
    }
    return 0;
}