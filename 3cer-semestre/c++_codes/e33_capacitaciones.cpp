#include <iostream>
#include<math.h>
using namespace std;


void avilitar(int cant_curs){ // funcion para ver si un curso se puede abrir o no
    if(cant_curs<1){
        cout<<" cerrar";
    }
    else{
        cout<<" avilitar";
    }
}

int main(){
    // declaracion de variables
    int n_solicitudes, edad, sexo, oficio, cod_identificacion, inscripcion, recaudo=0;
    int cant_peluqueria=0, cant_modisteria=0, cant_panaderia=0, sum_edad_modisteria=0;
    float porcen_h, sum_h=0, porcen_m, sum_m=0;
    
    // solicitud de cantidad de solicitudes
    cout<<" cantidad de solicitudes a recibir: ";cin>>n_solicitudes;

    // ingreso de datos de las solicitudes
    for(int i=1; i<=n_solicitudes; i++){
        cout<<"\n solicitud "<<i<<endl,

        cout<<" codigo de identificacion:";cin>>cod_identificacion;

        cout<<" edad: ";cin>>edad;

        cout<<" sexo \n 1->masculino\n 2->femenino\n ------->";cin>>sexo;
        while(sexo<1 || sexo>2){
            cout<<" valor ingresado no valido!!\n";
            cout<<" ingrese su sexo nuevamente:";cin>>sexo;
        }
        // proceso para obtemer el promedio de las mujeres y hombres 
        if(sexo==1){
            sum_h+=1;
        }
        else{
            sum_m+=1;
        }

        cout<<"\n oficio al que se quiere inscribir para capacitarse \n";
        cout<<" 1-> peluqeria \n 2-> modista \n 3-> panadero \n ------->";cin>>oficio;
        while(oficio<1 || oficio>3){
            cout<<" valor ingresado no valido!!\n";
            cout<<" ingrese su oficio de interes nuevamente:";cin>>oficio;
        }
        
        // obtenemos cuota de inscripcion
        if(oficio==1){
            inscripcion=5000;
            cant_peluqueria+=1;
        }
        else if(oficio==2){
            /*inscripcion para modisteria es de (5000-(500*0.2))*2=8000 */
            inscripcion=8000;
            cant_modisteria+=1;
            sum_edad_modisteria+=edad;
        }
        else{
            /*inscripcion para panaderia es de 5000-(500*0.2)=4000 */
            inscripcion=4000;
            cant_panaderia+=1;
        }

        // vamos obteniendo el recaudo todal de las inscripciones 
        recaudo+=inscripcion;
        
    }
    cout<<"\n RESULTADOS ";

    porcen_h=(sum_h/n_solicitudes)*100;
    cout<<"\n porcentaje de hombres:"<<porcen_h;

    porcen_m=(sum_m/n_solicitudes)*100;
    cout<<"\n porcentaje de mujeres:"<<porcen_m;

    cout<<"\n\n estado de los cursos ";
    cout<<"\n peluqueria:";avilitar(cant_peluqueria);
    cout<<"\n modisteria:";avilitar(cant_modisteria);
    cout<<"\n panaderia:";avilitar(cant_panaderia);

    cout<<"\n\n promedio de edades de interesados en modisteria:"<<sum_edad_modisteria/cant_modisteria<<endl;

    cout<<"\n\n dinero recaudado en las inscripciones:"<<recaudo;

    return 0;
}