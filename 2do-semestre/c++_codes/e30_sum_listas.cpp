#include <iostream>

using namespace std;

void create_lista(int arr[],int n){// creamos muna funcion para agregar elementos a una lista
	int valor; 

	for (int i=0; i<=n; i++){
		cout<<"ingresa un numero:";cin>>valor;
		arr[i]=valor;
	}
	
}

void sum_listas(int arr1[],int arr2[],int arr3[],int n){ // funcion para sumar dos listas 
	int valor; 

	for (int i=0; i<=n; i++){
		valor=arr1[i] + arr2[i];
		arr3[i]=valor;
	}
}

int main(){
    int v1[9], v2[9], v3[9];

    cout<<"ingresa valores para el vector 1 \n";
    create_lista(v1,9);

    cout<<"\ningresa valores para el vector 2 \n";
    create_lista(v2,9);

    cout<<"\n vector 1 \n ";
	for (int i=0; i<=9; i++){
		cout<<v1[i]<<" ";
	}

    cout<<"\n vector 2 \n ";
	for (int i=0; i<=9; i++){
		cout<<v2[i]<<" ";
	}

    cout<<"\n\nel vector 3 q es igual a la suma de elemento por elemento del vector 1 y 2 es el siguiente \n";
    sum_listas(v1,v2,v3,9);
    cout<<" vector 3 \n ";
	for (int i=0; i<=9; i++){
		cout<<v3[i]<<" ";
	}

    return 0;
}