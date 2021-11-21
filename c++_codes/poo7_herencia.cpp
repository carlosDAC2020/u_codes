// practica con herencia

# include <iostream>
# include <stdlib.h>
using namespace std;

// super clase o clase padre
class persona{
    private: // atributos
        string nombre;
        int edad;
    public: // metodos
        persona(string, int); // constructor
        void mostrar_persona();
};

// sub clase o clase hija
class alumno:public persona{
    private: // atributos
        string codigo;
        float nota;
    public: // metodos
        alumno(string, int, string, float);
        void mostrar_alumno();
};

// constructores
persona::persona(string _nombre, int _edad){ // clase padre
    nombre = _nombre;
    edad = _edad;
}
alumno::alumno(string _nombre, int _edad, string _codigo, float _nota):persona(_nombre, _edad){
    codigo = _codigo;
    nota = _nota;
}

// metodos
void persona::mostrar_persona(){ // metodo de la case padre
    cout<<"\n\n datos generales\n";
    cout<<" nombre: "<<nombre<<endl;
    cout<<" edad: "<<edad<<endl;
}
void alumno::mostrar_alumno(){
    mostrar_persona();
    cout<<" codigo: "<<codigo<<endl;
    cout<<" nota: "<<nota<<endl;
}

int main(){
    string name, code;
    int age;
    float note;

    cout<<"que tipo de persona eres?\n";
    cout<<"-->1 particular\n";
    cout<<"-->2 estudiante\n";

    int op;
    cout<<"\n ingresa tu opcion :";cin>>op;
    while(op<1 || op>2){
        cout<<"\n valor invalido!\n";
        cout<<" ingresa tu opcion :";cin>>op;
    }
    if (op==1){
        cout<<"\n particular\n";
        cout<<" nombre:";cin>>name;
        cout<<" edad:";cin>>age;
        persona person1(name,age);
        person1.mostrar_persona();

    }
    else if (op==2){
        cout<<"\n estudiante\n";
        cout<<" nombre:";cin>>name;
        cout<<" codigo:";cin>>code;
        cout<<" edad:";cin>>age;
        cout<<" nota:";cin>>note;
        alumno alumno1(name,age,code,note);
        alumno1.mostrar_alumno();
    }
        
    system("pause");
    return 0;
}