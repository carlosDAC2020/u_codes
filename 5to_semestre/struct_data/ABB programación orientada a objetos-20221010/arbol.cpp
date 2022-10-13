#include "arbol.h"

arbol::arbol()
{
  raiz = NULL;
}

ABB arbol::getraiz()
{
  return raiz;
}

ABB arbol::crearNodo(int x)
{
  ABB nuevoNodo = new(struct nodo);
  nuevoNodo->nro = x;
  nuevoNodo->izq = NULL;
  nuevoNodo->der = NULL;
  return nuevoNodo;
}

void arbol::insertar(ABB &arbolabb, int x)
{
  if(arbolabb == NULL)
  {
    arbolabb = crearNodo(x);
    cout<<"\n\t  Insertado..!"<<endl<<endl;
  }
  else if(x < arbolabb->nro)
    insertar(arbolabb->izq, x);
  else if(x > arbolabb->nro)
    insertar(arbolabb->der, x);
}

void arbol::preOrden(ABB arbolabb)
{
  if(arbolabb != NULL)
  {
    cout << arbolabb->nro <<" ";
    preOrden(arbolabb->izq);
    preOrden(arbolabb->der);
  }
}

void arbol::enOrden(ABB arbolabb)
{
  if(arbolabb != NULL)
  {
    enOrden(arbolabb->izq);
    cout << arbolabb->nro << " ";
    enOrden(arbolabb->der);
  }
}

void arbol::postOrden(ABB arbolabb)
{
  if(arbolabb != NULL)
  {
    postOrden(arbolabb->izq);
    postOrden(arbolabb->der);
    cout << arbolabb->nro << " ";
  }
}

bool arbol::busquedaRec(ABB arbolabb, int dato)
{
  int r=0;   // 0 indica que lo encontre
  if(arbolabb == NULL)
    return r;
  if(dato<arbolabb->nro)
    r = busquedaRec(arbolabb->izq, dato);
  else 
    if(dato > arbolabb->nro)
      r = busquedaRec(arbolabb->der, dato);
    else
      r = 1;   // son iguales, lo encontre
  return r;
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
  if(x < arbolabb->nro)
    elimina(arbolabb->izq, x);
  else 
    if(x > arbolabb->nro)
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
  if(dato < arbolabb->nro)
    r = validar(arbolabb->izq, dato);
  else 
    if(dato > arbolabb->nro)
      r = validar(arbolabb->der, dato);
    else
      r = 1;   // son iguales, lo encontre
  return r;
}
