#include "octal.h"

octal::octal(long valor) {
  for(int i = 0; i <= 10; i++)
    oct[i] = 0;

  /* coloca los digitos del argumento dentro del arreglo */
  for(int j = 10; valor != 0 && j >= 0; j--){
    oct[j] = valor % 8;
    valor /= 8;
  }
}


octal octal::operator+(const octal& op2) const {
  octal temp;
  int acarreo = 0;

  for(int i = 10; i >= 0; i--){
    temp.oct[i] = oct[i] + op2.oct[i] + acarreo;
    if(temp.oct[i] > 7){
      temp.oct[i] %= 8; //reduce a 0 - 7
      acarreo = 1;
    }
    else
      acarreo = 0;
  }
  return temp;
}

ostream& operator<<(ostream& salida, const octal& num) {
  int i;
  for(i = 0; (num.oct[i] == 0) && (i <= 10); i++);
  // ignora ceros a la izquierda/
  if(i == 11)
    salida << 0;
  else
    for( ; i <= 10; i++)
        salida << num.oct[i];
  return salida;
}
