#include "hexagonal.h"

//Constructor
 hexagonal::hexagonal(float L, float h)
 {
   setlado(L);
   setaltura(h);
 }

//Constructor de copia
  hexagonal::hexagonal(const hexagonal &copia)
  {
    lado = copia.lado;
    altura = copia.altura;
  }

//Metodos

  void hexagonal:: setlado(float L)
  {
    lado = (L < 0.0 ? 0.0 :L);
  }

  void hexagonal:: setaltura(float h)
  {
    altura = (h < 0.0 ? 0.0 :h);
  }

  float hexagonal:: getlado() const
  {
    return lado;
  }

  float hexagonal:: getaltura() const
  {
    return altura;
  }

  float hexagonal:: apotemaBase() const
  {
    return sqrt (3.0 * lado) /2.0;
  }

  float hexagonal:: apotema() const
  {
    return sqrt(pow(altura,2) + pow(apotemaBase(),2));
  }

  float hexagonal:: areaBase() const
  {
    return (6.0 * lado * apotemaBase()) / 2.0;
  }

  float hexagonal:: areaTrianguloLateral() const
  {
    return (lado * apotema()) / 2.0;
  }

  float hexagonal:: areaLateral() const
  {
    return areaTrianguloLateral() * 6.0;
  }

  float hexagonal:: areaTotal() const
  {
    return areaBase() + areaLateral();
  }

  float hexagonal:: volumen() const
  {
    return lado * apotemaBase() * altura;
  }

  void hexagonal:: imprime() const
  {
    cout << "\n*** Piramide hexagonal regular ***\n";
    cout << "\nLado del hexagono de la base = " << getlado();
    cout << "\nAltura de la piramide = " << getaltura();
    cout << "\nApotema de la base = " << apotemaBase();
    cout << "\nApotema de la piramide = " << apotema();
    cout << "\nArea de la base (hexagono) = " << areaBase();
    cout << "\nArea del triangulo lateral = "<< areaTrianguloLateral();
    cout << "\nArea lateral = " << areaLateral();
    cout << "\nArea total de la piramide = " << areaTotal();
    cout << "\nVolumen de la piramide = " << volumen ();
    cout << "\n______________________________________\n";
    
    }
