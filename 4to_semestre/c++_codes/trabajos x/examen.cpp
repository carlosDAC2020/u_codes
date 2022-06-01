#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// vectores de respuestas correctas
string respuestas_correctas[10]={"d", "b", "d", "c", "c", "d", "a", "e", "a", "d"};
string opciones[5]={"a","b","c","d","e"};

void ingreso_respuestas (string resp[][10], string est[], double tiemp[], int putj[] ){
	string respuesta;
    int x;
    srand(time(NULL));
	// ingresamos las respuestas de cda estudiante 
	for (int i=0; i<8; i++){
        cout<<"estudiante "<<i+1<<endl;
        cout<<" nombre:"<<est[i];
        cout<<"\n Respuestas \n";
        cout<<" las opciones de respuestas son. \n a, b ,c ,d ,e \n";
        for (int j = 0; j < 10; j++){
            // asignamos respuestas aleatoria 
            x=0 + rand() % (6-1);
            respuesta=opciones[x];
            resp[i][j]=respuesta;
            cout<<"\n pregunta "<<j+1<<":"<< resp[i][j]; 

            // evaluamos el puntaje del estudiantes 
            if(resp[i][j]==respuestas_correctas[i]){
                putj[i]+=1; // sumamos un punto por cada respuesta correcta 
            }
        }
      
        cout<<"\n tiempo en resolver el examen en minutos:";cin>>tiemp[i];
	}
}

// funcion para obtener el promedio de las minutos en los que se realizo el examen
double prom_tiempo_examen(double time[]){
    // variable auxiliar para la sumatoria de los timepos 
    double sum_times=0;

    // hacemos la sumatoria de los tiempos usando un ciclo for 
    for (int i = 0; i < 8; i++){
        sum_times+=time[i];
    }
    
    // obtenemos el promedio y lo retoenamos 
    return sum_times/8;
}

// funcion para obtener los estudiantes que gastaron mas tiempo en resolver el examnen 
void est_time_may_exam(string est[], double time[], double prom_time){
    cout<<"\n  Estudiantes que tardaron mas en resolver el examen \n";
    cout<<"| estudiante |  tiempo | \n ";
    for (int i = 0; i < 8; i++){
        if(time[i]>prom_time){
            cout<<"  "<<est[i]<<"         "<<time[i]<<endl;
        }
    }
}

// funcion para imrpimri a los estudiantes y sus correspondientes puntajes 
void puntaje_estudiantes(string est[], int putj[]){
    cout<<"\n| estudiante  |   puntaje   |\n";
    for (int i = 0; i < 8; i++){
        cout<<est[i]<<"           "<<putj[i]<<endl;
    }
    
}

// promedio de puntajes 
float prom_puntaje(int putj[]){
    int sum_putjs=0;
    for (int i = 0; i < 8; i++){
        sum_putjs+=putj[i];
    }
    return sum_putjs/8;
}

// funcion para obtener a los estudiantes que gastaron menos tiempo en el examen junto con su correspondiente puntaje
void list_est_menTime_puntj_exam(string est[], double time[], int putjs[], double prom_time){
    cout<<"\n  Estudiantes que tardaron menos en resolver el examen \n";
    cout<<"| estudiante |  tiempo | puntaje  |\n ";
    for (int i = 0; i < 8; i++){
        if(time[i]<prom_time){
            cout<<"  "<<est[i]<<"        "<<time[i]<<"      "<<putjs[i]<<endl;
        }
    }
}

int main(){
    // vectores a utilizar
    string estudiantes[8]={"carlos","jose","maria","jorge","diego","mario","juliana","melani"}; // nombres de los estudisntes 
    string resp_estudiantes[8][10]; // respouestas de los estudiantes 
    double tiempo_examen[8]; // tiempos de realizacion de cada estudiante
    int puntajes[8]={0,0,0,0,0,0,0,0}; // puntaje obtenido por cada estudiante

    cout<<" examen a estudiantes \n";

    // ingreso de los datos de los estudiantes 
    ingreso_respuestas(resp_estudiantes, estudiantes, tiempo_examen, puntajes);

    // imprimimos los datos del examnet y los estudiantes 
   	cout<<"datos del examen\n";
    cout<<"    estudiante    \n";
	for(int i=0; i<8; i++){
		cout<<" "<<i+1<<" "<<estudiantes[i]<<endl;
	}
    
    
	cout<<"\n preguntas   |";
	for(int i=0; i<10; i++){
		cout<<" "<<i+1<<" |";
	}
    cout<<" tiempo examen   |";
    cout<<endl;

	for(int f=0; f<8; f++){
		cout<<" estusiante "<<f+1<<"|";
		for(int c=0; c<10; c++){
			cout<<" "<<resp_estudiantes[f][c]<<" |";
		}
        cout<<"      "<<tiempo_examen[f];
		cout<<endl;
	}
    cout<<"\n r correctas   |";
	for(int i=0; i<10; i++){
		cout<<" "<<respuestas_correctas[i]<<" |";
	}

    // tiempo promedio del examne
    double prom_time=prom_tiempo_examen(tiempo_examen);
    cout<<"\n TIEMPO PROMEDIO EN QUE SE REALIZO EL EXAMNEN:"<<prom_time<<endl;

    // estudiantes que gastaron mas tiempo en el examen
    est_time_may_exam(estudiantes, tiempo_examen, prom_time);

    // puntajes obtenidos por cada estudiante
    puntaje_estudiantes(estudiantes, puntajes);

    // puntaje promedio 
    float promedio_puntaje=prom_puntaje(puntajes);
    cout<<"\n PROMEDIO DE PUNTAJES DEL EXAMEN:"<<promedio_puntaje<<endl;

    // l listado de los estudiantes que gastaron menos tiempo realizando la prueba y su respectivo puntaje obtenido
    list_est_menTime_puntj_exam(estudiantes, tiempo_examen, puntajes, prom_time);
    return 0;
}