#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int m=1000;

// estructura para los datos bacucis de los productos
struct product{
    string nombre;
    float precio_unidad;
    int p_p_m[m]; // produccion por mes 
    int v_p_m[m]; // ventas por mes 
};


// funciones a utilizar -------------------------------------------------------------

void nombre_precio(product arr[],int cant ){ // ingreso de nombre y precio de cada producto
	string name; 
    float precio;
	// agregamos los elemtos a la lista 
	for (int i=0; i<cant; i++){
        cout<<"--- producto "<<i+1<<endl;
		cout<<i+1<<" nombre: ";cin>>name;
		arr[i].nombre=name;
        cout<<i+1<<" precio por unidad: ";cin>>precio;
		arr[i].precio_unidad=precio;

	}
}

void produccion_ventas(product arr[], int filas, int columnas ){ // asignacion del valor de produccion y ventas de cada producto por mes 
    // variable que almacena el valor de producion por mesw 
	int valorA;
    // variable que almacena el valor de ventas por mes 
    int valorB; 
	// funciones para obtener numeros aleatorios
	srand(time(NULL));
	for (int fl=0; fl<=filas-1; fl++){
		for (int col=0; col<=columnas-1; col++){
			// asignamos un numero aleatorio al valorA
			valorA=1 + rand() % (501-1);
			// asignamos el valor de produccion correspondiente al mes dado por la variable col
			arr[fl].p_p_m[col]=valorA;
            // asignamos un numero aleatorio al valorB 
			valorB=1 + rand() % (valorA-1);
            // asignamos el valor de produccion correspondiente al mes dado por la variable col
            arr[fl].v_p_m[col]=valorB;
		}
	}
}


void producto_totl_produc(product arr[], int filas, int columnas ){ // produccion total por cada producto
    
}
//-----------------------------------------------------------------------------------

int main(){
	int filas,columnas;
	cout<<" produccion de la fabrica  \n";
	cout<<" cantidad de productos: ";cin>>filas;
	cout<<" meses de produccion: ";cin>>columnas;
    // vectores a utilizar
    product productos[filas];

	// ingreso de nombre y predio de cada producto 
	cout<<"\n productos\n";
	nombre_precio(productos, filas);

	// ingreso de los valores de produccion y ventas por cada mes 
    produccion_ventas( productos, filas, columnas);

	// imprecion de los datos ingresados
	cout<<"\n datos de la produccion \n";
	cout<<"----------------------------------------\n";
	cout<<" id | producto |  precio por unidad\n";
	cout<<"----------------------------------------\n";
	for(int i=0; i<filas; i++){
		cout<<" "<<i+1<<"  | "<<productos[i].nombre<<"        "<<productos[i].precio_unidad<<endl;
	}
	cout<<"----------------------------------------\n";
	cout<<endl;


	cout<<"\n";
	cout<<" produccion  |";
	for(int i=0; i<columnas; i++){
		cout<<"       mes  "<<i+1<<"        |";
	}
	cout<<endl;
    cout<<"             |";
    for(int i=0; i<columnas; i++){
        cout<<" produccion | ventas |";
    }
    cout<<endl;
	for(int f=0; f<filas; f++){
		cout<<"  producto "<<f+1<<" |";
		for(int c=0; c<columnas; c++){
			cout<<"    "<<productos[f].p_p_m[c]<<"        "<<productos[f].v_p_m[c]<<"     ";
		}
		cout<<endl;
	}

 

    return 0;
}