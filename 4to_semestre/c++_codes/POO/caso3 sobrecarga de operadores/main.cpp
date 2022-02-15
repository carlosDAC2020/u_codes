#include "racional.h"

int main()
{
    racional A, B, C;

    cin >> A;
    cin >> B;

    cout << "\n\n" << A;
    cout << "\n\n" << B;
    cout << "\n\n" << C;
    C = A + B;
    cout << "\n\n";
    cout << A << " + " << B << " = " << C;
    C = A - B;
    cout << "\n\n";
    cout << A << " - " << B << " = " << C;
    C = A * B;
    cout << "\n\n";
    cout << A << " * " << B << " = " << C;
    cout <<"\n\n";
    return 0;
}
