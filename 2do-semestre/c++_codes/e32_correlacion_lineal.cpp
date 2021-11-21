#include <iostream>
#include<math.h>
using namespace std;

void ingreso_datos(float arr1[], float arr2[],int cant){
	float v1, v2; 

	for (int i=0; i<cant; i++){
        cout<<"\n datos del jugador "<<i+1<<endl;
		cout<<" peso:";cin>>v1;
		arr1[i]=v1;
        cout<<" estaura:";cin>>v2;
        arr2[i]=v2;
	}
}
float media(float arr[], int cant){
	float sum_datos=0;
	float medi_a;
	for(int i=0; i<cant; i++){
		sum_datos+=arr[i];
	}
	medi_a=sum_datos/cant;
	return medi_a;
}

float covarianz_a(float arr1[], float arr2[], float med1, float med2, float cant){
    float xy, sum_xy, covar;

    for(int i=0; i<cant; i++){
        xy= arr1[i]*arr2[i];
        sum_xy= xy;
    }
    covar=(sum_xy/cant)-(med1*med2);
    return covar;
}

float desviacion_estandar(float arr[], float medi_a, int cant){

	float sum_x=0;
	float x;
	float varianza;
	float desv_estdr;
	for(int i=0; i<cant ;i++){ // hallamos la varianza usando un ciclo for 
		x=pow(arr[i]-medi_a,2);
		sum_x+=x;
	}
	varianza=sum_x/cant;
	desv_estdr=sqrt(varianza); // la desviacion estandar es la raiz cuadrada de la varianza
	return desv_estdr;

}

float correlaci_on(float covar, float desv_t_1, float desv_t_2){
    float correl;
    correl = covar / (desv_t_1*desv_t_2);
    return correl;
}

int main(){
    // declaracion y asignacion del tamaño de los vectores 
    int n;
    cout<<" ingresa cantidad de jugadores a evaluar:";cin>>n,
    cout<<"\n";

    // declaracion de vectores 
    float pesos[n], estaturas[n];
    ingreso_datos(pesos,estaturas,n);
    cout<<"\n peso y estatura de los estudiantes \n";
    cout<<"| estudiante| peso  | estatura ! \n";
    for (int i=0; i<n; i++){
        cout<<"   "<<i+1<<"       "<<pesos[i]<<"     "<<estaturas[i]<<endl;
    }

    // hallamos las medias aritmeticas
    float media_peso, media_estatura;
    media_peso=media(pesos,n);
    cout<<" media de los pesos:"<<media_peso<<endl;
    media_estatura=media(estaturas,n);
    cout<<" media estaturas:"<<media_estatura<<endl;

    // hallamos la covarianza
    float covarianza;
    covarianza=covarianz_a(pesos, estaturas, media_peso, media_estatura, n);
    cout<<" covarianza de pesos y estaturas: "<<covarianza<<endl;

    // desviaciones tipicas
    float desv_t_pesos, desv_t_estaturas;
    desv_t_pesos=desviacion_estandar(pesos, media_peso, n);
    cout<<" desviacion estandar de los pesos:"<<desv_t_pesos<<endl;
    desv_t_estaturas=desviacion_estandar(estaturas, media_estatura, n);
    cout<<" desviacion estandar de las estaturas:"<<desv_t_estaturas<<endl;

    // correlacion lineal
    float correlacion;
    correlacion= correlaci_on(covarianza, desv_t_pesos, desv_t_estaturas);
    cout<<" la correlacion de los pesos y las estaturas es de :"<<correlacion<<endl;

    // interpretacion de resultados

    // relacion
    if(correlacion>0){
        cout<<" relacion: positiva \n";
    }
    else if(correlacion<0){
        cout<<" relacion: negativa \n";
    }
    else{
        cout<<" relacion: inexistente \n";
    }
    

    // fuerza de relacion
    if((correlacion<=-1.0 && correlacion<=-0.5)||(correlacion>=0.5 && correlacion<=1.0)){
        cout<<" fuerza de relacion:FUERTE \n";
    }
    else if((correlacion>=-0.5 && correlacion<=-0.3)||(correlacion>=0.3 && correlacion<=0.5)){
        cout<<" fuerza de relacion: MODERADA \n";
    }
    else if((correlacion>=-0.3 && correlacion<=-0.1)||(correlacion>=0.1 && correlacion<=0.3)){
        cout<<" fuerza de relacion: DEBIL \n";
    }
    else if(correlacion>-0.1 && correlacion<0.1){
        cout<<" fuerza de relacion: NINGUNA \n";
    }

    return 0;
}