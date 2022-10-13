#include "arbol.h"

arbol::arbol()
{
  raiz = NULL;
}

ABB arbol::getraiz()
{
  return raiz;
}

ABB arbol::crearNodo(int cc, string name, string apll, int cel, int prof, int fn[], string city)
{
  ABB nuevoNodo = new(struct nodo);
  nuevoNodo->cedula = cc;
  nuevoNodo->Nombre = name;
  nuevoNodo->Apellido = apll;
  nuevoNodo->NoMovil = cel;
  nuevoNodo->profesion = prof;
  nuevoNodo->fch_nacimiento[0] = fn[0];
  nuevoNodo->fch_nacimiento[1] = fn[1];
  nuevoNodo->fch_nacimiento[2] = fn[2];
  nuevoNodo->city_residencia = city;
  nuevoNodo->izq = NULL;
  nuevoNodo->der = NULL;
  return nuevoNodo;
}

void arbol::insertar(ABB &arbolabb, int cc, string name, string apll, int cel, int prof, int fn[], string city)
{
  if(arbolabb == NULL)
  {
    arbolabb = crearNodo(cc, name, apll, cel,  prof, fn, city);
    cout<<"\n\t  Insertado..!"<<endl<<endl;
  }
  else if(cc < arbolabb->cedula)
    insertar(arbolabb->izq, cc, name, apll, cel,  prof, fn, city);
  else if(cc > arbolabb->cedula)
    insertar(arbolabb->der, cc, name, apll, cel,  prof, fn, city);
}

void arbol::preOrden(ABB arbolabb)
{
  if(arbolabb != NULL)
  {
    cout << arbolabb->cedula <<" ";
    preOrden(arbolabb->izq);
    preOrden(arbolabb->der);
  }
}

void arbol::enOrden(ABB arbolabb)
{
  cout<<"\negresados\n";
  if(arbolabb != NULL)
  {
    enOrden(arbolabb->izq);
    cout << arbolabb->cedula << " ";
    enOrden(arbolabb->der);
  }
}

void arbol::postOrden(ABB arbolabb)
{
  if(arbolabb != NULL)
  {
    postOrden(arbolabb->izq);
    postOrden(arbolabb->der);
    cout << arbolabb->cedula << " ";
  }
}

ABB arbol::busquedaRec(ABB arbolabb, int cc)
{
  
  if(arbolabb == NULL){
    return arbolabb;
  }
  else if(cc == arbolabb->cedula){
    return arbolabb;
  }
  else if(cc < arbolabb->cedula){
    return busquedaRec(arbolabb->izq,cc);
  }
  else{
    return busquedaRec(arbolabb->der,cc);
  }
}

ABB arbol::unirABB(ABB izq, ABB der)
{
    if(izq==NULL) return der;
    if(der==NULL) return izq;
    ABB centro = unirABB(izq->der, der->izq);
    izq->der = centro;
    der->izq = izq;
    return der;
}

void arbol::elimina(ABB &arbolabb, int x)
{
  if(arbolabb == NULL) return;
  if(x < arbolabb->cedula)
    elimina(arbolabb->izq, x);
  else 
    if(x > arbolabb->cedula)
      elimina(arbolabb->der, x);
    else
    {
      ABB p = arbolabb;
      arbolabb = unirABB(arbolabb->izq, arbolabb->der);
      delete p;
    }
}

bool arbol::validar(ABB &arbolabb, int dato)
{
  int r = 0;   // 0 indica que no lo encontre
  if(arbolabb == NULL)
    return r;
  if(dato < arbolabb->cedula)
    r = validar(arbolabb->izq, dato);
  else 
    if(dato > arbolabb->cedula)
      r = validar(arbolabb->der, dato);
    else
      r = 1;   // son iguales, lo encontre
  return r;
}


void arbol::buscar_egresados(ABB raizABB){
  int cedulaBus;
  cout<<"\n\n  BUSQUEDA DE EGRESADOS \n";
  cout<<"cc a buscar:";cin>>cedulaBus;
  bool egresado;
  egresado = validar(raizABB, cedulaBus);
  if(egresado == 0){
    cout << "La cedula ingreada no tiene datos guardados" << endl;
  }
  else{
    cout << "Nombre: " << raizABB->Nombre << endl;
    cout << "Apellido: " << raizABB->Apellido << endl;
    cout << "Telefono: " << raizABB->NoMovil << endl;
    cout << "Profesion: " << raizABB->profesion << endl;
    cout << "Fecha de nacimiento: " << raizABB->fch_nacimiento[0] << "," << raizABB->fch_nacimiento[1] << "," << raizABB->fch_nacimiento[2] << endl;
    cout << "Ciudad: " << raizABB->city_residencia << endl;
  }
}