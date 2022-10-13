#include <iostream>
using namespace std;

void mayor_menor(float est[][2]){
    float n_mayor=0, code_mayor=0;
    float n_menor=99999, code_menor=0;
    for (int f = 0; f < 5; f++)
    {
            // mayor nota 
        if(n_mayor < est[f][1]){
            n_mayor = est[f][1];
            code_mayor = est[f][0];
        }
            // menor nota 
        if(n_menor > est[f][1]){
            n_menor = est[f][1];
            code_menor = est[f][0];
        }
    }

    cout<<"\n estudiante con mayor nota \n";
    cout<<" codigo:"<<code_mayor<<endl;
    cout<<" nota:"<<n_mayor<<endl;

    cout<<"\n estudiante con menor nota \n";
    cout<<" codigo:"<<code_menor<<endl;
    cout<<" nota:"<<n_menor<<endl;
}
    
void promedio(float est[][2]){

    float sum_notas=0;
    for (int f = 0; f < 5; f++)
    {
       sum_notas+=est[f][1];
    }
    cout<<"\n el promedio del curso es de :"<<sum_notas/5<<endl;
}

void est_reprobados_aprobados(float est[][2]){
    cout<<"\n codigos de estudiantes aprobados \n";
    for (int f = 0; f < 5; f++)
    {
       if (est[f][1]>=3.0)
        {
            cout<<est[f][0]<<endl;
        }
    }

    cout<<"\n codigos de estudiantes reprobados \n";
    for (int f = 0; f < 5; f++)
    {
       if (est[f][1]<3.0)
        {
            cout<<est[f][0]<<endl;
        }
    }

}

int main(){
    float estudiantes[5][2];
    int cant_ap=0, cant_rp=0;
    int cant_mb=0, cant_bn=0, cant_suf=0, cant_insuf=0;

    cout<<" ingreso de notas \n";
    for(int i=0;i<5;i++){
        cout<<" estudiante "<<i+1<<"--------------------"<<endl;
        cout<<" codigo :";cin>>estudiantes[i][0];
        cout<<" nota :";cin>>estudiantes[i][1];
        cout<<" desempeño: ";
        if (estudiantes[i][1]>= 4.0 && estudiantes[i][1]<= 5.0){
            cout<<" muy bien "<<endl;
            cant_mb+=1;
        }
        
        else if (estudiantes[i][1]>= 3.0 && estudiantes[i][1]< 4.0){
            cout<<" bien "<<endl;
            cant_bn+=1;
        }
            
        else if (estudiantes[i][1]>= 2.0 && estudiantes[i][1]< 3.0){
            cout<<" suficiente"<<endl;
            cant_suf+=1;
        }
                  
        else{
            cout<<" insuficiente"<<endl;
            cant_insuf+=1;
        }
            

        if (estudiantes[i][1]>=3.0)
        {
            cant_ap+=1;
        }
        else{
            cant_rp+=1;
        }
    }
   

    cout<<"\n datos generales \n";
    mayor_menor(estudiantes);
    promedio(estudiantes);

    cout<<"n cantidad de estudiantes\n";
    cout<<" aprobados: "<<cant_ap<<endl;
    cout<<" reprobados: "<<cant_rp<<endl;
    
    est_reprobados_aprobados(estudiantes);

    cout<<"\n cantidades en las categorias de desempeño:\n";
    cout<<" muy bien: "<<cant_mb<<endl;
    cout<<" bien: "<<cant_bn<<endl;
    cout<<" suficiente: "<<cant_suf<<endl;
    cout<<" insuficiente: "<<cant_insuf<<endl;


    return 0;
}
    
