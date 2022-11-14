#include <iostream>

using namespace std;

struct fecha{
    int dia,mes,anio;
}nacimiento;

struct direccion{
    string departamento;
    char ciudad[50];
    string barrio;
}dir;

struct persona{
    char nombre[20];
    int id;
    int edad;
    struct direccion dir;
    struct fecha nacimiento;
}persona1;


int main() {

    // solicitamos los datos 
    cout<<"     Datos personales \n";
    cout<<"# Nombre:";cin>>persona1.nombre;
    cout<<"# Documento:";cin>>persona1.id;
    cout<<"# Direccion \n";
    cout<<" - Departamento:";cin>>persona1.dir.departamento;
    cout<<" - Ciudad:";cin>>persona1.dir.ciudad;
    cout<<" - Barrio:";cin>>persona1.dir.barrio;
    cout<<"# Fecha de Nacimiento \n";
    // solicitamos y validamos la fecha de nacimiento 
    do
    {
        cout<<" - Dia:";cin>>persona1.nacimiento.dia;
        cout<<" - Mes:";cin>>persona1.nacimiento.mes;
        cout<<" - Anio:";cin>>persona1.nacimiento.anio;
        if (persona1.nacimiento.dia<0 || persona1.nacimiento.dia>31 || persona1.nacimiento.mes<0 || persona1.nacimiento.mes>12 || persona1.nacimiento.anio<0 || persona1.nacimiento.anio>2022)
        {
            cout<<"\n ingresa una fehc avalida !! \n";
        }   
    } while (persona1.nacimiento.dia<0 || persona1.nacimiento.dia>31 || persona1.nacimiento.mes<0 || persona1.nacimiento.mes>12 || persona1.nacimiento.anio<0 || persona1.nacimiento.anio>2022);
    // obtenemos la edad
    persona1.edad=2022-persona1.nacimiento.anio;
    
    // imprimimos los datos obtenidos 
    cout<<"\n Datos obtenidos solicitados \n";
    cout<<" nombre:"<<persona1.nombre<<endl;
    cout<<" Documento:"<<persona1.id<<endl;
    cout<<" Direccion:"<<persona1.dir.departamento<<" - "<<persona1.dir.ciudad<<" - "<<persona1.dir.barrio<<" - "<<endl;
    cout<<" Fecha de Nacimiento:"<<persona1.nacimiento.dia<<" / "<<persona1.nacimiento.mes<<" / "<<persona1.nacimiento.anio<<" - "<<endl;
    cout<<" Edad:"<<persona1.edad<<endl;
    
    return 0;
}