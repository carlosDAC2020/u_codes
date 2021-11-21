#include <iostream>
#include <string>
using namespace std;

int main(){
    // declaracion de variables a utilizar 
    int sexo, estado, anio, i=1;
    int h_solteros=0, m_solteras=0, h_casados=0, m_casadas=0 ;
    int p_no_votan=0;
    string go="si";

    do{
        cout<<"persona "<<i;
        cout<<"\n año de nacimiento --> ";cin>>anio;
        int va=2021 - anio;
        if(va>=18){
             cout<<"\n\n ingrese su sexo\n 1=masculin\n 2=femenino\n --> ";cin>>sexo;
            while(sexo<1 || sexo>2){
                cout<<"\n valor ingresado herroneo";
                cout<<"\n ingrese su sexo nuevamente: ";cin>>sexo;
            }
            cout<<"\n\n ingrese su estado civl\n 1=soltero\n 2=casado\n --> ";cin>>estado;
            while(estado<1 || estado>2){
                cout<<"\n valor ingresado herroneo";
                cout<<"\n ingrese su estado civil nuevamente: ";cin>>estado;
            }
            if(sexo==1){
                if(estado==1){
                    h_solteros+=1;
                }
                else{
                    h_casados+=1;
                }
            }
            else{
                if(estado==1){
                    m_solteras+=1;
                }
                else{
                    m_casadas+=1;
                }
            }
        }
        else{
            p_no_votan+=1;
        }
        i+=1;
        cout<<"\n hay mas personas por preguntar? si/no: ";cin>>go;
    }
    while(go=="si" || go=="SI");

    cout<<"\n datos generales de la encuesta";

    cout<<"\n\n personas que pueden votar";
    cout<<"\n hombres -----------------------";
    cout<<"\n hombres solteros:"<<h_solteros;
    cout<<"\n hombres casados:"<<h_casados;
    cout<<"\n mujeres -----------------------";
    cout<<"\n mujeres solteros:"<<m_solteras;
    cout<<"\n mujeres casadas:"<<m_casadas;

    cout<<"\n\n totales----------------------";
    cout<<"\n personas solteros:"<<m_solteras+h_solteros;
    cout<<"\n personas casadas:"<<m_casadas+h_casados;
    cout<<"\n total de personas:"<<m_casadas+m_solteras+h_casados+h_solteros;

    cout<<"\n\n total de personas que no votan:"<<p_no_votan;


    return 0;
}