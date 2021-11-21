#include <iostream>
using namespace std;


int main(){
    // declaramos variables 
    string nombre, sexo, codigo;
    int  edad;

    // ingreso de datos
    cout<<"\n ingreso de datos de los estudiantes\n";
    cout<<" nombre:";cin>>nombre;
    cout<<" edad:";cin>>edad;
    cout<<" sexo (f / m):";cin>>sexo;
    cout<<" codigo:";cin>>codigo;
    // procedimiento
    if(edad>=18){
        if(sexo=="f" || sexo=="F"){
            cout<<"\n la estudiante "<<nombre<<" es mayor de edas y su codigo de estudiante es "<<codigo;
        }
        else{
            cout<<"\n el estudiante "<<nombre<<" es mayor de edas y su codigo de estudiante es "<<codigo;
        }
    }
    else{
        if(sexo=="f" || sexo=="F"){
            cout<<"\n la estudiante "<<nombre<<" es menor de edas y su codigo de estudiante es "<<codigo;
        }
        else{
            cout<<"\n el estudiante "<<nombre<<" es menor de edas y su codigo de estudiante es "<<codigo;
        }
    }
    return 0;
}
