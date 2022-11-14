#include <iostream>
using namespace std;

int main() {
    int  N=4, conta; 
    float nota[4][3], sumadefi, promG;
    string cod[4],nom[4];

    
    for (int e=0; e<N; e++) {
        cout<<" Estudiante "<<e+1<<endl;
        cout << "Codigo: "; cin >> cod[e];
        cout << "Nombre: "; cin >> nom[e];
        cout << "Nota 1: "; cin >> nota[e][0];
        cout << "Nota 2: "; cin >> nota[e][1];
    }
        
    sumadefi = 0;
    cout << "Codigo    Definitiva: " << endl;
    for (int e=0; e<N; e++) {
        nota[e][2]=(nota[e][0]+nota[e][1])/2;
        sumadefi = sumadefi + nota[e][2];
        cout << cod[e] << "   " << 
        nota[e][2] << endl;
    }
    promG=sumadefi/N;
    cout << "Promedio del grupo==> " << promG << endl;
    conta = 0;
    for (int e=0; e<N; e++) {
        if (nota[e][2]>=promG) {
        conta = conta + 1;
        }
    }
    cout << "Numero de estudiantes con (nota[e][2] >=promG) ==> " << conta << endl;
    return 0;
}