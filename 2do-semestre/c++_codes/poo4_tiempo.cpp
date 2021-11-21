/*
     ejemplo 4
 se construye una clase tiempo que contenga los siguientes
atributos enteros: horas, minutos y segundos hacemos 
que la clase contenga 2 constructores uno con 3 parametros enteros
que representan las hoaras, minutos y segundos y otro con un 
parametro de numero long que sdera la cantidad de segundos el cual 
se deber representar en horas minutos y segundos  

*/

# include <iostream>
# include <stdlib.h>
using namespace std;

class tiempo{
    private: // atributos
        int horas, minutos, segundos;
    public: // metodos
        tiempo(int, int, int); //constructor
        tiempo(long); // constructor2
        void mostrar_hora();
};

// declaramos el primer contructor
tiempo::tiempo(int _horas, int _minutos, int _segundos){
    horas= _horas;
    minutos= _minutos;
    segundos= _segundos;
}

// declaramos el constructor 2
tiempo::tiempo(long _tiempo){
    horas= _tiempo/(60*60);
    minutos= (_tiempo % (60*60) / 60);
    segundos= _tiempo % 60;
    
}

// declaracion del atributo
void tiempo::mostrar_hora(){
    cout<<"el tiempo es: "<<horas<<" horas, "<<minutos<<" minutos, "<<segundos<<" segundos"<<endl;
}

int main(){
    tiempo t1(12,5,34);
    tiempo t2(201600);

    t1.mostrar_hora();
    t2.mostrar_hora();

    system("pause");
    return 0;
}