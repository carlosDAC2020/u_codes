#include <iostream>
using namespace std;

struct estudiante{
    char codigo [10];
    char nombre [10];
    char apellido [10];
    int sexo ;
    int edad;
    int estado_civil;

    };


int main (){
    int n;
    cout<<" datos de estudiantes \n";
    cout<<" ingrese cantidad de estudiantes a evaluar: ";cin>>n;
    while(n<5){
        cout<<" ingrese mas de 5 estudiantes a evaluar \n";
        cout<<" ingrese cantidad de estudiantes a evaluar nuevamente: ";cin>>n;
    }
    estudiante n_estudiantes[n];


    // solicitamos datos
    for(int i=0; i<n; i++){
        cout<<"--------------------------------- \n";
        cout<<" ingrese datos datos de persona "<<i+1<<endl;

        cout<<"ingrese el codigo:";
        cin>>(n_estudiantes[i].codigo);
        cout<<"ingrese el nombre:";
        cin>>(n_estudiantes[i].nombre);
        cout<<"ingrese el apellido:";
        cin>>(n_estudiantes[i].apellido);
        cout<<"ingrese el sexo \n   1 = femenino \n   2 = masculino \n --> ";
        cin>>(n_estudiantes[i].sexo);
        while(n_estudiantes[i].sexo<1 || n_estudiantes[i].sexo>2){
            cout<<" ERROR!! \n";
            cout<<" didjite nuevmente el valor del sexo:";cin>>(n_estudiantes[i].sexo);
        }
        cout<<"ingrese el edad:";
        cin>>(n_estudiantes[i].edad);
    }
    
    // imprecion de datos 
    for(int i=0; i<n; i++){
        cout<<"--------------------------------- \n";
        cout<<" datos de persona "<<i+1<<endl;
        cout<<"codigo:"<<n_estudiantes[i].codigo<<endl;
        cout<<"nombre:"<<n_estudiantes[i].nombre<<endl;
        cout<<"apellido:"<<n_estudiantes[i].apellido<<endl;
        cout<<"sexo:"<<n_estudiantes[i].sexo<<endl;
        if(n_estudiantes[i].sexo==1){
            cout<<" femennino \n";
        }
        else{
            cout<<" masculino \n";
        }
        cout<<"edad:"<<n_estudiantes[i].edad<<endl;
    }

    // obtenemos datos estadisticos
        // cantidades
    int cantidad_mayores=0, cantidad_menores=0;
        // promedio
    int sum_edades_mayores=0, sum_edades_menores=0 sum_edades_total=0;
    float prom_edades_mayores, prom_edades_menores, prom_edades_total;


    for(int i=0; i<n; i++){
        // cantidad y promedio de edades de menores de edad
        if(n_estudiantes[i].edad<18){
            cantidad_menores+=1;
            sum_edades_menores+=n_estudiantes[i].edad;
        }
        // cantidad y promedio de edades de mayores de edad
        if(n_estudiantes[i].edad>=18){
            cantidad_mayores+=1; 
            sum_edades_mayores+=n_estudiantes[i].edad;
        }
       
        // promedio de edades totales 
        sum_edades_total+=n_estudiantes[i].edad;
    }
    // sacamos promedios
    prom_edades_total= sum_edades_total/n;
    prom_edades_menores= sum_edades_menores/cantidad_menores;
    prom_edades_mayores= sum_edades_mayores/cantidad_mayores;
    
    // imprimimos los datos estadisticos
    cout<<"\n datos de salida \n";
    cout<<" cantidad de estudiantes mayores de edad: "<<cantidad_mayores<<endl;
    cout<<" cantidad de estudiantes menores de edad: "<<cantidad_menores<<endl;
    cout<<" promedio de edades de mayores de edad: "<<prom_edades_mayores<<endl;
    cout<<" promedio de edades de menores de edad: "<<prom_edades_menores<<endl;
    cout<<" promedio de edades totales: "<<prom_edades_total<<endl;
    
    

    return 0;
}