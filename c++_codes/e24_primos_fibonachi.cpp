#include <iostream>
using namespace std;

bool n_primo(int num){ // evaluar si un numero es primo o no
	if (num==2){
		return true;
	}
	for (int i=2; i<num; i++){
		if(num%i==0){
			return false;
		}
	}
	return true;
}

int main(){
    // declaramos variables
    int p1=0;
    int p2=1;
    int p3;
    bool go=false;
    bool es_primo;
    cout<<"\n numero primos de la secuencia de fibonacci menores que 10000";
    
    while(go==false){
        // obtenemos los valores de la serie
        p3 = p1 + p2; // los valores de la serie de fibonacci se obtienen sumando los dos ultimos numeros de la serie 
        
        // evaluamos si el numero es primo o no 
        es_primo=n_primo(p3);
        if(es_primo==true){
            cout<<"\n--"<<p3;
        }

        // ordenamos los valores de las dos ultimas posiciones de la serie para poder obtener el siguente valor
        p1 = p2;
        p2 = p3;

        if (p3>10000){
            break;
        }
    }
    return 0;
}
