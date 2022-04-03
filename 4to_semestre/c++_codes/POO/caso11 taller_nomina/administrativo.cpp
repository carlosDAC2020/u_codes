#include "administrativo.h"


void administrativo::PonCargo (int carg){
    cargo=carg;
}

long administrativo::boni_cargo() const{
    switch (cargo){
    case 1:
        return 0.3*basico;
        break;
    case 2:
        return 0.2*basico;
        break;
    case 3:
        return 0.1*basico;
        break;
    default:
        cout<<"error";
        break;
    }
}
void administrativo::imprimir() const{
    empleado::imprimir();
    cout<<" cargo:"<<cargo<<endl;
}
long administrativo::neto() const{
    return (basico+boni_cargo())*0.89;
}

istream &operator>>(istream &cin, administrativo &a){
    cout<<" ingrese los datos del empleado administrativo \n";
    cout<<" # Cedula:";cin>>a.cedula;
    cout<<" # Nombre:";cin>>a.nombre;
    cout<<" # Apellido:";cin>>a.apellido;
    cout<<" # Salario Basico:";cin>>a.basico;
    cout<<"     # FECHA DE NACIMIENTO \n";
    cout<<" dia:";cin>>a.fechaN[0];
    cout<<" mes:";cin>>a.fechaN[1];
    cout<<" anio:";cin>>a.fechaN[2];
    cout<<"     # CARGO \n ";
    cout<<"1 -> Administrativo \n";
    cout<<"2 -> Jefe \n";
    cout<<"3 -> Auxiliar \n";
    do
    {
        cout<<" ingrese el cargo:";cin>>a.cargo;
        if(a.cargo<1 || a.cargo>3){
            cout<<" cargo ingresado no valido debe ser de 1 a 3 !!\n ";
        }
    } 
    while (a.cargo<1 || a.cargo>5);
}