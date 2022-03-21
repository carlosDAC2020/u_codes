#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
using namespace std;

class matriz {
    friend ostream &operator << (ostream &, const matriz &);
public:
    matriz(int = 1, int = 1);
    matriz(const matriz& orig);
    virtual ~matriz();
    void getMatrix() const;
    void setMatriz();
    void setfilas(int);
    void setcolumnas(int);
    void pedir_datos();
    int operator==(const matriz &) const;
    int operator!=(const matriz &a) const
    {
        return !(*this == a);
    }

    const matriz &operator=(const matriz &);
// suma de matrices 
    matriz operator+(const matriz &) const;
// multiplicacion escalar de una matriz
    matriz producto_escalar();
// producto de dos matrices 
    matriz operator*(const matriz &) const;
private:
    float **Matrix;
    int filas, columnas;
};

#endif // MATRIZ_H
