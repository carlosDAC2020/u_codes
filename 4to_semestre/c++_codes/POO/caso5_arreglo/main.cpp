#include "arreglo.h"

int main()
{
  arreglo A(10), B, C;
  cout << "\n** Primer arreglo ***\n";
  cin >> A;
  cout << "\n** Segundo arreglo ***\n";
  cin >> B;
  C = A;
  cout << "\n** Tercer arreglo ***\n";
  cout << C;
  if (A == C)
    cout << "\n\nA es igual a C";
  cout << "\n\n";
  return 0;
}