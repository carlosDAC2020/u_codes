#include "academico.h"
academico::academico(string ced, string nom, string apell, /*int fn[]*/ long basic , int nve, int ptji){
  ponCedula(ced);
  ponNombre(nom);
  ponApellido(apell);
  //ponFechaNac(fn);
  salarioBasico(basic); 
  PonNiveldeEstudio(nve);
  PonPuntajeInvestigacion(ptji);
}

academico::~academico(){

}

void academico::PonNiveldeEstudio (int nv_e){
    nivel_estudio=nv_e;
}

void academico::PonPuntajeInvestigacion (int ptj_inv){
    puntaje_investigacion=ptj_inv;
}


long academico::boni_nivel_estudio() const{

    long boni;
    switch (nivel_estudio){
        case 1: // tencio o tecnologo
            boni= 0.05*basico;
            break;
        case 2: // profecional
            boni= 0.08*basico;
            break;
        case 3: // especialista 
            boni= 0.10*basico;
            break;
        case 4: // magister
            boni= 0.20*basico;
            break;
        case 5: // doctor
            boni= 0,30*basico;
            break;
        default:
            cout<<"error\n ";
            break;
    }     
    return boni;
}

long academico::boni_puntaje_investigacion() const{

    long boni;
    if (puntaje_investigacion>0 && puntaje_investigacion<=10){ // no categorizado investigador 
        boni= puntaje_investigacion*(0.01*basico);
    }
    
    else if (puntaje_investigacion>10 && puntaje_investigacion<=100){ // investigador junior 
        boni= puntaje_investigacion*(0.03*basico);
    }
    
    else if(puntaje_investigacion>100 && puntaje_investigacion<=500){ // investigador asociado 
        boni= puntaje_investigacion*(0.05*basico);
    }
    else{                                              // investigador senior
        boni= puntaje_investigacion*(0.08*basico);
    }
    return boni;
}

void academico::imprimir() const{
    empleado::imprimir();
    cout<<"nivel de estudios:";
    switch (nivel_estudio)
    {
    case 1:
        cout<<" Técnico o Tecnológico \n";    
        break;
     case 2:
        cout<<" Profesional \n";
        break;
     case 3:
        cout<<" Especialista \n";
        break;
     case 4:
        cout<<" Magíster \n";
        break;
     case 5:
        cout<<" Doctor \n";
        break;
    
    }
    cout<<"puntaje de investigacion:"<<puntaje_investigacion<<endl;
}

long academico::neto() const{
    return (basico+boni_nivel_estudio()+boni_puntaje_investigacion())*0.89;
}

istream &operator>>(istream &cin, academico &a){
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

    cout<<"\n     # nivel de estudio \n ";
    cout<<"1 -> Técnico o Tecnológico \n";
    cout<<"2 -> Profesional \n";
    cout<<"3 -> Especialista \n";
    cout<<"4 -> Magíster \n";
    cout<<"5 -> Doctor \n";
    do{
        cout<<" ingrese el nivel de estudio:";cin>>a.nivel_estudio;
        if(a.nivel_estudio<1 || a.nivel_estudio>5){
            cout<<" nivel ingresado no valido debe ser de 1 a 5 !!\n ";
        }
    } 
    while (a.nivel_estudio<1 || a.nivel_estudio>5);
    
    do{
        cout<<" # puntaje de investigacion:";cin>>a.puntaje_investigacion;
        if (a.puntaje_investigacion<0){
            cout<<" puntaje ingresado no valido !!\n ";
        }
    } 
    while (a.puntaje_investigacion<0);
    
    return cin;
}

ostream &operator<<(ostream &cout, const academico &a){
    cout<<"       datos del empleado \n";
    cout<<" Documento:"<< a.cedula <<endl;
    cout<<" Nombre:"<<a.nombre<<endl;
    cout<<" Apellido:"<<a.apellido<<endl;
    //cout<<" Fecha de nacimiento:"<< a.fechaN[0] << "/" << mess[a.fechaN[1]] << "/" << a.fechaN[2]<<endl;
    cout<<" Sueldo basico:"<<a.basico<<"$"<<endl;
    cout<<"nivel de estudios:";
    switch (a.nivel_estudio)
    {
    case 1:
        cout<<" Técnico o Tecnológico \n";    
        break;
     case 2:
        cout<<" Profesional \n";
        break;
     case 3:
        cout<<" Especialista \n";
        break;
     case 4:
        cout<<" Magíster \n";
        break;
     case 5:
        cout<<" Doctor \n";
        break;
    
    }
    cout<<"puntaje de investigacion:"<<a.puntaje_investigacion<<endl;
    cout<<" neto a pagar:"<<a.neto()<<endl;
    return cout;
}

void imprimir_lista_academicos (int cant, vector<academico> &a){
    for (int i = 0; i < cant; i++){
        cout<<"\n empleado academico # "<<i+1<<endl;
        cout<<a[i];
        cout<<"\n----------------------------------------------";
    }
}

long nomina_total_academicos(int cant, vector<academico> &a){
    long total=0;
    for (int i = 0; i < cant; i++){
        total+=a[i].neto();
    }
    return total;
}