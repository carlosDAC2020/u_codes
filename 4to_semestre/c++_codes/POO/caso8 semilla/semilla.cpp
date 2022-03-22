#include "semilla.h"

semilla::semilla (int d)
{
  Nombre = " ";
  Dias = ((d < 8) || (d > 30) ? 8 : d);
  Horas = new float[Dias];
  for (int i = 0 ; i < Dias ; i++)
    Horas[i] = 0;
}

semilla::~semilla()
{
  delete []Horas;
}

float semilla::Promedio()
{
  float sum = 0.0;
  float Prom;
  for(int i = 0 ; i < Dias ; i++)
  {
    sum = sum + Horas[i];
  }
  Prom = (sum / (float)Dias);
  return Prom;
}

void obtenerDatos(int est , vector <semilla> &s) //funcion friend
{
  for(int i = 0 ; i < est ; i++)
  {
    cout << "\nIngrese los datos de la Semilla " << i+1 << "\n";
    cin >> s[i];
  }
}

void imprimirDatos(int est , const vector <semilla> &s) //funcion friend
{
  for(int i = 0 ; i < est ; i++)
  {
    cout << "\nLos datos de la Semilla " << i+1 << "\n";
    cout << s[i];
  }
}

void PromMayor (int est, vector <semilla> &s) //funcion friend
{
  int aux = 0;
  float mayor ;
  mayor = s[0].Promedio();
  for(int i = 0 ; i < est ; i++)
  {
    if (mayor < s[i].Promedio())
    {
      mayor = s[i].Promedio();
      aux = i;
    }
  }
  cout << "\nEl Promedio mayor es de "; s[aux].imprimirNom();
  cout << " con un promedio de "<< mayor << " horas por dia\n\n";
}

void semilla::imprimirProm()
{
  cout << "\nEl Promedio de " << Nombre << " es de " << Promedio() << "\n";
}

void semilla::imprimirNom()
{
  cout << Nombre;
}

istream &operator>>(istream &entra, semilla &a) //clase amiga
{
  cout << "Nombre: "; entra >> a.Nombre;
  cout << "\nHoras por dia (1 - 8).\n";
  for (int i = 0 ; i < a.Dias ; i++)
  {
    cout << "\nDia[" << i+1 << "]... ";
    do{
      entra >> a.Horas[i];
    }while(a.Horas[i] < 1.0 || a.Horas[i] > 8.0);
  }
  return entra;
}

ostream &operator<<(ostream &salida, const semilla &a) //clase amiga
{
  int i;
  cout << "\nNombre: "; 
  salida << a.Nombre << " dias: "; 
  salida << a.Dias;
  cout<< "\nHoras Trabajadas en cada uno de los dias...\n";
  for (  i = 0 ; i < a.Dias ; i++)
  {
    salida << "[" << i+1 << "]= " << a.Horas[i];
    salida << endl;
  }
  salida << endl;
  cout << "___________________________________\n";
  return salida;
}
