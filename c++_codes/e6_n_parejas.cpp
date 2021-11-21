/*
enunciado
ingresar n parejas de numeros y decir si es mayor o menor y si son iguales
*/
#include <iostream>
using namespace std;

int main(){
    int n, n1, n2;
    cout<<"ingresa el numero de parejas:";cin>>n;
    for(int i=1; i<=n; i++){
        cout<<"--------------------"<<endl;
        cout<<"pareja "<<i<<endl;
        cout<<"   n1=";cin>>n1; 
        cout<<"   n2=";cin>>n2;
        if(n1>n2){
            cout<<"   "<<n1<<">"<<n2<<endl;
        }
        else if(n1<n2){
            cout<<"   "<<n1<<"<"<<n2<<endl;
        }
        else{
            cout<<"   "<<n1<<"="<<n2<<endl;
        }
    }
  
    return 0;
}