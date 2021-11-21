/*
enunciado
promedio de un numero desconocido de estiudiantes
*/
#include <iostream>
using namespace std;

int main(){
    int op,est=1,suma=0;
    float nota ;
    bool go=true;
    cout<<"promedio de un numero desconocido de estudiantes"<<endl;
    while(go==true){
        cout<<"estudiante"<<est<<endl;
        cout<<"nota:",cin>>nota;
        suma+=nota;
        cout<<"\n ay otro estudiante con nota?\n->1 si\n->2 no\n numero de la opcion:";cin>>op;
        if(op==1){
            est+=1;
        }
        else{
            go=false;
        }
    cout<<"\n promedio de notas es igual a:"<<suma/est;
    }
    return 0;
}