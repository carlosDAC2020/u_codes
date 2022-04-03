#include "empleado.h"
#include "academico.h"
#include "administrativo.h"
#include "servicios.h"

using namespace std;
int menu(){
    int op;
    cout << "\n\t ";
    cout << "\n\t\t\tMENU" << endl;
    cout << "\n1.  .";
    cout << "\n2. .";
    cout << "\n3. .";
    cout << "\n4. ";
    cout << "\n5. Salir";
    cout << "\n\nEscoga una opcion:";cin>>op;
    while(op<1 || op>5){
        cout<<" valor ingresado no valido \n";
        cout<<" ingrese su opcion nuevamente:";cin>>op;
    }
    return op;
}

int main() {

   
    int go=1;
    while(go==1){
        switch(menu()){
            case 1:
                
            break;
            case 2:
                
            break;
            case 3:
                
            break;
            case 4:
                
            break;
            case 5:
                
            break;
            default:
                
        }
    }
    
  return 0;
}