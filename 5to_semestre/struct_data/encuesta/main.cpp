#include "encuesta.h"

int menu();
int menuPromedios();

int main() {
    encuesta A;
    int go=1;
    while (go < 5) {
        switch (menu()) {
            case 1: 
                A.pedirDatos();
                break;
            case 2: 
                A.imprimir();
                break;
            case 3: // menu de opciones para ver los promedios 
                switch (menuPromedios()){
                    case 1:
                        A.promEdad();
                        break;
                    case 2:
                        A.promIngresos();
                        break;
                    default: cout << "\n\n\tERROR EN OPCION";
                    }
                break;
            case 4: 
                A.porcentajes();
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
    cout<< "\n\t2. Mostrar datos";
    cout<< "\n\t3. Promedios";
    cout<< "\n\t4. Porcentajes";
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

int menuPromedios(){
    cout << "\n\n\t*** MENU PROMEDIOS ***";
    cout<< "\n\t1. Edad";
    cout<< "\n\t2. Ingresos";
    cout<< "\n\t3. Regresar al menu principal";

    int op;
    do
    {
        cout<<"\n ingresa una opcion:";cin>>op;
        if (op>3 || op<1)
        {
            cout<<" opcion ingresada no valida!!! \n porfavor ingresarla nuevamente \n";
        }
    } while (op>3 || op<1);
    return op;
}
