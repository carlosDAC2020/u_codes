/*
enunciado
 cramos algunas funciones que realicen operaciones 
 bacicas entre vectores
*/
#include <iostream>
using namespace std;


int main(){
    int n,valor;
    cout<<" ingrese cantidad de elementos de las listas:";cin>>n;
    int l_1[n], l_2[n],r_sum[n], r_resta[n], r_producto[n];

    // incecion de elementos a la lista 1
    cout<<"\n\n lista 1\n";
    for(int i=0; i<=n-1;i++){
        cout<<"ingresa un valor:";cin>>valor;
        l_1[i]=valor;
    }
    // incecion de elementos a la lista 2
    cout<<"\n\n lista 2\n";
    for(int i=0; i<=n-1;i++){
        cout<<"ingresa un valor:";cin>>valor;
        l_2[i]=valor;
    }
    int op=1;
    while(op==1){
        cout<<"\n\n escoja una opcion a realizar\n";
        cout<<"--1 suma de vectores\n";
        cout<<"--2 resta de vectores\n";
        cout<<"--3 producto de vectores\n";
        cout<<"--4 promedio de cada uno de los vectores\n";
        cout<<"--5 mayores y menores elementos de cada lista\n";
        int opt;
        cout<<" dijite su opcion:";cin>>opt;
        while(opt>5){
            cout<<"\nopcion dijitada no valida \n dijite su opcion nuevamente:";cin>>opt;
        }

        // evaliuamos que operacion realizar 
        if(opt==1){ // proceso de la suma
            for(int i=0; i<=n-1; i++){
                r_sum[i]= l_1[i] + l_2[i];
            }
            cout<<"\n el vector suma que da como resultado es el siguiente\n";
            for(int i=0; i<=n-1; i++){
                cout<<r_sum[i]<<" ";
            }
        }

        else if(opt==2){ // proceso de la resta
            for(int i=0; i<=n-1; i++){
                r_resta[i]= l_1[i] - l_2[i];
            }
            cout<<"\n el vector resta que da como resultado es el siguiente\n";
            for(int i=0; i<=n-1; i++){
                cout<<r_resta[i]<<" ";
            }
        }

        else if(opt==3){ // proceso del producto
            for(int i=0; i<=n-1; i++){
                r_producto[i]= l_1[i] * l_2[i];
            }
            cout<<"\n el vector producto que da como resultado es el siguiente\n";
            for(int i=0; i<=n-1; i++){
                cout<<r_producto[i]<<" ";
            }
        }

         else if(opt==4){ 
            float prom1, prom2;
            int sum1=0, sum2=0;

             for (int i=0; i<n; i++){
                 sum1+=l_1[i]; // suma de elementos de la lista 1
                 sum2+=l_2[i]; // suma de elementos de la lista 2
            }
            prom1= sum1/n;
            prom2= sum2/n;

            cout<<"\n\n promedios\n";
            cout<<"lista 1:"<<prom1<<"\n";
            cout<<"lista 2:"<<prom2<<"\n";
        }

         else { 
            int may1=l_1[1], may2=l_2[1]; // variables para almacenar los mayores
            int men1=l_1[1], men2=l_2[1]; // variables para almacenar los menores
            
            // mayores 
            for (int i=0; i<n; i++){
                // procedimiento para la lista 1
                if ( may1 < l_1[i] ){ 
                    may1=l_1[i];
                }
                // procedimiento para la lista 2
                if ( may2 < l_2[i] ){ 
                    may2=l_2[i];
                }
            }

            // menores
            for (int i=0; i<n; i++){
                // procedimiento para la lista 1
                if ( men1 > l_1[i] ){ 
                    men1=l_1[i];
                }
                // procedimiento para la lista 2
                if ( men2 > l_2[i] ){ 
                    men2=l_2[i];
                }
                
            }

            // imprecion de listas
            cout<<"\n\n lista 1\n";
            for(int i=0; i<n; i++){
		        cout<<l_1[i]<<" ";
	        }
            cout<<"\n\n lista 2\n";
            for(int i=0; i<n; i++){
		        cout<<l_2[i]<<" ";
	        }
            // imprecion de la respuestas
            cout<<"\n\n elementos mayores\n";
            cout<<"lista 1:"<<may1<<"\n";
            cout<<"lista 2:"<<may2<<"\n";
            
            cout<<"\n\n elementos menores\n";
            cout<<"lista 1:"<<men1<<"\n";
            cout<<"lista 2:"<<men2<<"\n";
        }
        cout<<"\ndesea volver al menu?\n-- 1 para si\n-- 2 para no\n elija:";cin>>op;
    }
    
    return 0;
}