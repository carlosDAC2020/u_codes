/*
Suponga que una empresa tiene 7 sucursales distribuidas en el país.
 Y en cada sucursal hay un equipo de 5 vendedores. Cada vez que un vendedor 
 en una sucursal concreta una venta, debe reportarla al sistema de información, 
 informando el valor total de la venta efectuada, con el fin de que el sistema 
 llevar la cuenta del volumen total de ventas acumulado de cada vendedor en el mes. 
 Escriba un programa en C++ que permita llevar el control de esta información y al final del mes, 
 se deben producir los siguientes resultados: <

a. Cual fue la sucursal que produjo más ingresos
b. Cual fue el vendedor que tuvo un mayor acumulado de ventas.
c. Cual es el valor total de las ventas en cada sucursal

NOTA
en este caso usaremos un vector de estructuras para gyardar los datos de los vendedores
y de dicho vector obtendremos los datos de salida

*/
#include<iostream>
using namespace std;

const int m=7; // numero de sucursales

// estructura para obtener los datos de los vendedores
struct venderor{
    string nombre;
    float acum_ventas=0; // acumulado de ventas 
};


void ingreso_vendedores(venderor arr[][m], int filas, int columnas ){  // ingreso de los nombres de los vendedores
    // variable para el nombre del vendedor  
    string name;
	for (int c=0; c<columnas; c++){
        cout<<"\n vendedores de la sucursal "<<c+1<<" \n";
		for (int f=0; f<filas; f++){
            cout<<" vendedor"<<f+1<<" : ";cin>>name;
			arr[f][c].nombre=name;
		}
	}
}


void venta(venderor arr[][m], int filas, int columnas){ // informe de una venta
    cout<<"\n INFORME DE VENTA ------------------------------------------------------------- \n";
    int suc;
    // solicitamos el local en cual trabaja y validamos 
    cout<<" numero sucursales en la caul vende :";cin>>suc;
    suc-=1;
    while (suc<0 || suc>6){
        cout<<" numero de sucursal incorrecto!! \n";
        cout<<" ingrese el numero de sucursal nuevamente:";cin>>suc;
    }
    // sabiendo la sucursal a la cual pertenece el vendedor pasamos a validar cual de los 5 vendedores de la sucursal es
    cout<<"\n cual de los vendedores de la sucursal "<<suc+1<<" esta reportando la venta?\n";
	cout<<" id | vendedor \n";
	for(int i=0; i<filas; i++){
		cout<<""<<i+1<<"   | "<<arr[i][suc].nombre<<endl;
	}
    int ven;
    cout<<" ingrese el id del vendedor que reporta la venta:",cin>>ven;
    ven-=1;
    while (ven<0 || ven>4){
        cout<<" id no valido !! \n";
        cout<<" ingrese el id del vendedor nuevamente:";cin>>suc;
    }
    // tenemos la sucursal y el vendedor  solo falta solicitar el monto de la venta y añadirlo al acumulado del vendedor 
    float vent_a;
    cout<<"\n hola "<<arr[ven][suc].nombre<<"!! :)\n";
    cout<<" cuanto es el monto de la venta a reportar:";cin>>vent_a;
    arr[ven][suc].acum_ventas+=vent_a;
}

void suc_may_ingreso(venderor arr[][m], int filas, int columnas ){ // sucursal con mayor cantidad de ingresos 
    int suc; // variable para almacenar el numero de la sucursal con mayor ganacia 
    float ingre_mayor=-1; // variable que almacema los mayores ingreso de una sucursal

    int sum_ingre; // variable para la sumatoria del monto de cada vendedor por sucursal

	for (int c=0; c<=columnas-1;c++){
		sum_ingre=0; // esta variabke ira sumamdo el acumulado de las ventas de cada vendedor de una sucursal 
		for (int f=0; f<=filas-1; f++){
			sum_ingre+=arr[f][c].acum_ventas; // realizamos la sumatoria 
		}
        if (sum_ingre>ingre_mayor){ 
            /* obtenemos la sucursal con mayor ingreso usando al compara
            el valor de las sumatorias delos ingreos de cada sucursal 
            viendo cal es mayor, y guardando en una variable auxiliar 
            el valor de la sucursal con dicho ingreso mayor */
            ingre_mayor=sum_ingre;
            suc=c+1;
        }
	}
    cout<<"\n la sucursal "<<suc<<" obtuvo la mayor ganancia en el mes con "<<ingre_mayor<<"$ de ingresos :)\n";
}

void vendedor_may_acum_ventas(venderor arr[][m], int filas, int columnas ){ // vendedor con mayor acumulado de ventas 
    string vdor; // almacena al vendedor con mayor acumuldo de ventas
    float may_acum_ventas=-1; // almacena el mayor acumulado de ventas de los vendedores
    for (int c=0; c<=columnas-1;c++){ 
		for (int f=0; f<=filas-1; f++){
            // evaluamos con un if cual vendedor obtuvo mayor acumulado 
            if (may_acum_ventas<arr[f][c].acum_ventas){ 
                vdor=arr[f][c].nombre;
                may_acum_ventas=arr[f][c].acum_ventas;
            }
        }
	}
    cout<<"\n "<<vdor<<" fue quien obtuvo el mayor acumulado de ventas este mes con "<<may_acum_ventas<<"$ de ingresos :)\n";
}

void val_total_ventas_x_sucursal(venderor arr[][m], int filas, int columnas ){ //valor total de ventas en cada sucursal
    int sum_ingre; // variable para la sumatoria del monto de cada vendedor por sucursal
    int v_t_vents_x_suc[7];
	for (int c=0; c<=columnas-1;c++){
		sum_ingre=0; // esta variabke ira sumamdo el acumulado de las ventas de cada vendedor de una sucursal 
		for (int f=0; f<=filas-1; f++){
			sum_ingre+=arr[f][c].acum_ventas; // realizamos la sumatoria 
		}
        v_t_vents_x_suc[c]=sum_ingre;
	}

    cout<<"\n  valor total de ventas en cada sucursal \n";
    cout<<"                   |";
    for(int i=0; i<columnas; i++){
		cout<<" sucursal "<<i+1<<" |";
	}
    cout<<"\n ingresos totales |";
    for(int i=0; i<columnas; i++){
		cout<<"    "<<v_t_vents_x_suc[i]<<"    ";
	}
    
}



int main(){
    // declaramos una matriz que guardara los datos de los vendedores de cada sucursal
    venderor datos_sucursales[5][m];
    // en esta matriz las files representan los vendedores y las colubnas las sucrsales 
    cout<<"\n ingresom de los integraten de los vendedores de cada sucursal";
    ingreso_vendedores( datos_sucursales, 5, 7 );

    int reportar; // dice si se quiere o no reportar una venta 
    int concluir=0; // dice si si se conlcuye o no el mes de ventas 
    while( concluir!=1){
        cout<<"\n\n control de ventas \n";
        cout<<" desea reportar una venta ?\n -- 1 para si\n --!=1 para no\n";
		cout<<" elija su opcion:";cin>>reportar;
        if(reportar==1){
            venta(datos_sucursales, 5, 7 );
        }
        cout<<"\n ya concluyo un mes de trabajo? \n -- 1 para si\n --!=1 para no\n";
        cout<<" elija su opcion:";cin>>concluir;
    }
    

    // imprecion de los datos ingresados
	cout<<"\n informe de ventas en el mes \n";
    for (int x = 0; x < 7; x++){
        cout<<"\n sucursal "<<x+1<<endl;
        cout<<"----------------------------------------\n";
	    cout<<" id | vendedor    |  acumulado de ventas \n";
	    cout<<"----------------------------------------\n";
	    for(int i=0; i<5; i++){
		    cout<<" "<<i+1<<"  | "<<datos_sucursales[i][x].nombre<<"           "<<datos_sucursales[i][x].acum_ventas<<endl;
	    }
	    cout<<"----------------------------------------\n";
	    cout<<endl;
    }
    // informacion de salida 
        // sucursal con mas ingresos
    suc_may_ingreso( datos_sucursales, 5,7 );
        //vendedor con mayor acumulado de ventas
    vendedor_may_acum_ventas( datos_sucursales, 5,7 );
        //valor total de ventas en cada sucursal 
    val_total_ventas_x_sucursal( datos_sucursales, 5,7 );

    return 0;
}
