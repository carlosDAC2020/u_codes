#include "intgrande.h"

/*constructor predeterminado; convierte un entero largo en un objeto IntGrande*/
IntGrande::IntGrande(long valor)
{
    for(int i = 0; i <= 29; i++)
        entero[i] = 0;

    /*coloca los digitos del argumento dentro del arreglo*/
    for(int j = 29; valor != 0 && j >= 0; j--){
        entero[j] = valor % 10;
        valor /= 10;
    }

}

/*constructor de conversion que convierte una cadena de caracteres
que representan un entero grande en un objeto IntGrande*/
IntGrande::IntGrande(const char *cadena)
{
    for(int i = 0; i <= 29; i++)
        entero[i] = 0;

    /*coloca los digitos del argumento dentro del arreglo*/
    int longitud = strlen(cadena);
    for(int j = 30 - longitud, k = 0; j <= 29; j++, k++)
        if (isdigit(cadena[k]))
            entero[j] = cadena[k] - '0';
}

IntGrande IntGrande::operator+(const IntGrande &op2)
{
    IntGrande temp;
    int acarreo = 0;

    for(int i = 29; i >= 0; i--){
        temp.entero[i] = entero[i] + op2.entero[i] + acarreo;
        if(temp.entero[i] > 9){
            temp.entero[i] %= 10; //reduce a 0-9
            acarreo = 1;
        }
        else
            acarreo = 0;
    }
    return temp;
}

/*operador de suma IntGrande + int
convierte op2 en un IntGrande e invoca a operator+*/
IntGrande IntGrande::operator+(int op2)
{
    return *this + IntGrande(op2);
}

/*operador de suma; IntGrande + cadena que representa
un valor IntGrande*/
IntGrande IntGrande::operator+(const char *op2)
{
    return *this + IntGrande(op2);
}

/*operador de salida sobrecargado*/
ostream& operator<<(ostream &salida, const IntGrande &num)
{
    int i;
    for(i = 0; (num.entero[i] == 0) && (i <= 29); i++);
    /*ignora ceros a la izquierda*/

    if(i == 30)
        salida<<0;
    else
        for( ; i <=29; i++)
            salida<<num.entero[i];
    return salida;
}
