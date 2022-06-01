#include "cuenta.h"

using namespace std; 

/* lista para almacenar los dastos de los clientes */
vector <cuenta> list_clientes(100);
/* variable que ira contando la cantidad 
de clientes */ 
int n_cliente=0; 
/* variable eque en un momento en especifico nos
 dara el id o posicion de un cliente en las lista
  para haci identificarslo */
int indice_cliente=0;  

int main(){
    n_cliente=lectura_asigancion_datos(list_clientes);

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
			if (loguin(n_cliente,list_clientes, indice_cliente)==1){
				cout<<"\n secion iniciada -----------------------------------------------------\n";
				int x=1;
				while (x==1){
                    list_clientes[indice_cliente].imprime();
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
						list_clientes[indice_cliente].retiro();
					}
					else if (option==2){
						list_clientes[indice_cliente].trasnferencia(n_cliente, list_clientes);
					}
					else{
						list_clientes[indice_cliente].recarga();
					}			
					cout<<"\n cerrar la secio \n 1--> no \n 1!=--> si\n ---->";cin>>x;
				}
				
			}
			cout<<"\n ----------------------------------------------------------------\n";
		}

		else if (option==2){ /// crear una nueva cuenta
            cuenta new_cuenta;
			nueva_cuenta(n_cliente,list_clientes, new_cuenta);
            list_clientes[n_cliente]=new_cuenta;
		}
 
		else { // ver estadisticas generales de los usuarios 
			int y=1;
			while (y==1){
				cout<<"\n ESTADISTICAS GENERALES ---------------------------------------------------\n";
				cout<<" que desea saber?\n";
				cout<<"--->1 lista de clientes \n";
				
				cout<<"\n escoja el numero de su opcion:";cin>>option;
				
				if (option==1){
					lista_clientes(n_cliente,list_clientes);
				}
					
				cout<<"\n volver al menu \n 1--> si \n 1!=--> no \n ---->";cin>>y;
			}
		}

		cout<<"\n que decea hacer? \n 1--> volver al menu de inicio  \n !=1--> salir del programa \n ---->";cin>>go;

        // guardamos los datos
        guardar_datos(n_cliente,list_clientes);
	}

    
    return 0;
}