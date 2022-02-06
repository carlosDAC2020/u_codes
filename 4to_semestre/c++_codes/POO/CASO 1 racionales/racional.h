#ifndef RACIONAL_H
#define RACIONAL_H

class Racional{
  public:
  Racional(int =0, int=1);
  void imprime();
  void getnum(int);
  void getden(int);
  Racional suma(Racional &);
  Racional resta(Racional &);
  Racional multiplicacion(Racional &);
  Racional divicion(Racional &);
  private:
  int num,den;
};
#endif // RACIONAL_H