# include <iostream>
# include <stdlib.h>
using namespace std;

class fecha{
    private: // atributos
        int dia, mes, anio;
    public: // metodos
        fecha(int, int, int); //constructor
        fecha(long); // constructor2
        void mostrar_Fecha();
};

// declaramos el primer contructor
fecha::fecha(int _dia, int _mes, int _anio){
    anio= _anio;
    mes= _mes;
    dia= _dia;
}

// declaramos el constructor 2
fecha::fecha(long _fecha){
    anio= int(_fecha/10000);
    mes= int((_fecha-anio*10000)/100);
    dia= int(_fecha-anio*10000-mes*100);
}

// declaracion del atributo
void fecha::mostrar_Fecha(){
    cout<<"la fecha es: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

int main(){
    fecha hoy(11,7,2021);
    fecha ayer(10,7,2021);

    hoy.mostrar_Fecha();
    ayer.mostrar_Fecha();

    system("pause");
    return 0;
}