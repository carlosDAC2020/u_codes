#ifndef PIRAMIDE_H
#define PIRAMIDE_H

class Piramide{
  public:
    Piramide();
    void imprime();
    void setaltura(float);
    void setlado(float);
    float base();
    float area_triangulos();
    float area_lateral(float);
    float area_total(float,float);
    float volumen(float);
  private:
    float altura,lado;
};
#endif // RACIONAL_H