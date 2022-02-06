#ifndef PIRAMIDE_H
#define PIRAMIDE_H

class Piramide{
  public:
    Piramide( float=0, float=1);
    void imprime();
    void getaltura(float);
    void getlasdo_base(float);
  private:
    float altura,lado_base;
};
#endif // RACIONAL_H