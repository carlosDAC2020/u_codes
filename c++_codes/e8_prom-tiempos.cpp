/*
enunciado
evalauacion de un atleta para la prueba se 5 km
tomando su tiempo potr varios dias 

condiciones
- no haga en ninguna de las pruebas un tiemmpo mayor a 16 m
- que en al menos una de las pruebas realice un tiempo mayor a 16 m
- que su proemdio de tiempo sea menor a 15 m
*/
#include <iostream>
using namespace std;

int main(){
    int tiempo,sum_tiempos=0,may_16m=0;
    float promedio;

    cout<<"tosm de tiempos\n";

    for (int i=1;i<=5;i++){
        cout<<"tiempo dia "<<i<<":";cin>>tiempo;
        sum_tiempos+=tiempo;
        if(tiempo>16){
            may_16m+=1;
        }
    }

    promedio = sum_tiempos / 5 ;
    if( promedio<15 || may_16m==0){
        cout<<"el atleta es apto!!!";
    }
    else{
        cout<<"el atleta no es apto:(";
    }

    return 0;
}