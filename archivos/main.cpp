#include <iostream> 
#include <fstream> 
#include <cmath> 
#include <stdlib.h>
using namespace std;    

int main() { 
	// variable auxiliar para almacenar los datos de las personas en forma de caracteres
   	string linea; 

	// variables que iran almacenado los datos de las personas 
   	string id; 
    string nombre; 
    int genero; 
    float estatura; 
    float peso; 
    int edad;
	float imc=0.0;

	// abrimos el atrchivo datos en modo lectorua 
	ifstream lectura; 			
	lectura.open("datos.csv", ios::in);
	if (lectura.fail()) {
		exit(1);
	}    

	// archivo con datos de jovenes con sobrepeso edad<25 imc>25
	ofstream jov_sobrepeso; 
	jov_sobrepeso.open("jov_sobrepeso.csv",ios::out); 
	if (jov_sobrepeso.fail()) {
		exit(1);
	}   

	// archivo con datos de jovenes con bajo peso edad<25 imc<18..}5
	ofstream jov_bajo_peso; 
	jov_bajo_peso.open("jov_bajo_peso.csv",ios::out); 
	if (jov_bajo_peso.fail()) {
		exit(1);
	}   

	// archivo con los adultos mayores  edad>59 imc nomal 18.5<imc<25
	ofstream adm_peso_normal; 
	adm_peso_normal.open("adm_peso_normal.csv",ios::out); 
	if (adm_peso_normal.fail()) {
		exit(1);
	}  

	// archivo con personas que presenten obecidad morbida imc>40
	ofstream obesidad_morbida; 
	obesidad_morbida.open("obesidad_morbida.csv",ios::out); 
	if (obesidad_morbida.fail()) {
		exit(1);
	}  
	
	int i=0;
	// recorremos el archivo datos.csv 
	while (getline(lectura, linea)) { 
		cout<<"\n\n persona "<<i+1<<endl;
		// asignamos los datos de las personas encontramos en el archvio
		// a la estructura auxiliar pers
			
			// agregamos el id
   		getline(lectura, linea, ';'); 
   		id=linea; 	
		cout<<id<<endl;		

			// agregamos el nombre
   		getline(lectura, linea, ';'); 
   		nombre=linea; 		
		cout<<nombre<<endl;

			// agregamos el genereo pero primero 
			// pasamos el dato encontrado de str a int
   		getline(lectura, linea, ';'); 
   		genero=atoi(linea.c_str()); 
		cout<<genero<<endl;

			// para los datos de peso y estatura los combertimos de tipo str a float 
			// para asignar su correspodiente valor a la estructura pers 
   		getline(lectura, linea, ';');
   		estatura=atof(linea.c_str()); 
		cout<<estatura<<endl;
   		getline(lectura, linea, ';'); 
   		peso=atof(linea.c_str());
		cout<<peso<<endl;

			// agregamos el dato de la edad 
			// a la estructura pers comvirtiendo su tipo de dato str a int 
      	getline(lectura,linea, ';'); 
      	edad=atoi(linea.c_str()); 
		cout<<edad<<endl;

			// calsulamos el valor del IMC de la persona 
   		imc= (peso / pow( (estatura/100) , 2));  
		cout<<imc<<endl;

		// agregamos los jovenes a sus archivo segun su peso
		if (edad<25){
			if (imc>25){ // jovenes con sobrepeso
				jov_sobrepeso<<id<<";";  
				jov_sobrepeso<<nombre << ";";
				jov_sobrepeso<<genero << ";";
       			jov_sobrepeso<<peso<<";";
       			jov_sobrepeso<<estatura<<";";
       			jov_sobrepeso<<edad<<";";
				jov_sobrepeso<<imc<<";"<<endl;
			}
			else if (imc<18.5){	 // jovenes con bajo peso 
				jov_bajo_peso <<id<<";";  
				jov_bajo_peso <<nombre << ";";
				jov_bajo_peso <<genero << ";";
       			jov_bajo_peso <<peso<<";";
       			jov_bajo_peso <<estatura<<";";
       			jov_bajo_peso <<edad<<";";
				jov_bajo_peso <<imc<<";"<<endl;
			}
		}

		// añadimos los datos correspondintes de los adultos mayores con peso normal 
		else if (edad>59){ 
			if(imc>18.5 && imc<25){
				adm_peso_normal <<id<<";";  
				adm_peso_normal <<nombre << ";";
				adm_peso_normal <<genero<< ";";
       			adm_peso_normal <<peso<<";";
       			adm_peso_normal <<estatura<<";";
       			adm_peso_normal <<edad<<";";
				adm_peso_normal <<imc<<";"<<endl;
			}
		}
		
		// hadimos los datos de las personas con obecidad morbida a su correspondiente archivo
		if (imc>40){
			obesidad_morbida <<id<<";";  
			obesidad_morbida <<nombre << ";";
			obesidad_morbida <<genero<< ";";
       		obesidad_morbida <<peso<<";";
       		obesidad_morbida <<estatura<<";";
       		obesidad_morbida <<edad<<";";
			obesidad_morbida <<imc<<";"<<endl;
		}
		i+=1;
	}

	lectura.close(); 
    jov_sobrepeso.close(); 
    jov_bajo_peso.close(); 
	adm_peso_normal.close();
	obesidad_morbida.close();
    cout << "=====ejecutado con exito!!! ====="; 

	
    return 0; 
}