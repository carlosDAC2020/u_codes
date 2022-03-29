#include "alumno.h"
#include "pregrado.h"
#include "posgrado.h"


int main()
{
    string codi, nomb, direcc, nprog;
    double precio;
    int periodos;
    int pruevas;
    float promedio;

    cout<<"\nPRUEVA PARA LA CLASE PREGRADO\n\n";
    cout<<"\nDigite codigo: ";
    cin>>codi;
    cout<<"\nDigite Nombre: ";
    cin>>nomb;
    cout<<"\nDigite Direccion: ";
    cin>>direcc;
    cout<<"\nDigite nombre del Programa: ";
    cin>>nprog;
    cout<<"\nDigite Precio del Periodo: ";
    cin>>precio;
    cout<<"\nDigite cantidad de Periodos: ";
    cin>>periodos;
    cout<<"\nDigite Puntaje obtenido en las pruevas Icfes: ";
    cout<<"\nSi coloca un dato menor que 0, se le asignara 0: ";
    cin>>pruevas;

    pregrado primero(codi, nomb, direcc, precio, periodos, nprog, pruevas);

    cout<<"\n\tPRIMERO\n\n";
    primero.imprime();
    cout<<"\n\n\n";

    cout<<"\n\tPrecio del Programa para PRIMERO -> "<<primero.PrecioPrograma();

    cout<<"\nPRUEVA PARA LA CLASE POSGRADO\n\n";
    cout<<"\nDigite codigo: ";
    cin>>codi;
    cout<<"\nDigite Nombre: ";
    cin>>nomb;
    cout<<"\nDigite Direccion: ";
    cin>>direcc;
    cout<<"\nDigite Precio del Periodo: ";
    cin>>precio;
    cout<<"\nDigite cantidad de Periodos: ";
    cin>>periodos;
    cout<<"\nDigite Titulo obtenido en Pregrado: ";
    cin>>nprog;
    cout<<"\nDigite Promedio obtenido en Pregrado (1.0 - 5.0): ";
    cout<<"\nSi coloca un dato menor que 0.0 o mayor de 5.0, se le asignara 0: ";
    cin>>promedio;

    posgrado segundo(codi, nomb, direcc, precio, periodos, nprog, promedio);

    cout<<"\n\tSEGUNDO\n\n";
    segundo.imprime();
    cout<<"\n\n\n";

    cout<<"\n\tPrecio del Programa para SEGUNDO -> "<<segundo.PrecioPrograma();

    return 0;

} // end main
