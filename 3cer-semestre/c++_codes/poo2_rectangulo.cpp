/*
    ejercicio 2
construimos una clase llamada rectangulo que tenga
con atrinbutos de largo y ancho y los metodos de 
perimetro() y area()

*/
# include <iostream>
# include <stdlib.h>
using namespace std;

class Rectangulo{
    private: // atributos
        float largo;
        float ancho;
    public: // metodos
        Rectangulo(float, float); // contructor
        void perimetro();
        void area();
};

// el contructor, nos sirve para inicializar los atributos
Rectangulo::Rectangulo(float _largo, float _ancho){
    largo = _largo;
    ancho = _ancho;
}

void Rectangulo::perimetro(){
    float perimetro= (2*largo) + (2*ancho);
    cout<<" el perimetro es igual a : "<<perimetro<<endl;
}

void Rectangulo::area(){
    float area = largo*ancho;
    cout<<" el area es igual a :"<<area<<endl;
}

int main(){
    Rectangulo p1= Rectangulo(20.1,12.5);

    p1.perimetro();
    p1.area();

    system("pause");
    return 0;
}