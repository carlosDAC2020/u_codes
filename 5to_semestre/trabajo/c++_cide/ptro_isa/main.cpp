#include <iostream>
#include <fstream> 
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
using namespace std;


string l_nombre[6]={
    "armando",
    "nicolas",
    "daniel",
    "maria",
    "marcela ",
    "alexandra"
};
 
string l_materias[3]={
    "informatica", 
    "fisica", 
    "quimica"
};

struct estudiante{
    string Nombre;
    int genero;
    string materia;
    float nota;
};
// resultados de examenes
estudiante lst_reults_estudiante[18];

struct usuario{
    string user;
    string password;
};
// lista de usuarios
usuario l_users[5];
int cant_usuarios=0;


// funciones a utilizar
int menu1();
void leer_archivo();
void crear_usuario();
int login();
void sesion();
int menu2();
void op1();
void op2();
void op3();
void op4();


//  variable que esfecifica el usuario que tiene una sesion activa
int index_usuario;

int main(){
    leer_archivo();
    for (int i = 0; i < 18; i++)
    {
        cout<<lst_reults_estudiante[i].nota<<endl;
    }
    
    int go=1;
	while (go<3){
        switch (menu1()) {
            case 1: 
                if (login()==1)
                {
                    sesion();
                }
            break;
            case 2: 
                crear_usuario();
            break;
            case 3:
                go=3; 
            break;
            default: ;
        }
    }
    return 0;
}

int menu1(){
    cout<<"\n SISTEMA DE NOTAS \n";
    cout<<"--->1 inicioa secion\n";
    cout<<"--->2 crea un usuario  \n";
    cout<<"--->3 salir del progarma \n";

    int option;
    cout<<" escoja el numero de su opcion:";cin>>option;
    while (option>3 || option<1){
        cout<<"\n valor ingresado no valido\n";
        cout<<" escoja el numero de su opcion nuevamente:";cin>>option;
    }
    return option;
}


/*
funcion de inico de sesion para los usuarios 
*/
int login(){
    string  user, password;
	int intentos=1;
    bool ok=false;
	while(intentos<=3){

        // aviso de intentso
        if (intentos>1)
        {
            cout<<"\n intento "<<intentos<<endl;
        }
        
		cout<<"\n INICIO DE CECION \n";
		cout<<" Usuario:";cin>>user;
		cout<<" Contrasenia:";cin>>password;

			// validacion de los datos 
		for(int i=0; i<cant_usuarios; i++){
			if (l_users[i].user==user && l_users[i].password==password){
				index_usuario=i;
                ok=true;
				return 1;
			}
		}
		if(ok==false){
			cout<<"\n\n datos no validos \n"; 
            intentos+=1;
		}

        if (intentos>3)
        {
            cout<<"\n excedio el numero de intentso de inicio de sesion !!! \n";
        }
	}
    return 0;
}


/*
 funcion que maneja la estructura de flujo de la sesion de los usuarios 
 como el menu de opciones a mostrar y la ejecucion de las opciones
 mostradas en el menu
*/
void sesion(){
    int go=1;
	while (go<5){
        switch (menu2()) {
            case 1: 
                op1(); // Porcentaje de aprovacion de examenes
            break;
            case 2: 
                op2(); // Porcentaje de los exámenes que fueron Excelentes
            break;
            case 3:
                op3(); // Materia con el mayor número de exámenes aprobados
            break;
            case 4:
                op4(); // Estudiante con el mejor desempeño para la materia informática
            break;
            case 5:
                go=5; 
            break;
            default: ;
        }
    }
}

/*
munu que se muestra al usuario al inicar sesion
*/
int menu2(){
    cout<<"\n hola "<<l_users[index_usuario].user<<endl;
    cout<<" Que desea revizar? \n";
    cout<<"--->1 Porcentaje de aprovacion de examenes \n";
    cout<<"--->2 Porcentaje de los exámenes que fueron Excelentes\n";
    cout<<"--->3 Materia con el mayor número de exámenes aprobados\n";
    cout<<"--->4 Estudiante con el mejor desempeño para la materia informática\n";
    cout<<"--->5 Cerrar sesion\n";

    int option;
    cout<<"\n escoja el numero de su opcion:";cin>>option;
    while (option>5 || option<1){
        cout<<"\n valor ingresado no valido\n";
        cout<<" escoja el numero de su opcion nuevamente:";cin>>option;
    }
    return option;
}


void op1(){
    cout<<"---------------------------------------------------\n";
    // porcentaje de aprovacion de examenes
    int cant_exm_apbs=0;
    float porct_exm_apbs;

    // buscamos la cantidad de examenes aprobados
    for (int i = 0; i < 18; i++)
    {
        if(lst_reults_estudiante[i].nota>=60){
            cant_exm_apbs+=1;
        }
    }

    // obtenemos el procentaje de exmanes aprobados
    porct_exm_apbs = (cant_exm_apbs*100)/18;
    
    cout<<"\n Porcentaje de examenes aprobados: "<<porct_exm_apbs<<"%"<<endl;
    cout<<"---------------------------------------------------\n";
}


void op2(){
    cout<<"---------------------------------------------------\n";
    // Porcentaje de los exámenes que fueron Excelentes
    int cant_exm_excelentes=0;
    float porct_exm_excelentes;

    // buscamos la cantidad de examenes aprobados
    for (int i = 0; i < 18; i++)
    {
        if(lst_reults_estudiante[i].nota>=90.0 && lst_reults_estudiante[i].nota<=100.0){
            cant_exm_excelentes+=1;
        }
    }

    // obtenemos el procentaje de exmanes aprobados
    porct_exm_excelentes = (cant_exm_excelentes*100)/18;
    
    cout<<"\n Porcentaje de examenes excelentes: "<<porct_exm_excelentes<<"%"<<endl;
    cout<<"---------------------------------------------------\n";
}


void op3(){
    cout<<"---------------------------------------------------\n";
    // Materia con el mayor número de exámenes aprobados
    int cant_exam_apb=0, may_cant_exam_apb=0, mtra;

    for (int i = 0; i < 3; i++)
    {
        cant_exam_apb=0;
        for (int y = 0; y < 18; y++)
        {   
            // obtenemos la cantidad de examenes aprobados de cada materia
            if (l_materias[i] == lst_reults_estudiante[y].materia)
            {
                if (lst_reults_estudiante[y].nota>=60)
                {
                    cant_exam_apb+=1;
                }
            }
        }
        // vamos comparando la cantidad de examenes aprobados de cada materia
        // para ver cual obtuvo mas examenes aprobados
        if (cant_exam_apb > may_cant_exam_apb) 
        {
            // asignamos el indice de la materia y la cantidad de examens 
            // aprobados a unas variables auxiliares
            may_cant_exam_apb = cant_exam_apb;
            mtra = i;
        }
    }   
    cout<<"\n la materia con mayor numero de examens aprobados fue "<<l_materias[mtra]<<"\n";
    cout<<" con "<<may_cant_exam_apb<<" examenes \n";
    cout<<"---------------------------------------------------\n";
}


void op4(){
    cout<<"---------------------------------------------------\n";
    // Estudiante con el mejor desempeño para la materia informática
    float may_nota_infta;
    estudiante est_may_noat_intf;

    for (int i = 0; i < 18; i++)
    {
        if(lst_reults_estudiante[i].materia == l_materias[0] && lst_reults_estudiante[i].nota > may_nota_infta)
        {
            may_nota_infta = lst_reults_estudiante[i].nota;
            est_may_noat_intf = lst_reults_estudiante[i];
        }
    }
    cout<<"\n estudiante con mayor nota en informatica \n";
    cout<<" Nombre: "<<est_may_noat_intf.Nombre<<endl;
    cout<<" Nota: "<<est_may_noat_intf.nota<<endl;

    cout<<"---------------------------------------------------\n";
}


/* 
funcion en la  cual creamos los usuarios
*/
void crear_usuario(){
    // validamo que no se exceda delos 5 usuarios minimos 
    if (cant_usuarios<5)
    {
        cout<<"\n NUEVO USURIO \n";
        cout<<" Definir usuario: ";cin>>l_users[cant_usuarios].user;
        cout<<" Definir contrasenia: ";cin>>l_users[cant_usuarios].password;
        
        cout<<"\n       USURIO GUARDADO EXITOSAMNETE !!!\n";

        // sumamos 1 a la cantidad de usuarios
        cant_usuarios+=1;
    }
    else{
        cout<<"\n !! LIMITE DE USUARIOS YA se ha registrado 5 usuarios \n";
    }
}



/*
esta funcion hace la lectura del archivo donde tensmos 
almacenados los datos de las notas de los estudiantes
y los guarda en una lista de registros de tipo estudiante
*/ 
void leer_archivo(){
    // declaramos y habrimos el archivo a leer
	ifstream archivo;
	archivo.open(".datos.csv", ios::in);
	if (archivo.fail()) { // validamos la existencia del archivo 
		cout << "* No se puedo leer el archivo." << endl;
		exit(1);
	}
    
    // variables auxiliares 
    string aux_nombre, aux_materia, linea, auxiliar;
    int aux_genro, idf;
    float nota;
    
    // guardamos los datos del archvo en una lista
    // cantidad de clientes ya guardados 
    int contador=0;
    // recorremos el 1archivo1 de lectura linea oir linea 
	while (getline(archivo, linea)) {
		stringstream stream(linea);
    // usamos un separador ; para identificar cada dato y asiganrlo a su correspondiente variable axuliar  
        
        getline(stream, auxiliar, ';');
        idf = atoi(auxiliar.c_str()); 
        aux_nombre = l_nombre[idf-1]; // nombre
		
        getline(stream, auxiliar, ';');
        idf = atoi(auxiliar.c_str()); 
        aux_genro= idf; // genero

        getline(stream, auxiliar, ';');
        idf = atoi(auxiliar.c_str()); 
        aux_materia = l_materias[idf-1]; // materia
        
        getline(stream, auxiliar, ';');
        nota = atof(auxiliar.c_str()); // nota
        
        // usamos las bvafriables auxiliares para guardar los datos correspondientes en la losta de resultados 
        lst_reults_estudiante[contador].Nombre = aux_nombre;
        lst_reults_estudiante[contador].genero = aux_genro;
        lst_reults_estudiante[contador].materia = aux_materia;
        lst_reults_estudiante[contador].nota = nota;

        contador+=1;
    }

    archivo.close();
}