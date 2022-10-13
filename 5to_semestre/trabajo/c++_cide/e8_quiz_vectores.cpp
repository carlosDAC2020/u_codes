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
    // solicitamos la cantidad de estudiantes a evaluar 
    int n;
    cout<<" ingrese la cantidad de estudiantes:";cin>>n;
       
    // declaramos las listas a utilizar 
    string id[n], names[n];
    float n1[n], n2[n], n3[n], n4[n], n5[n];
    float sum_nts_est=0, prom_nots_generales[n], prom_curso;

    // nota mayor y menor
    string id_not_may, name_not_may, id_not_men, name_not_men;
    float not_may=0, not_men=10;


    cout<<"\n ingreso de datos de los estudiantes \n";
    for (int i = 0; i < n; i++)
    {
        cout<<"\n estudiante "<<i+1<<endl;
        cout<<" codigo: ";cin>>id[i];
        cout<<" nombre: ";cin>>names[i];

        // ingreso y validacion de notas 

        do{
            cout<<" nota 1: ";cin>>n1[i];
            if (n1[i]<0 || n1[i]>5)
            {
                cout<<" las notas ingresadas deben estar entre 0 y 5 \n";
            }
        }
        while (n1[i]<0 || n1[i]>5);
        sum_nts_est+=n1[i];

        do{
            cout<<" nota 2: ";cin>>n2[i];
            if (n2[i]<0 || n2[i]>5)
            {
                cout<<" las notas ingresadas deben estar entre 0 y 5 \n";
            }
        }
        while (n2[i]<0 || n2[i]>5);
        sum_nts_est+=n2[i];

        do{
            cout<<" nota 3: ";cin>>n3[i];
            if (n3[i]<0 || n3[i]>5)
            {
                cout<<" las notas ingresadas deben estar entre 0 y 5 \n";
            }
        }
        while (n3[i]<0 || n3[i]>5);
        sum_nts_est+=n3[i];

        do{
            cout<<" nota 4: ";cin>>n4[i];
            if (n4[i]<0 || n4[i]>5)
            {
                cout<<" las notas ingresadas deben estar entre 0 y 5 \n";
            }
        }
        while (n4[i]<0 || n4[i]>5);
        sum_nts_est+=n4[i];

        do{
            cout<<" nota 5: ";cin>>n5[i];
            if (n5[i]<0 || n5[i]>5)
            {
                cout<<" las notas ingresadas deben estar entre 0 y 5 \n";
            }
        }
        while (n5[i]<0 || n5[i]>5);
        sum_nts_est+=n5[i];
        
        prom_nots_generales[i]= sum_nts_est/5;

        // vamos buscando la menor nota
        if(prom_nots_generales[i]<not_men){
            not_men=prom_nots_generales[i];
            id_not_men=id[i];
            name_not_men=names[i];
        }

        // vamos busacndo la mayor nota 
        if(prom_nots_generales[i]>not_may){
            not_may=prom_nots_generales[i];
            id_not_may=id[i];
            name_not_may=names[i];
        }
    }
    // obtenemos la nota promedio del curso
    prom_curso=proms(prom_nots_generales, n);
    // cantidad de estudiantes con promedio superior al curso 
    int cant_prom_sp=0;

    // imprimimos los resultados 
    cout<<"\n resultados ";
    for (int i = 0; i < n; i++)
    {
        cout<<"\n estudiante "<<i+1<<endl;
        cout<<" codigo: "<<id[i]<<endl;
        cout<<" nombre: "<<names[i]<<endl;
        cout<<" notas \n";
        cout<<" "<<n1[i]<<" "<<n2[i]<<" "<<n3[i]<<""<<n4[i]<<" "<<n5[i]<<endl;
        cout<<" promedio: "<<prom_nots_generales[i]<<endl;

        if (prom_nots_generales[i]>prom_curso)
        {
            cant_prom_sp+=1;
        }
        
    }

    cout<<"\n  NOTA PROMEDIO DEL CURSO:"<<prom_curso<<endl;
    cout<<"\n  CANTIDAD DE ESTUDIANTES CON PROMEDIO SUPERIOR AL PROMEDIO DEL CURSO:"<<cant_prom_sp<<endl;

    return 0;
}





