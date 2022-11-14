#include <iostream>
using namespace std;

int main() {
    // declaramos listas y contadores
    int num=1, i_par=0,i_impar=0;
    int par[100], impar[100];

    int sum_pares=0, sum_impares=0;

    // 
    while (num!=0)
    {
        cout<<"\n ingrese un numero: ";cin>>num;

        if (num%2==0)
        {
            par[i_par]=num;
            i_par+=1;
            sum_pares+=num;
        }
        else{
            impar[i_impar]=num;
            i_impar+=1;
            sum_impares=num;
        }
    }

    cout<<"\n\n  lista de pares \n";
    for (int i = 0; i < i_par; i++)
    {
        cout<<" "<<par[i];
    }

    float prom_pares = sum_pares/i_par;
    cout<<"\npromedio de numeros pares:"<<prom_pares;

    cout<<"\n\n lista de impares \n";
    for (int i = 0; i < i_impar; i++)
    {
        cout<<" "<<impar[i];
    }
    float prom_impares = sum_impares/i_impar;
    cout<<"\npromedio de numeros impares:"<<prom_impares;
    
    return 0;
}