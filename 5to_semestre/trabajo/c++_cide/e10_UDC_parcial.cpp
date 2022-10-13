/*Almacenes Éxito desea un programa que le permita obtener los siguientes datos:
- Porcentaje de clientes que pagaron con tarjeta Éxito, efectivo, otro medio de pago.
- Promedio de ventas del día.
- Monto de la venta máxima y mínima registrada.*/

#include <iostream>
#include <ctype.h> //Biblioteca para usar+ toupper y tolower
#include <locale.h>
using namespace std;

int main ()

{
	setlocale(LC_CTYPE, "Spanish");
	
	int clientes = 0;
	char centinela; //Variable iteradora encargada de controlar el ciclo
	long valordecompra;
	int mediodepago;
	float efec = 0, texito = 0, otro = 0, porefec, portexito, porotro;
	float sumaventa = 0, proventa;
	long max = 0, min = 999999999999;
	
	cout<<"¿Desea iniciar el registro de ventas?  [S]i - [N]o:";
	cin>>centinela;
	
	centinela = toupper(centinela); //Se convierte el caracter en mayúscula (para minúscula se usa "tolower")
	
	while (centinela == 'S')
	{
		system ("cls");
		
		cout<<"Datos del cliente número " <<++clientes <<endl; //++cliente es un contador en prefijo que se usa en instrucciones 2 en 1 como esta, el contador se incrementa y después usa el valor. Si, fuese cliente++, primero usara el valor y después se incrementaría él mismo.
		cout<<"\nMonto de la venta: $";
		cin>>valordecompra;
		
		sumaventa += valordecompra;
					
		//Validar que la opción digitada sea 1, 2 o 3
		do
		{
			system ("cls");
			cout<<"\nMedio de pago:" <<endl;
			cout<<"1. Efectivo" <<endl;
			cout<<"2. Tarjeta de crédito" <<endl;
			cout<<"3. Otro medio de pago" <<endl;
			cin>>mediodepago;
			if(mediodepago<1 || mediodepago>3)
			{
				cout<<"\nPor favor, digite una opción válida." <<endl;
				system ("pause");
				system ("cls");
			}
		}while (mediodepago<1 || mediodepago>3);
		
		if (mediodepago == 1)
		{
			efec++;
		}
		else 
		{
			if (mediodepago == 2)
			{
				++texito;
			}
			else
			{
				otro += 1;
			}
		}
		
		if (clientes == 1)
		{
			max = min = valordecompra;
		}
		else
		{
			if (valordecompra > max)
			{
			max = valordecompra;
			}
			else
			{
				if (valordecompra < min)
				{
				min = valordecompra;
				}
			}
		}
		
	system ("cls");
	cout<<"¿Desea registrar otra venta? [S]i - [N]o: ";
	cin>>centinela;
	centinela = toupper(centinela);
	}
	if(clientes == 0)
	{
		cout<<"No se registraron ventas"<<endl;
	}
	else
	{
		porefec = efec / clientes * 100;
		portexito = texito / clientes * 100;
		porotro = otro / clientes * 100;
		proventa = sumaventa / clientes;
		
		system ("cls");
		cout<<"Porcentaje de clientes que cancelaron con efectivo: " <<porefec <<"%" <<endl;
		cout<<"Porcentaje de clientes que cancelaron con tarjeta Éxito: " <<portexito <<"%" <<endl;
		cout<<"Porcentaje de clientes que cancelaron con otro medio de pago: " <<porefec <<"%" <<endl;
		cout<<"Promedio de ventas del día: $" <<proventa <<endl;
		cout<<"Monto de la venta máxima: $" <<max <<endl;
		cout<<"Monto de la venta mínima: $" <<min;	
	}
	
}