#include <iostream>
using namespace std;
const int Max=500;

//Funcion STRUCT
struct registro {
  string nombre;
  string apellido;
  int edad;
  int sexo;
  int genero_preferido;
}V[Max];

//Menu
void menu(){
  cout<<"\n¡Bienvenido al programa!"<<endl;
  cout<<"\nOpciones"<<endl;
  cout<<"\n1) Inciar encuesta"<<endl;
  cout<<"2) Busqueda de resultados"<<endl;
  cout<<"3) Salir del programa"<<endl;
}

//Funcion de DATOS
void datos(int b){
  for (int i=0; i<b; i++) {
    cout<<"\n**Usuario "<<i+1<<"**"<<endl;
    cout<<"Nombre: ";cin>>V[i].nombre;
    cout<<"Apellido: ";cin>>V[i].apellido;
    cout<<"Edad: ";cin>>V[i].edad;
    cout<<"Sexo:"<<endl;
    cout<<"1) Masculino"<<endl;
    cout<<"2) Femenino"<<endl;
    cout<<"Elija el sexo: ";cin>>V[i].sexo;
    cout<<"Generos de pelicula:"<<endl;
    cout<<"1) Accion"<<endl;
    cout<<"2) Comedia"<<endl;
    cout<<"3) Romance"<<endl;
    cout<<"4) Fantasia"<<endl;
    cout<<"5) Terror"<<endl;
    cout<<"Elija el genero preferido: ";cin>>V[i].genero_preferido; 
  }
}


//Menu de busqueda
void menu_busqueda(){
  cout<<"\n¿Que estadisticas desea ver?"<<endl;
  cout<<"Opciones:"<<endl;
  cout<<"1) Genero preferido por hombre, y genero preferido por mujeres"<<endl;
  cout<<"2) Genero preferido por menores de 17 anios"<<endl;
  cout<<"3) promedio de edades de hombres y mujeres "<<endl;
  cout<<"4) Genero preferido en general para todo el publico encuestado  "<<endl;
  cout<<"5) Tabla de votaciones"<<endl;
  cout<<"6) Regresar al menu principal"<<endl;
}

// genero preferido para los hombre y genero preferido para las mujeres 
void op_1(int cant){
    string generos[5]={"Accion","Comedia","Romance","Fantasia","Terror"};

    // variables auxiliares para hombres 
    string tendencia_hombres;
    int cant_tend_hombres=0;
    int auxA;
    // variables auxiliares para mujeres
    string tendencia_mujeres;
    int cant_tend_mujeres=0;
    int auxB;

    for (int t=1; t<=5; t++){
        auxA=0;
        auxB=0;
        for (int i=0; i<cant; i++){
            if (V[i].sexo==1){
                if(V[i].genero_preferido==t){
                     auxA+=1;
                }
            }
            else{
                if(V[i].genero_preferido==t){
                     auxB+=1;
                }
            }
        }
        // evaluamos para los hombres
        if (auxA>cant_tend_hombres){
            cant_tend_hombres=auxA;
            tendencia_hombres=generos[t];
        }
        // evaluamos para ,ujeres
        if (auxB>cant_tend_mujeres){
            cant_tend_mujeres=auxA;
            tendencia_mujeres=generos[t];
        }
    }
    cout<<" genro favorito entre los hombres es : "<<tendencia_hombres<<endl;
    cout<<" genro favorito entre las mujeres es : "<<tendencia_mujeres<<endl;
}

// generom preferido para menores de 17 anio 
void op_2(int cant){
    string generos[5]={"Accion","Comedia","Romance","Fantasia","Terror"};

    // variables auxiliares 
    string tendencia_menores;
    int cant_tend_menores=0;
    int aux;

        for (int t=1; t<=5; t++){
        aux=0;
        for (int i=0; i<cant; i++){
            if (V[i].edad<=17){
                if(V[i].genero_preferido==t){
                     aux+=1;
                }
            }
        }
        if (aux>cant_tend_menores){
            cant_tend_menores=aux;
            tendencia_menores=generos[t];
        }
    }
    cout<<" el genero preferido entre personas menores de 17 anios es: "<<tendencia_menores<<endl;
}

// promedio de edades de hombres y mujeres
void op_3(int cant){
        // sumatorias 
    int sum_edad_hombres=0, sum_edad_mujeres=0;
        // cantidades
    int cant_hombres=0, cant_mujeres=0; 
        // promedios
    float prom_edad_hombres, prom_edad_mujeres;

    for (int i=0; i<cant; i++){
            if (V[i].sexo==1){
                sum_edad_hombres+=V[i].edad;
                cant_hombres+=1;
            }
            else{
               sum_edad_mujeres+=V[i].edad;
                cant_mujeres+=1;
            }
    }
    // calculamos promedios 
    prom_edad_hombres=sum_edad_hombres/cant_hombres;
    cout<<"\n el promedio de las edades de los hombres es de : "<<prom_edad_hombres;

    prom_edad_mujeres=sum_edad_mujeres/cant_mujeres;
    cout<<"\n el promedio de edad de las mujeres ed de : "<<prom_edad_mujeres;
}

// Genero preferido en general para todo el publico encuestado 
void op_4(int cant){

    string generos[5]={"Accion","Comedia","Romance","Fantasia","Terror"};

    // variables auxiliares 
    string tendencia_general;
    int cant_tend_general=0;
    int aux;

    for (int t=1; t<=5; t++){
        aux=0;
        for (int i=0; i<cant; i++){
            if(V[i].genero_preferido==t){
                     aux+=1;
            }
        }
        if (aux>cant_tend_general){
            cant_tend_general=aux;
            tendencia_general=generos[t];
        }
    }
    cout<<"\n el genero preferido entre todo el publico encuestado fue : "<<tendencia_general;
}


//Tabla de votaciones
int votaciones(int c) {
  int accion=0, comedia=0, romance=0, fantasia=0, terror=0;
  for (int i=0; i<c; i++) {
    if (V[i].genero_preferido==1) {
      accion=accion+1;
    }
    if (V[i].genero_preferido==2) {
      comedia=comedia+1;
    }
    if (V[i].genero_preferido==3) {
      romance=romance+1;
    }
    if (V[i].genero_preferido==4) {
      fantasia=fantasia+1;
    }
    if (V[i].genero_preferido==5) {
      terror=terror+1;
    }
  }
  cout<<"\n tabla de votaciones ";
  cout<<"\nAccion: "<<accion<<endl;
  cout<<"Comedia: "<<comedia<<endl;
  cout<<"Romance: "<<romance<<endl;
  cout<<"Fantasia: "<<fantasia<<endl;
  cout<<"Terror: "<<terror<<endl;
  return 0;
}

//Funcion PRINCIPAL
int main() {
  int eleccion=0, a=0, eleccion2=0;
  while(eleccion0){
    menu();
    cout<<" ingrese el numero de su opcion: ";cin>>eleccion;
    if (eleccion==){

    }
    else if (
    {
        /* code */
    }
    
    
    
  }
  return 0;
}