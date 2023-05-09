#ifndef BINARIO_H
#define BINARIO_H

#include <iostream>
using namespace std;

class binario{
    friend ostream &operator<<(ostream &, const binario &);
public:
    binario(long = 0);
    binario operator+(const binario &) const;
private:
    short bin[40];
};

#endif // BINARIO_H
