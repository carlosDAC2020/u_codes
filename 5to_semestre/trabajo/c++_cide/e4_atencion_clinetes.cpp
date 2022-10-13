#include <iostream>
using namespace std;


int main() {
   int n_clientes, tipo_producto, nplatillos, np_tipo_1=0, np_tipo_2=0, np_tipo_3=0, np_tipo_4=0, np_tipo_5=0  ;
   int  precio_factura=0, total_facturas=0, mayor_factura=-1, aux;
   float promedio_facturas;
   string name_cliente, name_clinet_mayor_factura; 

   cout<<" cantidad de personas a aye¿tender:";cin>>n_clientes;

   for (int i = 1; i <= n_clientes; i++)
   {    
    cout<<" ingreso de datos del cliente "<<i<<endl;
    cout<<" nombre:";cin>>name_cliente;
    cout<<" cantidad de platillos a ordenar:";cin>>nplatillos;
    for (int p = 1; p <= nplatillos; p++)
    {
        cout<<"\n platillos que puede ordenar ";
        cout<<"\n 1 sopa : 6000";
        cout<<"\n 2 corrientazo:12000";
        cout<<"\n 3 postre: 5000";
        cout<<"\n 4 limonada: 4000";
        cout<<"\n 5 ensalada: 3000";
        do
        {
            cout<<" ingrese el numero del platillo que desea:";cin>>tipo_producto;
            if (tipo_producto<1 || tipo_producto>5)
            {
                cout<<" \n porducto ingresado ex inexistente\n porfa ingresar nuevamente\n";
            }
            
        } while (tipo_producto<1 || tipo_producto>5);
        
        switch (tipo_producto)
        {
            case 1:
                np_tipo_1+=1;
                precio_factura+=6000;
                break;
            case 2:
                np_tipo_2+=1;
                precio_factura+=12000;
                break;
            case 3:
                np_tipo_3+=1;
                precio_factura+=5000;
                break;
            case 4:
                np_tipo_4+=1;
                precio_factura+=4000;
                break;
            case 5:
                np_tipo_5+=1;
                precio_factura+=3000;
                break;
            
            default:
                break;
        }
    }
    cout<<"\n factura del cliente "<<name_cliente;
    cout<<"\n valor a pagar:"<<precio_factura;

    total_facturas+=precio_factura;

    if (precio_factura>mayor_factura)
    {
        mayor_factura=precio_factura;
        name_clinet_mayor_factura=name_cliente;
    }
   }

    cout<<"\n informacion general de ventas "<<endl;

    cout<<" cantidad de productos vendidados por cada tipo ",
    cout<<"\n 1 sopa :"<<np_tipo_1;
    cout<<"\n 2 corrientazo:"<<np_tipo_2;
    cout<<"\n 3 postre:"<<np_tipo_3;
    cout<<"\n 4 limonada:"<<np_tipo_4;
    cout<<"\n 5 ensalada:"<<np_tipo_5;

    cout<<"\n cliente con la factura mas cara";
    cout<<"\n nombre:"<<name_cliente;
    cout<<"\n precio:"<<mayor_factura;
   
    return 0;
}

