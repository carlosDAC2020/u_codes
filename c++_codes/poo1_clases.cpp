// clases en c++
# include <iostream>
# include <stdlib.h>
using namespace std;

class Persona{
    private: // atributos
        int edad;
        string nombre;
    public: // metodos
        Persona(int, string); // contructor
        void leer();
        void correr();
};

// el contructor, nos sirve para inicializar los atributos
Persona::Persona(int _edad, string _nombre){
    edad= _edad;
    nombre = _nombre;
}

void Persona::leer(){
    cout<<"Soy "<<nombre<<" y estoy leyendo un libro"<<endl;
}

void Persona::correr(){
    cout<<"Soy "<<nombre<<" y estoy corriendo una maraton"<<endl<<"anios"<<edad<<endl;
}

int main(){
    Persona p1= Persona(20,"alejandro");|
    Persona p2(19,"maria");
    Persona p3(23,"juan");

    p1.leer();
    p2.correr();
    p3.leer();
    p3.correr();

    system("pause");
    return 0;
}