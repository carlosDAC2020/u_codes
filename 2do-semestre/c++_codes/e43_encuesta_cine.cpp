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
  cout<<"2) Genero preferido por menores de 17 años"<<endl;
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
                auxA+=1;

            }
            else{
                auxB+=1;
            }
        }
        // evaluamos para los hombres
        if (auxA>cant_tend_hombres){
            cant_tend_hombres=auxA;
            tendencia_hombres=generos[t];
        }
        // evaluamos para ,ujeres
        if (auxA>cant_tend_hombres){
            cant_tend_hombres=auxA;
            tendencia_mujeres=generos[t];
        }
    }
    cout<<" genro favorito entre los hombres es : "<<tendencia_hombres<<endl;
    cout<<" genro favorito entre las mujeres es : "<<tendencia_mujeres<<endl;
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
  while(eleccion<3){
    menu();
    cout<<" ingrese el numero de su opcion: ";cin>>eleccion;
    switch(eleccion){
      case 1:
      do{
        cout<<"\nÂ¿Cuantos usuarios desea encuestar?: ";
        cin>>a;
      }while(a<0 || a>Max);
      datos(a);
      break;
      //----------------------------------------------------------------
      case 2:
      while(eleccion2<7){
        menu_busqueda();
        cout<<" ingrese el numero de su opcion: ";cin>>eleccion2;
        switch(eleccion2){
          case 1:
            op_1(a);
          break;
          case 2:
          break;
          case 3:
          break;
          case 4:
          break;
          case 5:
            votaciones(a);
          break;
          case 6:
          break;
          default:
          cout << "\n\n*** ERROR EN OPCION ***\n\n";
          eleccion2='0';
          break;
        }
      }
      break;
      //-----------------------------------------------------------------
      case 3:
      break;
      default:
      cout << "\n\n*** ERROR EN OPCION ***\n\n";
      eleccion='0';
      break;
    }
    
  }
  return 0;
}