#include "cuenta.h"

// constructor
cuenta::cuenta(string ced, string name, string apell, int n_c, int clav, float sald){
    cedula=ced;
    nombre=name;
    apellido=apell;
    num_cuenta=n_c;
    clave=clav;
    saldo=sald;
}

// destructor
cuenta::~cuenta(){

}

// sets
void cuenta::setcedula(string ced){
    cedula=ced;
}

void cuenta::setnombre(string name){
    nombre=name;
}

void cuenta::setapellido(string apell){
    apellido=apell;
}
    
void cuenta::setnum_cuenta(int n_c){
    num_cuenta=n_c;
}

void cuenta::setclave(int clav){
    clave=clav;
}

void cuenta::setsaldo(float sald){
    saldo=sald;
}

// gets
string cuenta::getcedula(){
    return cedula;
}

string cuenta::getnombre(){
    return nombre;
}

string cuenta::getapellido(){
    return apellido;
}

int cuenta::getnum_cuenta(){
    return num_cuenta;
}

int cuenta::getclave(){
    return clave;
}

float cuenta::getsaldo(){
    return saldo;
}


// metodos para las trnasacciones 
void cuenta::imprime(){
    cout<<"\n Bienvenid@ "<<nombre<<" "<<apellido<<"\n",
    cout<<" con numero de cuenta :"<<num_cuenta<<endl;
    
        // datos basicos del usuario
    cout<<"\n		 ESTADO DE SU CUENTA \n";
    cout<<" Salso actual:"<<saldo<<endl;
}

void cuenta::trasnferencia(int num_clientes,vector<cuenta> &a){
    int numero_cuenta, indx_transfer;
	float transfer;
	cout<<" \n\n solicirud de transferencia a otra cuenta\n";
	cout<<" numero de cuenta a tranferir:";cin>>numero_cuenta;
	cout<<" monto a tranferir a tranferir:";cin>>transfer;

	// verificamos que el numero de cuenta a tranferir este en la lista de clientes
	// en caso de que este guardamos el id del cliente al cual se le transferira 
	int z=0;
	for(int i=0; i<num_clientes; i++){
		if (numero_cuenta==a[i].getnum_cuenta()){
			indx_transfer=i;
			z=1;
			break;
		}
	}

	// se ejecutara la transaccion si el numero de cuenta coincide 
	if (z==1){
		if(saldo>=transfer){
			cout<<"\n transaccion exitosa \n";
			cout<<" transferiste a:"<<a[indx_transfer].getnombre()<<endl;
			cout<<" monto transferido:"<<transfer<<endl;
			
			// sumamos el tranferido al salo del usuario correspondiente 
            float aux_transfer_saldo=a[indx_transfer].getsaldo() + transfer;
			a[indx_transfer].setsaldo(aux_transfer_saldo);
			// restamos el tranferido al salo del usuario correspondiente 
			setsaldo(saldo-transfer);
			cout<<"\n  ahora su saldo es de "<<saldo<<"$ \n";
		}
		else{
			cout<<"\n lo sentimos no tiene saldo suficiente para esta transaccion !! :(\n";
		}
	}
	else{
		cout<<"\n lo sentimos el nuemro de cuenta ingresado no existe !! :(\n";
	}
}

void cuenta::retiro(){
    float ret;
	cout<<" \n\n solicirud de retiro\n";
	cout<<" ingrese el valor del monto a retirar :";cin>>ret;
	if(saldo<ret){
		cout<<"\n lo sentimos no tiene saldo suficiente para esta transaccion !! :(\n";
	}
	else{
        setsaldo(saldo - ret);
		cout<<"\n transaccion realizada ahora su saldo es de "<<saldo<<"$ \n";
	}
}

void cuenta::recarga(){
    float rec;
	cout<<" \n\n solicirud de recarga de saldo\n";
	cout<<" ingrese el valor del monto a recargar :";cin>>rec;
    setsaldo(saldo + rec);
	cout<<"\n transaccion realizada ahora su saldo es de "<<saldo<<"$ \n";
}



// -------  funcion lectura y aignacion de datos -------------- 
/* esta funcion lee y guarda datos de un archivo externo 
   en una estructura de datos pre declafrada en x programa 
   como en este caso
   
   se toma como parametro el nombre del archivo a leer 
   y se procesan y guardan los datos 
   en la estructura correspondiente 
*/
int lectura_asigancion_datos ( vector<cuenta> &a){
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

        

        // agregamos los datos a la estructura de lista de clientes para usarlos 
        a[contador].setnombre(nombre_aux);
        a[contador].setapellido(apellido_aux);
        a[contador].setcedula(cedula_aux);
        a[contador].setclave(clave_aux);
        a[contador].setnum_cuenta(num_cuenta_aux);
        a[contador].setsaldo(saldo_aux);
        contador+=1;
    }
    archivo.close();
    return contador;
}


// -------  funcion lectura y guardado de datos ----------------- 
/* esta funcion lee y los datos guardados en una lista 
   y los escribe en un archivo externo .csv, esto con 
   el fin de que los datos obtenicod en le ejecucion 
   del programa no se pierdan y podamos reutilizarlos 
*/
void guardar_datos (int num_clientes, vector<cuenta> &a){
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
    for (int i = 0; i < num_clientes; i++){
        temporal<<a[i].getnombre()<<";";
        temporal<<a[i].getapellido()<<";";
        temporal<<a[i].getcedula()<<";";
        temporal<<a[i].getnum_cuenta()<<";";
        temporal<<a[i].getclave()<<";";
        temporal<<a[i].getsaldo()<<";"<<endl;
    }

    // cerramos archivos de lectura y guardado
    archivo.close();
    temporal.close();

    // eliminamos el archivom de clientes inicial
    remove("clientes.csv");
    // renombramos el archivo temporal
    rename("temporal.csv","clientes.csv");
}

/*
 ------ funcion de incio de secion para usuarios --------------
    esta funcion toma como parametros la cantidad de clientes 
    la lista de clientes y un indice de cliente el cual sera retornada 
    si se lklegan a verificar correctamente los datos solicitados
    al usuario en la funcion 
*/
int loguin(int num_clientes,vector<cuenta> &a, int &index_client){
     string  aux_documento;
	int aux_clave, exit=1;
	bool ok=false;
	while(ok==false && exit==1){
		cout<<"\n INICIO DE CECION \n";
		cout<<" numero de documento:";cin>>aux_documento;
		cout<<" clave virtual:";cin>>aux_clave;

			// validacion de los datos 
		for(int i=0; i<num_clientes; i++){
			if (a[i].getcedula()==aux_documento && a[i].getclave()==aux_clave){
				ok=true;
				index_client=i;
				return 1;
			}
		}
		if(ok==false){
			cout<<"\n\n datos no validos \n"; 
			cout<<" 1--> probra nuevamente \n 2--> no probar\n ---->";cin>>exit;
		}
	}
}


/*sobrecarga de operadores para la imprecion de los datos de los clientes */ 
ostream &operator<<(ostream &cout, const cuenta &a){
    cout<<"\n usuario"<<a.nombre<<" "<<a.apellido<<"\n",
    cout<<" con numero de cuenta :"<<a.num_cuenta<<endl;
    
        // datos basicos del usuario
    cout<<"\n		 ESTADO DE SU CUENTA \n";
    cout<<" Salso actual:"<<a.saldo<<endl;

    return cout;
}

void nueva_cuenta(int &num_clientes,vector<cuenta> &list_c, cuenta &a){
      // variables auxiliares paraedir los datos 
	string aux_nombre, aux_apellido, aux_cedula;
	int  aux_clave, aux_n_cuenta;
    float aux_saldo;

	cout<<"\n REGUSTRO DE UNA NUEVA CUENTA \n";
	// datos personales 
	cout<<" nombre:";cin>>aux_nombre;
	cout<<" apellido:";cin>>aux_apellido;
	cout<<" num documneto:";cin>>aux_cedula;
	// datos de seguridad para el banco
		// clave virtual
	cout<<" clave virtual de 4 dijitos:";cin>>aux_clave;

		// asignacion de numero de cuenta 
	// evitamos asignar el mismo numero de cuenta a los ususarios de la siguiente manera 
	if(num_clientes>0){
		int valido=0;
		while (valido==0){
			// asignamos un numero aleatorio de 4 cifras como numero de cuenta 
			// y validamos que no se repita ese numero de cuenta con asignado de otros clientes 
			srand(time(NULL));
			aux_n_cuenta=1000 + rand() % (10000-1);
			for (int i=0; i<num_clientes; i++){
				if(aux_n_cuenta==list_c[i].getnum_cuenta()){
					valido=0;
					break;
				}
				if(i==num_clientes-1){
					valido=1;
				}
			}
		}
			// al confirmar que no se repita el numero de cuenta entre usuarios asignamos el valor 
			// del numero de cuenta a nuestro nuevo cliente 
		list_c[num_clientes].num_cuenta=aux_n_cuenta;
	}
	else{
		srand(time(NULL));
		aux_n_cuenta=1000 + rand() % (10000-1);
	}
		// asigansmos los datos almacenados en las varianles auxiliares al objeto cuenta pasado como parametro
    a.setnombre(aux_nombre);
    a.setapellido(aux_apellido);
    a.setcedula(aux_cedula);
    a.setnum_cuenta(aux_n_cuenta);
    a.setsaldo(0.0);

	num_clientes+=1; // sumamos el cliente a crear en la cantidad total de usuarios
}

void lista_clientes(int num_clientes, vector<cuenta> &a){
    cout<<"\n LISTA DE CLIENTES \n";
	for(int i=0; i<num_clientes; i++){
        cout<<" cliente "<<i+1<<endl;
		cout<<a[i]<<endl;
	}
}