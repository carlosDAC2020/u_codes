#include <iostream>
#include <cmath>
using namespace std;

//Autor: [Tu Nombre]
//Fecha: [Fecha de creación]
//Programa: Inversión y intercambio de valores
//Descripción: Este programa permite calcular la ganancia por inversión en término fijo y realizar el intercambio de valores.

int main() {
    int opcion, meses = 12; // Se establece la duración de la inversión en 12 meses
    float capital, interes, interesTotal, nuevoCapital; // Variables para almacenar el capital, interés generado y el nuevo capital con los intereses
    float A, B, C, aux; // Variables para el intercambio de valores

    cout << "Bienvenido a la aplicación " << endl;
    cout << "1. Calcular ganancia por inversión en término fijo" << endl;
    cout << "2. Intercambiar valores" << endl;
    cout << "3. Terminar" << endl;
    cout << "Selecciona la opción deseada:";cin >> opcion;

  // Se utiliza una estructura if-else para ejecutar la opción seleccionada
     if (opcion == 1) {
        // En el caso 1, se pide el capital a invertir y se calcula la ganancia total
        cout << "Introduce el capital a invertir: ";
        cin >> capital;
        interes = capital * 0.019; // Se calcula el interés generado en un mes (1.9%)
        interesTotal = interes * meses; // Se multiplica el interés por el número de meses para obtener la ganancia total
        nuevoCapital = capital + interesTotal; // Se suma el capital y la ganancia para obtener el nuevo capital
        cout << "El capital más los intereses generados durante 12 meses es de: $" << nuevoCapital << endl;
    } else if (opcion == 2) {
        // En el caso 2, se piden los valores A, B y C y se realiza el intercambio de valores
        cout << "Introduce el valor de A: ";
        cin >> A;
        cout << "Introduce el valor de B: ";
        cin >> B;
        cout << "Introduce el valor de C: ";
        cin >> C;
       aux = A; // Se almacena temporalmente el valor de A en una variable auxiliar
        A = B; // Se asigna el valor de B a A
        B = C; // Se asigna el valor de C a B
        C = aux; // Se asigna el valor temporal almacenado en la a variable auxiliar a C
        cout << "Los valores intercambiados son: " << endl;
        cout << "A: " << A << endl;
        cout << "B: " << B << endl;
        cout << "C: " << C << endl;
    } else if (opcion == 3) {
        cout << "Hasta pronto!" << endl;
    } else {
        cout << "Opción inválida, selecciona una opción entre 1 y 3." << endl;
    }

    return 0;
}
