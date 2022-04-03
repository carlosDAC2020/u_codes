#include "empleado.h"
string mess[] = {" ","Ene","Feb","Mar","Abr","May","Jun","Jul","Ago","Sep","Oct","Nov","Dic"};
int dias[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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
  cout<<" Sueldo basico:"<<basico<<endl;
}

long empleado::neto() const
{
  return 0,0;
}

istream &operator>>(istream &cin, empleado &a)
{
  
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
  