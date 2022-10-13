#include "lista.h"

lista::lista() {
  primV = ultmV = NULL;
  primR = ultmR = NULL;
}
  
void lista::pedirDatosVuelos()
{
  string cod, ciud;
  int cup;
  bool est;
  char res = 's';
  while (res == 's' || res == 'S') {
    cout << "\n\nDigite codigo del vuelo: ";
    cin >> cod;
    if (validarVuelos(cod) == 0) {
      cout << "\nCiudad destino = "; cin >> ciud;
      do{
        cout << "\nCupos = ";
        cin >> cup;
      }while(cup < 0);
      do{
        cout << "\nEstado del vuelo (1.Activo / 0.Cancelado) = ";
        cin >> est;
      }while(est != 1 and est != 0);
      entrarDatosVuelos(cod, ciud, cup, est);
      cout << "\n\tVuelo guardado con exito\n";
    } else
      cout << "\n\tVuelo existente no se guardo\n";
    do {
      cout << "\n\nDesea entrar otro vuelo (s/n): ";
      cin >> res;
    } while (res != 's' && res != 'S' && res != 'n' && res != 'N');
  }  
}

void lista::pedirDatosReservas()
{
  string ced, nom, coV;
  bool le;
  char res = 's';
  while (res == 's' || res == 'S') {
    cout << "\n\nDigite codigo del vuelo: ";
    cin >> coV;
    if (validarVuelos(coV) == 1) {
      cout << "\nCedula del viajero = "; cin >> ced;
      cout << "\nNombre = "; cin >> nom;
      struct nodoV *p = primV;
      while(p->codigo != coV) p = p->sigV;
      if(p->cupos > 0 and p->estado == 1) {
        p->cupos--;
        le = 0;
      }
      else
        le = 1;
      entrarDatosReservas(ced, nom, coV, le);
      cout << "\n\tDato guardado con exito\n";
      if(le == 0)
        cout << "\n\tVuelo reservado\n";
      else
        cout << "\n\tEn lista de espera\n";
    } else
      cout << "\n\tVuelo no existe, no se puede hacer reserva\n";
    do {
      cout << "\n\nDesea entrar otra reserva(s/n): ";
      cin >> res;
    } while (res != 's' && res != 'S' && res != 'n' && res != 'N');
  }  
}

void lista::entrarDatosVuelos(string v, string c, int cp, bool e) {
  nuevoV = (struct nodoV *) new (struct nodoV);
  nuevoV->codigo = v;
  nuevoV->ciudad = c;
  nuevoV->cupos = cp;
  nuevoV->estado = e;
  nuevoV->sigV = nuevoV->antV = NULL;
  if(primV == NULL)
    primV = nuevoV;
  else {
    ultmV->sigV = nuevoV;
    nuevoV->antV = ultmV;
  }
  ultmV = nuevoV;
}   

void lista::entrarDatosReservas(string c, string n, string cv, bool l) {
  nuevoR = (struct nodoR *) new (struct nodoR);
  nuevoR->cedula = c;
  nuevoR->nombre = n;
  nuevoR->codigoV = cv;
  nuevoR->lista = l;
  nuevoR->sigR = nuevoR->antR = NULL;
  if(primR == NULL)
    primR = nuevoR;
  else {
    ultmR->sigR = nuevoR;
    nuevoR->antR = ultmR;
  }
  ultmR = nuevoR;
}

void lista::modificarCuposVuelos()
{
  char ans;
  int ncup;
  string coV;
  cout << "\nCodigo vuelo = ";
  cin >> coV;
  if(validarVuelos(coV) == 1) {
    do{
      cout << "\n1.Quitar cupos\n2.Aumentar cupos\nEscoja = ";
      cin >> ans;
    }while(ans != '1' and ans != '2');
    do{
      cout << "\nCantidad de cupos = ";
      cin >> ncup;
    }while(ncup < 1);
    struct nodoV *p = primV;
    while(p->codigo != coV) p = p->sigV;
    if(ans == '1') {
      if(p->cupos >= ncup) p->cupos = p->cupos - ncup;
      else p->cupos = 0;
      if(p->estado == 1) {
        struct nodoR *q = ultmR;
        while(ncup != 0 and q != NULL) {
          if(q->codigoV == coV and q->lista == 0) {
            ncup--;
            q->lista = 1;
          }
          q = q->antR;
        }
      }
    }
    else {
      p->cupos = p->cupos + ncup;
      if(p->estado == 1) {
        struct nodoR *q = primR;
        while(q != NULL and p->cupos != 0){
          if(q->codigoV == coV and q->lista == 1){
            p->cupos--;
            q->lista = 0;
          }
          q = q->sigR;
        }
      }
    }
  }
  else {
    cout << "\n¡El codigo del vuelo no existe!\n";
  } 
}

void lista::modificarEstadoVuelo()
{
  string coV;
  char res;
  cout << "\nCodigo vuelo = ";
  cin >> coV;
  if(validarVuelos(coV) == 1) {
    struct nodoV *p = primV;
    while(p->codigo != coV) p = p->sigV;
    cout << "\nEl estado del vuelo es " << (p->estado == 1 ? "Activo " : "Cancelado ");
    do{
      cout << "\nDesea cambiar el estado (s/n) = ";
      cin >> res;
    }while(res != 's' and res != 'n');
    if(res == 's'){
      struct nodoR *q = primR;
      if(p->estado == 1) {
        p->estado = 0;
        while(q != NULL) {
          if(q->codigoV == coV and q->lista == 0) {
            p->cupos++;
            q->lista = 1;
          }
          q = q->sigR;
        } 
      }
      else {
        p->estado = 1;
        while(q != NULL and p->cupos != 0) {
          if(q->codigoV == coV and q->lista == 1) {
            p->cupos--;
            q->lista = 0;
          }
          q = q->sigR;
        } 
      }  
    } 
  } 
  else {
    cout << "\n¡El codigo del vuelo no existe!\n";
  } 
}

int lista::validarVuelos(string v) {
  struct nodoV *p = primV;
  while(p != NULL and p->codigo != v)
    p = p->sigV;
  if(p == NULL) return 0;
  return 1; 
}

void lista::imprimirReservas()
{
  struct nodoR *q = primR;
  struct nodoV *p = primV;
  cout << "\nLista de reservas de todos los vuelos\n\n";
  while(p != NULL) {
    cout << p->codigo << "  " << p->ciudad << "\n";
    q = primR;
    while(q != NULL) {
      if(p->codigo == q->codigoV) {
        cout << "\n" << q->cedula << " " << q->nombre << " ";
        cout << (q->lista == 0 ? "Vuelo reservado.\n" : "En lista de espera.\n");
      }
      q = q->sigR;
    }
    p = p->sigV;
  }
  cout << "\n\n";
}

void lista::imprimirListaEspera()
{
  struct nodoR *q = primR;
  struct nodoV *p = primV;
  cout << "\nLista de espera de todos los vuelos\n\n";
  while(p != NULL) {
    cout << "\n" << p->codigo << "  " << p->ciudad << "\n";
    q = primR;
    while(q != NULL) {
      if(p->codigo == q->codigoV and q->lista == 1) {
        cout << "\n" << q->cedula << " " << q->nombre;
      }
      q = q->sigR;
    }
    p = p->sigV;
  }
  cout << "\n\n";
}

