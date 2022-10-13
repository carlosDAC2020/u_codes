
#include <iostream>
using namespace std;

int main (){
	int go=1, n_cliente=0, recaudo_empresa=0, pago_compra, tipo_cable, cant_mt;
    int cant_A=0, cant_B=0, cant_C=0;
    int cant_cl_mas_100mt=0;
    int venta_max=0, venta_min=9999;
    int dto;
    float pago_neto, sum_desc_pago=0;
    string name_cliente;

    while (go==1)
    {
        cout<<"\n venta "<<n_cliente+1<<"------------------------"<<endl;
        cout<<"nombre cliente: ";cin>>name_cliente;
        do
        {
            cout<<"\n tipo de cable"<<endl;
            cout<<"1-> A"<<endl;
            cout<<"2-> B"<<endl;
            cout<<"3-> C"<<endl;
            cout<<" digite el numero del tipo deseado:";cin>>tipo_cable;
            if (tipo_cable<1 || tipo_cable>3)
            {
                cout<<" solo se hay opciones del 1 al 3!!"<<endl;
            }
            
        } while (tipo_cable<1 || tipo_cable>3);
        
        do
        {
            cout<<" cantidad de metros:";cin>>cant_mt;
            if (cant_mt<0)
            {
                cout<<"ERROR ingrese la cantidad nuevamente!!\n";
            }
        } while (cant_mt<0);

        // cantidad de clientes que compraron mas de 200 metros
        if (cant_mt>=100)
        {
            cant_cl_mas_100mt+=1;
        }
        

        // pagos netos 
        // descuentos 
        // valores de compra
        // cantidad e metros por cada cable 
        switch (tipo_cable)
        {
        case 1:
            cant_A+=1;
            pago_compra = cant_mt*1000;
            if (cant_mt>100)
            {
                pago_neto = pago_compra - (pago_compra*0.1);
                dto=10;
                sum_desc_pago+=pago_compra*0.2;
            }
            
            break;
        case 2: 
            cant_B+=1;
            pago_compra = cant_mt*2000;
            if (cant_mt>100)
            {
                pago_neto = pago_compra - (pago_compra*0.2);
                dto=20;
                sum_desc_pago+=pago_compra*0.2;
            }
            
            
            break;
        case 3:
            cant_C+=1;
            pago_compra = cant_mt*3000;
            pago_neto = pago_compra;
            dto=0;
            break;
        default:
            break;
        }
        recaudo_empresa+= pago_neto;

        cout<<" nombre del cliente:"<<name_cliente<<endl;
        cout<<" valor de la compra es: "<<pago_compra<<endl;
        cout<<" descuento del : "<<dto<<"%"<<endl;
        cout<<" valor neto a pagar: "<<pago_neto<<endl;

        // ventas maximas y minimas 
        if (pago_neto>venta_max)
        {
            venta_max=pago_neto;
        }

        if (pago_neto<venta_min)
        {
            venta_min=pago_neto;
        }
        

        do
        {
            cout<<"\n\n hay mas ventas por reportar? \n 1->si \n 0->no \n";
            cout<<" dijite su opcion:";cin>>go;
            if (go<0 || go>1)
            {
                cout<<" ingrese valores entre de 0 o 1 \n";
            }
            
        } while (go<0 || go>1);
        n_cliente+=1;
    }
    
    cout<<"\n informacion general de las ventas \n";
    cout<<" total metrospor tipo de cable :"<<endl;
    cout<<" A: "<<cant_A<<endl;
    cout<<" B: "<<cant_B<<endl;
    cout<<" C: "<<cant_C<<endl;	
    cout<<" recaudo: "<<recaudo_empresa<<endl;	
    cout<<" valor promedio dejado de percibir por descuentos: "<<sum_desc_pago/n_cliente<<endl;	
    cout<<" maximo valor cancelado: "<<venta_max<<endl;	
    cout<<" minimo valor cancelado : "<<venta_min<<endl;	
    float porcent_cl_mas_100mt=(cant_cl_mas_100mt/n_cliente)*100;
    cout<<" porcentaje de clientes que compraron mas de 100 metros de cable:"<<porcent_cl_mas_100mt<<endl;
}