#include "hexagonal.h"
#include <iostream>
#include <cmath>
using namespace std;
int main() {
  hexagonal A;
  float auxL, auxh;
  char res = 's';
  while(res == 's')
  {
    cout << "\nLado de la base(hexagono) = ";
    cin >> auxL;
    A.setlado(auxL);
    cout << "\nAltura de la piramide = ";
    cin >> auxh;
    A.setaltura(auxh);
    A.imprime();
    do{
      cout << "\n¿Otra piramide hexagonal? (s/n)... ";
      cin>> res;
    }while(res != 's' and res != 'n');
  }
  cout << "\n\n";
  return 0;
}
