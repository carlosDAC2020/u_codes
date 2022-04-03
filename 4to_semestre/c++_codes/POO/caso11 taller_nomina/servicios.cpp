#include "servicios.h"

void servicios::PonHorasExtras (double hext){
    horas_extra=hext;
}

double servicios::baseHorasExtras(){
    return (basico/30/8)*1.20;
}

void servicios::imprimir() const{
    empleado::imprimir();
    cout<<" horas extras:"<<horas_extra<<endl;
}

long servicios::neto() const{
    return (basico + ( horas_extra * baseHorasExtras() ) ) * 0.89;
}

istream &operator>>(istream &cin, servicios &a){
    cout<<" ingrese los datos del empleado de servicios \n";
    cout<<" # Cedula:";cin>>a.cedula;
    cout<<" # Nombre:";cin>>a.nombre;
    cout<<" # Apellido:";cin>>a.apellido;
    cout<<" # Salario Basico:";cin>>a.basico;
    cout<<"     # FECHA DE NACIMIENTO \n";
    cout<<" dia:";cin>>a.fechaN[0];
    cout<<" mes:";cin>>a.fechaN[1];
    cout<<" anio:";cin>>a.fechaN[2];
    cout<<" # horas extras :";cin>>a.horas_extra;
}