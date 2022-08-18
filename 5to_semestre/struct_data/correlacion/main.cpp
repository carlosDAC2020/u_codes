// carlos daniel agamez T00059006
// caso de correlacion aplicando lista simple 
#include "lista.h"

int menu();

int main() {
    lista A;
    int go=1;
    while (go < 5) {
        switch (menu()) {
            case 1: A.pedirDatos();
            break;
            case 2: A.quitarDatos();
            break;
            case 3: A.correlacion();
            break;
            case 4: A.imprimir();
            break;
            case 5: go=5;
            break;
            default: cout << "\n\n\tERROR EN OPCION";
        }
    }
    return 0;
}

int menu() {
    cout << "\n\n\t*** MENU PRINCIPAL ***";
    cout << "\n\n1. Entrar datos a la lista de jugadores";
    cout << "\n2. Borrar datos de la lista";
    cout << "\n3. Calcular correlaion";
    cout << "\n4. Imprimir la lista";
    cout << "\n5. Salir de menu";
    cout << "\n\n\tEscoja opcion: ";

    int op;
    do
    {
        cout<<"ingresa una opcion:";cin>>op;
        if (op>5 || op<1)
        {
            cout<<" opcion ingresada no valida!!! \n porfavor ingresarla nuevamente \n";
        }
    } while (op>5 || op<1);
    return op;
}
