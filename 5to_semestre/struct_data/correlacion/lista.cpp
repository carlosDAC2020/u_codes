
#include "lista.h"

lista::lista(){
  prim = ultm = NULL;
}

void lista::pedirDatos() {
  string cod;
  float est;
  float pes;
  int dato;
  char res = 's';
  while (res == 's' || res == 'S') {
    cout << "\n\nDigite codigo del jugador: ";
    cin >> cod;
    if (validar(cod) == 0) {
      do{
        cout << "Estatura: ";
        cin >> est;
      }while(est < 0.0);
      do{
        cout << "Peso: ";
        cin >> pes;
      }while(pes < 0.0);
      entrarDatos(cod,est,pes);
      cout << "\n\tJugador guardado con exito\n";
    } else
      cout << "\n\tJugador ya existente, no se guardo\n";
    do {
        cout << "\n\nDesea entrar otro dato (s/n): ";
        cin>>res;
    } while(res != 's' && res != 'S' && res != 'n' && res != 'N');
  }
}

void lista::entrarDatos(string v, float est, float pes) {
  nuevo = (struct nodo *) new (struct nodo);
  nuevo->codigo = v;
  nuevo->estatura = est;
  nuevo->peso = pes;
  nuevo->sig = NULL;
  if(prim == NULL)
    prim = nuevo;
  else
    ultm->sig = nuevo;
  ultm = nuevo;
}

int lista::validar(string v) {
  struct nodo *p = prim;
  while(p != NULL and p->codigo != v)
    p = p->sig;
  if(p == NULL) return 0;
  return 1;
}

void lista::borrarDatos(string v) {
  struct nodo *p = prim;
  if(prim->codigo == v){
    prim = prim->sig;
    delete(p);
  }
  else{
    struct nodo *q = prim->sig;
    while(q->codigo != v){
      p = p->sig;
      q = q->sig;
    }
    if(ultm == q){
      ultm = p;
      ultm->sig = NULL;
      delete(q);
    }
    else{
      p->sig = q->sig;
      delete(q);
    }
  }
}

void lista::quitarDatos(){
  string cod;
  char res = 's';
  while (res == 's' || res == 'S') {
    cout << "\n\nDigite codigo del jugador a borrar: ";
    cin>>cod;
    if (validar(cod) == 1) {
      borrarDatos(cod);
      cout << "\n\tDato borrado con exito\n";
    } else
      cout << "\n\tEl dato no existe\n";
    do {
        cout << "\n\nDesea borrar otro dato (s/n): ";
        cin>>res;
    } while(res != 's' && res != 'S' && res != 'n' && res != 'N');
  }
}

void lista::imprimir() {
  struct nodo *p = prim;
  cout << "Listado de jugadores, codigo, estatura, peso: \n\n";
  while(p != NULL)
  {
    cout << p->codigo << "   "<< p->estatura << "   "<< p->peso << "\n";
    p = p->sig;
  }
  cout << "\n";
}

void lista::correlacion(){
  struct nodo *p = prim;
  int n = 0;
  float sumaX = 0.0, sumaY = 0.0, sumaXY = 0.0, sumaX2 = 0.0, sumaY2 = 0.0;
  float mediaX, mediaY, desvX, desvY, covarianza, r;

  while(p != NULL){
    sumaX += p->estatura;
    sumaY += p->peso;
    sumaXY += (p->estatura)*(p->peso);
    sumaX2 += pow(p->estatura,2.0);
    sumaY2 += pow(p->peso,2.0);
    p = p->sig;
    n++;
  }
  mediaX = sumaX / (float)n;
  mediaY = sumaY / (float)n;
  desvX = sqrt((sumaX2 / (float)n) - pow(mediaX,2.0));
  desvY = sqrt((sumaY2 / (float)n) - pow(mediaY,2.0));
  covarianza = desvX = (sumaXY / (float)n) - (mediaX * mediaY);
  // hallamos la correlacion
  r = covarianza / (desvX * desvY);


// imprecion de los datos 
  cout<<"\n     Resultados ";
  cout<<"\n sumatoria de estaturas :"<<sumaX;
  cout<<"\n sumatoria de pesos :"<<sumaY;
  cout<<"\n promedio de estaturas :"<<mediaX;
  cout<<"\n promedio de pesos :"<<mediaY;
  cout<<"\n Covarianza :"<<covarianza;
  cout<<"\n desviacionn de estaturas :"<<desvX;
  cout<<"\n desviacion de pesos :"<<desvY;

  cout << "La correlacion es: " << r;
  cout<<"\n fuerza de relacion:";
   if((r<=-1.0 && r<=-0.5)||(r>=0.5 && r<=1.0)){
        cout<<" FUERTE \n";
    }
    else if((r>=-0.5 && r<=-0.3)||(r>=0.3 && r<=0.5)){
        cout<<"  MODERADA \n";
    }
    else if((r>=-0.3 && r<=-0.1)||(r>=0.1 && r<=0.3)){
        cout<<"  DEBIL \n";
    }
    else if(r>-0.1 && r<0.1){
        cout<<"  NINGUNA \n";
    }

    cout << "\n\n"; 
}