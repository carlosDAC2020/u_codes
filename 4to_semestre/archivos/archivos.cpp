#include <iostream> 
#include <fstream> 
#include <cmath> 
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <stdio.h>
using namespace std;    

struct usuario{ // estructura con la cual se manejaran los datos de los usuarios 
    string nombre;
    string apellido;
    string cedula;
    int num_cuenta;
    int clave;
    float saldo=0.0;
};

usuario list_clientes[100]; // lista que alojara los datos de los clientes 
int n_cliente=0; // variable que ira contando la cantidad de clientes 
int indice_cliente=0; // variable eque en un momento en especifico nosa dara el id o posicion de un cliente en las lista para gaci identificarslo 


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
	archivo.open("clientes.csv", ios::in);
	if (archivo.fail()) { // validamos la existencia del archivo 
		cout << "* No se puedo leer el archivo." << endl;
		exit(1);
	}
    
    // variables auxiliares 
    string nombre_aux, apellido_aux, cedula_aux,linea,auxiliar;
    int num_cuenta_aux,clave_aux;
    float saldo_aux=0.0;

    // cantidad de clientes ya guardados 
    int contador=0;
    // recorremos el archivo de lectura linea oir linea 
	while (getline(archivo, linea)) {
		stringstream stream(linea);
    // usamos un separador ; para identificar cada dato y asiganrlo a su correspondiente variable axuliar  
		getline(stream, nombre_aux, ';');
		getline(stream, apellido_aux, ';');
		getline(stream, cedula_aux, ';');
        getline(stream, auxiliar, ';');
		num_cuenta_aux = atoi(auxiliar.c_str());
        getline(stream, auxiliar, ';');
		clave_aux = atoi(auxiliar.c_str());
        getline(stream, auxiliar, ';');
		saldo_aux = atof(auxiliar.c_str());

        contador+=1;

        // agregamos los datos a la estructura de lista de clientes para usarlos 
        list_clientes[contador-1].nombre=nombre_aux;
        list_clientes[contador-1].apellido=apellido_aux;
        list_clientes[contador-1].cedula=cedula_aux;
        list_clientes[contador-1].num_cuenta=num_cuenta_aux;
        list_clientes[contador-1].clave=clave_aux;
        list_clientes[contador-1].saldo=saldo_aux;
    }
    archivo.close();
    return contador;
}

void escribir_guardar(){
    // declaramos y habrimos el archivo a leer
	ifstream archivo;
	archivo.open("clientes.csv", ios::in);
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
    for (int i = 0; i < n_cliente; i++){
        temporal<<list_clientes[i].nombre<<";";
        temporal<<list_clientes[i].apellido<<";";
        temporal<<list_clientes[i].cedula<<";";
        temporal<<list_clientes[i].num_cuenta<<";";
        temporal<<list_clientes[i].clave<<";";
        temporal<<list_clientes[i].saldo<<";"<<endl;
    }

    // cerramos archivos de lectura y guardado
    archivo.close();
    temporal.close();

    // eliminamos el archivom de clientes inicial
    remove("clientes.csv");
    // renombramos el archivo temporal
    rename("temporal.csv","clientes.csv");
    
}

//------------------- funcion para crear una nueva cuenta ------------------------------
/* esta funcion toma como parametro la cantidad de usuaarios guardados hasta la fecha 
   se solicitan los datos basicos del usuario para guardarlos en la lista de clientes  
*/
int nueva_cuenta(){

	// variables auxiliares paraedir los datos 
	string aux_nombre, aux_apellido, aux_cedula;
	int  aux_clave, aux_n_cuenta;
    float aux_saldo;

	cout<<"\n REGUSTRO DE UNA NUEVA CUENTA \n";
	// datos personales 
	cout<<" nombre:";cin>>aux_nombre;
	list_clientes[n_cliente].nombre=aux_nombre;

	cout<<" apellido:";cin>>aux_apellido;
	list_clientes[n_cliente].apellido=aux_apellido;

	cout<<" num documneto:";cin>>aux_cedula;
	list_clientes[n_cliente].cedula=aux_cedula;

	// datos de seguridad para el banco
		// clave virtual
	cout<<" clave virtual de 4 dijitos:";cin>>aux_clave;
	list_clientes[n_cliente].clave=aux_clave;

		// asignacion de numero de cuenta 
	// evitamos asignar el mismo numero de cuenta a los ususarios de la siguiente manera 
	if(n_cliente>0){
		int valido=0;
		while (valido==0){
			// asignamos un numero aleatorio de 4 cifras como numero de cuenta 
			// y validamos que no se repita ese numero de cuenta con asignado de otros clientes 
			srand(time(NULL));
			aux_n_cuenta=1000 + rand() % (10000-1);
			for (int i=0; i<n_cliente; i++){
				if(aux_n_cuenta==list_clientes[i].num_cuenta){
					valido=0;
					break;
				}
				if(i==n_cliente-1){
					valido=1;
				}
			}
		}
			// al confirmar que no se repita el numero de cuenta entre usuarios asignamos el valor 
			// del numero de cuenta a nuestro nuevo cliente 
		list_clientes[n_cliente].num_cuenta=aux_n_cuenta;
	}
	else{
		srand(time(NULL));
		aux_n_cuenta=1000 + rand() % (10000-1);
		list_clientes[n_cliente].num_cuenta=aux_n_cuenta;
	}
		//saldo
	list_clientes[n_cliente].saldo=0;

	n_cliente+=1; // sumamos el cliente a crear en la cantidad total de usuarios

    return n_cliente;
}

//---------------------- funcion de loguin -----------------------------------
/* funcion para incio de secion la cual retorna un valor entero 1 
   si los datos suministrados por el usuario correponden con los guardados
   en la lista de clientes 

   al identificar el usuario al que corresponden los datos se guardara su indice de referencia 
   el cual sera usado posteriromente para la realizacion de las transacciones  
*/

int loguin(){
    string  aux_documento;
	int aux_clave, exit=1;
	bool ok=false;
	while(ok==false && exit==1){
		cout<<"\n INICIO DE CECION \n";
		cout<<" numero de documento:";cin>>aux_documento;
		cout<<" clave virtual:";cin>>aux_clave;

			// validacion de los datos 
		for(int i=0; i<n_cliente; i++){
			if (list_clientes[i].cedula==aux_documento && list_clientes[i].clave==aux_clave){
				ok=true;
				indice_cliente=i;
				return 1;
			}
		}
		if(ok==false){
			cout<<"\n\n datos no validos \n"; 
			cout<<" 1--> probra nuevamente \n 2--> no probar\n ---->";cin>>exit;
		}
	}
}

//----------------------- funciones para las transacciones ------------------------
void retiro(){
	float ret;
	cout<<" \n\n solicirud de retiro\n";
	cout<<" ingrese el valor del monto a retirar :";cin>>ret;
	if(list_clientes[indice_cliente].saldo<ret){
		cout<<"\n lo sentimos no tiene saldo suficiente para esta transaccion !! :(\n";
	}
	else{
		list_clientes[indice_cliente].saldo-=ret;
		cout<<"\n transaccion realizada ahora su saldo es de "<<list_clientes[indice_cliente].saldo<<"$ \n";
	}
}

void transferencia(){
	int numero_cuenta, indx_transfer;
	float transfer;
	cout<<" \n\n solicirud de transferencia a otra cuenta\n";
	cout<<" numero de cuenta a tranferir:";cin>>numero_cuenta;
	cout<<" monto a tranferir a tranferir:";cin>>transfer;

	// verificamos que el numero de cuenta a tranferir este en la lista de clientes
	// en caso de que este guardamos el id del cliente al cual se le transferira 
	int z=0;
	for(int i=0; i<n_cliente; i++){
		if (numero_cuenta==list_clientes[i].num_cuenta){
			indx_transfer=i;
			z=1;
			break;
		}
	}

	// se ejecutara la transaccion si el numero de cuenta coincide 
	if (z==1){
		if(list_clientes[indice_cliente].saldo>=transfer){
			cout<<"\n transaccion exitosa \n";
			cout<<" transferiste a:"<<list_clientes[indx_transfer].nombre<<endl;
			cout<<" monto transferido:"<<transfer<<endl;
			
			// sumamos el tranferido al salo del usuario correspondiente 
			list_clientes[indx_transfer].saldo+=transfer;
			// restamos el tranferido al salo del usuario correspondiente 
			list_clientes[indice_cliente].saldo-=transfer;
			cout<<"\n  ahora su saldo es de "<<list_clientes[indice_cliente].saldo<<"$ \n";
		}
		else{
			cout<<"\n lo sentimos no tiene saldo suficiente para esta transaccion !! :(\n";
		}
	}
	else{
		cout<<"\n lo sentimos el nuemro de cuenta ingresado no existe !! :(\n";
	}
	
}

void recarga_cuenta(){
	float rec;
	cout<<" \n\n solicirud de recarga de saldo\n";
	cout<<" ingrese el valor del monto a recargar :";cin>>rec;
	
	list_clientes[indice_cliente].saldo+=rec;
	cout<<"\n transaccion realizada ahora su saldo es de "<<list_clientes[indice_cliente].saldo<<"$ \n";
}


//----------- funciones de administrador ---------------------------
void lista_clientes(){
	cout<<"\n LISTA DE CLIENTES \n";
	for(int i=0; i<n_cliente; i++){
		cout<<"\n cliente "<<i+1<<"------------------------"<<endl;
		cout<<" nombre:"<<list_clientes[i].nombre<<endl;
		cout<<" apellido:"<<list_clientes[i].apellido<<endl;
		cout<<" num documento:"<<list_clientes[i].cedula<<endl;
		cout<<" numero de cuenta:"<<list_clientes[i].num_cuenta<<endl;
        cout<<" saldo de cuenta:"<<list_clientes[i].saldo<<endl;
		cout<<"-----------------------------------------------\n";
	}
}

int main() { 
    n_cliente=leer_asiganr();// toma la cantidad de usuarios guardados hasta la fecha 

   int go=1;
	while (go==1){
		cout<<"\n BIENVENID@ A NUESTRO BANCO\n";
        cout<<" estamos para servirte \n en que podemos colaborarle? \n";
		cout<<"--->1 inicioa secion\n";
		cout<<"--->2 crea una cuenta  \n";
		cout<<"--->3 estadisticas de nuestro banmco \n";

		int option;
		cout<<" escoja el numero de su opcion:";cin>>option;
		while (option>3 || option<1){
			cout<<"\n valor ingresado no valido\n";
			cout<<" escoja el numero de su opcion nuevamente:";cin>>option;
		}

		if (option==1){ // inicio de secion de los clientes y ejecucion de transacciones 
			if (loguin()==1){
				cout<<"\n secion iniciada -----------------------------------------------------\n";
				int x=1;
				while (x==1){

					cout<<"\n Bienvenid@ "<<list_clientes[indice_cliente].nombre<<" "<<list_clientes[indice_cliente].apellido<<"\n",
					cout<<" con numero de cuenta :"<<list_clientes[indice_cliente].num_cuenta<<endl;
					
						// datos basicos del usuario
					cout<<"\n		 ESTADO DE SU CUENTA \n";
					cout<<" Salso actual:"<<list_clientes[indice_cliente].saldo<<endl;

						// menu de transacciones 
					cout<<"\n transacciones que puede hacer \n";
					cout<<"--->1 retiro \n";
					cout<<"--->2 transferencia \n";
					cout<<"--->3 recargar saldo \n";
					
					cout<<"\n escoja el numero de su opcion:";cin>>option;
					while (option>3 || option<1){
						cout<<"\n valor ingresado no valido\n";
						cout<<" escoja el numero de su opcion nuevamente:";cin>>option;
					}

					if (option==1){
						retiro();
					}
					else if (option==2){
						transferencia();
					}
					else{
						recarga_cuenta();
					}			
					cout<<"\n cerrar la secio \n 1--> no \n 1!=--> si\n ---->";cin>>x;
				}
				
			}
			cout<<"\n ----------------------------------------------------------------\n";
		}

		else if (option==2){ /// crear una nueva cuenta
			n_cliente=nueva_cuenta();
		}

		else { // ver estadisticas generales de los usuarios 
			int y=1;
			while (y==1){
				cout<<"\n ESTADISTICAS GENERALES ---------------------------------------------------\n";
				cout<<" que desea saber?\n";
				cout<<"--->1 lista de clientes \n";
				
				cout<<"\n escoja el numero de su opcion:";cin>>option;
				
				if (option==1){
					lista_clientes();
				}
					
				cout<<"\n volver al menu \n 1--> si \n 1!=--> no \n ---->";cin>>y;
			}
		}

		cout<<"\n que decea hacer? \n 1--> volver al menu de inicio  \n !=1--> salir del programa \n ---->";cin>>go;

        // guardamos los datos
        escribir_guardar();
	}
    
    return 0; 
}
