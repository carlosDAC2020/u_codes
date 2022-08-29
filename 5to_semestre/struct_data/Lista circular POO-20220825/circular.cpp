#include "circular.h"

circular::circular() {
    prim = NULL;
}

circular::circular(const circular &orig) {   
  if(orig.prim == NULL)
    prim = NULL;
  else {
    struct nodo *p = orig.prim;
    int c = 1;
    if(p->sig == NULL) {
      nuevo = (struct nodo *) new (struct nodo);
      nuevo->codigo = p->codigo;
      nuevo->ant = nuevo->sig = NULL;
      prim = nuevo; 
    } 
    else {
      while(p->sig != orig.prim)
      {
        p = p->sig;
        c++;
      } 
      p = orig.prim;
      nuevo = (struct nodo *) new (struct nodo);
      nuevo->codigo = p->codigo;
      nuevo->ant = nuevo->sig = NULL;
      switch(c)
      {
        case 2:
          prim = nuevo;
          p = p->sig;    
          nuevo = (struct nodo *) new (struct nodo);
          nuevo->codigo = p->codigo;
          nuevo->ant = nuevo->sig = NULL;    
          prim->sig = prim->ant = nuevo;
          nuevo->sig = nuevo->ant = prim;
          break;
        default:
          struct nodo *ultm;
          prim = ultm = nuevo;
          p = p->sig;    
          while(p->sig != orig.prim)
          {
            nuevo = (struct nodo *) new (struct nodo);
            nuevo->codigo = p->codigo;
            nuevo->ant = nuevo->sig = NULL;
            ultm->sig = nuevo;
            nuevo->ant = ultm;         
            ultm = nuevo;      
            p = p->sig;
          }
          nuevo = (struct nodo *) new (struct nodo);
          nuevo->codigo = p->codigo;
          nuevo->ant = nuevo->sig = NULL;  
          ultm->sig = nuevo;
          nuevo->ant = ultm;
          nuevo->sig = prim;
          prim->ant = nuevo;
      }
    }
  }
}

circular::~circular() {
    struct nodo *p = prim;
    p->ant->sig = NULL;
    while(p->sig != NULL)
    {
      prim = prim->sig;
      delete(p);
      p = prim;
    }
    delete(p);
}

void circular::preguntar1()
{
  string dato;
  char res = 's';
  while(res == 's' || res == 'S') {
    cout << "\nDigite codigo a entrar... ";
    cin >> dato;
    if(validar(dato)) {
      cout << "\nEl dato ya existe...";
      cout << "\nNo se guarda en la lista.\n";
    }
    else {
      cout << "\nEl codigo no existe...";
      entrada(dato);
      cout << "\nDato guardado con exito...\n";
    }   
    do{
      cout << "\nDesea entrar otro dato (s/n)... ";
      cin >> res;
    }while(res != 's' && res != 'S' && res != 'n' && res != 'N');
  }
}
    
void circular::entrada(string v)
{
  nuevo = (struct nodo *) new (struct nodo);
  nuevo->codigo = v;
  nuevo->sig = nuevo->ant = NULL;
  if(prim == NULL)
    prim = nuevo;
  else
    if(prim->sig == NULL) //Es el segundo nodo
    {
      prim->sig = prim->ant = nuevo;
      nuevo->sig = nuevo->ant = prim;
      if(nuevo->codigo < prim->codigo)
        prim = nuevo;
    }
    else
    {
      struct nodo *p = prim;  
      while(p->codigo < v)
        p = p->sig;
      p->ant->sig = nuevo;
      nuevo->ant = p->ant;
      nuevo->sig = p;
      p->ant = nuevo;
      if(nuevo->codigo < prim->codigo)
        prim = nuevo;
    }
}
    
void circular::preguntar2()
{
    string dato;
    char res = 's';
    
    while(res == 's' || res == 'S')
    {
        cout << "\n*** DATOS DE LA LISTA ***\n";
        listar();
        cout << endl;
        
        cout << "\nDigite codigo a borrar... ";
        cin >> dato;
        
        if(validar(dato))
        {
            borrar(dato);
            cout << "\nEl dato fue borrado con exito...\n";
        }
        else
        {
            cout << "\nDato no existe...\n";
            cout << "\nEl dato NO puede ser borrado...\n";
        }
        
        do{
            cout << "\nDesea borrar otro dato (s/n)... ";
            cin >> res;
        }while(res != 's' && res != 'S' && res != 'n' && res != 'N');
    }
}
    
void circular::borrar(string v)
{
  struct nodo *p = prim;
  if(prim->codigo == v)
  {
    prim = prim->sig;
    p->ant->sig = prim;
    prim->ant = p->ant;
    delete(p);
  }
  else
  {
    while(p->codigo != v)
      p = p->sig;
      p->ant->sig = p->sig;
      p->sig->ant = p->ant;
      delete(p);
    }
}
    
int circular::validar(string v)
{
  struct nodo *p = prim;
  if(p == NULL) return 0;
  if(p->sig == NULL)
  {
    if(p->codigo == v)
      return 1;
    return 0;
  }
  while(p->sig != prim  && p->codigo != v)
    p = p->sig;
  if(p->sig == prim && p->codigo != v)
    return 0;
  return 1;
}
    
void circular::listar() const
{
  struct nodo *p = prim;
  cout << "\n(";
  while(p->sig != prim)
  {
    cout << p->codigo << ", ";
    p = p->sig;
  }
  cout << p->codigo << ")" << "\n";
}