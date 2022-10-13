#include "arbol.h"

int menu();
void ingreso_datos(ABB, arbol);



int main()
{
  arbol arbolABB;
  ABB raizABB = arbolABB.getraiz();
  int go=0;
  while (go < 6) {
        switch (menu()) {
            case 1: ingreso_datos(raizABB, arbolABB);
            break;
            case 2: arbolABB.buscar_egresados(raizABB);
            break;
            case 3: arbolABB.enOrden(raizABB);
            break;
            case 4: 
            break;
            case 5: 
            break;
            case 6: go=6;
            break;
            default: cout << "\n\n\tERROR EN OPCION";
        }
    }
    return 0;
  
}
int menu()
{
  int op;
  cout << "\n\t\t  ..DIRECTORIO LABORAL EGRESADOS..\n\n";
  cout << "\t [1]  ingresar egresado\n";
  cout << "\t [2]  buscar egresado por la cedula\n";
  cout << "\t [3]  buscar egresados por profecion\n";
  cout << "\t [4]  buscar egresados por ciudad\n";
  cout << "\t [5]  Eliminar elemento\n";
  cout << "\t [6] SALIR\n";
  do
    {
        cout<<"ingresa una opcion:";cin>>op;
        if (op>6 || op<1)
        {
            cout<<" opcion ingresada no valida!!! \n porfavor ingresarla nuevamente \n";
        }
    } while (op>6 || op<1);
    return op;
}

void ingreso_datos(ABB raizABB, arbol arbolABB){
      int cc;
  string Name;
  string Apell;
  int NoM;
  int prof;
  int fch_nc[3]={0,0,0};
  string city_res;

  cout<<" INGRESA LOS DATOS DEL EGRESADO \n";
  do
  {
     cout << " cedula : ";  cin>> cc;
     if (cc<0)
     {
      cout<<" los numeros negativos no son validos!! \n";
     }
     
  } while (cc<0);
  
 
  cout << " nombre : ";  cin>> Name;

  cout << " apellido : ";  cin>> Apell;

  do
  {
    cout << " num movil : ";  cin>> NoM;
    if (NoM<0)
     {
      cout<<" los numeros negativos no son validos!! \n";
     }

  } while (NoM<1);
  
  do
  {
    cout << "\n ingeneria de profecion  \n";
    cout<<" 1 -> Industrial \n";
    cout<<" 2 -> Eléctrica \n";
    cout<<" 3 -> Electrónica \n";
    cout<<" 4 -> Mecánica \n";
    cout<<" 5 -> Mecatrónica \n";
    cout<<" 6 -> Química \n";
    cout<<" 7 -> Biomédica \n";
    cout<<" 8 -> Ambiental \n";
    cout<<" 9 -> Civil \n";
    cout<<" 10 -> Sistemas \n";
    cout<<" ingrese su opcion aqui -->";cin>>prof;
    if (prof<1 || prof>10)
    {
      cout<<" ingrese solo los valores señalados !! \n";
    }
  } while (prof<1 || prof>10);
  
  cout << " fecha de nacimiento \n";
  do
  {
    cout << " dia : ";  cin>> fch_nc[0];
    cout << " mes : ";  cin>> fch_nc[1];
    cout << " anio : ";  cin>> fch_nc[2];
    
    if (fch_nc[0]<1 || fch_nc[0]>31 || fch_nc[1]<1 || fch_nc[1]>12 || fch_nc[2]<1)
    {
      cout<<" fecha ingresada no valida \n";
    }
    
  } while (fch_nc[0]<1 || fch_nc[0]>31 || fch_nc[1]<1 || fch_nc[1]>12 || fch_nc[2]<1);
  
  cout << " ciudad de rsidencia : ";  cin>> city_res;

  
    if(arbolABB.validar(raizABB, cc)){
        arbolABB.insertar(raizABB, cc, Name, Apell, NoM, prof, fch_nc, city_res );
        cout << "\n dato ingresado exitosamente.\n";
    } 
    else{
         cout << "\n ya hay un registro similar .\n";
    }
       

}
