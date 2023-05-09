#include "octal.h"

octal::octal(int decimal) {
    int i = 0;

    // Conversion del número decimal a octal
    while (decimal > 0) {
        oct[i] = (decimal % 8) + '0';
        decimal /= 8;
        i++;
    }
    oct[i] = '\0';

    // Reversión de la cadena octal
    int len = i;
    for (i = 0; i < len / 2; i++) {
        char temp = oct[i];
        oct[i] = oct[len - i - 1];
        oct[len - i - 1] = temp;
    }
}


octal octal::operator+(const octal& op2) const {
    octal temp;
    int carry = 0, i;

    // Suma dígito por dígito, con acarreo si es necesario
    for (i = 0; oct[i] != '\0' || op2.oct[i] != '\0'; i++) {
        int sum = (oct[i] - '0') + (op2.oct[i] - '0') + carry;
        temp.oct[i] = (sum % 8) + '0';
        carry = sum / 8;
    }

    if (carry != 0) {
        temp.oct[i] = carry + '0';
        i++;
    }

    temp.oct[i] = '\0';

    return temp;
}

ostream& operator<<(ostream& salida, const octal& num) {
    int i;

    // Ignora los ceros a la izquierda
    for (i = 0; num.oct[i] == '0' && num.oct[i + 1] != '\0'; i++);

    // Imprime los dígitos restantes
    for (; num.oct[i] != '\0'; i++) {
        salida << num.oct[i];
    }

    // Si el número es cero, imprime un único cero
    if (i == 0) {
        salida << "0";
    }

    return salida;
}
