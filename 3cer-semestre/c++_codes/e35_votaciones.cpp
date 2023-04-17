#include<iostream>
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
			valor=1 + rand() % (51-1);
			// añadimos el valor a la matriz
			vot_os[fl][col]=valor;
		}
	}
}

void cant_votos_x_municipio(int vot_os[][m], int v_t_m[],string mun[], int filas, int columnas ){
    // cantidad de votos por cada municipio
	int sum_f;

	for (int f=0; f<=filas-1;f++){
		sum_f=0; // esta variable ira contabilizando la suma de cada fila 
		for (int c=0; c<=columnas-1; c++){
			sum_f+=vot_os[f][c]; 
		}
		v_t_m[f]=sum_f; // se guardara la suma de cada fila en una lista 
	} 
    cout<<"\n\n total votos por cada municipio \n";
    cout<<" municipio | votos \n";
    for(int i=0; i<filas; i++){
        cout<<" "<<mun[i]<<"         "<<v_t_m[i]<<endl;
    }
}
	
int cant_votos_x_candidatos(int vot_os[][m], int v_t_c[], string cand[], int filas, int columnas ){
    // cantidad de votos por cada candidato
	int sum_c;

	for (int c=0; c<=columnas-1;c++){
		sum_c=0; // esta variabke ira contabilizando la suma de cada columna
		for (int f=0; f<=filas-1; f++){
			sum_c+=vot_os[f][c];
		}
		v_t_c[c]=sum_c; // se añadira la suma de cada columna a una lista 
	}
    cout<<"\n\n total votos por cada candidato \n";
    cout<<" candidato | votos \n";
    for(int i=0; i<columnas; i++){
        cout<<" "<<cand[i]<<"     "<<v_t_c[i]<<endl;
    }
}

void may_elemento_lista(int lista[], int cant, string x[]){
    /* en esta funcion buscamos encontar el candidato ganador asi como el municipio con mayor numero de votacion
    para ello usamos esta funcion la cual busca encontar el elemento mayor de una lista de tipo entero 
    la cual sera la lista de votos por cada candiddato o la lista de votos por cada miunicipio */
    int may=-10;
    string c_o_m;
    for(int i=0; i<cant; i++){
        if (lista[i] > may){
            may=lista[i];
            c_o_m=x[i];
        }
    }
    // imprimimos el elemento mayor de la lista numerica y el elemento ya ses de la lista de candidatos o municipios segun corresponda
    cout<<" "<<c_o_m<<"     "<<may<<endl;
}

int main(){
	int filas,columnas;
	cout<<" elecciones regionales \n";
	cout<<" cantidad de munucipios: ";cin>>filas;
	cout<<" cantidad de candidatos: ";cin>>columnas;
    // vectores a utilizar
    string candidatos[columnas], municipios[filas];
	int votos[filas][m];
    int v_t_candidato[columnas], v_t_municipio[filas];

	
	// ingreso de datos
	cout<<"\n ingreso del nombre de los municipios\n";
	create_lista(municipios, filas);

	cout<<"\n\n ingreso del nombre de los candidatos\n";
	create_lista(candidatos, columnas);

	// ingreso de datos a la matriz de votos de forma aleatoria
    ingreso_votos( votos, filas, columnas);

	// imprecion de los datos ingresados
	cout<<"\n datos de las elecciones \n";
	cout<<"--------------------\n";
	cout<<" id | municipio \n";
	cout<<"--------------------\n";
	for(int i=0; i<filas; i++){
		cout<<""<<i+1<<"  | "<<municipios[i]<<endl;
	}
	cout<<"--------------------\n";
	cout<<endl;


	cout<<"--------------------\n";
	cout<<" id | candidatos \n";
	cout<<"--------------------\n";
	for(int i=0; i<columnas; i++){
		cout<<" "<<i+1<<"  | "<<candidatos[i]<<endl;
	}
	cout<<"--------------------\n";
	cout<<endl;


	cout<<"cantidad de votos\n";
	cout<<"    votos    |";
	for(int i=0; i<columnas; i++){
		cout<<" candidato "<<i+1<<" |";
	}
	cout<<endl;
	for(int f=0; f<filas; f++){
		cout<<" municipio "<<f+1<<" |";
		for(int c=0; c<columnas; c++){
			cout<<"    "<<votos[f][c]<<"         ";
		}
		cout<<endl;
	}

    // votos totales por cada candidato
    cant_votos_x_candidatos(votos, v_t_candidato, candidatos, filas, columnas );

    // votos totales por cada municipio
    cant_votos_x_municipio(votos, v_t_municipio, municipios, filas, columnas );
	
    // candidato ganador 
    cout<<"\n\n el candidato ganaror de las votaciones fue:\n";
    cout<<" candidato | votos \n";
    may_elemento_lista(v_t_candidato, columnas, candidatos);

    //municipio con mayor votacion
    cout<<"\n\n el municipio con mayor votacion fue fue:\n";
    cout<<" municipio | votos \n";
    may_elemento_lista(v_t_municipio, filas, municipios);

    return 0;
}