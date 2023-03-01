#include <iostream>
#include <cmath>
using namespace std;

// declaramos las funciones a utilizar 
void circulo();
void elipse();
void cardioide();
int menu();

int main() {
    int go=1;
    /* manejamos la ejecucion del programa con cilo whille y una variable go 
     la cual dice si es programa debe detenerse o no */
    while (go < 5) {
        /* usamos un swith para manejar la opcion que llegue del menu 
        esat opcion sera ingresada por el isuario */
        switch (menu()) {
            case 1: circulo();
            break;
            case 2: elipse();
            break;
            case 3: cardioide();
            break;
            case 4: go=5;
            break;
            default: cout << "\n\n\tERROR EN OPCION";
        }
    }
    return 0;
}

/* se le solicita al usuario la opcion que deces probar*/
int menu() {
    cout << "\n\n\t*** CALCULO DE AREA Y PERIMETRO ***";
    cout << "\n de que figura deseas calcular ?";
    cout << "\n1. circulo";
    cout << "\n2. elipse";
    cout << "\n3. cardioide";
    cout << "\n4. Salir de menu";
    cout << "\n\n\tEscoja opcion: ";

    int op;
    do
    {
        cout<<"ingresa una opcion:";cin>>op;
        if (op>4 || op<1)
        {
            cout<<" opcion ingresada no valida!!! \n porfavor ingresarla nuevamente \n";
        }
    } while (op>5 || op<1);
    return op;
}

// funcion que calcula el area y perimetro del circulo
void circulo(){
    float r;

    cout<<"\n calculo del area y perimetro del Corculo \n";
    cout<<" radio :";cin>>r;

    float area = M_PI *  pow(r, 2);
    float perimetro = 2*M_PI*r;

    cout<<"\n Resultados "<<endl;
    cout<<" Area : "<<area<<endl;
    cout<<" Perimetro : "<<perimetro<<endl;
}

// funcion que calcula el area y perimetro de la elipse
void elipse(){
    float r1,r2;

    cout<<"\n calculo del area y perimetro del elipse \n";
    do
    {
        cout<<" semieje r1 :";cin>>r1;
        cout<<" semieje r2 :";cin>>r2;

        if (r1>r2)
        {
            cout<<"\n el valor de r1 debe ser menor al de r2 \n";
        }
        
    } while (r1>r2);
    
    float area = M_PI * r1 * r2; ;
    float perimetro = M_PI*(3 * (r1 + r2) - sqrt((3*r1 + r2)*(r1 + 3*r2)));

    cout<<"\n Resultados "<<endl;
    cout<<" Area : "<<area<<endl;
    cout<<" Perimetro : "<<perimetro<<endl;
}

// funcion que calcula el area y perimetro del cardiloide
void cardioide(){
    float r;

    cout<<"\n calculo del area y perimetro del Cardiolde \n";
    cout<<" radio :";cin>>r;

    float area = 6 * M_PI * pow(r, 2);
    float perimetro = 16*r;

    cout<<"\n Resultados "<<endl;
    cout<<" Area : "<<area<<endl;
    cout<<" Perimetro : "<<perimetro<<endl;
}