#include "administrativo.h"

administrativo::administrativo(string ced, string nom, string  apell, /*int  fn[]*/ long bas , int carg){
  ponCedula(ced);
  ponNombre(nom);
  ponApellido(apell);
  //ponFechaNac(fn);
  salarioBasico(bas); 
  PonCargo(carg);
}
administrativo::~administrativo(){

}


void administrativo::PonCargo (int carg){
    cargo=carg;
}

long administrativo::boni_cargo() const{
    long boni;
    switch (cargo){
    case 1:
        boni= 0.3*basico;
        break;
    case 2:
        boni= 0.2*basico;
        break;
    case 3:
        boni= 0.1*basico;
        break;
    default:
        cout<<"error";
        break;
    }
    return boni;
}

void administrativo::imprimir() const{
    empleado::imprimir();
    cout<<" cargo:";
    switch (cargo)
    {
    case 1:
        cout<<"Administrativo \n";
        break;
    case 2:
        cout<<"Jefe \n";
        break;
    case 3:
        cout<<"Auxiliar \n";
        break;
    }
}

long administrativo::neto() const{
    return (basico+boni_cargo())*0.89;
}

istream &operator>>(istream &cin, administrativo &a){
    cout<<"\n       ingreso de datos del empleado \n";
    cout<<" # Cedula:";cin>>a.cedula;
    cout<<" # Nombre:";cin>>a.nombre;
    cout<<" # Apellido:";cin>>a.apellido;

    /*
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
    */
    do{
        cout<<" # Salario Basico:";cin>>a.basico;
        if (a.basico<0){
        cout<<" ingresaste un salario no valid!! \n";
        }
    } 
    while (a.basico<0);

    cout<<"\n     # CARGO \n ";
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

    return cin;
}

ostream &operator<<(ostream &cout, const administrativo &a){
    cout<<"       datos del empleado \n";
    cout<<" Documento:"<< a.cedula <<endl;
    cout<<" Nombre:"<<a.nombre<<endl;
    cout<<" Apellido:"<<a.apellido<<endl;
    //cout<<" Fecha de nacimiento:"<< a.fechaN[0] << "/" << mess[a.fechaN[1]] << "/" << a.fechaN[2]<<endl;
    cout<<" Sueldo basico:"<<a.basico<<"$"<<endl;
    cout<<" cargo:";
    switch (a.cargo)
    {
    case 1:
        cout<<"Administrativo \n";
        break;
    case 2:
        cout<<"Jefe \n";
        break;
    case 3:
        cout<<"Auxiliar \n";
        break;
    }

    return cout;
}

void imprimir_lista_administrativo (int cant, vector<administrativo> &a){
    for (int i = 0; i < cant; i++){
        cout<<"\n empleado administrativo # "<<i+1<<endl;
        cout<<a[i];
        cout<<"\n----------------------------------------------";
    }
}

long nomina_total_administrativos (int cant, vector<administrativo> &a){
    long total=0;
    for (int i = 0; i < cant; i++){
        total+=a[i].neto();
    }
    return total;
}