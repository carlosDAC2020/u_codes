#include <iostream>
#include <math.h>
using namespace std;

// declaramos el prototipo de las funciones que utilizaremos
int menu();
void caso1();
void caso2();
void caso3();
void caso4();
void caso5();



int main() {
   int go=1;
    while (go < 5) {
        switch (menu()) {
            case 1: caso1();
            break;
            case 2: caso2();
            break;
            case 3: caso3();
            break;
            case 4: caso4();
            break;
            case 5: caso5();
            break;
            case 6: go=5;
            break;
            
            default: cout << "\n\n\tERROR EN OPCION";
        }
    }
    return 0;
}


// delcaramos las funciones --------------------------------------------------------------

int menu() {
    cout << "\n\n\t*** MENU PRINCIPAL ***";
    cout << "\n que program,a desea probar? ";
    cout << "\n1. calculamos el volumen de un SILO";
    cout << "\n2. decir si un numero es primo o no";
    cout << "\n3. verificar los lados de un triangulo rectangulo";
    cout << "\n4. calcular la puntuacion de un examen para n estudiantes";
    cout << "\n5. obten la tabla de multiplicar de un numero";
    cout << "\n6. salir del programa ";
    cout << "\n\n\tEscoja opcion: ";

    int op;
    do
    {
        cout<<"ingresa una opcion:";cin>>op;
        if (op>6 || op<1)
        {
            cout<<" opcion ingresada no valida!!! \n porfavor ingresarla nuevamente \n";
        }
    } while (op>6 || op<1);
    return op;
}

// calcularemos el volumen de un cilo en el cual se almacenan cereales en grano 
void caso1(){
    float vol_total, d, H1, H2, vol_cilindro, vol_cono;
    cout<<"\n CASO 1 \n";
    cout<<" ingrese los datos necesarios para obtener el volumen"<<endl;
    cout<<" diametro interior del cilindro:";cin>>d;
    cout<<" altura interior del cilindro:";cin>>H1;
    cout<<" altura interior del cono:";cin>>H2;

    vol_cilindro = 3.1416 * pow((d/2),2) * H1;
    vol_cono =  (3.1416 * pow((d/2),2) * H2) / 3;
    vol_total = vol_cilindro+ vol_cono;
    
    cout<<"\n el volumen toal del cilo es de:"<<vol_total;
}

// evaluamos en en est funcion si un numero es primo 
bool n_primo(int num){ // evaluar si un numero es primo o no
	if (num==2){
		cout<<" es primo \n";
		return true;
	}
	for (int i=3; i<=num; i++){
		if(num%i==0){
			cout<<" no es primo \n";
			return false;
		}
	}
	cout<<" es primo \n";
	return true;
}
void caso2(){
    int num;
    cout<<"\n CASO 2 \n";
    cout<<" ingresa un numero:";cin>>num;

    cout<<"\n el numero :"<<n_primo(num);

}

// verificar si un conjunto de lados a b y c conforman un triangulo rectangulo  
void caso3(){
    // declaramos las variables a utilizar
    float a,b,c;
    int n;
    cout<<"\n CASO 3 \n";
    cout<<" ingrese cantidad de conjuntos de valoras a,b y c a evaluar:";cin>>n;
    for (int i = 1; i<=n; i++)
    {
        cout<<"\n conjunto "<<i<<endl;
        cout<<" ingresa el valor del lado A:";cin>>a;
        cout<<" ingresa el valor del lado B:";cin>>b;
        cout<<" ingresa el valor del lado C:";cin>>c;

        if (pow(c,2) == pow(a,2) + pow(b,2))
        {
            cout<<"\n el conjunto de datos ingresados a, b y c SI conforman un trinagulo rectangulo";
            cout<<" cuya hipotenusa es:"<<c<<endl;
        }
        else
        {
            cout<<"\n el conjunto de datos ingresados a, b y c NO conforman un trinagulo rectangulo";
        }
        
    }
}

/* solicitar las cantidad de rspuestas acertadas, erradas y en blnaco de n estudiantes
y calcular su puntuacion final */
void caso4(){
    int n, cant_Rbn, cant_Rmal, cant_Rbla, puntaje_final;
    cout<<"\n CASO 4 \n";
    cout<<" cantidad de estudiantes a evaluar:";cin>>n;

    for (int i = 1; i <= n; i++)
    {
        cout<<"\n estudiante "<<i<<endl;
        do
        {
            cout<<" respuestas correctas:";cin>>cant_Rbn;
            cout<<" respuestas erradas:";cin>>cant_Rmal;
            cout<<" respuestas en blanco :";cin>>cant_Rbla;
            if (cant_Rbla+cant_Rbn+cant_Rmal>50)
            {
                cout<<"\n la cantidad total de respuestas ingresada supera 50 ";
                cout<<"\n porfavor ingresar las cantidades correctas  ";
            }
        } while (cant_Rbla+cant_Rbn+cant_Rmal>50);
        
        

        puntaje_final= (cant_Rbn*4) - (cant_Rmal*2) - cant_Rbla;
        cout<<"\n pintaje final:"<<puntaje_final;
        cout<<"\n pintaje final:";
        if(puntaje_final>=140){
            cout<<" sobresaliente";
        }
        else if (puntaje_final<140 || puntaje_final>=80){
            cout<<" aprobado";
        }
        else{
            cout<<" reprobado";
        }
        cout<<"\n------------------------------";
    }
}

// ontenemos la tabla de miltiplicar de un numero ingresado por el usuario 
void caso5(){
    int num;
    cout<<"\n CASO 5 \n";
    cout<<" ingredse un numero:";cin>>num;
    if (num>0)
    {
        num*=-1;
    }

    cout<<"'n tabla de multiplicar del "<<num;
    for (int i = 1; i <= 10; i++)
    {
        cout<<"\n "<<num<<" x "<<i<<" = "<<num*i;
    }
}