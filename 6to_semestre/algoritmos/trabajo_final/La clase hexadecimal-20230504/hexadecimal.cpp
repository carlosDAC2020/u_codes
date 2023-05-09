#include "hexadecimal.h"

/*constructor predeterminado*/
hexadecimal::hexadecimal(long valor)
{
  int i, temp = 0;
  for(i = 0; i < 100; i++) hexa[i] = '0';
  i = 99;
  while(valor > 0) {
    temp = valor % 16;
    if(temp < 10) {
      hexa[i] = temp + 48;
      i--;
    }
    else {
      hexa[i] = temp + 55;
      i--;
    }
    valor = valor / 16;
  }
}

hexadecimal hexadecimal::operator+(const hexadecimal &op2) const
{
    hexadecimal temp;
    int carry = 0;

    // Iteramos desde la derecha hacia la izquierda
    for (int i = 99; i >= 0; i--) {
        int num1 = hexa[i] >= '0' && hexa[i] <= '9' ? hexa[i] - '0' : hexa[i] - 'A' + 10;
        int num2 = op2.hexa[i] >= '0' && op2.hexa[i] <= '9' ? op2.hexa[i] - '0' : op2.hexa[i] - 'A' + 10;

        int sum = num1 + num2 + carry;
        carry = sum > 15 ? 1 : 0;
        sum %= 16;

        temp.hexa[i] = sum < 10 ? (char)(sum + '0') : (char)(sum - 10 + 'A');
    }

    return temp;
}

ostream& operator<<(ostream &salida, const hexadecimal &num)
{
    bool is_zero = true;
    for (int i = 0; i < 100; i++) {
        if (num.hexa[i] != '0') {
            is_zero = false;
            break;
        }
    }

    if (is_zero) {
        salida << "0";
    } else {
        int i = 0;
        while (num.hexa[i] == '0' && i < 99) i++;
        for (; i < 100; i++) salida << num.hexa[i];
    }

    return salida;
}


/*
hexadecimal hexadecimal::operator+(const hexadecimal &op2) const
{
    hexadecimal temp;
    int acarreo = 0;
    for(int i = 100; i >= 0; i--){
        temp.hexa[i] = hexa[i] + op2.hexa[i] + acarreo;
        if(temp.hexa[i] > 9){
            temp.hexa[i] %= 10; //reduce a 0-9
            acarreo = 1;
        }
        else
            acarreo = 0;
    } 
    return temp;
}*/

/*operador de salida sobrecargado
ostream& operator<<(ostream &salida, const hexadecimal &num)
{
    int i;
    for(i = 0; (num.hexa[i] == '0') && (i < 100); i++);
    ignora ceros a la izquierda
    if(i == 99)
        salida << 0;
    else
        for( ; i < 100; i++)
            salida << num.hexa[i];
    return salida;
}
*/