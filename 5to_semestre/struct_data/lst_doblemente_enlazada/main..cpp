#include <iostream>
using namespace std;

struct nodo {
    int num;
    struct nodo *sig, *ant;
};

struct nodo *prim = NULL, *ultm, *nuevo;

void menu();
void pedirDatos();
void entrarDatos(int);
void quitarDatos();
void borrarDatos(int, struct nodo *);
int validar(int, struct nodo *);
void imprimir1(struct nodo *);
void imprimir2(struct nodo *);

/*
 * Lista doble enlazada con menú
 */
 
int main() {
    char op = '0';
    while (op < '5') {
        menu();
        cin>>op;
        switch (op) {
            case '1': pedirDatos();
                break;
            case '2': quitarDatos();
                break;
            case '3': imprimir1(prim);
                break;
            case '4': imprimir2(ultm);
                break;
            case '5': cout << "Chao xd";
                break;
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
    cout << "\n3. Imprimir lista de menor a mayor";
    cout << "\n4. Imprimir lista de mayor a menor";
    cout << "\n5. Salir del menu";
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
        } while (res != 's' && res != 'S' && res != 'n' && res != 'N');
    }
}

void quitarDatos() {
    int dato;
    char res = 's';
    while (res == 's' || res == 'S') {
        cout << "\n\nDigite dato a borrar: ";
        cin>>dato;
        if (validar(dato, prim) == 1) {
            borrarDatos(dato, prim);
            cout << "\n\tDato borrado con exito\n";
        } else
            cout << "\n\tEl dato no existe\n";
        do {
            cout << "\n\nDesea borrar otro dato (s/n): ";
            cin>>res;
        } while (res != 's' && res != 'S' && res != 'n' && res != 'N');
    }
}

void entrarDatos(int v) {
  nuevo = (struct nodo *) new (struct nodo);
  nuevo->num = v;
  nuevo->sig = nuevo->ant = NULL;
  if(prim == NULL){
    prim = ultm = nuevo;
  }
  else{
    if(prim->num > nuevo->num){
      nuevo->sig = prim;
      prim->ant = nuevo;
      prim = nuevo;
    }
    else{
      if(ultm->num < nuevo->num){
        ultm->sig = nuevo;
        nuevo->ant = ultm;
        ultm = nuevo;
      }
      else{
        struct nodo *p = prim;
        while(p->num < nuevo->num){
          p = p->sig;
        }
        p->ant->sig = nuevo;
        nuevo->ant = p->ant;
        nuevo->sig = p;
        p->ant = nuevo;
      }
    }
  }
}

int validar(int v, struct nodo *p) {
  while(p != NULL and p->num != v){
    p = p->sig;
  }
  if(p == NULL){
    return 0;
  }
  return 1;
}

void borrarDatos(int v, struct nodo *p) {
  if(prim->num == v){
    prim = prim->sig;
    prim->ant = NULL;
    delete(p);
  }
  else{
    if(ultm->num == v){
      p = ultm;
      ultm = ultm->ant;
      ultm->sig = NULL;
      delete(p);
    }
    else{
      while(p->num != v){
        p = p->sig;
      }
      p->ant->sig = p->sig;
      p->sig->ant = p->ant;
      delete(p);
    }
  }
}
