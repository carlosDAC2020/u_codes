#include "academico.h"


void academico::PonNiveldeEstudio (int nv_e){
    nivel_estudio=nv_e;
}

void academico::PonPuntajeInvestigacion (int ptj_inv){
    puntaje_investigacion=ptj_inv;
}


long academico::boni_nivel_estudio() const{

    switch (nivel_estudio){
        case 1: // tencio o tecnologo
            return 0.05*basico;
            break;
        case 2: // profecional
            return 0.08*basico;
            break;
        case 3: // especialista 
            return 0.10*basico;
            break;
        case 4: // magister
            return 0.20*basico;
            break;
        case 5: // doctor
            return 0,30*basico;
            break;
        default:
            cout<<"error\n ";
            break;
    }     
        
}

long academico::boni_puntaje_investigacion() const{

    if (puntaje_investigacion>0 && puntaje_investigacion<=10){ // no categorizado investigador 
        return puntaje_investigacion*(0.01*basico);
    }
    
    else if (puntaje_investigacion>10 && puntaje_investigacion<=100){ // investigador junior 
        return puntaje_investigacion*(0.03*basico);
    }
    
    else if(puntaje_investigacion>100 && puntaje_investigacion<=500){ // investigador asociado 
        return puntaje_investigacion*(0.05*basico);
    }
    else{                                              // investigador senior
        return puntaje_investigacion*(0.08*basico);
    }
}

void academico::imprimir() const{
    empleado::imprimir();
    cout<<"nivel de estudios:"<<nivel_estudio<<endl;
    cout<<"puntaje de investigacion:"<<puntaje_investigacion<<endl;
}

long academico::neto() const{
    return (basico+boni_nivel_estudio()+boni_puntaje_investigacion())*0.89;
}

istream &operator>>(istream &cin, academico &a){
    cout<<" ingrese los datos del empleado academico \n";
    cout<<" # Cedula:";cin>>a.cedula;
    cout<<" # Nombre:";cin>>a.nombre;
    cout<<" # Apellido:";cin>>a.apellido;
    cout<<" # Salario Basico:";cin>>a.basico;
    cout<<"     # FECHA DE NACIMIENTO \n";
    cout<<" dia:";cin>>a.fechaN[0];
    cout<<" mes:";cin>>a.fechaN[1];
    cout<<" anio:";cin>>a.fechaN[2];
    cout<<"     # nivel de estudio \n ";
    cout<<"1 -> Técnico o Tecnológico \n";
    cout<<"2 -> Profesional \n";
    cout<<"3 -> Especialista \n";
    cout<<"4 -> Magíster \n";
    cout<<"5 -> Doctor \n";
    do
    {
        cout<<" ingrese el nivel de estudio:";cin>>a.nivel_estudio;
        if(a.nivel_estudio<1 || a.nivel_estudio>5){
            cout<<" nivel ingresado no valido debe ser de 1 a 5 !!\n ";
        }
    } 
    while (a.nivel_estudio<1 || a.nivel_estudio>5);
    
    cout<<" # puntaje de investigacion:";cin>>a.puntaje_investigacion;
}