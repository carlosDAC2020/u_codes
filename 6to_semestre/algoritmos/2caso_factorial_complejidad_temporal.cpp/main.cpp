#include <iostream>
using namespace std;

// Carlos Daniel Agamez Palomino T00059006

/*
El algoritmo es una función recursiva para calcular el factorial de un número entero n. La complejidad de tiempo del algoritmo depende del número de llamadas recursivas que se realizan para calcular el factorial de n.


En el peor caso, se realizan n llamadas recursivas para calcular factorial(n). Cada llamada recursiva implica una multiplicación y una resta, lo que da una complejidad de tiempo de O(n).
*/

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}


int main() {
    cout << factorial(5) << endl; 
    /*
    c1
    n=5
    r 5 * c2
          n=4
    r 5 * 4 * c3
              n=3
    r 5 * 4 * 3 * c4
                  n=2
    r 5 * 4 * 3 * 2 * c1
                      n=1
    r 5 * 4 * 3 * 2 * 1 

    return 120     
    */
    cout << factorial(0) << endl; // salida: 1
    cout << factorial(1) << endl; // salida: 1
    return 0;
}