#include "racional.h"

racional::racional() {
    num = 0;
    dem = 1;
}
//Método imprimir

ostream &operator<<(ostream &salida, const racional &a) {
    salida << a.num << "/" << a.dem;
    return salida;
}
//Método suma

racional racional::operator+(const racional &a) const {
    racional res;
    res.num = (num * a.dem) + (dem * a.num);
    res.dem = dem * a.dem;

    return res;
}
//Método resta

racional racional::operator-(const racional &a) const {
    racional res;
    res.num = (num * a.dem) - (dem * a.num);
    res.dem = dem * a.dem;

    return res;
}

racional racional::operator*(const racional &a) const {
    racional res;
    res.num = num * a.num;
    res.dem = dem * a.dem;

    return res;
}

istream &operator>>(istream &entrada, racional &a) {
    cout << "\nDigite numerador: ";
    entrada >> a.num;
    do {
        cout << "\nDigite denominador: ";
        entrada >> a.dem;
    } while (a.dem == 0);

    return entrada;
}
