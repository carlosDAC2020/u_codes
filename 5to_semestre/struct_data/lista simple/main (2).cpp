#include <iostream>
using namespace std;

struct nodo {
 int num;
 struct nodo *sig;
 };
struct nodo *prim = NULL, *ultm, *nuevo;

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

int validar(int v, struct nodo *p) {
  while (p != NULL && p->num != v)
    p = p->sig;
  if (p == NULL) return 0;
  return 1;
}
void borrarDatos(int v, struct nodo *p) {
 struct nodo *a = p->sig;
 if (prim->num == v) 
 {
    prim = prim->sig; 
    p->sig = NULL;
    delete p;
  } else
    if (ultm->num == v) 
    {
      while (a != ultm) 
      {
        a = a->sig; 
        p = p->sig;
      }
      ultm = p;
      ultm->sig = NULL;
      delete a;
    } else 
      {
        while (a->num != v) 
        {
          a = a->sig; 
          p = p->sig;
        }
        p->sig = a->sig;
        a->sig = NULL;
        delete a;
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
    } while(res != 's' && res != 'S' && res != 'n' && res != 'N');
  }
}

void imprimir(struct nodo *p) {
  cout << "\n\n";
  while (p != NULL) {
    cout << p->num << ", ";
    p = p->sig;
  }
}

void insertar(int b) {
  int dato, referencia;
  char res = 's';
  while (res == 's' || res == 'S') {
    cout << "\n\nDigite dato a insertar: ";
    cin >> dato;
    cout << "\nDigite referencia: ";
    cin >> referencia;
    if (validar(dato, prim) == 0 && validar(referencia, prim) == 1){
      if (b == 1)
        insertarAntes(dato, referencia);
      else
        insertarDespues(dato, referencia);
      cout << "\n\tDato insertado con exito\n";
      cout << "\n\tSe inserto " << dato;
      cout << (b == 1 ? " antes de " : " despues de ");
      cout << referencia << "\n";
    } else {
      if (validar(dato, prim) != 0)
          cout << "\n\tDato a insertar ya existente \n";
      if (validar(referencia, prim) != 1)
          cout << "\n\tLa referencia no esta en la lista \n";
    }
    do {
      cout << "\n\nDesea entrar otro dato (s/n): ";
      cin >> res;
    } while(res != 's' && res != 'S' && res != 'n' && res != 'N');
  }
}

void insertarDespues(int v, int refe)
{
  nuevo = (struct nodo *) new (struct nodo);
  nuevo->num = v;
  nuevo->sig = NULL;
  if(refe == ultm->num)
  {
    ultm->sig = nuevo;
    ultm = nuevo;
  }
  else
  {
    struct nodo *p = prim;
    while(p->num != refe)
    {
      p = p->sig;
    }
    nuevo->sig = p->sig;
    p->sig = nuevo;
  }
}

void insertarAntes(int v, int refe)
{
  nuevo = (struct nodo *) new (struct nodo);
  nuevo->num = v;
  nuevo->sig = NULL;
  if(refe == prim->num)
  {
    nuevo->sig = prim;
    prim = nuevo;
  }
  else
  {
    struct nodo *p = prim, *a = prim->sig;
    while(a->num != refe)
    {
      p = p->sig;
      a = a->sig;
    }
    p->sig = nuevo;
    nuevo->sig = a;
  }
}