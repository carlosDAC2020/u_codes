#include <iostream>
using namespace std;

int main(){
    string name, name_may[15], name_men[15];
    int edad;

    for(int i=1; i<=15; i++){
        cout<<"\ningreso de datos \n";
        cout<<" nombre:";cin>>name;
        cout<<" edad:";cin>>edad;

        if(edad>=18){
            name_may[i]=name;
        }
        else{
            name_men[i]=name;
        }
    }
    cout<<"\n mayores de eedad\n";
     for(int i=1; i<=15; i++){
        cout<<name_may[i]<<endl;
    }
    cout<<"\n menores de eedad\n";
     for(int i=1; i<=15; i++){
        cout<<name_men[i]<<endl;
    }



    return 0;
}