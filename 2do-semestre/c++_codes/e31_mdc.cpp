#include<iostream>
#include<cmath>
using namespace std;


// funcion para solicitar los datos 
void almacenar_val(int arr[], int cant){
    for(int i=0; i<cant; i++){
        cout<<"Ingrese las edades del usuario "<<i<<" :"<<endl;
        cin>>arr[i];
    }
}

// funcion para hallar la media aritmetica
void media(int arr[], int cant){
	int sum_edades=0;
	float medi_a;
	for(int i=0; i<cant; i++){
		sum_edades+=arr[i];
	}
	medi_a=sum_edades/cant;
	cout<<"\n la media aritmetica o promedio de las edades es de: "<<medi_a<<endl;
}

// desviacion estandar
void desviacion_estandar(int arr[], int cant){
	// para hallar la desviacion estandar primero encontramos el promedio
	int sum_edades=0;
	float medi_a;
	for(int i=0; i<cant; i++){
		sum_edades+=arr[i];
	}
	medi_a=sum_edades/cant;

	// ahora si procedemos a encontrar la desviacion estandar
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
	cout<<"\n la desviacion estandar de las edades es igaul a: "<<desv_estdr<<endl;

}


// moda o dato que mas se repite
/*void moda(int arr[], int cant){
	
	cout<<"\n edad| se repite \n";
	for(int i=0 ;i<cant; i++){
		cout<<" "<<arr[i]<<" | "<<repite[i]<<endl;
	}

	int mod_a=arr[0];
	int rep=-10;
	for(int i=0; i<cant; i++){
		if(rep < repite[i]){
			rep=repite[i];
			mod_a=arr[0];
		}
	}
	cout<<" la moda de las edades es: "<<mod_a<<endl;
}
*/

int main(){
    int cantidad;
    int inicio;
    int calculo;
	
    
    
    
    cout<<"¿Quiere activar el programa de calculo de edades?\n1.) Iniciar\n2.) Desactivar"<<endl;
    cin>>inicio;
    //Se declara el inicio del ciclo del programa
    while(inicio == 1){
    //se almacenan las edades    
        cout<<"Bienvenido al programa calculo de edades, elija la cantidad de edades que desea almacenar"<<endl;
        cout<<"Digite cuantas edades tomara"<<endl;
        cin>>cantidad;
		// matriz que almacenara las edades
		int edades[cantidad];
        
        almacenar_val(edades, cantidad);
		
        
    //Se toma la eleccion de que proceso calcular
        cout<<"¿Que problema quiere resolver?\n1.) Media aritmetica\n2.) Desviacion estandar\n3.) Edad que mas se repite"<<endl;
        cin>>calculo;
		while(calculo<=0 || calculo>3){
			cout<<"\n valor ingresado no valido!\n";
			cout<<" ingrese su opcion nuevamente: ";cin>>calculo;
		}
        
    //Calculo de la media aritmetica
        if(calculo == 1){
            media(edades, cantidad);
            break;
        }
    //Calculo desviacion estandar
        else if(calculo == 2){
            desviacion_estandar(edades,cantidad);
            break;
        }
    
    //Calculo edad que mas se repite
        else{
            //moda(edades, cantidad);
            break;
        }
        
        
        cout<<"¿Quiere volver a iniciar el programa?\n1.) Iniciar\n2.) Desactivar"<<endl;
        cin>>inicio;
    }
    
    if(inicio == 2){
        cout<<"Desactivando programa...."<<endl;
    }
    
    
    
    return 0;
}