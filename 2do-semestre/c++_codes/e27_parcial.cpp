/*
parcial 1

ejercicio 1
1.	Elabore un programa en C++ que reciba 6 números enteros y 
diga cuales son pares y cuales no. Además, calcule el promedio 
del conjunto números pares y el conjunto de los números impares y 
devuelve cual conjunto tiene mayor promedio si el de los números 
pares o el de los números impares. 
*/
/*
#include <iostream>
using namespace std;

void add_data(int &num){// funcion para solicitar un numero
    cout<<" ingrese un numero : ";cin>>num;
}

bool par_impar(int num){ // evaluar si un numero es par o impar 
	if(num%2==0){
		cout<<" el numero es par \n";
		return true;
	}
	else{
		cout<<" el numero es impar \n";
		return false;
	}
}

int main(){
    int numero, sum_pares=0, sum_impares=0, cant_pares=0, cant_impares=0 ;
    float prom_pares, prom_impares;
    for(int i=1; i<=6; i++){
        cout<<"\n dsto "<<i<<endl;
        add_data(numero);
        if(par_impar(numero)==true){
            sum_pares+= numero;
            cant_pares+=1;
        }
        else{
            sum_impares+= numero;
            cant_impares+=1;
        }
    }
    // obtenemos los promedios
    cout<<" promedios\n";
    prom_pares= sum_pares/cant_pares;
    prom_impares= sum_impares/cant_impares;
    if(prom_pares > prom_impares){
        cout<<"promedio mayor es el de los pares: "<<prom_pares<<endl;
        cout<<"promedio menor es el de los impares: "<<prom_impares<<endl;
    }
    else{
        cout<<"promedio mayor es el de los impares: "<<prom_impares<<endl;
        cout<<"promedio menor es el de los pares: "<<prom_pares<<endl;
    }
    return 0;
}
//----------------------------------------------------------------------------------------------
*/

/*
ejercicio 2
a eléctrica consumida en un inmueble depende de la cantidad de electrodomésticos 
que se tengan y del tiempo de uso de los mismos. Dicha energía se suele medir en 
Kilovatios/hora. (kW/h). Un kW/h representa la energía consumida por un aparato 
que tiene una potencia de 1 kW (1 kW = 1000 Watios) durante una hora de trabajo 
continuo. Es decir que 1kW/h = 1000 w/h

A medida que se usan los electrodomésticos, el contador de energía va acumulando
la potencia que entrega y con base en ese registro la empresa de energía factura
cada mes el valor que se debe pagar, multiplicando los kW/h consumidos por la tarifa
aplicable por cada kW/hora. Se utilizan Tarifas del kW/h distintas para predios de uso 
residencial y para predios de uso comercial.

 Escriba un programa en C++ para calcular el valor a pagar al final del
  mes por consumo de energía en un predio, si se conocen los siguientes datos:
•	Valor (tarifa) por cada kW/h en instalaciones residenciales
•	Valor (tarifa) por cada kW/h en instalaciones comerciales
•	Tipo de uso del predio: 1= residencial 2= comercial
•	Cantidad de electrodomésticos y/ aparatos que consumen energía 
•	Y Por cada uno de esos electrodomésticos se conoce: 
        	Potencia del aparato (expresada en Watios) 
        	Tiempo total que el aparato estuvo trabajando durante el mes (expresado en horas)


*/

/*
#include <iostream>
using namespace std;

void add_data_f(float &num){// funcion para solicitar un dato
    cout<<"-->";cin>>num;
}
void add_data_i(int &num){// funcion para solicitar un dato
    cout<<"-->";cin>>num;
}


int main(){
    float tarifa_res, tarifa_com, tarifa_cobrar, wH, sum_wH=0, cobro_total, potencia_electrs;
    int tipo_predio, cant_electrs, h_trabajo_electrs;

    cout<<" ingreso de tarifas de cobro\n";
    cout<<" perdio residencial ";add_data_f(tarifa_res);
    cout<<" perdio comercial ";add_data_f(tarifa_com);
    
    cout<<"\n ingreso de datos del cliente";
    cout<<" tpo de predio \n 1 residencial \n 2 comercial \n ";add_data_i(tipo_predio);
    while(tipo_predio<1 || tipo_predio>2){
        cout<<"\n valor ingresado incorrecto!\n";
        cout<<" ingrese el tipo de predio  nuevamente ";add_data_i(tipo_predio);
    }
    if(tipo_predio==1){
        tarifa_cobrar=tarifa_res;
    }
    else{
        tarifa_cobrar=tarifa_com;
    }
    cout<<" cantidad de electrodomesticos en uso ";add_data_i(cant_electrs);

    cout<<"\n\n ingreso de datos de los electrodomesticos \n";
    for(int i=1; i<=cant_electrs; i++){
        cout<<"\n electrodomestico "<<i<<endl;
        cout<<" potencia en Watios ";add_data_f(potencia_electrs);
        cout<<" horas de trabajo ";add_data_i(h_trabajo_electrs);
        wH= potencia_electrs * h_trabajo_electrs;
        sum_wH+= wH;
    }
    cobro_total= sum_wH * tarifa_cobrar;

    cout<<" el valor total a pagar debe ser de :"<<cobro_total<<"$";
    
    
    cout<<"       0 0 0 0   0           \n";
	cout<<"      0         0 0          \n";
	cout<<"     0         0   0         \n";
	cout<<"      0       0     0        \n";
	cout<<"       0 0 0 0 0 1 0 0       \n";
	cout<<"            0         0      \n";
	cout<<"           0           0    \n";

    return 0;
}
*/