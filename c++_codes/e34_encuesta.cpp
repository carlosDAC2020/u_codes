#include<iostream>
using namespace std;

// declaramos funciones a utilizar

void prom_edades(int eda_d[], int sex_o[], int cant){
	// variables para sumatorias
	int sum_edad_m=0, sum_edad_f=0, sum_edad_total;
	// variables para cantidades
	int cant_m=0, cant_f=0;
	// promedios
	float prom_edad_m, prom_edad_f, prom_edad_total;

	// procedimiento
	for (int i=0; i<cant; i++){
		// suma de edades para el promedio total
		sum_edad_total+=eda_d[i];

		// para los hombres
		if(sex_o[i]==1){
			sum_edad_m+=eda_d[i]; // sumatoria de edades de los hombes 
			cant_m+=1; // cantidad de hombres
		}
		// para las mujeres
		else{
			sum_edad_f+=eda_d[i]; // sumatoria de edades de las mujeres
			cant_f+=1; // cantidad de mujeres
		}
	}
	// obtenemos promedios 
	prom_edad_m= sum_edad_m / cant_m; // hombres
	prom_edad_f= sum_edad_f / cant_f; // mujeres
	prom_edad_total= sum_edad_total / cant; // total

	cout<<"\n promedios de las edades\n";
	cout<<"------------------------\n";
	cout<<"        | promedio "<<endl;
	cout<<"------------------------\n";
	cout<<" mujeres| "<<prom_edad_f<<endl;
	cout<<" hombres| "<<prom_edad_m<<endl;
	cout<<" totales| "<<prom_edad_total<<endl;
}

void prom_ingresos(float ingres_os[], int sex_o[], int cant){
	// variables para sumatorias
	int sum_ingre_m=0, sum_ingre_f=0, sum_ingre_total;
	// variables para cantidades
	int cant_m=0, cant_f=0;
	// promedios
	float prom_ingre_m, prom_ingre_f, prom_ingre_total;

	// procedimiento
	for (int i=0; i<cant; i++){
		// suma de edades para el promedio total
		sum_ingre_total+=ingres_os[i];

		// para los hombres
		if(sex_o[i]==1){
			sum_ingre_m+=ingres_os[i]; // sumatoria de ingresos de los hombes 
			cant_m+=1; // cantidad de hombres
		}
		// para las mujeres
		else{
			sum_ingre_f+=ingres_os[i]; // sumatoria de ingresos de las mujeres 
			cant_f+=1; // cantidad de mujeres
		}
	}
	// obtenemos promedios 
	prom_ingre_m= sum_ingre_m / cant_m; // hombres
	prom_ingre_f= sum_ingre_f / cant_f; // mujeres
	prom_ingre_total= sum_ingre_total / cant; // total

	cout<<"\n promedios de los ingresos\n";
	cout<<"------------------------\n";
	cout<<"        | promedio "<<endl;
	cout<<"------------------------\n";
	cout<<" mujeres| "<<prom_ingre_f<<endl;
	cout<<" hombres| "<<prom_ingre_m<<endl;
	cout<<" totales| "<<prom_ingre_total<<endl;
}

void porcentaje_sexos(int sex_o[], int cant){
	// variables para cantidades
	int cant_m=0, cant_f=0;
	// promedios
	float porcentaje_m, porcentaje_f;

	// procedimiento
	for (int i=0; i<cant; i++){
		
		// para los hombres
		if(sex_o[i]==1){
			cant_m+=1; // cantidad de hombres
		}
		// para las mujeres
		else{
			cant_f+=1; // cantidad de mujeres
		}
	}
	// porcentajes
	porcentaje_m= (cant_m/cant)*100; // hombres
	porcentaje_f= (cant_f/cant)*100; // mujeres

	cout<<"\n porcentaje de los sexoa\n";
	cout<<"------------------------\n";
	cout<<"        | porcentaje "<<endl;
	cout<<"------------------------\n";
	cout<<" mujeres| "<<porcentaje_f<<" %"<<endl;
	cout<<" hombres| "<<porcentaje_m<<" %"<<endl;
}


int main(){
	// solicitamos la cantidad de personas
	int cant_e;
	cout<<" numero de personas a encuestar: ";cin>>cant_e;
	while(cant_e<1 || cant_e>10){
		cout<<"\n el rango de personas encuestadas debe ser de 1 a 10\n";
		cout<<" ingresa numero de personas a encuestar nuevamente: ";cin>>cant_e;
	}
	
	// declaramos las listas donde guardaremos los datos
	string cod[cant_e], name[cant_e];
	int sexo[cant_e], edades[cant_e];
	float ingresos[cant_e];

	// variables axuliriales para el algoritmo

	cout<<"\n ENCUESTA	\n";
	// ingreso de datos
	for(int i=0; i<cant_e; i++){
		cout<<"\n encuestado "<<i+1<<endl;
		cout<<" codigo: ";cin>>cod[i];

		cout<<" nombre: ";cin>>name[i];
		
		cout<<" edad: ";cin>>edades[i];
		
		cout<<" sexo \n 1=masculino \n 2=femenino \n ---->: ";cin>>sexo[i];
		while(sexo[i]<1 || sexo[i]>2 ){
			cout<<"\n valor ingresado no valido\n";
			cout<<" ingrese el sexo nuevamente: ";cin>>sexo[i];
		}
		cout<<" ingresos: ";cin>>ingresos[i];

	}

	int pregunta=1;
	while (pregunta==1){
		cout<<"\n---------------------------------------------------";
		cout<<"\n que datos de la encuesta decea ver ? ";
		cout<<"\n---------------------------------------------------\n";
		cout<<"--->1 mostar datos de la encuesta \n";
		cout<<"--->2 promedio de edad de los hombres, mujeres y en general\n";
		cout<<"--->3 promedio de ingresos al año de los hombres, mujeres y en general\n";
		cout<<"--->4 porcentaje de hombres y de mujeres \n";

		int option;
		cout<<"\n escoja el numero de su opcion:";cin>>option;
			while (option>4 || option<1){
				cout<<"\n valor ingresado no valido\n";
				cout<<" escoja el numero de su opcion nuevamente:";cin>>option;
			}

		if (option==1){ // imprecion de datos
			cout<<"\n datos de la encuesta \n";
			cout<<" codigo   | nombre   | sexo   | edad   | ingresos"<<endl;
			cout<<"\n---------------------------------------------------\n";
			for(int i=0; i<cant_e; i++){
				cout<<" "<<cod[i]<<"   "<<name[i]<<"   "<<sexo[i]<<"   "<<edades[i]<<"   "<<ingresos[i]<<endl;
			}
			cout<<"\n---------------------------------------------------";
		}
		else if (option==2){  // promedio de edad de los hombres, mujeres y en general
			prom_edades(edades, sexo, cant_e);
		}
		else if (option==3){  // promedio de ingresos al año de los hombres, mujeres y en general
			prom_ingresos(ingresos, sexo, cant_e);
		}
		else{ //porcentaje de hombres y de mujeres 
			porcentaje_sexos(sexo, cant_e);
		}
		cout<<"\n\n desea volver al menu \n-- 1 si\n--!=1 no";
		cout<<"\n responda:";cin>>pregunta;
	}

    return 0;
}