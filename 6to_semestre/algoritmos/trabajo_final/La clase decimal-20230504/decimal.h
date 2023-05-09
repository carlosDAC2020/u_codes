#ifndef DECIMAL_H
#define DECIMAL_H

#include <iostream>
using namespace std;

class decimal
{
public:
    friend ostream &operator<<(ostream &, const decimal &);
public:
    decimal(long = 0);
    decimal operator+(const decimal &) const;
private:
    short dec[30];
};

#endif // DECIMAL_H
