/* se necesita un programa el cual maneje el proceso de produccion y ventas de una fabrica 
de distintoa tipos de productos en un n numero de meses 

 el programa debe solicitar al usuaario la cantidad de productos a demas 
 del nombre de cada producto y su produccion y ventas por cada mes  por cada mes 
 
 	el menu que el usuario tendra sera el siguiente
    1 produccion total de cada producto
	2 ventas y ganancias totales de cada producto
	3 porcentaje de ventas por mes 
  */

#include<iostream>
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
		cout<<" nombre: ";cin>>name;
		arr[i].nombre=name;
        cout<<" precio por unidad: ";cin>>precio;
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
    // cantidad de produccion por cada producto
	int sum_f=0;
    cout<<"\n\n produccion total de cada producto \n";
    cout<<" producto | produccion total \n";
	for (int f=0; f<=filas-1;f++){
		sum_f=0; // esta variabla va sumando la produccion por mes de cada producto
		for (int c=0; c<=columnas-1; c++){
			sum_f+=arr[f].p_p_m[c];
		}
		cout<<" "<<arr[f].nombre<<"         "<<sum_f<<endl;
	} 
}

void vents_gan_produc(product arr[], int filas, int columnas ){ // ventas y ganancias totales por cada producto
       // cantidad de ventas por cada producto
	int sum_f=0;
    cout<<"\n\n ventas y ganancias totales de cada producto \n";
    cout<<" producto |  ventas   | ganancias \n";
	for (int f=0; f<=filas-1;f++){
		sum_f=0; // esta variabla va sumando las ventas por mes de cada producto
		for (int c=0; c<=columnas-1; c++){
			sum_f+=arr[f].p_p_m[c];
		}
        // obtenemos las ganancias totales por producto multiplicando su precio por unidad con la cantidad de ventas totales 
		cout<<" "<<arr[f].nombre<<"         "<<sum_f<<"         "<<sum_f*arr[f].precio_unidad<<"$"<<endl;
	} 
}

void porcent_vents_x_mes(product arr[], int filas, int columnas ){ // porcentaje de ventas de cada mes por producto 
    float porcent_v; // porcentaje de ventas

    cout<<"\n porcentaje de ventas de cada mes por producto  \n";
	cout<<"-------------------\n";
	cout<<" id | producto \n";
	cout<<"-------------------\n";
	for(int i=0; i<filas; i++){
		cout<<" "<<i+1<<"  | "<<arr[i].nombre<<endl;
	}
	cout<<"-------------------\n";
	cout<<endl;

    cout<<"             |";
    for(int i=0; i<columnas; i++){
		cout<<"      mes "<<i+1<<"     |";
	}
	cout<<endl;
	for(int f=0; f<filas; f++){
		cout<<"  producto "<<f+1<<" |";
		for(int c=0; c<columnas; c++){
            porcent_v=((arr[f].v_p_m[c]*1.0)/(arr[f].p_p_m[c]*1.0))*100;
			cout<<"    "<<porcent_v<<"%     ";
		}
		cout<<endl;
	}
}

//-----------------------------------------------------------------------------------

int main(){
    // INGRESO DE DATOS -------------------------------------------------------------
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


	cout<<"\n PRODUCCION Y VENTAS DE CADA PRODUCTO POR MES \n";
	cout<<"             |";
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

    // MENU --------------------------------------------------------------------------------
    int op=1;
	while (op==1){
        int option;
		cout<<"\n\n quue decea ver sobre la produccion y ventas de la fabrica ?\n";
		cout<<"--->1 produccion total de cada producto\n";
		cout<<"--->2 ventas y ganancias totales de cada producto\n";
		cout<<"--->3 porcentaje de ventas por mes \n";

		cout<<" escoja el numero de su opcion:";cin>>option;
		while (option>3 || option<1){
			cout<<"\n valor ingresado no valido\n";
			cout<<" escoja el numero de su opcion nuevamente:";cin>>option;
		}

		if (option==1){
			producto_totl_produc(productos, filas, columnas);
		}
		else if (option==2){
			vents_gan_produc(productos, filas, columnas);
		}
		else {
			porcent_vents_x_mes(productos, filas, columnas);
		}

		cout<<"\n\n desua volver al menu?\n -- 1 para si\n --!=1 para no\n";
		cout<<" elija:";cin>>op;
	}
    return 0;
}