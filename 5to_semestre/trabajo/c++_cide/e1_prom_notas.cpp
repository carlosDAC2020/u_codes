#include <iostream>
using namespace std;

int menu() {
    cout << "\n\n\t*** MENU PRINCIPAL ***";
    cout<< "\n\t1. promedio ponderado";
    cout<< "\n\t2. promedio simple de un curso";
    cout<< "\n\t3. Nota minima para ganar una materia";
    cout<< "\n\t4. Salir del programa";
    
    int op;
    do
    {
        cout<<"\n ingresa una opcion:";cin>>op;
        if (op>4 || op<1)
        {
            cout<<" opcion ingresada no valida!!! \n porfavor ingresarla nuevamente \n";
        }
    } while (op>5 || op<1);
    return op;
}

void promedio_ponderado(){
    
    int cant_materias, sum_creditos=0, sum_n_x_c=0, n_creditos;
    float nota_f, prom_ponderado;
    cout<<" ingresa cantidad de materias a evaluar:";cin>>cant_materias;


    for (int i = 0; i < cant_materias; i++){
        cout<<"\n materia "<<i+1<<endl;
        cout<<" numero de creditos:";cin>>n_creditos;
        sum_creditos+=n_creditos;
        cout<<" nota final:";cin>>nota_f;
        while (nota_f<0 || nota_f>5){
            cout<<"\n valor ingresado herroneo \n";
            cout<<" ingrese la nota final nuevamenete:";cin>>nota_f;
        }
        sum_n_x_c+=nota_f*n_creditos;
    }
    prom_ponderado=sum_n_x_c/sum_creditos;

    cout<<"\n el promedio genral del estudisnte fue de "<<prom_ponderado<<endl;
    
}

void pronmedio_curso(){
    int n_estudiantes;
    float nota,sum_notas=0 ,prom_notas;

    cout<<" ingrese la cantidad de estudiantes:";cin>>n_estudiantes;

    // pedimos notas a estudiantes
    for (int i = 0; i < n_estudiantes; i++)
    {
        do
        {
            cout<<" nota de estudiante "<<i<<":";cin>>nota;
            if (nota<0 ||nota>5)
            {
                cout<<" ingresar una nota entre 0 y 5  \n";
            }
        } while (nota<0 ||nota>5 );

        sum_notas+=nota;
    }
    prom_notas=sum_notas/n_estudiantes;

    cout<<" el promedio del curso es:"<<prom_notas;
    
}

void nota_minima(){
    float n1, n2, n3;
    cout<<"\n nota minima para ganar una materia \n";
    // solicitamos las notas 
    do
    {
        cout<<" Nta del primer corte:";cin>>n1;
       if (n1<0 ||n1>5)
        {
            cout<<" ingresar una nota entre 0 y 5  \n";
        }
    } while (n1<0 ||n1>5 );

    do{
        cout <<"nota del segundo corte:" ; cin>>n2;
        if (n2<0 ||n2>5)
        {
            cout<<" ingresar una nota entre 0 y 5 \n";
            }
    } while (n1<0 ||n1>5 );
    
    n3=(3 - n1*0.3 - n2*0.35)/0.35;

    cout<<" \n la nota minima para ganar la materia es de:"<<n3;

}

int main() {
    int go=1;
    while (go == 1) {
        switch (menu()) {
            case 1: promedio_ponderado();
                break;
            case 2: pronmedio_curso();
                break;
            case 3: nota_minima();
                break;
            case 4: go=0;
                break;
            default: cout << "\n\n\tERROR EN OPCION";
        }
    }
    return 0;
}

