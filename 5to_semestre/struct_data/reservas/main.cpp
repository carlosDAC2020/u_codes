
#include "lista.h"

int menu();
void vuelos();
void edit_vuelos();
lista A;

int main() {
  int go = 1;
  while (go==1) {
    switch (menu()) {
      case 1: vuelos();
        break;
      case 2: A.pedirDatosReservas();
        break;
      case 3: A.imprimirReservas(); 
        break;
      case 4: A.imprimirListaEspera();
        break;
      case 5: go=0;
        break;
      default: cout << "\n\n\tERROR EN OPCION";
    }
  }
  return 0;
}

int menu() {
  int op;
    cout << "\n\n\t*** MENU PRINCIPAL ***";
    cout << "\n\n1. Vuelos";
    cout << "\n2. Reservas";
    cout << "\n3. Listado de reservas";
    cout << "\n4. Lista de espera";
    cout << "\n5. Salir del menu";
    do
    {
      cout << "\n\n\tEscoja opcion: ";cin>>op;
      if (op<1 || op>5)
      {
        cout<<"\n ingresar solo valores entre 1 y 5 \n";
      }
    } while (op<1 || op>5);
}

void vuelos() {
  int go = 1, op;
  while (go == 1) {
    cout << "\n\n\t*** MENU VUELOS ***";
    cout << "\n\n1. Entrar nuevos vuelos";
    cout << "\n2. Modificar vuelos existentes";
    cout << "\n3. Salir del menu";
    cout << "\n\n\tEscoja opcion: ";
    do
    {
      cout << "\n\n\tEscoja opcion: ";cin>>op;
      if (op<1 || op>5)
      {
        cout<<"\n ingresar solo valores entre 1 y 5 \n";
      }
    } while (op<1 || op>3);
    switch (op) {
      case 1: A.pedirDatosVuelos();
        break;
      case 2: edit_vuelos();
        break;
      case 3: go=0;
        break;
      default: cout << "\n\n\tERROR EN OPCION";
    }
  }
}

void edit_vuelos() {
  int go = 0, op;
  while(go==1) {
    cout << "\n\n\t*** MENU MODIFICAR VUELOS ***";
    cout << "\n\n1.Modificar cupos";
    cout << "\n2. Modificar estado del vuelo";
    cout << "\n3. Salir del menu";
    cout << "\n\n\tEscoja opcion: ";
    do
    {
      cout << "\n\n\tEscoja opcion: ";cin>>op;
      if (op<1 || op>5)
      {
        cout<<"\n ingresar solo valores entre 1 y 3 \n";
      }
    } while (op<1 || op>3);
    switch (op) {
      case 1: A.modificarCuposVuelos();
        break;
      case 2: A.modificarEstadoVuelo();
        break;
      case 3: go=0;
        break;
      default: cout << "\n\n\tERROR EN OPCION";
    }
  }
}