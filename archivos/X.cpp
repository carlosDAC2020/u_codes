
#include <iostream> 
#include <fstream> 
#include <cmath> 
#include <stdlib.h>
using namespace std;    

struct persona{ 
    string id; 
    string nombre; 
    int genero; 
    float estatura; 
    float peso; 
    float edad;
};

int main() { 
   	string linea; 
   	persona pers; 
   	float imc= 0.0;
	
	ifstream lectura; 			
	lectura.open("datos.csv");    

	ofstream hombres; 
	hombres.open("hombres.csv"); 
	ofstream mujeres; 
	mujeres.open("mujeres.csv");
	
	while (!lectura.eof()) { 
   		getline(lectura, linea, ';'); 
   		pers.id=linea; 			
   		getline(lectura, linea, ';'); 
   		pers.nombre=linea; 
   		getline(lectura, linea, ';'); 
   		pers.genero=atoi(linea.c_str()); 
   		getline(lectura, linea, ';');
   		pers.estatura=atof(linea.c_str()); 
   		getline(lectura, linea, ';'); 
   		pers.peso=atof(linea.c_str());
      getline(lectura,linea, ';');
      pers.edad=atof(linea.c_str()); 
   		imc = (pers.peso / pow( (pers.estatura/100) , 2))/10; 
   		if ( pers.genero == 1){
       hombres <<pers.id<<";" <<imc<<";"<<endl;  
		   hombres << pers.nombre << ";" << imc << ";" << endl;
       hombres <<pers.peso<<";"<<imc<<";"<<endl;
       hombres <<pers.estatura<<";"<<imc<<";"<<endl;
       hombres <<pers.edad<<";"<<imc<<";"<<endl;
		}
   		else{
          mujeres <<pers.id<<";" <<imc<<";"<<endl;
      		mujeres << pers.nombre << ";" << imc << ";" << endl;
          mujeres <<pers.peso<<";"<<imc<<";"<<endl;
          mujeres <<pers.estatura<<";"<<imc<<";"<<endl;
      
      	}
	}
	lectura.close(); 
    hombres.close(); 
    mujeres.close(); 
    cout << "=====ejecutado con exito!!! ====="; 
    return 0; 
}


