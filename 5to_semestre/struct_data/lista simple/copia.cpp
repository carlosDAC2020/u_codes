#include <iostream>
using namespace std;

struct nodo {
 int num;
 struct nodo *sig;
};
nodo *prim = NULL, *ultm, *nuevo;



void menu();
void pedirDatos();
void entrarDatos(int);
void quitarDatos();
int validar(int, struct nodo *);
void borrarDatos(int, struct nodo *);
void imprimir(struct nodo *);
void insertarAntes(int, int);
void insertarDespues(int, int);
void insertar(int);

int main() {
  char op = '0';
  while (op < '6') {
    menu();
    cin>>op;
    switch (op) {
      case '1': pedirDatos();
      break;
    case '2': quitarDatos();
      break;
    case '3': insertar(1);
      break;
    case '4': insertar(2);
      break;
    case '5': imprimir(prim);
      break;
    case '6': break;
    default: cout << "\n\n\tERROR EN OPCION";
      op = '0';
    }
  }
 return 0;
}


void menu() {
 cout << "\n\n\t*** MENU PRINCIPAL ***";
 cout << "\n\n1. Entrar datos a la lista";
 cout << "\n2. Borrar datos de la lista";
 cout << "\n3. Insertar antes";
 cout << "\n4. Insertar despues";
 cout << "\n5. Imprimir lista";
 cout << "\n6. Salir del menu";
 cout << "\n\n\tEscoja opcion: ";
}

void pedirDatos() {
  int dato;
  char res = 's';
  while (res == 's' || res == 'S') {
    cout << "\n\nDigite dato a entrar: ";
    cin>>dato;
    if (validar(dato, prim) == 0) {
      entrarDatos(dato);
      cout << "\n\tDato guardado con exito\n";
    } else
      cout << "\n\tDato existente no se guardo\n";
    do {
        cout << "\n\nDesea entrar otro dato (s/n): ";
        cin>>res;
    } while(res != 's' && res != 'S' && res != 'n' && res != 'N');
  }
}


// validamos que el dato ingresado exista o no en la lista
int validar(int v, struct nodo *p) {
  while (p != NULL && p->num != v)
    p = p->sig;
  if (p == NULL) return 0;
  return 1;
}

void entrarDatos(int v) {
  nuevo = (struct nodo *) new (struct nodo);
  nuevo->num = v;
  nuevo->sig = NULL;
  if (prim == NULL)
    prim = nuevo;
  else
    ultm->sig = nuevo;
  ultm = nuevo;
}