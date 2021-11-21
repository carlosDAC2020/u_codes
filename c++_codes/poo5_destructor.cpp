
# include <iostream>
# include <stdlib.h>
using namespace std;

class perro{
    private: // atributos
        string name, raza;
    public: // metodos
        perro(string, string); //constructor
        ~perro(); // destructor
        void mostrar_datos();
        void jugar();
};

// declaramos el contructor
perro::perro(string _nombre, string _raza){
    name = _nombre;
    raza = _raza;
}

// declaramos el destructor
perro::~perro(){

}

// declaracion del atributo
void perroo::mostrar_datos(){
    cout<<" nombre"<<name<<endl;
    cout<<" raza"<<raza<<endl;
}

void perro::jugar(){
    cout<<" el perro "<<name<<" esta jugando"<<endl;
}

int main(){
    perro p1("toby","labrador"); // creamos un objeto

    p1.mostrar_datos();
    p1.juan();
    p1.~perro(); // destruimos el objeto
    p1.mostrar_datos();

    system("pause");
    return 0;
}