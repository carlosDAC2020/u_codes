#include <iostream> 
#include <fstream> 
#include <cmath> 
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <stdio.h>
using namespace std;    

struct monitor{ 
    int id;
    string nombre;
    string apellido;
    string asignatura;
    astring dias_monitoria[2];
};

monitor list_monitores[100]; // se crea listado de los monitores
int n_monitores=0;

// -------  funcion lectura y guardado de datos -------------------------------- 
/* esta funcion lee y guarda datos de un archivo externo 
   en una estructura de datos pre declafrada en x programa 
   como en este caso
   
   se toma como parametro el nombre del archivo a leer 
   y en proceso se procesan y guardan los datos 
   en la estructura correspondiente 
*/
int leer_asiganr(){
    // declaramos y habrimos el archivo a leer
	ifstream archivo;
	archivo.open("monitores.csv", ios::in);
	if (archivo.fail()) { // validamos la existencia del archivo 
		cout << "* No se puedo leer el archivo." << endl;
		exit(1);
	}
    
    // variables auxiliares 
    int aux_id;
    estring  aux_nombre, aux_apellido, aux_asignatura, aux_dias_monitorias[2] ,aux;

    // cantidad de clientes ya guardados 
    int contador=0;
    // recorremos el archivo de lectura linea oir linea 
	while (getline(archivo, linea)) {
		stringstream stream(linea);
    // usamos un separador ; para identificar cada dato y asiganrlo a su correspondiente variable axuliar  
		int i=0;
        getline(stream, aux, ';');
        aux_id = atoi(aux.c_str());
		getline(stream, aux_nombre, ';');
		getline(stream, aux_apellido, ';');
        getline(stream, aux_asignatura, ';');
        getline(stream, aux_dias_monitorias[0], ';');
        getline(stream, aux_dias_monitorias[0], ';');
		
        list_monitores[contador].id=aux_id;
        list_monitores[contador].nombre=aux_nombre;
        list_monitores[contador].apellido=aux_apellido;
        list_monitores[contador].asignatura=aux_asignatura;
        list_monitores[contador].dias_monitoria[0]=aux_dias_monitorias[0];
        list_monitores[contador].dias_monitoria[1]=aux_dias_monitorias[1];
    

        contador+=1;
    }
    archivo.close();
    return contador;
}

void escribir_guardar(){
    // declaramos y habrimos el archivo a leer
	ifstream archivo;
	archivo.open("monitores.csv", ios::in);
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

    // escribimos los datos almacenados en la lista de clientes en elarchivo temporal
    for (int i = 0; i < n_monitores; i++){
        temporal<<list_monitores[i.id<<";";
        temporal<<list_monitores[i].nombre<<";";
        temporal<<list_monitores[i].apellido<<";";
        temporal<<list_monitores[i].asignatura<<";";
        temporal<<list_monitores[i].dias_monitoria[0]<<";";
        temporal<<list_monitores[i].dias_monitoria[1]<<";"<<endl;
    }

    // cerramos archivos de lectura y guardado
    archivo.close();
    temporal.close();

    // eliminamos el archivom de clientes inicial
    remove("monitores.csv");
    // renombramos el archivo temporal
    rename("temporal.csv","monitores.csv");
    
}



int main() { 
    leer_asiganr();// toma la cantidad de usuarios guardados hasta la fecha 

  
    // guardamos los datos
    escribir_guardar();
	
    
    return 0; 
}
