#include <iostream>
using namespace std;

int main(){
    string estado;
    string r_correctas[10]={"D","A","C","A","B","B","E","E","D","A"};
    string r_ingresadas[10]={"D","E","B","A","B","C","E","A","D","A"};
    float nota=0;
    cout<<" evaluacion de examen de opcion mu8ltiple  \n";
    cout<<"------------------------------------ \n";
    cout<<"| respuestas | r_alumno   | estado \n";
    cout<<"------------------------------------ \n";
    for(int i=0; i<10; i++){
        if(r_correctas[i]==r_ingresadas[i]){
            estado="bien";
            nota+=0.5;
        }
        else{
            estado="mal";
        }
        cout<<"| "<<r_correctas[i]<<"          | "<<r_ingresadas[i]<<"          | "<<estado<<"\n";
    }
    cout<<"------------------------------------ \n";
    cout<<"la nota que se obtuvo en el examen fue de :"<<nota;
    
    return 0;
}