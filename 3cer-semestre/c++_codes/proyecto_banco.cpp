
#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// declaramos incialmente los vectores y estructuras que organizararn la informacion del programa 

const int n=1000; // tamaño predeterminado de las listas a utilizar 

struct historial{	// esta estructura manejara la informacion del historial de transacciones de cada cliente 
	string transaccion;
	float monto;
};

struct cliente{		// estructura que organuzara la informacion de los usuarios 
    string nombre;
    string apellido;
    int sexo;
    int edad;
    int n_documento;
    int clave_virtual; // clave se seguridad para inicion de secion para el usuario
    int num_cuenta; // numero de cuenta asiganado por el banco 
	float saldo; // saldo del usuario en la cuenta 
	historial h_transacciones[n]; // historial de las transacciones del ususario
	int n_transacciones=0; // cantidad de transaaciones que ha realizado el usuario
};
// lista en la cual se guardara la informacion de cada ususario 
cliente list_clientes[n];
int n_cliente=0; // variable que ira contando la cantidad de clientes 
int indice_cliente=0; // variable eque en un momento en especifico nosa dara el id o posicion de un cliente en las lista para gaci identificarslo 


// funciones para el registro y secion de los clientes ----------------------------------------------------------------------------
void nueva_cuenta(){
	// variables auxiliares paraedir los datos 
	string aux_nombre, aux_apellido;
	int aux_sexo, aux_edad, aux_documento, aux_clave_v, aux_n_cuenta;

	cout<<"\n REGUSTRO DE UNA NUEVA CUENTA \n";
	// datos personales 
	cout<<" nombre:";cin>>aux_nombre;
	list_clientes[n_cliente].nombre=aux_nombre;

	cout<<" apellido:";cin>>aux_apellido;
	list_clientes[n_cliente].apellido=aux_apellido;

	cout<<" edad:";cin>>aux_edad;
	list_clientes[n_cliente].edad=aux_edad;

	cout<<" num documneto:";cin>>aux_documento;
	list_clientes[n_cliente].n_documento=aux_documento;

	cout<<" sexo\n 1-->F\n 2-->M \n --:";cin>>aux_sexo;
	while (aux_sexo>2 || aux_sexo<1){
		cout<<"\n valor ingresado no valido\n";
		cout<<" escoja el numero se su sexo nuevamente:";cin>>aux_sexo;
	}
	list_clientes[n_cliente].sexo=aux_sexo;

	// datos de seguridad para el banco
		// clave virtual
	cout<<" clave virtual de 4 dijitos:";cin>>aux_clave_v;
	list_clientes[n_cliente].clave_virtual=aux_clave_v;

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

	n_cliente+=1;
}

int loguin(){
	int aux_documento, aux_clave, exit=0;
	bool ok=false;
	while(ok==false && exit==0){
		cout<<"\n INICIO DE CECION \n";
		cout<<" numero de documento:";cin>>aux_documento;
		cout<<" clave virtual:";cin>>aux_clave;

			// validacion de los datos 
		for(int i=0; i<n_cliente; i++){
			if (list_clientes[i].n_documento==aux_documento && list_clientes[i].clave_virtual==aux_clave){
				ok=true;
				indice_cliente=i;
				return 1;
			}
		}
		if(ok==false){
			cout<<"\n\n datos no validos \n"; 
			cout<<" 0--> probra nuevamente \n 1--> no probar\n ---->";cin>>exit;
		}
	}
}

// funciones para las transacciones ------------------------------------------------------------------------
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
		
		// agregamos la transaccion realizada al historial del ususario
		list_clientes[indice_cliente].n_transacciones+=1;
			// agregamos el tipo de transaccion realizada
		list_clientes[indice_cliente].h_transacciones[list_clientes[indice_cliente].n_transacciones-1].transaccion=" Retiro";
			// agregamos el munto utilizada en dicha transaccion
		list_clientes[indice_cliente].h_transacciones[list_clientes[indice_cliente].n_transacciones-1].monto=ret;
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

			// agregamos la transaccion realizada al historial del ususario que envia la transferencia
			list_clientes[indice_cliente].n_transacciones+=1;
				// agregamos el tipo de transaccion realizada
			list_clientes[indice_cliente].h_transacciones[list_clientes[indice_cliente].n_transacciones-1].transaccion=" Transferencia -";
				// agregamos el munto utilizada en dicha transaccion
			list_clientes[indice_cliente].h_transacciones[list_clientes[indice_cliente].n_transacciones-1].monto=transfer;
		
			// agregamos la transaccion realizada al historial del ususario que recibe la transferencia
			list_clientes[indx_transfer].n_transacciones+=1;
				// agregamos el tipo de transaccion realizada
			list_clientes[indx_transfer].h_transacciones[list_clientes[indx_transfer].n_transacciones-1].transaccion=" Transferencia +";
				// agregamos el munto utilizada en dicha transaccion
			list_clientes[indx_transfer].h_transacciones[list_clientes[indx_transfer].n_transacciones-1].monto=transfer;
		
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

	// agregamos la transaccion realizada al historial del ususario
	list_clientes[indice_cliente].n_transacciones+=1;
		// agregamos el tipo de transaccion realizada
	list_clientes[indice_cliente].h_transacciones[list_clientes[indice_cliente].n_transacciones-1].transaccion=" Recarga";
		// agregamos el munto utilizada en dicha transaccion
	list_clientes[indice_cliente].h_transacciones[list_clientes[indice_cliente].n_transacciones-1].monto=rec;
}


// funcion que muestar estadisticas generales del los clientes --------------------------------------------------------
void lista_clientes(){
	cout<<"\n LISTA DE CLIENTES \n";
	for(int i=0; i<n_cliente; i++){
		cout<<"\n cliente "<<i+1<<"------------------------"<<endl;
		cout<<" nombre:"<<list_clientes[i].nombre<<endl;
		cout<<" apellido:"<<list_clientes[i].apellido<<endl;
		cout<<" num documento:"<<list_clientes[i].n_documento<<endl;
		cout<<" edad:"<<list_clientes[i].edad<<endl;
		cout<<" numero de cuenta:"<<list_clientes[i].num_cuenta<<endl;
		cout<<"-----------------------------------------------\n";
	}

}

void cant_F_M(){
	cout<<"\n CANTIDAD DE MUJERES Y HOMBRES \n";
	int cant_f=0, cant_m=0;
	for(int i=0; i<n_cliente; i++){
		if(list_clientes[i].sexo==1){
			cant_f+=1;
		}
		else{
			cant_m+=1;
		}
	}
	cout<<"   sexo   | cantidad \n";
	cout<<"  mujeres     "<<cant_f<<endl;
	cout<<"  hombres     "<<cant_m<<endl;
}

void cant_may_men_edad(){
	cout<<"\n CANTIDAD DE MAYORES Y MENORES DE EDAD \n";
	int cant_men_edad=0, cant_may_edad=0;
	for(int i=0; i<n_cliente; i++){
		if(list_clientes[i].edad<18){
			cant_men_edad+=1;
		}
		else{
			cant_may_edad+=1;
		}
	}
	cout<<"     situacio      | cantidad \n";
	cout<<"  mayores de edad   "<<cant_may_edad<<endl;
	cout<<"  menores de edad   "<<cant_men_edad<<endl;
}


int main(){
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

						// historial de transacciones 
					if(list_clientes[indice_cliente].n_transacciones>0){
						cout<<"\n		 HISTORIAL DE TRANSACCIONES  \n";
						cout<<"\n      tipo        |     monto   \n";
						int aux=list_clientes[indice_cliente].n_transacciones;
						for(int i=0; i<aux; i++){
							cout<<list_clientes[indice_cliente].h_transacciones[i].transaccion<<"          "<<list_clientes[indice_cliente].h_transacciones[i].monto<<endl;
						}
					}
					else{
						cout<<"\n No ha realizado transacciones aun \n";
					}
					

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
			nueva_cuenta();
		}

		else { // ver estadisticas generales de los usuarios 
			int y=1;
			while (y==1){
				cout<<"\n ESTADISTICAS GENERALES ---------------------------------------------------\n";
				cout<<" que desea saber?\n";
				cout<<"--->1 lista de clientes \n";
				cout<<"--->2 cantidad de hombres y mujeres \n";
				cout<<"--->3 cantidad de mayores y menores de edad \n";
						
				cout<<"\n escoja el numero de su opcion:";cin>>option;
				while (option>3 || option<1){
					cout<<"\n valor ingresado no valido\n";
					cout<<" escoja el numero de su opcion nuevamente:";cin>>option;
				}

				if (option==1){
					lista_clientes();
				}
				else if (option==2){
					cant_F_M();
				}
				else{
					cant_may_men_edad();
				}			
				cout<<"\n volver al menu \n 1--> si \n 1!=--> no \n ---->";cin>>y;
			}
		}

		cout<<"\n que decea hacer? \n 1--> volver al menu de inicio  \n !=1--> salir del programa \n ---->";cin>>go;

	}
	
    return 0;
}