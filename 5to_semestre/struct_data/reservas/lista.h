#ifndef LISTA_H
#define LISTA_H
#include <iostream>
using namespace std;

struct nodoV {
  string codigo;
  string ciudad;
  int cupos;
  bool estado;
  struct nodoV *sigV, *antV;
};
struct nodoR {
  string cedula;
  string nombre;
  string codigoV;
  bool lista;
  struct nodoR *sigR, *antR;
};

class lista {
public:
  lista();
  void pedirDatosVuelos();
  void entrarDatosVuelos(string, string, int, bool);
  void pedirDatosReservas();
  void entrarDatosReservas(string, string, string, bool);
  void modificarCuposVuelos();
  void modificarEstadoVuelo();
  int validarVuelos(string);
  void imprimirReservas();
  void imprimirListaEspera();
private:
  struct nodoV *primV, *ultmV, *nuevoV;
  struct nodoR *primR, *ultmR, *nuevoR;
};

#endif