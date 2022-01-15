/* 
caso de estudio de nomina
*/
#include <iostream>
# include <stdlib.h>
#include <math.h>
using namespace std;

int main(){
    // declaramos variables a utiñlizar 
    string nombre, apellido;
    float salario_hora;
    float horas_ordinarias, horas_extra;

    // solicitamos datos al usuario
    cout<<" nomina de un trabajador\n";
    cout<<" cslculemos el salario neto a pagar a de mas de la retencion en la fuente\n";
    cout<<"\n ingrese los siguienyes datos\n";
    cout<<" nombre: ";cin>>nombre;
    cout<<" apellido: ";cin>>apellido;
    cout<<" salario por hora: ";cin>>salario_hora;
    cout<<" horas de trabajo ordinario: ";cin>>horas_ordinarias;   
    cout<<" horas extra: ";cin>>horas_extra;

    // asi calculamos el salrio neto y la retecion en fuente
    float pago_horas=0, pago_horas_extras=0, valor_extra=0, salario_neto=0, retencion_fuente=0, salario_total=0;
    
    pago_horas= salario_hora * horas_ordinarias;
    valor_extra= (salario_hora * 0.4) + salario_hora;
    pago_horas_extras= valor_extra * horas_extra;
    salario_neto= pago_horas + pago_horas_extras;
    retencion_fuente= salario_neto * 0.1;
    salario_total= salario_neto - retencion_fuente;

    // imprimimos resultados
    cout<<"\n\n     DATOS DEL EMPLEADO";
    cout<<"\n     nombre:      :"<<nombre;
    cout<<"\n    apellido:     :"<<apellido;
    cout<<"\n  salario neto:   :"<<salario_neto;
    cout<<"\n   ret fuente     :"<<retencion_fuente;
    cout<<"\n  salario total:  :"<<salario_total;


    return 0;
}
