#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H

#include <iostream>
using namespace std;

class hexadecimal
{
public:
    friend ostream &operator<<(ostream &, const hexadecimal &);
public:
    hexadecimal(long = 0);
    hexadecimal operator+(const hexadecimal &) const;
private:
    char hexa[100];
};

#endif // HEXADECIMAL_H