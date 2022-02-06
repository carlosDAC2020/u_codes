#ifndef PIRAMIDE_H
#define PIRAMIDE_H

class Piramide{
  public:
  Piramide( float=0, float=1);
  void imprime();
  void getnum(int);
  void getden(int);
  Racional suma(Racional &);
  private:
  float altura,lado_base;
};
#endif // RACIONAL_H