#include "decimal.h"

int main()
{
    decimal n1(7654321);
    decimal n2(7891234);
    decimal n3;

    cout << "\nn1 es " << n1;
    cout << "\nn2 es " << n2;
    cout << "\nn3 es " << n3;

    n3 = n1 + n2;

    cout << "\n\n" << n1 << " + " << n2 << " = " << n3;

    cout<<"\n\n";

    return 0;
}
