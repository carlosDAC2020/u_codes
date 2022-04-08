#include "empleado.h"
#include "academico.h"
#include "administrativo.h"
#include "servicios.h"

using namespace std;

// creamos vectores para guardar los datos de lo empleados 
vector <academico> list_academicos(100);
vector <administrativo> list_administrativos(100);
vector <servicios> list_servicios(100);

// variables auxilioares para señalar las cantidades de cada tipo de empleado
int cant_academicos=0, cant_administradores=0, cant_servicios=0;

int menu(){
    int op;
    cout << "\n\t ";
    cout << "\n\t\t\tMENU administracion de empleados" << endl;
    cout << "\n1. añadir empleados  .";
    cout << "\n2. informacion de empleados academicos.";
    cout << "\n3. informacion de empleados administrativos.";
    cout << "\n4. informacion de empleados de servicios";
    cout << "\n\nEscoga una opcion:";cin>>op;
    while(op<1 || op>4){
        cout<<" valor ingresado no valido \n";
        cout<<" ingrese su opcion nuevamente:";cin>>op;
    }
    return op;
}


void añadir_empleado(){
    cout<<" INGRESO DE EMPLEADOS \n";
    int go=1;
    while (go==1){
        cout<<"\n que tipo de empledo desea ingresar?\n";
        cout<<"1--> academico \n";
        cout<<"2--> administrativo \n";
        cout<<"3--> servicios \n";

        int tipo;
        do{
            cout<<" ingrese el tipo deseado:",cin>>tipo;
            if (tipo<1 || tipo>3){
                cout<<"valor ingresado no valido !!!\n";
            }
        } 
        while (tipo<1 || tipo>3);

        switch (tipo){
            case 1:
                cout<<"\n ingreso de empleadco tipo academico";
                cin>>list_academicos[cant_academicos];
                cant_academicos+=1;
            break;
        
            case 2:
                cout<<"\n ingreso de empleadco tipo administrativo";
                cin>>list_administrativos[cant_administradores];
                cant_administradores+=1;
            break;

            case 3:
                cout<<"\n ingreso de empleadco tipo servicios";
                cin>>list_servicios[cant_servicios];
                cant_servicios+=1;
            break;
        }
        cout<<"\n desea agregar otro empleado?\n 1 = si \n 2= no\n ingrese su opcion:";cin>>go;
    }
    
}

int main() {
   
    int go=1, op;
    while(go==1){
        switch(menu()){
            //---------------------------------------------
            case 1:
                añadir_empleado();
            break;
            //---------------------------------------------
            case 2:
                cout<<"\n que desea saber de los empleados academicos ?\n";
                cout<<"1--> lista de empleados \n";
                cout<<"2--> total a pagar en nomina  \n";
                cout << "\n\nEscoga una opcion:";cin>>op;
                while(op<1 || op>2){
                    cout<<" valor ingresado no valido \n";
                    cout<<" ingrese su opcion nuevamente:";cin>>op;
                }
                switch (op){
                    case 1:
                        imprimir_lista_academicos(cant_academicos, list_academicos);
                    break;

                    case 2:
                        cout<<"\n la nomina total a pagar es de:"<<nomina_total_academicos(cant_academicos, list_academicos);
                    break;
                }
                
            break;
            //---------------------------------------------
            case 3:
                cout<<"\n que desea saber de los empleados academicos ?\n";
                cout<<"1--> lista de empleados \n";
                cout<<"2--> total a pagar en nomina  \n";
                cout << "\n\nEscoga una opcion:";cin>>op;
                while(op<1 || op>2){
                    cout<<" valor ingresado no valido \n";
                    cout<<" ingrese su opcion nuevamente:";cin>>op;
                }
                switch (op){
                    case 1:
                        imprimir_lista_administrativo(cant_administradores, list_administrativos);
                    break;

                    case 2:
                        cout<<"\n la nomina total a pagar es de:"<<nomina_total_administrativos(cant_administradores, list_administrativos);
                    break;
                }
            break;
            //---------------------------------------------
            case 4:
                cout<<"\n que desea saber de los empleados academicos ?\n";
                cout<<"1--> lista de empleados \n";
                cout<<"2--> total a pagar en nomina  \n";
                cout << "\n\nEscoga una opcion:";cin>>op;
                while(op<1 || op>2){
                    cout<<" valor ingresado no valido \n";
                    cout<<" ingrese su opcion nuevamente:";cin>>op;
                }
                switch (op){
                    case 1:
                        imprimir_lista_servicios(cant_servicios, list_servicios);
                    break;

                    case 2:
                        cout<<"\n la nomina total a pagar es de:"<<nomina_total_servicios(cant_servicios, list_servicios);
                    break;
                }
                
            break;
        }
        cout<<"\n que quiere hacer ahora? \n 1= volver al menu \n 2= salir del programa\n ingrese su opcion:";cin>>go;
    }
    
  return 0;
}