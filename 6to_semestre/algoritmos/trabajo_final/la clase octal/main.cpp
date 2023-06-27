#include "octal.h"


int main() {
    // Crea dos objetos octales
    octal oct1(13);
    octal oct2(15);
    octal oct3;

    // Suma los dos objetos octales y guarda el resultado en un tercero
    oct3 = oct1 + oct2;

    // Imprime los tres objetos octales
    cout << "Octal 1: " << oct1 << endl;
    cout << "Octal 2: " << oct2 << endl;
    cout << "Suma: " << oct3 << endl;

    return 0;
}
