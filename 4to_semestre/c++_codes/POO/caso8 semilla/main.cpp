#include "semilla.h"

void semillas(string, int, int);
void menu(string);

int main()
{
  int nalum , ndias;
  string noinve;
  cout << "\nGrupo de investigacion (sin espacios en blanco): ";
  cin >> noinve;
  do{
    cout << "\nNo.semillas, entre 1(uno) y 5(cinco): ";
    cin >> nalum;
  }while (nalum < 1 || nalum > 5);
  do{
    cout << "\nNo.dias proyecto, entre 8(ocho) y 30(treinta): ";
    cin >> ndias;
  }while(ndias < 8 || ndias > 30);
  semillas(noinve, ndias ,nalum);
  cout<<"\n\n";
  return 0;
}

void menu(string ni)
{
  cout << "\n\tGRUPO DE INVESTIGACION " << ni;
  cout << "\n\t\t\tMENU" << endl;
  cout << "\n1. Datos de los estudiantes semillas.";
  cout << "\n2. En pantalla datos del semillero.";
  cout << "\n3. Promedios horas trabajadas del semillero.";
  cout << "\n4. Promedio mas alto de horas diarias trabajadas.";
  cout << "\n5. Salir";
  cout << "\n\nEscoga una opcion:";
}

void semillas(string bo, int nd, int ne)
{
  semilla a(nd),b(nd),c(nd),d(nd),e(nd);
  vector <semilla> semillero(5);
  semillero[0] = a;
  semillero[1] = b;
  semillero[2] = c;
  semillero[3] = d;
  semillero[4] = e;
  char ans = '0';
  while(ans < '5')
  {
    menu(bo);
    cin >> ans;
    switch(ans)
    {
    case '1':
      obtenerDatos(ne , semillero);//Llamado a una función friend
      break;
    case '2':
      imprimirDatos(ne , semillero);//Llamado a una función friend
      break;
    case '3':
      for (int i = 0 ; i < ne ; i++)
      {
        semillero[i].imprimirProm();
      }
      break;
    case '4':
      PromMayor(ne,semillero);//Llamado a una función friend
      break;
    case '5':
      break;
    default:
      cout<<"\nError en opción\n";
      ans = '0';
    }
  }
}