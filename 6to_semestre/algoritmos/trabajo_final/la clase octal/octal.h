#ifndef OCTAL_H
#define OCTAL_H

#include <iostream>
using namespace std;

class octal {
  friend ostream& operator<<(ostream& os, const octal&);
public:
    octal(long = 0);
    octal operator+(const octal& op2) const;
private:
    int oct[11];
};

#endif // OCTAL_H

