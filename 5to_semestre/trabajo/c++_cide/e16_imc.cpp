#include <iostream>
using namespace std;

struct perosna{
    string id ;
    string name;
    int genero;
    float estatura;
    float peso;
    float IMC;
};
perosna datos[5];

// declaramos funcion para calcular ICM
float IMC (float &pe_so, float &esta_tura){
    // realizamos el calculo aplicando la formula proporcionada en el enunciado
    float icm= pe_so / (esta_tura*esta_tura);
    // retornamos el valor del resultado 
    return icm;
}

// declaramos funcion para solicitar los datos de emtrada al usuario 
void preguntar(){
    
    for (int i = 0; i < 5; i++)
    {
        cout<<" persona "<<i+1;

        cout<<" id: ";cin>>datos[i].id;
        cout<<" nombre: ";cin>>datos[i].name;
        cout<<" genero \n 1 > femenino \n 2 > masculino \n --------> ";datos[i].genero;
        while(datos[i].genero<1 || datos[i].genero>2){
            cout<<" valor ingresado incorrecto!\n";
            cout<<" ingrese el genero nuevamente: ";cin>>datos[i].genero;
        }

        cout<<" ingrese su pero en Kg: ";cin>>datos[i].peso;
        while(datos[i].peso<0){
            cout<<" valor ingresado incorrecto!\n";
            cout<<" ingrese su peso en Kg nuevamente: ";cin>>datos[i].peso;
        }
        cout<<"\n ingrese su estatura en M: ";cin>>datos[i].estatura;
        while(datos[i].estatura<0){
            cout<<" valor ingresado incorrecto!\n";
            cout<<" ingrese su estatura en M nuevamente: ";cin>>datos[i].estatura;
        }

        // calculamosm el imc de cada persona
        datos[i].IMC = IMC(datos[i].peso, datos[i].estatura);
    }
}


void mostrar_datos(){
    for (int i = 0; i < 5; i++)
    {
        cout<<"\n persona "<<i+1<<endl;

        cout<<" id: "<<datos[i].id<<endl;
        cout<<" nombre: "<<datos[i].name<<endl;
        cout<<" genero: ";
        if(datos[i].genero==1){
            cout<<" femenino"<<endl;
        }
        else{
            cout<<" masculino"<<endl;
        }
        cout<<" peso Kg: "<<datos[i].peso<<endl;
        cout<<" estatura en M: "<<datos[i].estatura<<endl;
        cout<<" IMC: "<<datos[i].IMC<<endl;
    }
} 


void may_imc(){
    perosna per;
    float may_imc=0;
    for (int i = 0; i < 5; i++)
    {
        if(datos[i].IMC>may_imc){
            per=datos[i];
            may_imc=datos[i].IMC;
        }
    }
    
    cout<<" la persona con mayor IMC es :";
    cout<<" id:"<<per.id<<endl;
    cout<<" nombre:"<<per.name<<endl;
    if(per.genero==1){
            cout<<" femenino"<<endl;
        }
        else{
            cout<<" masculino"<<endl;
        }
    cout<<" peso: "<<per.peso<<endl;
    cout<<" estatura: "<<per.estatura<<endl;
    cout<<" IMC: "<<per.IMC<<endl;

}

void men_imc(){
    perosna per;
    float men_imc=99999;
    for (int i = 0; i < 5; i++)
    {
        if(datos[i].IMC<men_imc){
            per=datos[i];
            men_imc=datos[i].IMC;
        }
    }
    cout<<" la persona con menor IMC es :"<<endl;
    cout<<" id:"<<per.id<<endl;
    cout<<" nombre:"<<per.name<<endl;
    if(per.genero==1){
            cout<<" femenino"<<endl;
        }
        else{
            cout<<" masculino"<<endl;
        }
    cout<<" peso: "<<per.peso<<endl;
    cout<<" estatura: "<<per.estatura<<endl;
    cout<<" IMC: "<<per.IMC<<endl;
}

int main(){
    
    // solicitamos los datos a los usuarios 
    preguntar();
    int go=1;
    while (go < 4) {
        cout << "\n\n\t*** MENU PRINCIPAL ***";
        cout << "\n1. mostra todos los datos ";
        cout << "\n2. mostra el menor imc";
        cout << "\n3. mostra el mayor imc";
        cout << "\n4. salir del progarma ";
        cout << "\n\n\tEscoja opcion: ";
        int op;
        do
        {
            cout<<"ingresa una opcion:";cin>>op;
            if (op>4 || op<1)
            {
                cout<<" opcion ingresada no valida!!! \n porfavor ingresarla nuevamente \n";
            }
        } while (op>6 || op<1);

        switch (op) {
            case 1: mostrar_datos();
            break;
            case 2: may_imc();
            break;
            case 3: men_imc();
            break;
            case 4: go=4;
            break;
        }
    }
    return 0;
}
