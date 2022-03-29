#include "operario.h"

int menu(){
    int op;
    cout << "\n\tGRUPO DE INVESTIGACION ";
    cout << "\n\t\t\tMENU" << endl;
    cout << "\n1. ingreso de datos de los operarios .";
    cout << "\n2. En pantalla datos de los operarios.";
    cout << "\n3. bonificacion total pagada en el proyecto.";
    cout << "\n4. nomina totatl pagada en rpyecto.";
    cout << "\n5. Salir";
    cout << "\n\nEscoga una opcion:";cin>>op;
    while(op<1 || op>5){
        cout<<" valor ingresado no valido \n";
        cout<<" ingrese su opcion nuevamente:";cin>>op;
    }
    return op;
}

int main() {

    // variables para el numero de dias de trabajo y cantidad de operarios 
    int dias_trabajo, num_operarios;

    // cramos la lista de operarios 
    vector <operario> trabajadores(100);

    // ingreso de datos 
    cout<<" datos del trabajo!! \n";
    cout<<" ingresa la cantodad de operarios:";cin>>num_operarios;
    do{
        cout<<" ingresa la cantodad de dias del proyecto:";cin>>dias_trabajo;
        if(dias_trabajo<8 || dias_trabajo>30){
            cout<<" numero de dias ingresados no valido \n";
        }
    }
    while(dias_trabajo<8 || dias_trabajo>30);
    

    int go=1;
    while(go==1){
        switch(menu()){
            case 1:
                // ingreso de datos de los operarios
                obtenerDatos(num_operarios, dias_trabajo, trabajadores);
            break;
            case 2:
                // impresion de los datos de operarios
                imprimirOperarios(num_operarios, trabajadores);
            break;
            case 3:
                // bonificacion total pagada en el proyecto
                cout<<"\nla bonificacion total a pagar en el proyecto fue de :"<<bonificacionTotal(num_operarios, trabajadores)<<"$ \n";
            break;
            case 4:
                // nomina total pagada en le proyecto
                cout<<"\nla nomina total a pagar en el proyecto fue de :"<<nominaTotal(num_operarios, trabajadores)<<"$ \n";
            break;
            case 5:
                go=0;
            break;
            default:
                cout<<"error";
        }
    }
    
  return 0;
}