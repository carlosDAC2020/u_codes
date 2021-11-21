#include <iostream>
using namespace std;

// declaramos funcion para solicitar los datos de emtrada al usuario 
void preguntar(float &pe_so, float &esta_tura){
    // al solicitar cada dato los validamos usando un ciclo while 
    cout<<"\n ingrese su pero en Kg: ";cin>>pe_so;
    while(pe_so<0){
        cout<<" valor ingresado incorrecto!\n";
        cout<<"\n ingrese su pero en Kg nuevamente: ";cin>>pe_so;
    }
    cout<<"\n ingrese su estatura en M: ";cin>>esta_tura;
    while(esta_tura<0){
        cout<<" valor ingresado incorrecto!\n";
        cout<<"\n ingrese su estatura en M nuevamente: ";cin>>esta_tura;
    }
}

// declaramos funcion para calcular ICM
float ICM (float &pe_so, float &esta_tura){
    // realizamos el calculo aplicando la formula proporcionada en el enunciado
    float icm= pe_so / (esta_tura*esta_tura);
    // retornamos el valor del resultado 
    return icm;
}

int main(){
    // declaramos variables 
    float peso, estatura,i_c_m;
    string go="si";
    do{
        cout<<"\n\n calculemos su ICM ";
        // imvocamos la funcion para solicitar los datos 
        preguntar(peso,estatura);
        // mostramos el resultado del icm invocando la funcion que lo calcula 
        cout<<"\n su ICM es igual a "<<ICM(peso,estatura);
        // mostramos el diagnostico del usuario
        i_c_m=ICM(peso,estatura);
        cout<<"\n el diagnostico del usuario es de ";
        if(i_c_m<18.5){
            cout<<"delgadez";
        }
        else if(i_c_m>=18,5 || i_c_m<=25.5){
            cout<<"peso normal";
        }
        else {
            cout<<"obecidad";
        }
        // preguntamos al usuario si decea seguir calculando los icm de otras personas
        cout<<"\n\n decea calcular el ICM otra vez? si/no";cin>>go;
    }
    while(go=="si" || go=="SI");
 
    return 0;
}
