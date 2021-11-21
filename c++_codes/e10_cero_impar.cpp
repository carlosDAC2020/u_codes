/*
enunciado
en una lista de n elementos combertir los elementos impares en cero 
*/
#include <iostream>
using namespace std;

int main(){
    // declaramos variables
    int n,valor;
    cout<<" ingresa cantidad de elementos de la lista:";cin>>n;
    int nums[n];

    // incecion de elementos a la lista
    for(int i=0; i<=n-1;i++){
        cout<<"ingresa un valor:";cin>>valor;
        nums[i]=valor;
    }
    // impresion de la lista 
    cout<<"\n\nlista inicial"<<endl;
    for(int i=0; i<=n-1; i++){
        cout<<nums[i]<<" ";
    }
    // imprecion de lista con valores impares cambiados a cero
    cout<<"\n\nlista final"<<endl;
    for(int i=0; i<=n-1; i++){
        if(nums[i]%2!=0){
            nums[i]=0;
            cout<<nums[i]<<" ";
        }
        else{
            cout<<nums[i]<<" ";
        }
    }
    return 0;
}