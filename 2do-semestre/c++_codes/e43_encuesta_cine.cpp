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

//Menu de busqueda
void menu_busqueda(){
  cout<<"\n¿Que estadisticas desea ver?"<<endl;
  cout<<"Opciones:"<<endl;
  cout<<"1) Tendencia entre hombre y mujeres"<<endl;
  cout<<"2) Media y mediana entre hombres y mujeres"<<endl;
  cout<<"3) Genero preferido por hombre, y genero preferido por mujeres"<<endl;
  cout<<"4) Genero preferido por menores de 17 años"<<endl;
  cout<<"5) Tabla de votaciones"<<endl;
  cout<<"6) Todas las estadisticas"<<endl;
  cout<<"7) Regresar al menu principal"<<endl;
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

// tendencia hombres
void tendencia_hombres_y_mujeres(int cant){
    string tend[5]={"Accion","Comedia","Romance","Fantasia","Terror"}
    for(int i=1,i<=5,i++){
        
    }
}


//Media
float media(int R) {
  int suma=0, promedio=0;
  for (int j=0; j<R; j++) {
    suma=suma+V[j].genero_preferido;
  }
  promedio=suma/R;
  cout<<"La media es: "<<promedio<<endl;
  return 0;
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
          break;
          case 2:
            media(a);
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
          case 7:
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