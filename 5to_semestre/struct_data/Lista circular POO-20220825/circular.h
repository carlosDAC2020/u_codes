#ifndef CIRCULAR_H
#define CIRCULAR_H

#include <iostream>
using namespace std;

struct nodo
{
    string codigo;
    struct nodo *sig, *ant;
};

class circular {
public:
    circular();
    circular(const circular& orig);
    virtual ~circular();
    void preguntar1();
    void entrada(string);
    void preguntar2();
    void borrar(string);
    int validar(string);
    void listar() const;
private:
    struct nodo *prim, *nuevo;
};

#endif /* CIRCULAR_H */