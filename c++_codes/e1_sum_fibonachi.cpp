/* enunciados
calcule la suma de los terminos de la serie de FIBONACCI
cuyos valores se encuentran entrre 100 y 10,000 
*/
#include <iostream>
using namespace std;

int main(){
    // declaramos variables
    int p1=0;
    int p2=1;
    int p3;
    int sum_e=0;
    bool go=false;
    cout<<"valores del la serie de finonacci entre 100 y 10,000"<<endl;
    while(go==false){
        // obtenemos los valores de la serie
        p3 = p1 + p2; // los valores de la serie de fibonacci se obtienen sumando los dos ultimos numeros de la serie 
        
        if((p3>=100) && (p3<=10000)){
            cout<<"--"<<p3<<endl;
            sum_e+=p3; // si se cumple la condicion se va realisando la suma de los valores 
        }

        // ordenamos los valores de las dos ultimas posiciones de la serie para poder obtener el siguente valor
        p1 = p2;
        p2 = p3;

        if (p3>10000){
            break;
        }
    
    }
    cout<<"el valor de la suma de los numeros de la serie de fibonacci que estan entre 100 y 10000 es de:"<<sum_e;
    return 0;
}
