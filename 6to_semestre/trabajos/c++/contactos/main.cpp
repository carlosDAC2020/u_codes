#include <iostream> 
#include <fstream> 
#include <cmath> 
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <stdio.h>
using namespace std;    

struct contacto{ 
    int id;
    string nombre;
    string correo;
    string celular;
};

contacto list_contactos[100]; // se crea listado de los contactos
int n_contactos=0;

// funciones a utilizar 
int leer_asiganr();
void escribir_guardar();
int menu();
int menu_edit();
void show_contacts();
void add_contact();
void edit_contact();
void delete_contact();


int main() { 
    n_contactos = leer_asiganr();// toma la cantidad de contactos guardados en el archivo 

    int go=1;
    while (go < 5) {
        switch (menu()) {
            case 1: 
                show_contacts();
                break;
            case 2: 
                add_contact();
                break;
            case 3: 
                edit_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5: 
                go=5;
                break;
            default: cout << "\n\n\tERROR EN OPCION";
        }
    }

    // guardamos los datos 
    escribir_guardar();
    return 0; 
}

int menu() {
    cout << "\n\n\t*** MI AGENDA ***";
    cout<< "\n\t1. Mostrar contactos";
    cout<< "\n\t2. Añadir un contacto";
    cout<< "\n\t3. Editar un contacto";
    cout<< "\n\t4. Eliminar un contacto";
    cout<< "\n\t5. Salir del programa";
    
    int op;
    do
    {
        cout<<"\n ingresa una opcion:";cin>>op;
        if (op>5 || op<1)
        {
            cout<<" opcion ingresada no valida!!! \n porfavor ingresarla nuevamente \n";
        }
    } while (op>5 || op<1);
    return op;
}



void show_contacts(){
    cout<<"\n -------- Lista de contactos -----------\n";
    for (int i = 0; i < n_contactos; i++)
    {
        cout<<" ID: "<<list_contactos[i].id<<endl;
        cout<<list_contactos[i].nombre<<endl;
        cout<<list_contactos[i].correo<<endl;
        cout<<list_contactos[i].celular<<endl;
        cout<<"-------------------"<<endl;
    }
}

void add_contact(){

    cout<<"\n--------- Añade un contacto -----------\n";
    if (n_contactos>0)
    {   
        list_contactos[n_contactos].id = n_contactos;
        cout<<list_contactos[n_contactos].id<<endl;
    }
    else{
        list_contactos[n_contactos].id = n_contactos;
    }
    cout<<"nombre:";cin>>list_contactos[n_contactos].nombre;
    cout<<"correo:";cin>>list_contactos[n_contactos].correo;
    cout<<"celular:";cin>>list_contactos[n_contactos].celular;

    n_contactos+=1;
    cout<<"\n Contacto guardado ;) !!\n";
}


int menu_edit() {
    cout << "\n que desea editar";
    cout<< "\n1. nombre";
    cout<< "\n2. correo";
    cout<< "\n3. celular";
    cout<< "\n4. Salir del programa";
    
    int op;
    do
    {
        cout<<"\n ingresa una opcion:";cin>>op;
        if (op>4 || op<1)
        {
            cout<<" opcion ingresada no valida!!! \n porfavor ingresarla nuevamente \n";
        }
    } while (op>5 || op<1);
    return op;
}
void edit_contact(){
    int id;
    cout<<"\n--------- Edita un contacto -----------\n";
    do
    {
        cout<<"id del contacto a editar :";cin>>id;
        if (id<0)
        {
            cout<<"\n id ingresado no valido \n";
        }
    } while (id<0);
    
    int valid=0;
    for (int i = 0; i <= n_contactos; i++)
    {
        if (id == list_contactos[i].id )
        {   
            cout<<"\n contacto a editar \n";
            cout<<"nombre:"<<list_contactos[id].nombre<<endl;
            cout<<"correo:"<<list_contactos[id].correo<<endl;
            cout<<"celular:"<<list_contactos[id].celular<<endl;
            switch (menu_edit())
            {
            case 1:
                cout<<"edita el nombre:";cin>>list_contactos[id].nombre;
                break;
            case 2:
                cout<<"edita el correo:";cin>>list_contactos[id].correo;
                break;
            case 3:
                cout<<"edita el celular:";cin>>list_contactos[id].celular;
                break;
            default:
                break;
            }
            cout<<" Informacion actualizada ;) !!\n";
            break;
        }
        valid+=1;
    }

    if (valid==n_contactos)
    {
        cout<<"\n id ingresado no exiatente !!!!\n";
    }
    
   
}

void delete_contact(){
    int id;
    cout<<"\n--------- Ekimina un contacto -----------\n";
    do
    {
        cout<<"id del contacto a eliminar :";cin>>id;
        if (id<0)
        {
            cout<<"\n id ingresado no valido \n";
        }
    } while (id<0);

    int valid=0;
    for (int i = 0; i <= n_contactos; i++)
    {
        if (id == list_contactos[i].id )
        {   
            cout<<"\n contacto eliminado \n";
            cout<<"nombre:"<<list_contactos[id].nombre<<endl;
            cout<<"correo:"<<list_contactos[id].correo<<endl;
            cout<<"celular:"<<list_contactos[id].celular<<endl;
            for (int j = id; j < n_contactos ; j++)
            {
                list_contactos[j]=list_contactos[j+1];
            }
            break;
        }
        valid+=1;
    }

    // reasignacion de los id
    for (int i = 0; i < n_contactos; i++)
    {
        list_contactos[i].id=i;
    }
    

    if (valid==n_contactos)
    {
        cout<<"\n id ingresado no exiatente !!!!\n";
    }

    n_contactos-=1;
}



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
	archivo.open("agenda.csv", ios::in);
	if (archivo.fail()) { // validamos la existencia del archivo 
		cout << "* No se puedo leer el archivo." << endl;
		exit(1);
	}
    
    // variables auxiliares 
    string  aux_nombre, aux_correo, aux_celular,aux, linea;
    int aux_id;

    // cantidad de contactos ya guardados 
    int contador=0;
    // recorremos el archivo de lectura linea oir linea 
	while (getline(archivo, linea)) {
		stringstream stream(linea);
    // usamos un separador ; para identificar cada dato y asiganrlo a su correspondiente variable axuliar  
        getline(stream, aux, ';');
        aux_id = atoi(aux.c_str());
		getline(stream, aux_nombre, ';');
		getline(stream, aux_correo, ';');
        getline(stream, aux_celular, ';');
        
        // guardamos los datos obtenidos del archivo en la lista de contactos
        list_contactos[contador].id=aux_id;
        list_contactos[contador].nombre=aux_nombre;
        list_contactos[contador].correo=aux_correo;
        list_contactos[contador].celular=aux_celular;

        contador+=1;
    }
    archivo.close();
    return contador;
}

void escribir_guardar(){
    // declaramos y habrimos el archivo a leer
	ifstream archivo;
	archivo.open("agenda.csv", ios::in);
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

    // escribimos los datos almacenados en la lista de contactos en el archivo temporal
    for (int i = 0; i < n_contactos; i++){
        temporal<<list_contactos[i].id<<";";
        temporal<<list_contactos[i].nombre<<";";
        temporal<<list_contactos[i].correo<<";";
        temporal<<list_contactos[i].celular<<";"<<endl;
    }

    // cerramos archivos de lectura y guardado
    archivo.close();
    temporal.close();

    // eliminamos el archivom de clientes inicial
    remove("agenda.csv");
    // renombramos el archivo temporal
    rename("temporal.csv","agenda.csv");
    
}