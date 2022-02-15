#ifndef RACIONAL_H
#define RACIONAL_H

#include <iostream>
using namespace std;

class racional {
    friend ostream &operator<<(ostream &, const racional &);
    friend istream &operator>>(istream &, racional &);
public:
    //Objeto
    racional();
    //Métodos
    racional operator+(const racional&) const;
    racional operator-(const racional &) const;
    racional operator*(const racional &) const;

private:
    int num;
    int dem;

};

#endif // RACIONAL_H
