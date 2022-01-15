/*
crear un programa en c++ con una jerarqui de clases
siendo animal la clase padre y humano y perro las subclases
aplicar polimorfismo en usando un metodo correr  
*/

# include <iostream>
# include <stdlib.h>
using namespace std;

                                // clase padre
class animal{
    private:
        string nombre;
        int edad;
    public:
        animal(string,int);
        virtual void correr();
        virtual void mostrar();
};


                                // sub clases
class humano : public animal{
    public:
        humano(string,int);
        void correr();
        void mostrar();
};


class perro : public animal{
    private:
        string raza;
    public:
        perro(string, int, string);
        void correr();
        void mostrar();
};


// contructor persona
animal::animal(string _nombre, int _edad){
    nombre = _nombre;
    edad = _edad;
}
// metodos
void correr(){
}
void animal::mostrar(){
    cout<<" nombre: "<<nombre<<endl;
    cout<<" edad: "<<edad<<endl;
}

// constructor alumno
humano::humano(string _nombre, int _edad) : animal(_nombre, _edad){
}
// metodos
void humano::mostrar(){
    cout<<" datos del humano "<<endl;
    animal::mostrar();
    
}
void humano::correr(){
    cout<<" corre en dos patas \n";
}

// consgtructor profesor
perro::perro(string _nombre, int _edad, string _raza) : animal(_nombre,_edad){
    raza = _raza;
}
// metodos
void perro::mostrar(){
    cout<<" datos del perro \n";
    animal::mostrar();
    cout<<" raza: "<<raza<<endl;
}
void perro::correr(){
    cout<<" corre en cuatro patas\n";
}


int main(){
    
    humano h1("carlos",19);
    perro p1("toby",9,"labrador");
    
    h1.humano::mostrar();
    h1.humano::correr();
    cout<<"\n";
    p1.perro::mostrar();
    p1.perro::correr();

        
    system("pause");
    return 0;
}