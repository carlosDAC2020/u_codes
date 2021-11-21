#include <iostream>
#include <string>
using namespace std;

int main(){
    int sum,i;
    cout<<" suma de los num ero del uno al 100 que sean multplos de 7 y 11";
    
    int op;
    cout<<"\n cual bucle dsea usar para resolverlo\n1 para for\n2 para while\n -->";cin>>op;
    while(op<1 || op>2){
        cout<<"\n\n valor ingresano no valido";
         cout<<"\n cual bucle dsea usar para resolverlo nuevamente\n -->";cin>>op;
    }
    if(op==1){
         for (i=1; i<=100; i++){
            if( (i%7==0) || (i%11==0)){
                sum+=i;
            }
        }
        cout<<" con for la suma es igual a "<<sum;
    }
    else{
        i=1;
         while (i<=100){
            if( (i%7==0) || (i%11==0)){
                sum+=i;
            }
            i+=1;
        }
        cout<<" con whille la suma es igual a "<<sum;
    }
    return 0;
}