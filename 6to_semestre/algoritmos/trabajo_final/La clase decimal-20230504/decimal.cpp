#include "decimal.h"

/*constructor predeterminado*/
decimal::decimal(long valor)
{
    for(int i = 0; i <= 29; i++)
        dec[i] = 0;

    /*coloca los digitos del argumento dentro del arreglo*/
    for(int j = 29; valor != 0 && j >= 0; j--){
        dec[j] = valor % 10;
        valor /= 10;
    }

}

decimal decimal::operator+(const decimal &op2) const
{
    decimal temp;
    int acarreo = 0;
    for(int i = 29; i >= 0; i--){
        temp.dec[i] = dec[i] + op2.dec[i] + acarreo;
        if(temp.dec[i] > 9){
            temp.dec[i] %= 10; //reduce a 0-9
            acarreo = 1;
        }
        else
            acarreo = 0;
    }
    return temp;
}

/*operador de salida sobrecargado*/
ostream& operator<<(ostream &salida, const decimal &num)
{
    int i;
    for(i = 0; (num.dec[i] == 0) && (i <= 29); i++);
    /*ignora ceros a la izquierda*/

    if(i == 30)
        salida << 0;
    else
        for( ; i <= 29; i++)
            salida << num.dec[i];
    return salida;
}
