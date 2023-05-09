#include "binario.h"

int main()
{
    binario n1(79);
    binario n2(369);
    binario n3;

    cout << "\nn1 es " << n1;
    cout << "\nn2 es " << n2;
    cout << "\nn3 es " << n3;

    n3 = n1 + n2;
    cout << "\n\n" << n1 << " + " << n2 << " = " << n3;

    cout << "\n\n";

    return 0;
}
