#include<iostream>
/* las librerias a continucacion las utilizo para posteriormente en el programa 
hacer uso de una funcion que estas proporcionan la cual me permite trabajar con numeros aleatorios 
esto es muy util para asiganar automaticamente valores a la matriz de prodccion 
al evitar ingresarlos los valores por teclado  por teclado haciendo las pruebas del codigo mas rapidas */
#include <stdlib.h>
#include <time.h>
using namespace std;


void create_lista(string arr[],int cant ){
	string valor; 

	// agregamos los elemtos a la lista 
	for (int i=0; i<cant; i++){
		cout<<i+1<<"->";cin>>valor;
		arr[i]=valor;
	}
}

const int m=1000;
void ingreso_votos(int vot_os[][m], int filas, int columnas ){
    // variable que almacenara valores para asignarlos en la matriz
	int valor; 
	// funciones para obtener numeros aleatorios
	srand(time(NULL));
	// asignamos avalores a la matriz usando un bucle for anidado
	for (int fl=0; fl<=filas-1; fl++){
		for (int col=0; col<=columnas-1; col++){
			// asignamos un numero aleatorio al valor
			valor=1 + rand() % (501-1); //en un rango de 1 a 500
			// añadimos el valor a la matriz
			vot_os[fl][col]=valor;
		}
	}
}

void cant_p_frutas(int frut_as[][m], int f_t_f[],string frut[], int filas, int columnas ){
	int sum_f=0;

	for (int f=0; f<=filas-1;f++){
		sum_f=0; // esta variable ira contabilizando la suma de cada fila 
		for (int c=0; c<=columnas-1; c++){
			sum_f+=frut_as[f][c]; 
		}
		f_t_f[f]=sum_f; // se guardara la suma de cada fila en una lista 
	} 
    cout<<"\n\n total de produccion por cada fruta \n";
    cout<<" fruta | produccion total \n";
    for(int i=0; i<filas; i++){
        cout<<" "<<frut[i]<<"         "<<f_t_f[i]<<endl;
    }
}
	



void may_elemento_lista(int lista[], int cant, string x[]){

    int may=-10;
    string f_may;
    for(int i=0; i<cant; i++){
        if (lista[i] > may){
            may=lista[i];
            f_may=x[i];
        }
    }
    // imprimimos el mayor numero de producion de las frutas
    cout<<" "<<f_may<<"     "<<may<<endl;
}


void sum_produccion(int frut_as[][m], int filas, int columnas){
    int sum_product=0;

	for (int f=0; f<=filas-1;f++){
		for (int c=0; c<=columnas-1; c++){
			sum_product+=frut_as[f][c]; 
		}
	} 
    cout<<"\n'n la cantidad total de produccion es de:"<<sum_product<<endl;
}

int main(){
	int filas,columnas;
	cout<<" prodcucion de fabrica de conservas \n";
	cout<<" cantidad de frutas: ";cin>>filas;
	cout<<" cantidad de meses: ";cin>>columnas;
    // vectores a utilizar
    string frutas[filas];
	int produccion[filas][m];
    int f_t_frutas[filas];

	
	// ingreso de datos
	cout<<"\n ingreso de las frutas\n";
	create_lista(frutas, filas);


	// ingreso de datos a la matriz de votos de forma aleatoria
    ingreso_votos( produccion, filas, columnas);

	// imprecion de los datos ingresados
	cout<<"\n datos de produccion \n";
	cout<<"--------------------\n";
	cout<<" id | frutas \n";
	cout<<"--------------------\n";
	for(int i=0; i<filas; i++){
		cout<<""<<i+1<<"  | "<<frutas[i]<<endl;
	}
	cout<<"--------------------\n";
	cout<<endl;

	cout<<"cantidad de produccion\n";
	cout<<"    produccion  |";
	for(int i=0; i<columnas; i++){
		cout<<" mes "<<i+1<<"   |";
	}
	cout<<endl;
	for(int f=0; f<filas; f++){
		cout<<"    fruta "<<f+1<<"     |";
		for(int c=0; c<columnas; c++){
			cout<<"    "<<produccion[f][c]<<"    ";
		}
		cout<<endl;
	}

     // produccion total de cada fruta
    cant_p_frutas(produccion, f_t_frutas, frutas, filas, columnas );
    // fruta con mayor producion
    cout<<"\n\n la fruta con mayor produccion  fue:\n";
    cout<<" fruta | produccion total \n";
    may_elemento_lista(f_t_frutas, filas, frutas);
    // produccion total
    sum_produccion(produccion, filas, columnas);


    return 0;