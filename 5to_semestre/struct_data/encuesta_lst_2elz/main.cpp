#include "lista.h"

int menu();

int main() {
    lista A;
    int go=1;
    while (go < 5) {
        switch (menu()) {
            case 1: 
                A.pedirDatos();
                break;
            case 2: 
                A.quitarDatos();
                break;
            case 3: 
                A.mostra_stadisticas();
                break;
            case 4: 
                A.imprimir1();
                break;
            case 5: 
                go==5;
                break;
            default: cout << "\n\n\tERROR EN OPCION";
        }
    }
    return 0;
}

int menu() {
    cout << "\n\n\t*** MENU PRINCIPAL ***";
    cout<< "\n\t1. Entrada de datos";
    cout<< "\n\t2. Borrar datos";
    cout<< "\n\t3. Estadisticas";
    cout<< "\n\t4. Mostrar empleados";
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


