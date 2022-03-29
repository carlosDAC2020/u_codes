#include "operario.h"

// metodos de la clase 
operario::operario(int d)
{
  nombre = " ";
  dias = (d < 8 or d > 30 ? 8 : d);
  cargo = 0;
  horas = new long[dias];
  for(int i = 0; i < dias; i++)
    horas[i] = 0;
}

operario::~operario()
{
  delete []horas;
}

const operario &operario::operator=(const operario &derecha)
{
	if (&derecha != this){ //verifica la autoasignacion
        nombre = derecha.nombre;
        dias = derecha.dias;
        cargo = derecha.cargo;
        delete []horas;
        horas = new long[dias];
        for (int i = 0 ; i < dias ; i++)
            horas[i] = derecha.horas[i];
	}
	return *this; //Por ejemplo, habilita X = Y = Z
}

float operario::promedio() const
{
  float pro, aux = 0.0;
  for(int i = 0; i < dias; i++)
    aux += (float)horas[i];
  pro = aux / (float)dias;
  return pro;
}

long operario::base() const
{
  long bas = 0, aux;
  if(promedio() > 4.0)
  {
    for(int i = 0; i < dias; i++)
      if(horas[i] > 4)
      {
        aux = horas[i] - 4;
        bas += aux;
      }
  }
  return bas;
}

long operario::bonificacion() const
{
  long bono;
  switch(cargo)
  {
    case 1:
      bono = base() * (OS * 0.7);
      break;
    case 2:
      bono = base() * (OP * 0.5);
      break;
    case 3:
      bono = base() * (OE * 0.3);
      break;
  }
  return bono; 
}

long operario::extras() const
{
  long ext = 0;
  for(int i = 0; i < dias; i++)
    ext += horas[i];
  return ext;
}

long operario::neto() const
{
  long net;
  switch(cargo)
  {
    case 1:
      net = (dias * 8 * OS) + (extras() * (OS * 1.3)) + bonificacion();
      break;
    case 2:
      net = (dias * 8 * OP) + (extras() * (OP * 1.5)) + bonificacion();
      break;
    case 3:
      net = (dias * 8 * OE) + (extras() * (OE * 1.7)) + bonificacion();
      break;
  }
  return net;
}


// metoddos amigos
istream &operator>>(istream &cin, operario &a)
{
  cout << "Nombre: "; cin >> a.nombre;
  cout << "Tipo empleado (1 supervisor)(2 planta)(3 especializado): ";
  do{
    cin >> a.cargo;
    if(a.cargo < 1 || a.cargo > 3 )
      cout << "\nDebe ser (1 o 2 o 3)\n";
  }
  while(a.cargo < 1 || a.cargo > 3);

  cout << "\nHoras extras por dia (1 - 8).\n";
  // funciones para obtener numeros aleatorios
    srand(time(NULL));
  for (int i = 0 ; i < a.dias ; i++){
    // asignamos un numero aleatorio al valor
    a.horas[i]=1 + rand() % (9-1);
    cout << "\nDia[" << i+1 << "] = "<<a.horas[i];
  }
  return cin; 
}

ostream &operator<<(ostream &cout, const operario &a)
{
  int i;
  cout << "\nNombre: "<< a.nombre; 
  cout  << " dias: "<< a.dias; 
  cout<< "\nHoras extras en cada uno de los dias...\n";
  for (  i = 0 ; i < a.dias ; i++)
  {
    cout << "[" << i+1 << "]= " << a.horas[i];
    cout << endl;
  }
  cout << "\nTipo de empleado: ";
  switch(a.cargo)
  {
    case 1:
      cout << "supervisor.";
      break;
    case 2:
      cout << "planta.";
      break;
    case 3:
      cout << "especializado.";
      break;  
  }
  cout <<"\n valor neto a pagar :"<<a.neto()<<endl;
  cout << "___________________________________\n";
  return cout;
}

void obtenerDatos (int ne, int nd, vector<operario> &a)
{
  operario s(nd);
  for(int i = 0; i < ne; i++)
  {
      cout<<" operario "<<i+1<<endl;
      cin >> s;
      a[i] = s;
      cout<<endl;
  } 
}

void imprimirOperarios (int ne, const vector<operario> &a)
{
    for(int i = 0; i < ne; i++){
        cout<<" operario "<<i+1<<endl;
        cout << a[i];
    }
}


long bonificacionTotal(int ne, vector<operario> &a){
  long boni_total=0;
     for(int i = 0; i < ne; i++){
        boni_total+=a[i].bonificacion();
    }
    return boni_total;
}

long nominaTotal(int ne, vector<operario> &a){
  long nomi_total=0;
     for(int i = 0; i < ne; i++){
        nomi_total+=a[i].neto();
    }
    return nomi_total;
}