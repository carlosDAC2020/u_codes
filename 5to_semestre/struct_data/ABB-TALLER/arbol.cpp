#include "arbol.h"

string profeciones[10]={"Industrial","Eléctrica","Electrónica","Mecánica","Mecatrónica","Química","Biomédica","Ambiental","Civil","Sistemas"};


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
  nuevoNodo->edad=2021-fn[2];
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

void arbol::imprimir_egresado(ABB raizABB){
    cout << "Nombre: " << raizABB->Nombre << endl;
    cout << "Apellido: " << raizABB->Apellido << endl;
    cout << "Telefono: " << raizABB->NoMovil << endl;
    cout << "Profesion: ingenieria "<<profeciones[raizABB->profesion-1]; 
    cout << "Fecha de nacimiento: " << raizABB->fch_nacimiento[0] << "," << raizABB->fch_nacimiento[1] << "," << raizABB->fch_nacimiento[2] << endl;
    cout << "Ciudad: " << raizABB->city_residencia << endl;
}

void arbol::buscar_por_ciudad(ABB arbolabb, string city){
  
  if (arbolabb!=NULL)
  {
    buscar_por_ciudad(arbolabb->izq, city );
    if (arbolabb->city_residencia==city)
    {
      cout<<"\n----------------------\n";
      imprimir_egresado(arbolabb);
    }
  }
 
}

void arbol::buscar_por_profesion(ABB arbolabb, int prof){
  if (arbolabb!=NULL)
  {
    buscar_por_profesion(arbolabb->izq, prof );
    if (arbolabb->profesion==prof)
    {
      cout<<"\n----------------------\n";
      imprimir_egresado(arbolabb);
    }
  }
}

void arbol::buscar_por_rango_edad(ABB arbolabb, int li, int ls){
  if (arbolabb!=NULL)
  {
    buscar_por_rango_edad(arbolabb->izq, li, ls );
    if (arbolabb->edad>=li && arbolabb->edad<=ls)
    {
      cout<<"\n----------------------\n";
      imprimir_egresado(arbolabb);
    }
  }
}

void arbol::buscar_egresados(ABB raizABB, int op){
  string city;
  int cedulaBus, prof, li, ls;

  cout<<"\n\n  BUSQUEDA DE EGRESADOS  \n";
  switch (op)
  {
    // buscar por cedula
  case 1:
    cout<<"cc a buscar:";cin>>cedulaBus;
    bool val;
    val = validar(raizABB, cedulaBus);
    cout << "\n Datos del egresado" << endl;
    if(val == 0){
      cout << "La cedula ingreada no tiene datos guardados" << endl;
    }
    else{
      cout<<"\n----------------------\n";
      imprimir_egresado(raizABB);
    }
    break;

    // buscar pro profecion 
  case 2:
    do
    {
      cout << "\n ingeneria de profecion  \n";
      cout<<" 1 -> Industrial \n";
      cout<<" 2 -> Eléctrica \n";
      cout<<" 3 -> Electrónica \n";
      cout<<" 4 -> Mecánica \n";
      cout<<" 5 -> Mecatrónica \n";
      cout<<" 6 -> Química \n";
      cout<<" 7 -> Biomédica \n";
      cout<<" 8 -> Ambiental \n";
      cout<<" 9 -> Civil \n";
      cout<<" 10 -> Sistemas \n";
      cout<<" ingrese su opcion aqui -->";cin>>prof;
      if (prof<1 || prof>10)
      {
        cout<<" ingrese solo los valores señalados !! \n";
      }
    } while (prof<1 || prof>10);
    cout<<"\n egresados de  ingenieria selescioanda \n ";
    buscar_por_profesion(raizABB, prof);
    break;

    // buscar por ciudad 
  case 3:
    cout<<" Cuidad a buscar:";cin>>city;
    cout<<" egresados de la ciudad "<<city<<endl;
    buscar_por_ciudad(raizABB, city);
    break;

    // buscar por rango de edad 
  case 4:
    cout<<" ingresa un rango de edad \n";
    cout<<" edad minima:";cin>>li;
    cout<<" edad maxima:";cin>>ls;
    cout<<" \n egresados entre "<<li<<" y "<<ls<<" años \n";
    buscar_por_rango_edad(raizABB, li, ls);
    break;
  default:
    break;
  }
  
}