#include <iostream>
using namespace std;


int main() {
    int tipo, valor_pagar, cant_autos, total_factura=0;
    string placa;

    cout<<" datos de la factura \n";
    cout<<" cantidad de autos arreglados:";cin>>cant_autos;
    for (int i=1; i<=cant_autos; i++){
        cout<<"\n datos del auto "<<i<<endl;
        cout<<" placa: ";cin>>placa;
        do
        {
            cout<<" costo del daño: ";cin>>valor_pagar;
            if (valor_pagar<0)
            {
                cout<<"\n el costo a pagar no puede ser menor a cero \n";
            }
            
        } while (valor_pagar<0);
        
        
        do
        {
            cout<<" tipo de daño: ";cin>>tipo;
            if (tipo<1 || tipo>3)
            {
                cout<<"\n ingresar solo un valor de tipo de 1 a 3 \n";
            }
            
        } while (tipo<1 || tipo>3);
        
        

        // verificamos las reglas del gerente 
        if ((tipo==1 && valor_pagar>1000000) || (tipo==2 && valor_pagar>3000000) || (tipo==3 && valor_pagar>5000000))
        {
            cout<<" el costo no esta en los estandares del gerente \n";
        }
        else{
            cout<<" el costo si esta en los estandares del gerente \nm";
            total_factura+=valor_pagar;
        }
    }

    cout<<" el valor totak a pagar en la facvtura es de :"<<total_factura<<endl;
    
    return 0;
}
