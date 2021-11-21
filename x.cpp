#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstring>
using namespace std;
std::string unused;

void agregarContacto(int);
void eliminarContacto();
void mostrarAgenda();
void vaciarAgenda();
int main (void) {
	int opcion;
	ifstream archivo;
	archivo.open("agenda.csv", ios::in);
	if (archivo.fail()) {
		ofstream archivo;
		archivo.open("agenda.csv", ios::out);
		if (archivo.fail()) {
			cout << "* Error al leer y/o general el archivo." << endl;
			exit(1);
		} else archivo << "id;nombre;apellido;numero;correo" << endl;
	}

  	int numeroDeLineas = 0;
	ifstream in("agenda.csv");
	while ( std::getline(in, unused) ) ++numeroDeLineas;

	cout << "-- Agenda de contactos --\n - Menú -\n [1] -> Agregar un contacto\n [2] -> Eliminar un contacto\n [3] -> Mostrar todos los contactos\n [4] -> Vaciar agenda\n [5] -> Salir\nOpción: "; cin >> opcion;
	switch (opcion) {
		case 1: { 
			agregarContacto(numeroDeLineas - 1);
			main();
		}
		case 2: { 
			eliminarContacto();
			main();
		}
		case 3: { 
			mostrarAgenda();
			main();
		}
		case 4: {
			vaciarAgenda();
			main();
		}
		case 5: { 
			exit(1);
		}
		default: { 
			cout << "* Opción inválida. Intente de nuevo.\n\n"; 
			main();
		}
	}
}

void agregarContacto (int id) {
	ofstream archivo;
	archivo.open("agenda.csv", ios::in | ios::out | ios::app);
	if (!archivo.fail()) {
		string nombre, apellido;
		char correo[50], telefono[20], len;
		char* puntero1 = nullptr;
		char* puntero2 = nullptr;
		bool validoT = false, validoC = false;
		
		cout << "\nNombre: "; cin >> nombre;
		cout << "Apellido: "; cin >> apellido;
		do {
			cout << "Número telefónico: "; cin >> telefono;
			if (strlen(telefono) > 10) {
				cout << "\n * Alerta: El número telefónico excede la cantidad de caracteres permitidos (10)." << endl;
				validoT = false;
			} else if (strlen(telefono) < 10) {
				cout << "\n * Alerta: El número telefónico no cuenta con la cantidad de caracteres requeridos (10)." << endl;
				validoT = false;
			} else validoT = true;
		} while (!validoT);
		do {
			cout << "Correo: "; cin >> correo;
			len = strlen(correo);

			for (int i = 0; i < len; i++) {
				puntero1 = strstr(correo, "@");
				if (puntero1 != nullptr) break;
			}

			for (int i = 0; i< len; i++) {
				puntero2 = strstr(correo, ".");
				if (puntero2 != nullptr) break;
			}

			if (puntero1 != nullptr) {
				if (puntero2 != nullptr) {
					validoC =  true;
				} else cout << "\n * Alerta: Falta un punto (.) luego del símbolo arroba (@)." << endl;
			} else cout << "\n * Alerta: Falta el símbolo arroba (@)." << endl;
		} while (!validoC);

		archivo << id << ';' << nombre << ';' << apellido << ';' << telefono << ';' << correo << endl;

		cout << "\n * Contacto agregado con éxito.\n\n";

		archivo.close();
	}
}

void eliminarContacto () {
	string ID, linea, id, nombre, apellido, telefono, correo;
	ifstream archivo;
	ofstream temporal;
	archivo.open("agenda.csv", ios::in);
	temporal.open("temporal.csv", ios::out);
	if (archivo.fail()) {
		if (temporal.fail()) cout << "* No se pudo leer la agenda." << endl;
	} else {
		temporal << "id;nombre;apellido;numero;correo" << endl;
		cout << "ID del contacto a eliminar: "; cin >> ID;
		getline(archivo, linea);
		while (getline(archivo, linea)) {
			stringstream stream(linea);
			
			getline(stream, id, ';');
			if (id == ID) cout << "\n * Contacto eliminado con éxito\n" << endl;
			else {
				getline(stream, nombre, ';');
				getline(stream, apellido, ';');
				getline(stream, telefono, ';');
				getline(stream, correo, ';');

				temporal << id << ';' << nombre << ';' << apellido << ';' << telefono << ';' << correo << endl;
			}
		} 
		rename("temporal.csv", "agenda.csv");
		temporal.close();
		archivo.close();
	}
}

void mostrarAgenda () {
	string linea, id, nombre, apellido, telefono, correo;
	ifstream archivo;
	archivo.open("agenda.csv", ios::in);
	cout << endl;
	if (getline(archivo, linea)) {
		while (getline(archivo, linea)) {
			stringstream stream(linea);
			
			getline(stream, id, ';');
			getline(stream, nombre, ';');
			getline(stream, apellido, ';');
			getline(stream, telefono, ';');
			getline(stream, correo, ';');

			cout << "- Datos del contacto -\n ID: " << id << "\n Nombre: " << nombre << "\n Apellido: " << apellido << "\n Número telefónico: " << telefono << "\n Correo: " << correo << endl << endl;
		}
	} else cout << "\n * Agenda vacía\n" << endl;
	archivo.close();
}

void vaciarAgenda() {
	ofstream archivo;
	archivo.open("agenda.csv", ios::out);
	if (archivo.fail()) cout << "* No se pudo vaciar la agenda.\n" << endl;
	else {
		archivo << "id;nombre;apellido;numero;correo" << endl;
		cout << "\n * Agenda limpiada con éxito.\n" << endl;
	}
	archivo.close();
}