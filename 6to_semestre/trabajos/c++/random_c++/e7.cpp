#include <iostream>
using namespace std;


int main() {
    // Declaración de variables
    double salario_mensual, utilidad, acumulador_utilidades = 0.0;
    int antiguedad;

    // Solicitar al usuario el salario mensual y la antigüedad del trabajador
    cout << "Ingrese el salario mensual del trabajador: ";
    cin >> salario_mensual;

    cout << "Ingrese la antiguedad del trabajador (en años): ";
    cin >> antiguedad;

    // Calcular la utilidad correspondiente según la antigüedad del trabajador
    if (antiguedad <= 1) {
        utilidad = salario_mensual * 0.05;
    } else if (antiguedad <= 2) {
        utilidad = salario_mensual * 0.07;
    } else if (antiguedad <= 5) {
        utilidad = salario_mensual * 0.1;
    } else if (antiguedad <= 10) {
        utilidad = salario_mensual * 0.15;
    } else {
        utilidad = salario_mensual * 0.2;
    }

    // Agregar la utilidad calculada al acumulador
    acumulador_utilidades += utilidad;

    // Mostrar la utilidad calculada y la suma acumulada de todas las utilidades
    cout << "La utilidad del trabajador es: " << utilidad << endl;
    cout << "La suma acumulada de utilidades es: " << acumulador_utilidades << endl;

    return 0;
}
