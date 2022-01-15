// practica con polimorfismo

# include <iostream>
# include <stdlib.h>
using namespace std;

                                // clase padre
class persona{
    private:
        string nombre;
        int edad;
    public:
        persona(string,int);
        virtual void mostrar();
};


                                // sub clases
class alumno : public persona{
    private:
        float nota_final;
    public:
        alumno(string,int ,float);
        void mostrar();
};


class profesor : public persona{
    private:
        string materia;
    public:
        profesor(string, int, string);
        void mostrar();
};


// contructor persona
persona::persona(string _nombre, int _edad){
    nombre = _nombre;
    edad = _edad;
}
// metodo
void persona::mostrar(){
    cout<<" nombre: "<<nombre<<endl;
    cout<<" edad: "<<edad<<endl;
}

// constructor alumno
alumno::alumno(string _nombre, int _edad, float _nota_final) : persona(_nombre, _edad){
    nota_final = _nota_final;
}
// metodos
void alumno::mostrar(){
    persona::mostrar();
    cout<<" nota final: "<<nota_final<<endl;
}

// consgtructor profesor
profesor::profesor(string _nombre, int _edad, string _materia) : persona(_nombre,_edad){
    materia = _materia;
}
// metodos
void profesor::mostrar(){
    persona::mostrar();
    cout<<" materia: "<<materia<<endl;
}


int main(){
    persona *vector[3];

    vector[0] = new alumno("carlos",19,4.5);
    vector[1] = new alumno("jose",17,3.5);
    vector[2] = new profesor("moises",69,"calculo");

    vector[0]->mostrar();
    cout<<"\n";
    vector[1]->mostrar();
    cout<<"\n";
    vector[2]->mostrar();
        
    system("pause");
    return 0;
}