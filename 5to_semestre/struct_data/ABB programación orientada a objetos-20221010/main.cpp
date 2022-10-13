#include "arbol.h"

void menu();
void menu2();

int main()
{
  arbol arbolABB;
  ABB raizABB;
  raizABB = arbolABB.getraiz();
  int x;
  int op, op2;
  do
  {
    menu();  cin>> op;
    cout << endl;
    switch(op)
    {
      case 1:
        cout << " Ingrese valor : ";  cin>> x;
        if(arbolABB.validar(raizABB, x))
          arbolABB.insertar(raizABB, x);
        else
          cout << "\nDato ya está en el arbol.\n";
        break;
      case 2:
        menu2();  cin>> op2;
        if(raizABB != NULL)
        {
          switch(op2)
          {
            case 1:
              arbolABB.enOrden(raizABB); break;
            case 2:
              arbolABB.preOrden(raizABB); break;
            case 3:
              arbolABB.postOrden(raizABB); break;
          }
        }
        else
          cout << "\n\t Arbol vacio..!";
          break;
      case 3:
        bool band;
        cout<<" Valor a buscar: "; cin>> x;
        band = arbolABB.busquedaRec(raizABB, x);
        if(band == 1)
          cout << "\n\tEncontrado...";
        else
          cout << "\n\tNo encontrado...";
        break;
      case 4:
        cout<<" Valor a eliminar: "; cin>> x;
        arbolABB.elimina(raizABB, x);
        cout << "\n\tEliminado..!";
        break;
      case 5:
        break;
      default:
        op = 0;
    }
  }while(op != 5);
}

void menu()
{
  cout << "\n\t\t  ..[ ARBOL BINARIO DE BUSQUEDA ]..\n\n";
  cout << "\t [1]  Insertar elemento\n";
  cout << "\t [2]  Recorridos de profundiad\n";
  cout << "\t [3]  Buscar elemento\n";
  cout << "\t [4]  Eliminar elemento\n";
  cout << "\t [5] SALIR\n";
  cout << "\n\t Ingrese opcion : ";
}

void menu2()
{
  cout << endl;
  cout << "\t [1] En Orden     \n";
  cout << "\t [2] Pre Orden    \n";
  cout << "\t [3] Post Orden   \n";
  cout << "\n\tOpcion :  ";
}
