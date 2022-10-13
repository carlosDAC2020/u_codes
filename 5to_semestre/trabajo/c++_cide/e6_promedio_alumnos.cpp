#include <iostream>
using namespace std;


// prototipos de funciones que utilizaremos
void preguntar(float &, float &, float &, int );
void aprobado_o_reprobado(float, int &, int &);


int main() {
    // declaramos las variables a utilizar
    float n_parcial, n_quizes, n_trabajos, n_final, prom_genral, sum_notas=0;
    int n_estudiantes, cant_aprobados=0, cant_reprobados=0;

    // preguntamos la cantodad de estudiantes a evaluara al usuario
    cout<<" a cuantos estudiantes desea evaluar:";cin>>n_estudiantes;

    for (int i = 1; i <= n_estudiantes; i++)
    {   
        // preguntamos la snotas al usuario
        preguntar(n_quizes, n_trabajos, n_parcial, i);

        // obtenemos la nota final
        n_final = (n_quizes*0.3) + (n_trabajos*0.3) + (n_parcial*0.5);

        // vamos suman do las notas para obtener el promedio general 
        sum_notas+=n_final;

        cout<<"\n la nota final del estudiante fue de:"<<n_final<<endl;

        // decimos si el estudiante aprobo o reprobo 
        aprobado_o_reprobado(n_final, cant_aprobados, cant_reprobados);

        cout<<"\n------------------------------------------------";
    }

    // obtenemos el promedio genral de las notas finales 
    prom_genral = sum_notas/n_estudiantes;

    cout<<"\n DARTOS GENERALES ";
    cout<<"\n cantidad de estudiantes aprobados:"<<cant_aprobados;
    cout<<"\n cantidad de estudiantes reprobados:"<<cant_reprobados;
    cout<<"\n promedio genral de notas :"<<prom_genral;
    
   
    return 0;
}

// pregunta las notas a los usuarios y las valida 
void preguntar(float &n1, float &n2,  float &n3, int i){
    cout<<"\n estudiante "<<i<<endl;
        do
        {
            cout<<" nota de quizes:";cin>>n1;
            if (n1<0 || n1>5)
            {
                cout<<" ingresar una nota entre 0 y 5 \n";
            }
        } while (n1<0 || n1>5);
        do
        {
            cout<<" nota de trabajos:";cin>>n2;
            if (n2<0 || n2>5)
            {
                cout<<" ingresar una nota entre 0 y 5 \n";
            }
        } while (n2<0 || n2>5);

        do
        {
            cout<<" nota del parcial :";cin>>n3;
            if (n3<0 || n3>5)
            {
                cout<<" ingresar una nota entre 0 y 5 \n";
            }
        } while (n3<0 || n3>5);
}


// nos dice si un estudiante aprobo o reprobo una materia 
void aprobado_o_reprobado(float n, int &cant_ap, int &cant_rp){
    if (n>3.0)
    {
        cout<<"\n el estudiante aprobo la materia";
        cant_ap+=1;
    }
    else{
        cout<<"\n el estudiante reprobo la materia";
        cant_rp+=1;
    }
}