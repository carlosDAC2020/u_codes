#include <iostream>
#include <fstream> 
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
using namespace std;

struct est{
    string name;
    float n1;
    float n2;
    float n3;
    float n_def;
};
est lst_est[100];
int cant_est=0;

int leer_notas();
int menu();
void ingresdo_notas(int );
void aprobados();
void reprobados();
void mejor_est();
void peor_est();
void est_superiores();

int main() {
    int cant_inical_est = leer_notas();

    int go=1;
	while (go<7){
        switch (menu()) {
            case 1: 
                ingresdo_notas(cant_inical_est);
            break;
            case 2: 
                aprobados();
            break;
            case 3:
                reprobados();
            break;
            case 4:
                 mejor_est();
            break;
            case 5:
                 peor_est();
            break;
            case 6:
                est_superiores();
            break;
            case 7:
                go=7; 
            break;
            default: ;
        }
    }
    
    return 0;
}



int menu(){
    cout<<"\n SISTEMA DE NOTAS \n";
    cout<<"--->1 ingreso de notas de los estudiantes\n";
    cout<<"--->2 mostrar estudiantes aprobados  \n";
    cout<<"--->3 mostrar estudiantes reprobados  \n";
    cout<<"--->4 mejor estudiante  \n";
    cout<<"--->5 peor estudiante  \n";
    cout<<"--->6 mostra estudiantes con notas superiores  \n";
    cout<<"--->7 salir del progarma \n";

    int option;
    cout<<" escoja el numero de su opcion:";cin>>option;
    while (option>7 || option<1){
        cout<<"\n valor ingresado no valido\n";
        cout<<" escoja el numero de su opcion nuevamente:";cin>>option;
    }
    return option;
}

void ingresdo_notas(int cant_ini){
    cout<<"\n\n INGRESO DE NOTAS \n";
    int cant_add;
    cout<<" Cantidad de estudiantes a registrar: ";cin>>cant_add;

    // declaramos y habrimos el archivo a leer
	ifstream archivo;
	archivo.open("estudiantes.csv", ios::in);
	if (archivo.fail()) { // validamos la existencia del archivo 
		cout << "* No se puedo leer el archivo." << endl;
		exit(1);
	}
    
    // declaramos variable temporal de escrituras de datos 
    ofstream temporal; 
	temporal.open("temporal.csv", ios::out);
    if (temporal.fail()) {
		exit(1);
	} 

    cant_est = cant_ini + cant_add;

    for (int  i = cant_ini; i < cant_est; i++)
    {
        cout<<"\n Estudiante "<<i+1<<endl;
        cout<<" Nombre: ";cin>>lst_est[i].name;
        do
        {
            cout<<" Nota 1: ";cin>>lst_est[i].n1;
            if (lst_est[i].n1<0 || lst_est[i].n1>5)
            {
                cout<<"\n ingrese una nota valida \n";
            }
        } while (lst_est[i].n1<0 || lst_est[i].n1>5);

        do
        {
            cout<<" Nota 2: ";cin>>lst_est[i].n2;
            if (lst_est[i].n2<0 || lst_est[i].n2>5)
            {
                cout<<"\n ingrese una nota valida \n";
            }
        } while (lst_est[i].n2<0 || lst_est[i].n2>5);

        do
        {
            cout<<" Nota 3: ";cin>>lst_est[i].n3;
            if (lst_est[i].n3<0 || lst_est[i].n3>5)
            {
                cout<<"\n ingrese una nota valida \n";
            }
        } while (lst_est[i].n3<0 || lst_est[i].n3>5);
        
    
        lst_est[i].n_def = (lst_est[i].n1*0.33) + (lst_est[i].n2*0.33) + (lst_est[i].n1*0.33);

       
    }

    for (int  i = 0; i < cant_est; i++){
         // escribimos los datos almacenados en la lista de estudiantes en el archivo temporal
        temporal<<lst_est[i].name<<";"<<lst_est[i].n1<<";"<<lst_est[i].n2<<";"<<lst_est[i].n3<<";"<<lst_est[i].n_def<<endl;
    }
    
    // cerramos archivos de lectura y guardado
    archivo.close();
    temporal.close();

    // eliminamos el archivom de empleados inicial
    remove("estudiantes.csv");
    // renombramos el archivo temporal
    rename("temporal.csv","estudiantes.csv");

    
}


void aprobados(){
    // declaramos variable temporal de escrituras de datos de los estudiantes aprobados
    ofstream temporal; 
	temporal.open("ganadores.csv", ios::out);
    if (temporal.fail()) {
		exit(1);
	} 

    cout<<"\n\n ESTUDIANTES APROBADOS \n";
    for (int i = 0; i < cant_est; i++)
    {
        if (lst_est[i].n_def>=3.0)
        {
            cout<<"\n Nombre: "<<lst_est[i].name<<endl;
            cout<<" Promedio: "<<lst_est[i].n_def<<endl;
            // escribimos los datos en en el archivo temporal
            temporal<<lst_est[i].name<<";"<<lst_est[i].n1<<";"<<lst_est[i].n2<<";"<<lst_est[i].n3<<";"<<lst_est[i].n_def<<endl;        
        }
    }
    temporal.close();
}

void reprobados(){
    // declaramos variable temporal de escrituras de datos de los estudiantes reprobados
    ofstream temporal; 
	temporal.open("reprobados.csv", ios::out);
    if (temporal.fail()) {
		exit(1);
	} 

    cout<<"\n\n ESTUDIANTES REPROBADOS \n";
    for (int i = 0; i < cant_est; i++)
    {
        if (lst_est[i].n_def<3.0)
        {
            cout<<"\n Nombre: "<<lst_est[i].name<<endl;
            cout<<" Promedio: "<<lst_est[i].n_def<<endl;
            // escribimos los datos en en el archivo temporal
            temporal<<lst_est[i].name<<";"<<lst_est[i].n1<<";"<<lst_est[i].n2<<";"<<lst_est[i].n3<<";"<<lst_est[i].n_def<<endl;        
        }
    }
    temporal.close();
}

void mejor_est(){
    // declaramos variable temporal de escrituras de datos del mejor estudiante 
    ofstream temporal; 
	temporal.open("mejor.csv", ios::out);
    if (temporal.fail()) {
		exit(1);
	} 

    float may_nota=0.0;
    int indesx_est;
    for (int i = 0; i < cant_est; i++)
    {
        if (lst_est[i].n_def>may_nota)
        {
            may_nota=lst_est[i].n_def;
            indesx_est=i;
        }
    }

    cout<<"\n\n MEJOR ESDTUDIANTE \n";
    cout<<"\n Nombre: "<<lst_est[indesx_est].name<<endl;
    cout<<" Promedio: "<<lst_est[indesx_est].n_def<<endl;
    // escribimos los datos en en el archivo temporal
    temporal<<lst_est[indesx_est].name<<";"<<lst_est[indesx_est].n1<<";"<<lst_est[indesx_est].n2<<";"<<lst_est[indesx_est].n3<<";"<<lst_est[indesx_est].n_def<<endl;        

    temporal.close();
}

void peor_est(){
    // declaramos variable temporal de escrituras de datos del peor esdtudisnte
    ofstream temporal; 
	temporal.open("peor.csv", ios::out);
    if (temporal.fail()) {
		exit(1);
	} 

    float men_nota=10.0;
    int indesx_est;
    for (int i = 0; i < cant_est; i++)
    {
        if (lst_est[i].n_def<men_nota)
        {
            men_nota=lst_est[i].n_def;
            indesx_est=i;
        }
    }

    cout<<"\n\n PEOR ESDTUDIANTE \n";
    cout<<"\n Nombre: "<<lst_est[indesx_est].name<<endl;
    cout<<" Promedio: "<<lst_est[indesx_est].n_def<<endl;
    // escribimos los datos en en el archivo temporal
    temporal<<lst_est[indesx_est].name<<";"<<lst_est[indesx_est].n1<<";"<<lst_est[indesx_est].n2<<";"<<lst_est[indesx_est].n3<<";"<<lst_est[indesx_est].n_def<<endl;        

    temporal.close();
}

void est_superiores(){
    // declaramos variable temporal de escrituras de datos de los estudiantes con notas superiones 
    ofstream temporal; 
	temporal.open("gsuperior.csv", ios::out);
    if (temporal.fail()) {
		exit(1);
	} 

    cout<<"\n\n ESTUDIANTES CON NOTAS SUPERIORES \n";
    for (int i = 0; i < cant_est; i++)
    {
        if (lst_est[i].n_def<=4.0)
        {
            cout<<"\n Nombre: "<<lst_est[i].name<<endl;
            cout<<" Promedio: "<<lst_est[i].n_def<<endl;
            // escribimos los datos en en el archivo temporal
            temporal<<lst_est[i].name<<";"<<lst_est[i].n1<<";"<<lst_est[i].n2<<";"<<lst_est[i].n3<<";"<<lst_est[i].n_def<<endl;        
        }
    }
    temporal.close();
}

int leer_notas(){
    // declaramos y habrimos el archivo a leer
	ifstream archivo;
	archivo.open("estudiantes.csv", ios::in);
	if (archivo.fail()) { // validamos la existencia del archivo 
		cout << "* No se puedo leer el archivo." << endl;
		exit(1);
	}
    
    // variables auxiliares 
    string linea, auxiliar;
    
    
    // guardamos los datos del archvo en una lista
    
    // recorremos el 1archivo1 de lectura linea oir linea 
	while (getline(archivo, linea)) {
		stringstream stream(linea);
    // usamos un separador ; para identificar cada dato y asiganrlo a su correspondiente variable axuliar  
        
        getline(stream, auxiliar, ';');
        lst_est[cant_est].name = auxiliar; // nombre
		
        getline(stream, auxiliar, ';');
        lst_est[cant_est].n1 = atof(auxiliar.c_str()); // nota 1

        getline(stream, auxiliar, ';');
        lst_est[cant_est].n2 = atof(auxiliar.c_str()); // nota 2

        getline(stream, auxiliar, ';');
        lst_est[cant_est].n3 = atof(auxiliar.c_str()); // nota 3

        getline(stream, auxiliar, ';');
        lst_est[cant_est].n_def = atof(auxiliar.c_str()); // nota definit

        cant_est+=1;  
    }
    archivo.close();

    return cant_est;
}