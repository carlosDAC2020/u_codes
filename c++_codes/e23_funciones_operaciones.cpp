#include <iostream>
using namespace std;
 
void perdi_datos(float &a, float &b){
  cout<<" ingrese un numero a:";cin>>a;
  cout<<" ingrese un numero b:";cin>>b;
  cout<<endl;
}

float suma(float a, float b){
  float r=a+b;
  return r;
}

float resta(float a, float b){
  float r=a-b;
  return r;
}

float prodcto(float a, float b){
  float r=a*b;
  return r;
}

void cociente(float a, float b){
  if(b==0){
    cout<<"la operación mo se puede ejecutar";
    
  }
  else{
    float r=a/b;
    cout<<" cociente igual a:"<<r;
  }
}





int main(){
    string x="si";
    do{
        float A,B, respuesta=0;
        perdi_datos(A,B);
        int go;
        cout<<"\n\n funciones de operaciones basicas\n\n";
        cout<<"opcines para operar \n 1 sumar\n 2 restar \n 3 multiplicar\n 4 cociente \n >>>";cin>>go;
        
        if(go==1){
            cout<<"suma="<<suma(A,B);
        }
        else if(go==2){
            cout<<"resta="<<resta(A,B);
        }
        else if(go==3){
            cout<<"producto="<<prodcto(A,B);
        }
        else if(go==4){
            cociente(A,B);
        }
        cout<<"\n\n decea usar el programa otra vez ? si/no: ";cin>>x;
    }
    while(x=="si" || x=="SI");
  return 0;
}