#include "circular.h"

void menu() {
  cout << "\n*** LISTA CIRCULAR ***";
  cout << "\n\n1. Entrar datos a la lista...";
  cout << "\n2. Borrar datos de la lista...";
  cout << "\n3. Mostrar lista...";
  cout << "\n4. Salir...";
  cout << "\n\nEscoja opcion... ";
}

int main() {
  char op = '0';
  circular A;
  while (op < '4') {
    menu();
    cin >> op;
    switch (op) {
      case '1':
        A.preguntar1();
        break;
      case '2':
        A.preguntar2();
        break;
      case '3':
        A.listar();
        break;
      case '4': break;
      default:
        cout << "\n\n\t*** ERROR EN OPCION ***\n";
        op = '0';
    }
  }
  circular B(A);
  cout << "\n*** EVALUANDO EL CONSTRUCTOR DE COPIA ***\n";
  cout << "\nEl objeto A = "; A.listar();
  cout << "\nEl objeto copiado B = "; B.listar();
  cout << "\n\n";
  return 0;
}