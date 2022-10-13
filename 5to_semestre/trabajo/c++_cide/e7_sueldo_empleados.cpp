#include <iostream>
using namespace std;

// funcion que retorna el promedio de una lista
float proms(float arr[], int n){
    float sum_s=0;
    for (int i = 0; i < n; i++)
    {
        sum_s+=arr[i];
    }
    return sum_s/n;
}



int main() {
    // solicitamos la cantidad de empleados a evaluar 
    int n;
    do
    {
        cout<<" ingrese la cantidad de empleados:";cin>>n;
        if (n<0 || n>50)
        {
            cout<<"la cantidad de empleados deberia ser de (1 <= n <= 50) !!!\n";
        }
        
    } 
    while (n<0 || n>50);
    
    // declaramos las listas a utilizar 
    string id[n];
    int grupo[n];
    float sueldo[n], nuevo_sueldo[n], prom_s;

    // solicitamos los datos a los empleaods 
    for (int i = 0; i < n; i++)
    {
        cout<<"\n empleado "<<i+1<<" -------------------"<<endl;
        
        cout<<" ID :";cin>>id[i];
        do
        {
            cout<<" grupo :";cin>>grupo[i];
            if (grupo[i]<1 || grupo[i]>2)
            {
                cout<<" el grupo debe ser 1 o 2 !!!\n";
            }
        } 
        while (grupo[i]<1 || grupo[i]>2);
        
        do
        {
            cout<<" sueldo :";cin>>sueldo[i];
            if (sueldo[i]<1)
            {
                cout<<" no ingresar valores inferios a 1 !!! \n";
            }
        } 
        while (sueldo[i]<1);
        
        // asignamos el aumento de sueldo correspondiente 
        if (grupo[i]==1)
        {
            nuevo_sueldo[i] = sueldo[i] + 250000;
        }
        else{
            nuevo_sueldo[i] = sueldo[i] + 150000;
        }
    }
    cout<<"\n datos actuales de los empleados \n";
    cout<<"--------------------------------------\n";
	cout<<"      id   |   grupo   |   sueldo    |  \n";
	cout<<"--------------------------------------\n";
    for(int i=0; i<n; i++){
        cout<<"    "<<id[i]<<"     | "<<grupo[i]<<"    |      "<<sueldo[i]<<endl;
    }
    cout<<"----------------------------------------\n";
    
    
    // obtenemos el promedio de los nuevos sueldos
    prom_s = proms(nuevo_sueldo, n);

    // revisamos si a algun empleado se cambiara de grupo
    int cant_empl_g1_al_g2=0; // contador de los empleados que cambiaran de grupo
    float sueldos_g1[n];
    int can_g1=0;
    for (int i = 0; i < n; i++)
    {
        if ( (nuevo_sueldo[i]>prom_s) && grupo[i]==1 )
        {
            grupo[i]=2;   
            cant_empl_g1_al_g2+=1;
        }
        // obetenmos una lsiat de los sueldos de los empleados del grupo 1
        // para obtener su promedio posteriormente
        if (grupo[i]==1)
        {
            sueldos_g1[i] = nuevo_sueldo[i];
            can_g1+=1;
        }
        
    }

    // imprimimos los resultados 
    cout<<"\n datos de los empleados despues de aplicar el aumento \n";
    cout<<"--------------------------------------------\n";
	cout<<"      id   |   grupo   |   nuevo sueldo    |  \n";
	cout<<"--------------------------------------------\n";
    for(int i=0; i<n; i++){
        cout<<"    "<<id[i]<<"     | "<<grupo[i]<<"    |      "<<nuevo_sueldo[i]<<endl;
    }
    cout<<"--------------------------------------------\n";
    cout<<" promedio de los neevos sueldos :"<<prom_s;
    cout<<" promedio de los sueldos del grupo 1:"<<proms(sueldos_g1,can_g1 );
   cout<<" cantidad de empleados que pasaron del grupo 1 al 2:"<<cant_empl_g1_al_g2;
    return 0;
}
