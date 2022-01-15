#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente{
  public:
  Cliente(string, string, int =0, int=0, int=0, float=0);
  private:
  string nombre, apellido;
  int edad, clave, n_cuenta;
  float saldo;
};
#endif // RACIONAL_H