#include <iostream>
#include <fstream> 
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
using namespace std;

struct equipo{
    int ID;
    string Nombre;
    float precio_unitario;
    int Cantidad;
    int Fecha_ingreso[3];
    string responsable;
};
equipo lst_equipos[100];

struct empleado{
    int ID;
    string Nombre;
    string Apellido;
    int Edad;
    string Profesion;
    int Fecha_ingreso[3]={0,0,0};
    int Fecha_finalizacion[3]={0,0,0};
    int clasificacion;
};
empleado emplds[6];

// funciones a utilizar 
int menu();
int leer_asiganr_empleados();
int leer_asignar_equipos();
void guardar_empleados(int);
void guardar_equipos(int);
void imprimir_equipos(int );
void imprimir_empledos(int );
void agregar_equipos(int &);
void agregar_empledos(int &);
void editar_equipos(int );
void editar_empledos(int );
void estadisticas_generales(int, int);



int main() {
    int cant_empleados=leer_asiganr_empleados();
    int cant_equipos=leer_asignar_equipos();

    int go=1;
    while (go < 8) {
        switch (menu()) {
            case 1: imprimir_equipos(cant_equipos);
            break;
            case 2: imprimir_empledos(cant_empleados);
            break;
            case 3: agregar_equipos(cant_equipos);
            break;
            case 4: agregar_empledos(cant_empleados);
            break;
            case 5: editar_equipos(cant_equipos);
            break;
            case 6: editar_empledos(cant_empleados);
            break;
            case 7: estadisticas_generales(cant_empleados, cant_equipos);
            break;
            case 8: go=8;
            break;
            default: ;
        }
        // vamos guardando los registros de empleados y equipos
        guardar_empleados(cant_empleados);
        guardar_equipos(cant_equipos);
    }
    return 0;
}

int menu() {
    cout << "\n\n\t*** MENU PRINCIPAL ***";
    cout << "\n que programa desea probar? ";
    cout << "\n1. Mostrar el ctalogo de equipos";
    cout << "\n2. Mostrar listado de empleaodos";
    cout << "\n3. Agregar equipos";
    cout << "\n4. Agregar empledos";
    cout << "\n5. Editar equipo";
    cout << "\n6. Editar empleado";
    cout << "\n7. Estadisticas generales";
    cout << "\n8. salir del programa ";
    cout << "\n\n\tEscoja opcion: ";

    int op;
    do
    {
        cout<<"ingresa una opcion:";cin>>op;
        if (op>8 || op<1)
        {
            cout<<" opcion ingresada no valida!!! \n porfavor ingresarla nuevamente \n";
        }
    } while (op>8 || op<1);
    return op;
}

void imprimir_equipos(int cant_e){
    cout<<"\n EQUIPOS REGISTRADOS \n";
    if (cant_e==0)
    {
        cout<<"hasta el momento no hay equipos registrados \n";
    }
    else{
        for (int i = 0; i < cant_e; i++)
        {
            cout<<" Id:"<<lst_equipos[i].ID<<endl;
            cout<<" Nombre: "<<lst_equipos[i].Nombre<<endl;
            cout<<" Cantidad: "<<lst_equipos[i].Cantidad<<endl;
            cout<<" Precio unitario: "<<lst_equipos[i].precio_unitario<<endl;
            cout<<" Fecha de ingreso: "<<lst_equipos[i].Fecha_ingreso[0]<<"/"<<lst_equipos[i].Fecha_ingreso[1]<<"/"<<lst_equipos[i].Fecha_ingreso[2]<<endl;
            cout<<" Responsable:"<<lst_equipos[i].responsable<<endl;
            cout<<"---------------------------------\n";
        }
    }
}


void imprimir_empledos(int cant_emp){
    cout<<"\n EMPLEADOS REGISTRADOS \n";
    if (cant_emp==0)
    {
        cout<<"hasta el momento no hay empleados registrados \n";
    }
    else{
        for (int i = 0; i < cant_emp; i++)
        {
            cout<<" Id:"<<emplds[i].ID<<endl;
            cout<<" Nombre: "<<emplds[i].Nombre<<endl;
            cout<<" Apellido: "<<emplds[i].Apellido<<endl;
            cout<<" Edad : "<<emplds[i].Edad<<endl;
            cout<<" Profesion : "<<emplds[i].Profesion<<endl;
            cout<<" Fecha de ingreso :"<<emplds[i].Fecha_ingreso[0]<<"/"<<emplds[i].Fecha_ingreso[1]<<"/"<<emplds[i].Fecha_ingreso[2]<<endl;
            cout<<" Fecha de finalizacion :"<<emplds[i].Fecha_ingreso[0]<<"/"<<emplds[i].Fecha_ingreso[1]<<"/"<<emplds[i].Fecha_ingreso[2]<<endl;
            cout<<" Clasificacion :"<<emplds[i].clasificacion<<endl;
            cout<<"------------------------------------\n";
        }
    }
}


void agregar_equipos(int &cant_e){
    cout<<"\n Ingreso de datos de un nuevo equipo \n";
    lst_equipos[cant_e].ID=cant_e; // asiganamos el id del equipo como su posiscion en la lista
    cout<<" Nombre: ";cin>>lst_equipos[cant_e].Nombre;

            // ingresos y validaciones de la cantidad precio unitario y fecha de ingreso 
            // nuevo
    do
    {
        cout<<" Cantidad: ";cin>>lst_equipos[cant_e].Cantidad;
        if (lst_equipos[cant_e].Cantidad<0)
        {
            cout<<"\n   no ingresar valores menores a cero \n";
        }
    } while (lst_equipos[cant_e].Cantidad<0);
    do
    {
        cout<<" Precio unitario: ";cin>>lst_equipos[cant_e].precio_unitario;
        if (lst_equipos[cant_e].precio_unitario<0)
        {
            cout<<"\n   no ingresar valores menores a cero \n";
        }
    } while (lst_equipos[cant_e].precio_unitario<0);
    do{
         cout<<"\n Fecha de ingreso: \n";
         cout<<"  Dia: ";cin>>lst_equipos[cant_e].Fecha_ingreso[0];
         cout<<" Mes: ";cin>>lst_equipos[cant_e].Fecha_ingreso[1];
         cout<<" Anio: ";cin>>lst_equipos[cant_e].Fecha_ingreso[2];
         if (lst_equipos[cant_e].Fecha_ingreso[0]<0 || lst_equipos[cant_e].Fecha_ingreso[0]>31 || lst_equipos[cant_e].Fecha_ingreso[1]<0 || lst_equipos[cant_e].Fecha_ingreso[1]>12 || lst_equipos[cant_e].Fecha_ingreso[2]<0 || lst_equipos[cant_e].Fecha_ingreso[2]>2022)
         {
            cout<<"\n ingrese una fecha valida \n";
         }
    } while(lst_equipos[cant_e].Fecha_ingreso[0]<0 || lst_equipos[cant_e].Fecha_ingreso[0]>31 || lst_equipos[cant_e].Fecha_ingreso[1]<0 || lst_equipos[cant_e].Fecha_ingreso[1]>12 || lst_equipos[cant_e].Fecha_ingreso[2]<0 || lst_equipos[cant_e].Fecha_ingreso[2]>2022);
   
    cout<<" Responsable:";cin>>lst_equipos[cant_e].responsable;

    cant_e+=1;
    
}


void agregar_empledos(int &cant_emp){
    if (cant_emp>=6)
    {
        cout<<"\n NO se puede añadir nuevos empleados \n ya existen 6 empleados registrados \n";
    }
    else{
        cout<<"\n ingreso de datos del nuevo empleado \n";
        emplds[cant_emp].ID=cant_emp; // asigamanos su id 
        cout<<" Nombre: ";cin>>emplds[cant_emp].Nombre;
        cout<<" Apellido: ";cin>>emplds[cant_emp].Apellido;
        cout<<" Profesion : ";cin>>emplds[cant_emp].Profesion;
        do
        {
            cout<<" Edad : ";cin>>emplds[cant_emp].Edad;
            if (emplds[cant_emp].Edad<=0)
            {
                cout<<"\n   no ingresar valores menores a cero \n";
            }
            
        } while (emplds[cant_emp].Edad<=0);

        do
        {
             cout<<"\n Fecha de ingreso : \n ";
             cout<<" Dia: ";cin>>emplds[cant_emp].Fecha_ingreso[0];
             cout<<" Mes: ";cin>>emplds[cant_emp].Fecha_ingreso[1];
             cout<<" Anio: ";cin>>emplds[cant_emp].Fecha_ingreso[2];
             if(emplds[cant_emp].Fecha_ingreso[0]<0 || emplds[cant_emp].Fecha_ingreso[0]>31 || emplds[cant_emp].Fecha_ingreso[1]<0 || emplds[cant_emp].Fecha_ingreso[1]>12 || emplds[cant_emp].Fecha_ingreso[2]<0 || emplds[cant_emp].Fecha_ingreso[2]>2022){
                cout<<"\n ingrese una fecha valida \n";
             }
        } while (emplds[cant_emp].Fecha_ingreso[0]<0 || emplds[cant_emp].Fecha_ingreso[0]>31 || emplds[cant_emp].Fecha_ingreso[1]<0 || emplds[cant_emp].Fecha_ingreso[1]>12 || emplds[cant_emp].Fecha_ingreso[2]<0 || emplds[cant_emp].Fecha_ingreso[2]>2022);

         do
        {
             cout<<"\n Fecha de finalizacion : \n ";
             cout<<" Dia: ";cin>>emplds[cant_emp].Fecha_finalizacion[0];
             cout<<" Mes: ";cin>>emplds[cant_emp].Fecha_finalizacion[1];
             cout<<" Anio: ";cin>>emplds[cant_emp].Fecha_finalizacion[2];
             if(emplds[cant_emp].Fecha_finalizacion[0]<0 || emplds[cant_emp].Fecha_finalizacion[0]>31 || emplds[cant_emp].Fecha_finalizacion[1]<0 || emplds[cant_emp].Fecha_finalizacion[1]>12 || emplds[cant_emp].Fecha_finalizacion[2]<0 || emplds[cant_emp].Fecha_finalizacion[2]<emplds[cant_emp].Fecha_ingreso[2]){
                cout<<"\n ingrese una fecha valida \n";
             }
        } while (emplds[cant_emp].Fecha_finalizacion[0]<0 || emplds[cant_emp].Fecha_finalizacion[0]>31 || emplds[cant_emp].Fecha_finalizacion[1]<0 || emplds[cant_emp].Fecha_finalizacion[1]>12 || emplds[cant_emp].Fecha_finalizacion[2]<0 || emplds[cant_emp].Fecha_finalizacion[2]<emplds[cant_emp].Fecha_ingreso[2]);

        do
        {
            cout<<" Clasificacion (1, 2 o 3):";cin>>emplds[cant_emp].clasificacion;
            if(emplds[cant_emp].clasificacion<1 || emplds[cant_emp].clasificacion>3){
                cout<<"\n ingresar solo los valorde correspondientes \n";
            }
        } while (emplds[cant_emp].clasificacion<1 || emplds[cant_emp].clasificacion>3);
        
        cant_emp+=1;
    }
}


void editar_equipos(int cant_e){
    int id;
    cout<<"\n EDITAR DATOS DE UN EQUIPO \n";
    cout<<" ingresa el id del equipo a editar \n";
    cout<<"-->";cin>>id;

    if (id<0 || id>=cant_e)
    {
        cout<<"\n !! id ingresado inexistente \n";
    }
    else{
        cout<<"\n Datos actuales del equipo  \n";
        cout<<" Id:"<<lst_equipos[id].ID<<endl;
        cout<<" Nombre: "<<lst_equipos[id].Nombre<<endl;
        cout<<" Cantidad: "<<lst_equipos[id].Cantidad<<endl;
        cout<<" Precio unitario: "<<lst_equipos[id].precio_unitario<<endl;
        cout<<" Fecha de ingreso: "<<lst_equipos[id].Fecha_ingreso[0]<<"/"<<lst_equipos[id].Fecha_ingreso[1]<<"/"<<lst_equipos[id].Fecha_ingreso[2]<<endl;
        cout<<" Responsable:"<<lst_equipos[id].responsable<<endl;

        cout<<"\n Nuevos datos a ingresar \n";
        cout<<" Nombre: ";cin>>lst_equipos[id].Nombre;

            // ingresos y validaciones de la cantidad precio unitario y fecha de ingreso 
            // nuevo
    do
    {
        cout<<" Cantidad: ";cin>>lst_equipos[id].Cantidad;
        if (lst_equipos[id].Cantidad<0)
        {
            cout<<"\n   no ingresar valores menores a cero \n";
        }
    } while (lst_equipos[id].Cantidad<0);
    do
    {
        cout<<" Precio unitario: ";cin>>lst_equipos[id].precio_unitario;
        if (lst_equipos[id].precio_unitario<0)
        {
            cout<<"\n   no ingresar valores menores a cero \n";
        }
    } while (lst_equipos[id].precio_unitario<0);
    do{
         cout<<"\n Fecha de ingreso: \n";
         cout<<"  Dia: ";cin>>lst_equipos[id].Fecha_ingreso[0];
         cout<<" Mes: ";cin>>lst_equipos[id].Fecha_ingreso[1];
         cout<<" Anio: ";cin>>lst_equipos[id].Fecha_ingreso[2];
         if (lst_equipos[id].Fecha_ingreso[0]<0 || lst_equipos[id].Fecha_ingreso[0]>31 || lst_equipos[id].Fecha_ingreso[1]<0 || lst_equipos[id].Fecha_ingreso[1]>12 || lst_equipos[id].Fecha_ingreso[2]<0 || lst_equipos[id].Fecha_ingreso[2]>2022)
         {
            cout<<"\n ingrese una fecha valida \n";
         }
    } while(lst_equipos[id].Fecha_ingreso[0]<0 || lst_equipos[id].Fecha_ingreso[0]>31 || lst_equipos[id].Fecha_ingreso[1]<0 || lst_equipos[id].Fecha_ingreso[1]>12 || lst_equipos[id].Fecha_ingreso[2]<0 || lst_equipos[id].Fecha_ingreso[2]>2022);
   
    cout<<" Responsable:";cin>>lst_equipos[id].responsable;
    }
    

}


void editar_empledos(int cant_emp){
     int id;
    cout<<"\n EDITAR DATOS DE UN EMPLEADO \n";
    cout<<" ingresa el id del empleado a editar \n";
    cout<<"-->";cin>>id;

    if (id<0 || id>cant_emp)
    {
        cout<<"\n !! id ingresado inexistente \n";
    }
    else{
        cout<<"\n Datos actuales del empleado  \n";
        cout<<" Id:"<<emplds[id].ID<<endl;
        cout<<" Nombre: "<<emplds[id].Nombre<<endl;
        cout<<" Apellido: "<<emplds[id].Apellido<<endl;
        cout<<" Edad : "<<emplds[id].Edad<<endl;
        cout<<" Profesion : "<<emplds[id].Profesion<<endl;
        cout<<" Fecha de ingreso :"<<emplds[id].Fecha_ingreso[0]<<"/"<<emplds[id].Fecha_ingreso[1]<<"/"<<emplds[id].Fecha_ingreso[2]<<endl;
        cout<<" Fecha de finalizacion :"<<emplds[id].Fecha_ingreso[0]<<"/"<<emplds[id].Fecha_ingreso[1]<<"/"<<emplds[id].Fecha_ingreso[2]<<endl;
        cout<<" Clasificacion :"<<emplds[id].clasificacion<<endl;
        
        cout<<"\n Nuevos datos a ingresar \n";
        cout<<" Nombre: ";cin>>emplds[id].Nombre;
        cout<<" Apellido: ";cin>>emplds[id].Apellido;
        cout<<" Profesion : ";cin>>emplds[id].Profesion;
        do
        {
            cout<<" Edad : ";cin>>emplds[id].Edad;
            if (emplds[id].Edad<=0)
            {
                cout<<"\n   no ingresar valores menores a cero \n";
            }
            
        } while (emplds[id].Edad<=0);

        do
        {
             cout<<"\n Fecha de ingreso : \n ";
             cout<<" Dia: ";cin>>emplds[id].Fecha_ingreso[0];
             cout<<" Mes: ";cin>>emplds[id].Fecha_ingreso[1];
             cout<<" Anio: ";cin>>emplds[id].Fecha_ingreso[2];
             if(emplds[id].Fecha_ingreso[0]<0 || emplds[id].Fecha_ingreso[0]>31 || emplds[id].Fecha_ingreso[1]<0 || emplds[id].Fecha_ingreso[1]>12 || emplds[id].Fecha_ingreso[2]<0 || emplds[id].Fecha_ingreso[2]>2022){
                cout<<"\n ingrese una fecha valida \n";
             }
        } while (emplds[id].Fecha_ingreso[0]<0 || emplds[id].Fecha_ingreso[0]>31 || emplds[id].Fecha_ingreso[1]<0 || emplds[id].Fecha_ingreso[1]>12 || emplds[id].Fecha_ingreso[2]<0 || emplds[id].Fecha_ingreso[2]>2022);

         do
        {
             cout<<"\n Fecha de finalizacion : \n ";
             cout<<" Dia: ";cin>>emplds[id].Fecha_finalizacion[0];
             cout<<" Mes: ";cin>>emplds[id].Fecha_finalizacion[1];
             cout<<" Anio: ";cin>>emplds[id].Fecha_finalizacion[2];
             if(emplds[id].Fecha_finalizacion[0]<0 || emplds[id].Fecha_finalizacion[0]>31 || emplds[id].Fecha_finalizacion[1]<0 || emplds[id].Fecha_finalizacion[1]>12 || emplds[id].Fecha_finalizacion[2]<0 || emplds[id].Fecha_finalizacion[2]<emplds[id].Fecha_ingreso[2]){
                cout<<"\n ingrese una fecha valida \n";
             }
        } while (emplds[id].Fecha_finalizacion[0]<0 || emplds[id].Fecha_finalizacion[0]>31 || emplds[id].Fecha_finalizacion[1]<0 || emplds[id].Fecha_finalizacion[1]>12 || emplds[id].Fecha_finalizacion[2]<0 || emplds[id].Fecha_finalizacion[2]<emplds[id].Fecha_ingreso[2]);

        do
        {
            cout<<" Clasificacion (1, 2 o 3):";cin>>emplds[id].clasificacion;
            if(emplds[id].clasificacion<1 || emplds[id].clasificacion>3){
                cout<<"\n ingresar solo los valorde correspondientes \n";
            }
        } while (emplds[id].clasificacion<1 || emplds[id].clasificacion>3);
    }
}
/*

    en la sigueinte funcion obtendremos las siguinetes estadisticas 
    relevantes 

    empleados
        promedio de edad
        porcentaje de empleados por clasificacion
    
    equipos
        promedio de precios
        producto con mayor y menor precio
        mas dispobible y nenos disponible
*/
    
void estadisticas_generales(int cant_emp, int cant_e){
    // empleados
    int sum_edad=0, cant_c1=0, cant_c2=0, cant_c3=0;
    float prom_edade_emps, porct_c1, porct_c2, porct_c3;

    // equipos
    float sum_precio_unitario=0, prom_precio_unitario, may_prec=0, men_prec=999999999999999;
    int product_may_cant, product_men_cant, may_cant=0, men_cant=9999999999999, product_may_prc, product_men_prc;

    for (int i = 0; i < cant_e; i++)
    {
        // para los empleados
        if (i<cant_emp)
        {   
            // sumatoria de las edades para posteriormente obtener el promedio
            sum_edad+=emplds[i].Edad;

            // obtenemos la cantidad de empelados por cada clasificacion 
            switch (emplds[i].clasificacion)
            {
            case 1:
                cant_c1+=1;
                break;
            case 2:
                cant_c2+=1;
                break;
            case 3:
                cant_c3+=1;
                break;
            default:
                break;
            }
        }

        // para los productos 

        // sumatoria para posteriormente obtener los promedios de precios unitarios
        sum_precio_unitario+=lst_equipos[i].precio_unitario; 

        // obtenemos el mayor y menor precio
        if (may_prec<lst_equipos[i].precio_unitario)
        {
            may_prec=lst_equipos[i].precio_unitario;
            product_may_prc=i;
        }
        if (men_prec>lst_equipos[i].precio_unitario)
        {
            men_prec=lst_equipos[i].precio_unitario;
            product_men_prc=i;
        }
        
        // obtenemos el mayor y menor cantidad de unidades
        if (may_cant<lst_equipos[i].Cantidad)
        {
            may_cant=lst_equipos[i].Cantidad;
            product_may_cant=i;
        }
        if (men_cant>lst_equipos[i].Cantidad)
        {
            men_cant=lst_equipos[i].Cantidad;
            product_men_cant=i;
        }
    }
    
    // promedio de edad de los empleados 
    prom_edade_emps=sum_edad/cant_emp;
    // porcentajes por clasificacion de empleados 
    porct_c1=(cant_c1/cant_emp)*100;
    porct_c2=(cant_c2/cant_emp)*100;
    porct_c3=(cant_c3/cant_emp)*100;

    cout<<"\n Empleados \n";
    cout<<"     Promedio de edad: "<<prom_edade_emps<<endl;
    cout<<"     prodentajes por clasificacion: "<<endl;
    cout<<"     clf 1: "<<porct_c1<<endl;
    cout<<"     clf 2: "<<porct_c2<<endl;
    cout<<"     clf 3: "<<porct_c3<<endl;

    // promedio de precios unitarios de equipos
    prom_precio_unitario=sum_precio_unitario/cant_e;
    cout<<"\n Empleados \n";
    cout<<"     Promedio de precios unitarios: "<<prom_precio_unitario<<endl;
    cout<<"     producto con mayor precio: "<<endl;
    cout<<"         nombre: "<<lst_equipos[product_may_prc].Nombre<<endl;
    cout<<"         Precio unitario: "<<lst_equipos[product_may_prc].precio_unitario<<endl;
    cout<<"     producto con menr precio: "<<endl;
    cout<<"         nombre: "<<lst_equipos[product_men_prc].Nombre<<endl;
    cout<<"         Precio unitario: "<<lst_equipos[product_men_prc].precio_unitario<<endl;

    cout<<"     producto con mayor cantidad disponible: "<<endl;
    cout<<"         nombre: "<<lst_equipos[product_may_cant].Nombre<<endl;
    cout<<"         Cantidad: "<<lst_equipos[product_may_cant].Cantidad<<endl;
    cout<<"     producto con menr cantidad disponible: "<<endl;
    cout<<"         nombre: "<<lst_equipos[product_men_cant].Nombre<<endl;
    cout<<"         Cantidad: "<<lst_equipos[product_men_cant].Cantidad<<endl;

}


// -------  funcion lectura y guardado de datos -------------------------------- 
/* esta funcion lee y guarda datos de un 1archivo1 externo 
   en una estructura de datos pre declafrada en x programa 
   como en este caso
   
   se toma como parametro el nombre del 1archivo1 a leer 
   y en proceso se procesan y guardan los datos 
   en la estructura correspondiente 
*/
int leer_asiganr_empleados(){
    // declaramos y habrimos el archivo1 a leer
	ifstream archivo1;
	archivo1.open("empleados.csv", ios::in);
	if (archivo1.fail()) { // validamos la existencia del archivo1 
		cout << "* No se puedo leer el archivo1." << endl;
		exit(1);
	}
    
    // variables auxiliares 
    string nombre_aux, apellido_aux, aux_profesion ,linea,auxiliar;
    int aux_id, aux_edad, aux_fi[3], aux_ff[3], aux_clasificacion;
    
    // cantidad de clientes ya guardados 
    int contador=0;
    // recorremos el 1archivo1 de lectura linea oir linea 
	while (getline(archivo1, linea)) {
		stringstream stream(linea);
    // usamos un separador ; para identificar cada dato y asiganrlo a su correspondiente variable axuliar  
		getline(stream, auxiliar, ';');
        aux_id = atoi(auxiliar.c_str()); // id 
        getline(stream, nombre_aux, ';'); // nombre 
		getline(stream, apellido_aux, ';');// apellido
        getline(stream, aux_profesion, ';'); // profesion
        getline(stream, auxiliar, ';');
		aux_edad = atoi(auxiliar.c_str()); // edad 
        

        getline(stream, auxiliar, '/');
        aux_fi[0] = atoi(auxiliar.c_str()); // fecha inicion dia 
        getline(stream, auxiliar, '/');
        aux_fi[1] = atoi(auxiliar.c_str()); // fecha inicion mes 
        getline(stream, auxiliar, ';');
        aux_fi[2] = atoi(auxiliar.c_str()); // fecha inicion anio
        
        getline(stream, auxiliar, '/');
        aux_ff[0] = atoi(auxiliar.c_str()); // fecha final dia 
        getline(stream, auxiliar, '/');
        aux_ff[1] = atoi(auxiliar.c_str()); // fecha final mes 
        getline(stream, auxiliar, ';');
        aux_ff[2] = atoi(auxiliar.c_str()); // fecha final anio

        getline(stream, auxiliar, ';');
		aux_clasificacion = atoi(auxiliar.c_str());  // clasificacion

        
        // agregamos los datos a la estructura de lista de empleaods
        emplds[contador].ID=aux_id;
        emplds[contador].Nombre=nombre_aux;
        emplds[contador].Apellido=apellido_aux;
        emplds[contador].Edad=aux_edad;
        emplds[contador].Profesion=aux_profesion;
        emplds[contador].Fecha_ingreso[0]=aux_fi[0];
        emplds[contador].Fecha_ingreso[1]=aux_fi[1];
        emplds[contador].Fecha_ingreso[2]=aux_fi[2];
        emplds[contador].Fecha_finalizacion[0]=aux_ff[0];
        emplds[contador].Fecha_finalizacion[1]=aux_ff[1];
        emplds[contador].Fecha_finalizacion[2]=aux_ff[2];
        emplds[contador].clasificacion=aux_clasificacion;

        contador+=1;
    }
    archivo1.close();
    return contador;
}

int leer_asignar_equipos(){
    // declaramos y habrimos el archivo a leer
	ifstream archivo;
	archivo.open("equipo.csv", ios::in);
	if (archivo.fail()) { // validamos la existencia del archivo 
		cout << "* No se puedo leer el archivo." << endl;
		exit(1);
	}
    
    // variables auxiliares 
    string nombre_aux, aux_responsable, linea, auxiliar;
    int aux_id, aux_cantidad, aux_fi[3];
    float aux_precio_unitario;
    

    // cantidad de clientes ya guardados 
    int contador=0;
    // recorremos el 1archivo1 de lectura linea oir linea 
	while (getline(archivo, linea)) {
		stringstream stream(linea);
    // usamos un separador ; para identificar cada dato y asiganrlo a su correspondiente variable axuliar  
		getline(stream, auxiliar, ';');
        aux_id = atoi(auxiliar.c_str()); // id 
        getline(stream, nombre_aux, ';'); // nombre producto 
		getline(stream, auxiliar, ';');
        aux_precio_unitario = atof(auxiliar.c_str()); // precio unitario
        getline(stream, auxiliar, ';');
        aux_cantidad = atoi(auxiliar.c_str()); // cantidad del equipo
        getline(stream, auxiliar, '/');
        aux_fi[0] = atoi(auxiliar.c_str()); // dia fecha de ingreso 
        getline(stream, auxiliar, '/');
        aux_fi[1] = atoi(auxiliar.c_str()); // mes fecha de ingreso 
        getline(stream, auxiliar, ';');
        aux_fi[2] = atoi(auxiliar.c_str()); // anio fecha de ingreso 
        getline(stream, aux_responsable, ';'); // responsable del equipo

        // agragamos los datos a la lista de equipos 
        lst_equipos[contador].ID=aux_id;
        lst_equipos[contador].Nombre=nombre_aux;
        lst_equipos[contador].precio_unitario=aux_precio_unitario;
        lst_equipos[contador].Cantidad=aux_cantidad;
        lst_equipos[contador].Fecha_ingreso[0]=aux_fi[0];
        lst_equipos[contador].Fecha_ingreso[1]=aux_fi[1];
        lst_equipos[contador].Fecha_ingreso[2]=aux_fi[2];
        lst_equipos[contador].responsable=aux_responsable;

        contador+=1;
    }
  
    archivo.close();
    return contador;
}


void guardar_empleados(int cant_emp){
    // declaramos y habrimos el archivo a leer
	ifstream archivo;
	archivo.open("empleados.csv", ios::in);
	if (archivo.fail()) { // validamos la existencia del archivo 
		cout << "* No se puedo leer el archivo." << endl;
		exit(1);
	}
    
    // declaramos variable temporal de escrituras de datos 
    ofstream temporal; 
	temporal.open("temporal.csv", ios::out);
    if (temporal.fail()) {
		exit(1);
	} 

    // escribimos los datos almacenados en la lista de empleados en el archivo temporal
    for (int i = 0; i < cant_emp; i++){
        temporal<<emplds[i].ID<<";";
        temporal<<emplds[i].Nombre<<";";
        temporal<<emplds[i].Apellido<<";";
        temporal<<emplds[i].Profesion<<";";
        temporal<<emplds[i].Edad<<";";
        temporal<<emplds[i].Fecha_ingreso[0]<<"/"<<emplds[i].Fecha_ingreso[1]<<"/"<<emplds[i].Fecha_ingreso[0]<<";";
        temporal<<emplds[i].Fecha_finalizacion[0]<<"/"<<emplds[i].Fecha_finalizacion[1]<<"/"<<emplds[i].Fecha_finalizacion[0]<<";";
        temporal<<emplds[i].clasificacion<<endl;
        
    }

    // cerramos archivos de lectura y guardado
    archivo.close();
    temporal.close();

    // eliminamos el archivom de empleados inicial
    remove("empleados.csv");
    // renombramos el archivo temporal
    rename("temporal.csv","empleados.csv");
}

void guardar_equipos(int cant_e){
    // declaramos y habrimos el archivo a leer
	ifstream archivo;
	archivo.open("equipo.csv", ios::in);
	if (archivo.fail()) { // validamos la existencia del archivo 
		cout << "* No se puedo leer el archivo." << endl;
		exit(1);
	}
    
    // declaramos variable temporal de escrituras de datos 
    ofstream temporal; 
	temporal.open("temporal.csv", ios::out);
    if (temporal.fail()) {
		exit(1);
	} 

    // escribimos los datos almacenados en la lista de empleados en el archivo temporal
    for (int i = 0; i < cant_e; i++){
        temporal<<lst_equipos[i].ID<<";";
        temporal<<lst_equipos[i].Nombre<<";";
        temporal<<lst_equipos[i].precio_unitario<<";";
        temporal<<lst_equipos[i].Cantidad<<";";
        temporal<<lst_equipos[i].Fecha_ingreso[0]<<"/"<<lst_equipos[i].Fecha_ingreso[1]<<"/"<<lst_equipos[i].Fecha_ingreso[0]<<";";
        temporal<<lst_equipos[i].responsable<<endl;
        
    }

    // cerramos archivos de lectura y guardado
    archivo.close();
    temporal.close();

    // eliminamos el archivom de equipos inicial
    remove("equipo.csv");
    // renombramos el archivo temporal
    rename("temporal.csv","equipo.csv");
}