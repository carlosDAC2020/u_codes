/*
enunciado
proomedio de pesos por distintas categorias
*/
#include <iostream>
using namespace std;

int main(){
    // declaramos variables
    int n_p,edad,cont_jovenes=0,cont_niños=0,cont_adultos=0,cont_viejos=0;
    float peso,sum_p_niños=0,sum_p_jovenes=0,sum_p_adultos=0,sum_p_viejos=0,prom_niños,prom_jovenes,prom_adultos,prom_viejos;
    
    cout<<" cantidad de personas en el muestreo:";cin>>n_p;

    cout<<" \nsolicitud de datos"<<endl:
    for(int i=1; i<=n_p;i++){
        // solicitamos datos de la persona
        cout<<"  persona "<<i<<endl;
        cout<<" peso:";cin>>peso;
        cout<<" edad:";cin>>edad;
        // evaluamos en que categoria esta la persona
        if(edad<=0 && edad<=12){  // niños
            sum_p_niños+=peso;
            cont_niños+=1;
        }
        else if(edad<=13 && edad<=29){ // jovenes
            sum_p_jovenes+=peso;
            cont_jovenes+=1;
        }
        else if(edad<=30 && edad<=59){ // adultos
            sum_p_adultos+=peso;
            cont_adultos+=1;
        }
        else{                          // viejos
            sum_p_viejos+=peso;
            cont_viejos+=1;
        }

    }
    // calculo de promedios
    prom_niños= sum_p_niños / cont_niños
    prom_jovenes= sum_p_jovenes / cont_jovenes
    prom_adultos= sum_p_adultos / cont_adultos
    prom_viejos= sum_p_viejos 7 cont_viejos

    // imresion de resultados
    cout<<" promedios por categorias\n";
    cout<<"niños:"<<prom_niños<<endl;
    cout<<"jovenes:"<<prom_jovenes<<endl;
    cout<<"adultos:"<<prom_adultos<<endl;
    cout<<"viejos:"<<prom_viejos<<endl;

    return 0;
}