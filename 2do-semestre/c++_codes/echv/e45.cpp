#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;  


struct municipio{
    string codigo;
    string nombre;
    float product_carne;
    float product_leche;
};

municipio l[100];

void pedir_datos(int n){
    cout<<"\n solicitud de datos\n";
    for(int i=0; i<n; i++){
        cout<<" municipio "<<i+1<<endl;
        cout<<" codigo :";cin>>l[i].codigo;
        cout<<" nombre :";cin>>l[i].nombre;
        cout<<" produccion carne :";cin>>l[i].product_carne;
        cout<<" produccion leche :";cin>>l[i].product_leche;
    }
    

}

void llenar_product_mayor(int n){
    ofstream p_m; 
	p_m.open("product_mayor.csv", ios::out);

    float may_p=l[0].product_carne;
    int id;
    for (int i = 0; i < n; i++){
        if (l[i].product_carne>may_p){
            may_p=l[i].product_carne;
            id=i;
        }
        
    }
    p_m<<"mayor produccion de carne ;\n";
    p_m<<"codigo"<<";"<<"nombre"<<";"<<"produccion de carne"<<endl;
    p_m<<l[id].codigo<<";"<<l[id].nombre<<";"<<l[id].product_carne<<endl;
    
    p_m.close();
}

void llenar_product_menor(int n){
    ofstream p_m; 
	p_m.open("product_menor.csv", ios::out);

    float men_p=l[0].product_leche;
    int id;
    for (int i = 0; i < n; i++){
        if (l[i].product_leche<men_p){
            men_p=l[i].product_leche;
            id=i;
        }
        
    }
    p_m<<"menor produccion de leche ;\n";
    p_m<<"codigo"<<";"<<"nombre"<<";"<<"produccion de leche"<<endl;
    p_m<<l[id].codigo<<";"<<l[id].nombre<<";"<<l[id].product_leche<<endl;
    
    p_m.close();
}


void llenar_product_media(int n){
    ofstream p_media; 
	p_media.open("product_media.csv", ios::out);

    float sum_p_carne=0,sum_p_leche=0;
    float mendia_p_carne, media_p_leche;
    for (int i = 0; i < n; i++){
        sum_p_carne+=l[i].product_carne;
        sum_p_leche+=l[i].product_leche;
    }
    mendia_p_carne=sum_p_carne/n;
    media_p_leche=sum_p_leche/n;

    p_media<<"media de produccion de carne"<<";"<<"media de produccion de leche"<<endl;
    p_media<<mendia_p_carne<<";"<<media_p_leche<<endl;
    
    p_media.close();
}

int main() { 
    int cant, go=1;
    while (go==1){
        
        cout<<"\n ingrese el numero de municipios a ingresar:";cin>>cant;
        pedir_datos(cant);
        llenar_product_mayor(cant);
        llenar_product_menor(cant);
        llenar_product_media(cant);
        cout<<"\n volver a pedir datos \n 1 para si: ";cin>>go;
    }
    
    return 0; 
}