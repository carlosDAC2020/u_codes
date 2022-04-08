#include "empleado.h"


empleado::empleado(string ced, string nom, string apell, int fn[], long bas)
{
  ponCedula(ced);
  ponNombre(nom);
  ponApellido(apell);
  ponFechaNac(fn);
  salarioBasico(bas); 
}
empleado::~empleado()
{ }

void empleado::ponCedula(string ced)
{
  cedula = ced;
}

void empleado::ponNombre(string nom)
{
  nombre = nom;
}

void empleado::ponApellido(string apell)
{
  apellido = apell;
}

void empleado::ponFechaNac(int fn[])
{
  validarFecha(fn);
  cout << fn[0] << "/" << mess[fn[1]] << "/" << fn[2];
}

void empleado::salarioBasico(long bas)
{
  basico = (bas < 0 ? 0 : bas);
}

void empleado::imprimir() const
{
  cout<<"       datos del empleado \n";
  cout<<" Documento:"<< cedula <<endl;
  cout<<" Nombre:"<<nombre<<endl;
  cout<<" Apellido:"<<apellido<<endl;
  cout<<" Fecha de nacimiento:"<< fechaN[0] << "/" << mess[fechaN[1]] << "/" << fechaN[2]<<endl;
  cout<<" Sueldo basico:"<<basico<<"$"<<endl;
}

long empleado::neto() const
{
  return 0,0;
}

istream &operator>>(istream &cin, empleado &a)
{
  cout<<"       ingreso de datos del empleado \n";
  cout<<" # Cedula:";cin>>a.cedula;
  cout<<" # Nombre:";cin>>a.nombre;
  cout<<" # Apellido:";cin>>a.apellido;

  cout<<"     # FECHA DE NACIMIENTO \n";
  int res;
  do{
    cout<<" dia:";cin>>a.fechaN[0];
    cout<<" mes:";cin>>a.fechaN[1];
    cout<<" anio:";cin>>a.fechaN[2];
    validarFecha(a.fechaN);
    cout<<a.fechaN[0] << "/" << mess[a.fechaN[1]] << "/" << a.fechaN[2]<<endl;
    cout<<" esta de acuerdo con la fecha ingresada?\n 1=si \n 2=no\n ingrse su opcion:";cin>>res;
  } 
  while (res!=1);
  
  do{
    cout<<" # Salario Basico:";cin>>a.basico;
    if (a.basico<0){
      cout<<" ingresaste un salario no valid!! \n";
    }
  } 
  while (a.basico<0);
  
  
  return cin;
}

ostream &operator<<(ostream &cout, const empleado &a){
  cout<<"       datos del empleado \n";
  cout<<" Documento:"<< a.cedula <<endl;
  cout<<" Nombre:"<<a.nombre<<endl;
  cout<<" Apellido:"<<a.apellido<<endl;
  cout<<" Fecha de nacimiento:"<< a.fechaN[0] << "/" << mess[a.fechaN[1]] << "/" << a.fechaN[2]<<endl;
  cout<<" Sueldo basico:"<<a.basico<<"$"<<endl;

  return cout;
}

void validarFecha(int F[])
{
  F[1] = (F[1] >= 1 && F[1] <= 12)? F[1] : 1;
  F[2] = (F[2] >= Aini && F[2] <= Afin)? F[2] : Aini;
  if((F[1] == 2) and (anioBisiesto(F[2]) == true))
    F[0] = (F[0] >= 1 && F[0] <= 29)? F[0] : 1;
  else
    F[0] = (F[0] >= 1 && F[0] <= dias[F[1]])? F[0] : 1;
}

int anioBisiesto(int verificaAnio)
{
  if(verificaAnio % 400 == (verificaAnio % 100 != 0 && verificaAnio % 4 == 0))
    return 1;
  else
    return 0;
}
  