#include <iostream>
using namespace std;

// funcion para añadro datos a la lista
void add_datos_lista(string arr[], int n){
    for (int i=0; i<n; i++){
        cout<<"---> ";cin>>arr[i];
    }
} 
// alubmnos matriculados en mabas asignaturas 
void almnos_2_materias(string c[], string p[], string arr_aux[], int n_c, int n_p, int n_c_p){
    int posicion=0;
    for(int i=0; i<n_c_p; i++){
        for(int j=0; i<n_c_p; i++){
             if(c[i]==p[j]){
                arr_aux[i]=p[j];
                posicion+=1;
            }
        }
    }
    
    cout<<"\n codigos de estudiantes inscritos en las dos materias \n";
    for (int i = 0; i <posicion; i++){
        cout<<"->"<<arr_aux[i]<<endl;
    }
}

// matriculados en materia x pero no en materia y
void calculo_no_programacion(string xy[], string x[], string x_n_y[], int nxy, int nx){
    int posicion=0;
    for( int i=0; i<nxy; i++){
        for(int j=0; j<nx; j++){
            if(xy[i]!=x[j]){
                x_n_y[posicion]=x[j];
                posicion+=1;
            }
        }
    }

    for (int i = 0; i <=posicion; i++){
        cout<<"->"<<x_n_y[i]<<endl;
    }
}

int main(){
    // variables a utilizar
    int n_calculo, n_programacion;
    cout<<" cantidad de estudiants en calculo:";cin>>n_calculo;
    string l_calculo[n_calculo];
    cout<<" cantidad de estudiants en programcion:";cin>>n_programacion;
    string l_programacion[n_programacion];

    // ingresamos los datos a la lista
    cout<<"\n lista de codigos matriculados en calculo \n";
    add_datos_lista(l_calculo, n_calculo);
    cout<<"\n lista de codigos matriculados en programcion \n";
    add_datos_lista(l_programacion, n_programacion);

    // procedimiento para obtener los datos solivitados 
    int mcp=n_programacion+n_calculo;
        // punto A : alubmnos matriculados en mabas asignaturas 
    string l_alumnos_2_materias[mcp];
    almnos_2_materias(l_calculo, l_programacion, l_alumnos_2_materias, n_calculo, n_programacion, mcp);
       
        // punto B : natriculados en calculo pero no en programacion
    string l_calculo_no_prog[mcp];
    cout<<"\n\n natriculados en calculo pero no en programacion \n",
    calculo_no_programacion(l_alumnos_2_materias, l_calculo, l_calculo_no_prog, mcp, n_calculo);
       
        // punto C :matriculados en programcion pero no en calculo
    string l_prog_no_calculo[mcp];
    cout<<"\n\n matriculados en programcion pero no en calculo \n";
    calculo_no_programacion(l_alumnos_2_materias, l_programacion, l_prog_no_calculo, mcp, n_programacion);
    
    return 0;
}