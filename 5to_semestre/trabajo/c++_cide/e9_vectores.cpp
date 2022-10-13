#include <iostream>
using namespace std;


int main() {
    // declaramos el arreglo A
    int arrA[10]={8, 3, 6, 50, 42, 35, 29, 33, 12, 5 };
    
    // declaramos y llenamos el arreglo B
    int n;
    do
    {
        cout<<"\n cantidad de elemntos a ingresar en el arreglo B:";cin>>n;
        if (n<1)
        {
            cout<<"no puede ingresar valores inferiores a 1 !!";
        }
    } while (n<1);
    int arrB[n];
    cout<<"\n inresa numeros al arreglo B ";
    for (int i = 0; i < n; i++)
    {
        cout<<"\n arr["<<i<<"] = ";cin>>arrB[i];
    }
    


    // declaramos el arreglo C
    string arrC[7]={"Carlos", "Sebastian", "Antonio", "Jesus", "Antonio", "Antonio", "Luis"};

    // imprimimos los arreglos 
    cout<<"\n arreglo A \n";
    int may_nun_arrA=0;
    for (int i = 0; i < 10; i++)
    {
        cout<<arrA[i]<<" ";
        if (arrA[i]>may_nun_arrA)
        {
            may_nun_arrA=arrA[i];
        }
    }
    cout<<"\n el mayor numero del arreglo A es : "<<may_nun_arrA<<endl;
    
   cout<<"\n arreglo B \n";
   int sum_elmt_arrB=0;
    for (int i = 0; i < n; i++)
    {
        cout<<arrB[i]<<" ";
        sum_elmt_arrB+=arrB[i];
    }
    float prom_arrB = sum_elmt_arrB/n;
    cout<<"\n el promedio del arreglo B es : "<<prom_arrB<<endl;

    cout<<"\n arreglo C \n";
    int n_antonio=0, n_luis=0, n_sebastian=0, n_carlos=0, n_jesus=0;
    for (int i = 0; i < 7; i++)
    {
        cout<<arrC[i]<<" ";
        
        if (arrC[i]=="Carlos")
        {
            n_carlos+=1;
        }
        else if (arrC[i]=="Sebastian")
        {
            n_sebastian+=1;
        }
        else if (arrC[i]=="Antonio")
        {
            n_antonio+=1;
        }
        else if (arrC[i]=="Jesus")
        {
            n_jesus+=1;
        }
        else if (arrC[i]=="Luis")
        {
            n_luis+=1;
        }
    }
    cout<<"\n cuantas veces se repiten los nombres en el arreglo C \n";
    cout<<"Carlos: "<<n_carlos<<endl;
    cout<<"Sebastian: "<<n_sebastian<<endl;
    cout<<"Antonio: "<<n_antonio<<endl;
    cout<<"Jesus: "<<n_jesus<<endl;
    cout<<"Luis:"<<n_luis<<endl;
        
   cout<<"\n remplazamos en el arreglo A los numero mayores a 5 por cero \n";
   cout<<"\n arreglo A \n";
    for (int i = 0; i < 10; i++)
    {
        if (arrA[i]>5)
        {
            arrA[i]=0;
        }
        cout<<arrA[i]<<" ";
    }
    return 0;
}
