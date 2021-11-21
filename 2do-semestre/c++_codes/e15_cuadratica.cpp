
#include <iostream>
#include<math.h>
using namespace std;

int main(){
    float a,b,c, D=0, x1=0, x2=0 ;
    string go;
    do{
        cout<<"\n\n calculemos las raices de una ecuacion cuadratica\n";
        cout<<"Digite el valor de a: "; cin>>a;
        cout<<"Digite el valor de b: "; cin>>b;
        cout<<"Digite el valor de c: "; cin>>c;
        
        
        D=(b*b) - (4*a*c);
        
        if (D >= 0.0 && a != 0.0){
            x1 = (-b + (sqrt(D))) / (2*a);
            x2 = (-b - (sqrt(D))) / (2*a);
            cout << "\nEsta ecuacion tiene dos raices reales:";
            cout << "\nx1 = " << x1;
            cout << "\nx2 = " << x2;
        }
        else{
            if (D < 0){
                cout << "\nEsta ecuacion tiene raices imaginarias…";
            }
            else if (a == 0){
                x1 = -c / b;
                cout << "\nNo aplica. Es una linea recta…";
                cout << "\nx = " << x1;
            }
        }
        cout<<"\n\n desea probar el programa nuvamente? \n si o no: ";cin>>go;
    }
    while(go=="si" || go=="SI");
    
    
    return 0;
}