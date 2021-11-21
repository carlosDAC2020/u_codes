#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//  funciones random resiclables

//  matematicas basicas-----------------------------------------------

bool par_impar(int num){ // evaluar si un numero es par o impar 
	if(num%2==0){
		cout<<" par \n";
		return true;
	}
	else{
		cout<<" impar \n";
		return false;
	}
}

bool n_primo(int num){ // evaluar si un numero es primo o no
	if (num==2){
		cout<<" primo \n";
		return true;
	}
	for (int i=2; i<=num; i++){
		if(num%i==0){
			cout<<" no es primo \n";
			return false;
		}
	}
	cout<<" primo \n";
	return true;
}

int factorial(int num){ // hayar el factorial de un numero
	int fact=1;
	while(num>1){
		fact*=num;
		num-=1;
	}
	cout<<" factorial="<<fact<<endl;
	return fact;
}

int valor_absoluto(int num){ // hayar el valor absoluto de un numero
	if (num<1){
		num*=-1;
		cout<<" valor absoluto="<<num<<endl;
		return num;
	}
	cout<<" valor absoluto="<<num<<endl;
	return num;
}
//---------------------------------------------------------------------

// listas y matrizes---------------------------------------------------
int create_lista(int arr[],int n){// creamos auna lista con numeros aleatorios
	int valor; 

	srand(time(NULL));

	// agregamos numeros aleatorios a la lista
	for (int i=0; i<=n; i++){
		valor=1 + rand() % (51-1);
		arr[i]=valor;
	}
	cout<<" lista aleatoria \n";
	for (int i=0; i<=n; i++){
		cout<<arr[i]<<" ";
	}
	return arr[n];
}

int create_matriz(){
	int f, c;
	cout<<"\n\n creamos una matriz\n";
	cout<<" numero de filas:";cin>>f;
	cout<<" numero de columnas:",cin>>c;
	
	int matriz[f][c];
	
	if (f==c){
		// variable que almacenara valores para asignarlos en la matriz
		int valor; 
		// funciones para obtener numeros aleatorios
		srand(time(NULL));
		// asignamos avalores a la matriz usando un bucle for anidado
		for (int fl=0; fl<=f-1; fl++){
			for (int col=0; col<=c-1; col++){
				// asignamos un numero aleatorio al valor
				valor=1 + rand() % (51-1);
				// añadimos el valor a la matriz
				matriz[fl][col]=valor;
			}
		}
		// imprimimos la matriz final
		cout<<"\n\n matriz aleatoria \n";
		for (int fl=0; fl<=f-1; fl++){
			for (int col=0; col<=c-1; col++){
				cout<<matriz[fl][col]<<" ";
			}
			cout<<"\n";
		}
		return matriz[f][c];
	}
}

int main(){
	// pruena de funciones matematicas---------------------------------
	/*int numero, option;

	cout<<" ingresa un numero:";cin>>numero;
	int op=1;
	while (op==1){
		cout<<" que funcion decea probar?\n";
		cout<<"--->1 evaluar si un numero es par 0 impar\n";
		cout<<"--->2 evaluar si un numero es primo o no\n";
		cout<<"--->3 hayar el factorial de un numero\n";
		cout<<"--->4 hayar el valor absoluto de un numero\n";

		cout<<" escoja el numero de su opcion:";cin>>option;
		while (option>4 || option<1){
			cout<<"\n valor ingresado no valido\n";
			cout<<" escoja el numero de su opcion nuevamente:";cin>>option;
		}

		if (option==1){
			par_impar(numero);
		}
		else if (option==2){
			n_primo(numero);
		}
		else if (option==3){
			factorial(numero);
		}
		else{        
			valor_absoluto(numero);
		}
		cout<<"\n\n desua volver al menu?\n -- 1 para si\n --!=1 para no\n";
		cout<<" elija:";cin>>op;
	}*/

		// prueba de funciones de listas y matrizes
	// declaramos la lista y su tamaño
	/*int cant;
	cout<<" creamos una lista \n";
	cout<<" cantidad de elementos que tendra la lista:";cin>>cant;
	int new_array[cant];
	// invocamos la funcion para crear una lista aleatoria
	create_lista(new_array,cant);*/

	// declaramos la matiz
	int filas, columnas;
	cout<<"\n\n creamos una matriz\n";
	cout<<" numero de filas:";cin>>filas;
	cout<<" numero de columnas:",cin>>columnas;
	
	int new_matriz[filas][columnas];

	// variable que almacenara valores para asignarlos en la matriz
	int valor; 
	// funciones para obtener numeros aleatorios
	srand(time(NULL));
	// asignamos avalores a la matriz usando un bucle for anidado
	for (int fl=0; fl<=filas-1; fl++){
		for (int col=0; col<=columnas-1; col++){
			// asignamos un numero aleatorio al valor
			valor=1 + rand() % (51-1);
			// añadimos el valor a la matriz
			new_matriz[fl][col]=valor;
		}
	}
	// imprimimos la matriz final
	cout<<"\n\n matriz aleatoria \n";
	for (int fl=0; fl<=filas-1; fl++){
		for (int col=0; col<=columnas-1; col++){
			cout<<new_matriz[fl][col]<<" ";
		}
		cout<<"\n";
	}

	int pregunta=1;
	while (pregunta==1){
		cout<<"\n\n que funcion para la matriz decea probar?";
		cout<<"\n--->1 imprimir diagonal principal";
		cout<<"\n--->2 imprimir diagonal segundaria";
		cout<<"\n--->3 suma de cada fila";
		cout<<"\n--->4 suma de cada columna";
		cout<<"\n--->5 mayor elemento de cada fila ";
		cout<<"\n--->6 mayor elemento de cada columna";
		cout<<"\n--->7 menores elemento de cada fila ";
		cout<<"\n--->8 menores elemento de cada columna";
		cout<<"\n--->9 promedio de cada fila ";
		cout<<"\n--->10 promedio de cada columna";
		cout<<"\n--->11 imprimir la triangular superor";
		cout<<"\n--->12 imprimir la triangular inferior";

		int option;
		cout<<"\n escoja el numero de su opcion:";cin>>option;
		while (option>12 || option<1){
			cout<<"\n valor ingresado no valido\n";
			cout<<"\n escoja el numero de su opcion nuevamente:";cin>>option;
		}
		
		// imprimir diagonal principal
		if (option==1){
			//diagonal_1(matr_iz) 
			if(filas==columnas){ // cuando la matriz es cuadrada
				cout<<"\n\n diagonal principal\n";
				for (int f=0; f<=filas-1; f++){
					for (int c=0; c<=columnas-1; c++){
						if(f==c){
							cout<<" "<<new_matriz[f][c];
						}
						else{
							cout<<" "<<0;
						}
					}
					cout<<"\n";
				}
			}
			else{
				cout<<"\n\n esta matriz no tiene diagonal principal";
			}
		}
		
		// imprimir diagonal segundaria
		else if (option==2){
			//diagonal_2(matr_iz)
			if(filas==columnas){ // cuando la matriz es cuadrada
				cout<<"\n\n diagonal segundaria\n";
				for (int f=0; f<=filas-1; f++){
					for (int c=0; c<=columnas-1; c++){
						if(f+c==columnas-1){
							cout<<" "<<new_matriz[f][c];
						}
						else{
							cout<<" "<<0;
						}
					}
					cout<<"\n";
				}
			}
			else{
				cout<<"\n\n esta matriz no tiene diagonal segundaria";
			}
		}
		
		// suma de cada fila de la matriz
		else if (option==3){
			//sum_filas(matr_iz)
			int lst_sum_f[filas];
			int sum_f;

			for (int f=0; f<=filas-1;f++){
				sum_f=0;
				for (int c=0; c<=columnas-1; c++){
					sum_f+=new_matriz[f][c];
				}
				lst_sum_f[f]=sum_f;
			}

			// imprimimos los resultados
			cout<<"\n\n suma de cada fila\n ";
			for (int i=0; i<=filas-1; i++){
				cout<<"-fila "<<i<<"="<<lst_sum_f[i]<<"\n";
			}
		}
		
		// suma de cada columna
		else if (option==4){
			//sum_columnas(matr_iz)
			int lst_sum_c[columnas];
			int sum_c;

			for (int c=0; c<=columnas-1;c++){
				sum_c=0;
				for (int f=0; f<=filas-1; f++){
					sum_c+=new_matriz[f][c];
				}
				lst_sum_c[c]=sum_c;
			}

			// imprimimos los resultados
			cout<<"\n\n suma de cada columna\n ";
			for (int i=0; i<=columnas-1; i++){
				cout<<"-columna "<<i<<"="<<lst_sum_c[i]<<"\n";
			}
		}
		
		// hayamos el mayor elememnto de cada fila
		else if (option==5){
			//may_elemento_filas(matr_iz)
			// lista donde guardaremos los mayores ekementos de cada fila 
			int may_elmts_f[filas];
			int el_may_f;
			// evaluamos los elementos con un doble bucle for 
			for (int f=0;f<=filas-1; f++){
				el_may_f=new_matriz[f][0];
				for (int c=0; c<=columnas-1; c++){
					if(el_may_f < new_matriz[f][c]){
						el_may_f=new_matriz[f][c];
					}
				}
				may_elmts_f[f]=el_may_f;
			}
			// imprimimos respuestas
			cout<<"\n\n elemento mayor de cada fila\n";
			for (int i=0; i<filas; i++){
				cout<<"-fila "<<i<<"="<<may_elmts_f[i]<<"\n";
			}
		}

		// hayar el mayor elemento de cada columna
		else if (option==6){
			//may_elemento_columnas(matr_iz)
			// lista donde guardaremos los mayores ekementos de cada columna 
			int may_elmts_c[columnas];
			int el_may_c;
			// evaluamos los elementos con un doble bucle for 
			for (int c=0; c<columnas; c++){
				el_may_c=new_matriz[0][c];
				for (int f=0; f<filas; f++){
					if(el_may_c < new_matriz[f][c]){
						el_may_c=new_matriz[f][c];
					}
				}
				may_elmts_c[c]=el_may_c;
			}
			// imprimimos respuestas
			cout<<"\n\n elemento mayor de cada columna\n";
			for (int i=0; i<columnas; i++){
				cout<<"-columna "<<i<<"="<<may_elmts_c[i]<<"\n";
			}
		}
		// hayar el menor elemento de cada fila
		else if (option==7){
			//men_elemento_filas(matr_iz)
			// lista donde guardaremos los mayores ekementos de cada fila 
			int men_elmts_f[filas];
			int el_men_f;
			// evaluamos los elementos con un doble bucle for 
			for (int f=0; f<filas; f++){
				el_men_f=new_matriz[f][0];
				for (int c=0; c < columnas; c++){
					if(el_men_f > new_matriz[f][c]){
						el_men_f=new_matriz[f][c];
					}
				}
				men_elmts_f[f]=el_men_f;
			}
			// imprimimos respuestas
			cout<<"\n\n elemento menor de cada fila\n";
			for (int i=0; i<filas; i++){
				cout<<"-fila "<<i<<"="<<men_elmts_f[i]<<"\n";
			}
		}

		// hayamos el menor elemento de cada columna
		else if (option==8){
			//men_elemento_columnas(matr_iz)
			// lista donde guardaremos los mayores ekementos de cada columna 
			int men_elmts_c[columnas];
			int el_men_c;
			// evaluamos los elementos con un doble bucle for 
			for (int c=0; c<columnas; c++){
				el_men_c=new_matriz[0][c];
				for (int f=0; f < filas; f++){
					if(el_men_c > new_matriz[f][c]){
						el_men_c=new_matriz[f][c];
					}
				}
				men_elmts_c[c]=el_men_c;
			}
			// imprimimos respuestas
			cout<<"\n\n elemento menor de cada columna\n";
			for (int i=0; i<filas; i++){
				cout<<"-columna "<<i<<"="<<men_elmts_c[i]<<"\n";
			}
		}

		// mayamos el promedio de cada fila
		else if (option==9){
			//promedio_filas(matr_iz)
			// lista donde almacenamos los promedios de cada fila
			int lst_pro_f[filas];
			// usamos estas variables auxiliares para hayarlos promedios
			float prom_f;
			int sum_prom_f;
			// usamos un bucle para relaizar el proceso de promediado
			for (int f=0; f<filas; f++){
				sum_prom_f=0;
				for(int c=0; c<columnas; c++){
					sum_prom_f+=new_matriz[f][c];
				}
				prom_f= sum_prom_f / columnas;
				lst_pro_f[f]=prom_f;
			}
			// imprimimos los resultados
			cout<<"\n\n promdeios de cada fila\n";
			for (int i=0; i<filas; i++){
				cout<<" -fila "<<i<<"="<<lst_pro_f[i]<<endl;
			}
		}

		// hayamos el promedio de cada columna
		else if (option==10){
			//promedio_columnas(matr_iz)
			// lista donde almacenamos los promedios de cada columna
			int lst_pro_c[columnas];
			// usamos estas variables auxiliares para hayar los promedios
			float prom_c;
			int sum_prom_c;
			// usamos un bucle para relaizar el proceso de promediado
			for (int c=0; c<columnas; c++){
				sum_prom_c=0;
				for(int f=0; f<filas; f++){
					sum_prom_c+=new_matriz[f][c];
				}
				prom_c= sum_prom_c / filas;
				lst_pro_c[c]=prom_c;
			}
			// imprimimos los resultados
			cout<<"\n\n promdeios de cada columna\n";
			for (int i=0; i<columnas; i++){
				cout<<" -columna "<<i<<"="<<lst_pro_c[i]<<endl;
			}
		}
		// imprimir triangular superior
		else if (option==11){
			//triangular_1(matr_iz)
			cout<<"\n\n triangular superior \n";
			for (int f=0; f<filas; f++){
				for (int c=0; c<columnas; c++){
					if (f<c){
						cout<<" "<<new_matriz[f][c];
					}
					else{
						cout<<" "<<0;
					}
				}
				cout<<"\n";
			}
		}

		// imprimimos la triagular inferios
		else if (option==12){
			//triangular_2(matr_iz)
			cout<<"\n\n triangular inferior \n";
			for (int f=0; f<filas; f++){
				for (int c=0; c<columnas; c++){
					if (f>c){
						cout<<" "<<new_matriz[f][c];
					}
					else{
						cout<<" "<<0;
					}
				}
				cout<<"\n";
			}
		}
		cout<<"\n\n desea volver al menu \n-- 1 si\n--!=1 no";
		cout<<"\n responda:";cin>>pregunta;
	}

	
	return 0;
}
