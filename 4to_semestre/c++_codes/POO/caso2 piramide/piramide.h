#ifndef PIRAMIDE_H
#define PIRAMIDE_H

class Piramide{
  public:
    Piramide();
    void imprime();
    void setaltura(float);
    void setlado(float);
    float getaltura();
    float getlado();
    float base();
    float area_triangulos();
    float area_lateral();
    float area_total();
    float volumen();
  private:
    float altura,lado;
};

#endif // RACIONAL_H