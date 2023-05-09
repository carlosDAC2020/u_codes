#ifndef OCTAL_H
#define OCTAL_H

#include <iostream>
using namespace std;

class octal {
public:
    octal(int decimal = 0);
    octal operator+(const octal& op2) const;
    friend std::ostream& operator<<(std::ostream& os, const octal& n);

private:
    char oct[100];
};

#endif // OCTAL_H
