#include "servicios.h"

servicios::servicios(string ced, string nom, string apell, /*int fn[]*/ long bas, long he){
    ponCedula(ced);
    ponNombre(nom);
    ponApellido(apell);
    //ponFechaNac(fn);
    salarioBasico(bas); 
    PonHorasExtras(he);
}
servicios::~servicios(){

}

void servicios::PonHorasExtras (long ext){
    horas_extra=ext;
}

long servicios::baseHorasExtras() const{
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
   
   do{
        cout<<" # horas extras :";cin>>a.horas_extra;
        if (a.horas_extra<0){
        cout<<" ingresaste un salario no valid!! \n";
        }
    } 
    while (a.horas_extra<0);
    
}
ostream &operator<<(ostream &cout, const servicios &a){
    cout<<"       datos del empleado \n";
    cout<<" Documento:"<< a.cedula <<endl;
    cout<<" Nombre:"<<a.nombre<<endl;
    cout<<" Apellido:"<<a.apellido<<endl;
    //cout<<" Fecha de nacimiento:"<< a.fechaN[0] << "/" << mess[a.fechaN[1]] << "/" << a.fechaN[2]<<endl;
    cout<<" Sueldo basico:"<<a.basico<<"$"<<endl;
    cout<<" horas extras:"<<a.horas_extra<<endl;

    return cout;
}

void imprimir_lista_servicios (int cant, vector<servicios> &a){
    for (int i = 0; i < cant; i++){
        cout<<"\n empleado de servicios # "<<i+1<<endl;
        cout<<a[i];
        cout<<"\n----------------------------------------------";
    }
}

long nomina_total_servicios (int cant, vector<servicios> &a){
    long total=0;
    for (int i = 0; i < cant; i++){
        total+=a[i].neto();
    }
    return total;
}