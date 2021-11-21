#include <iostream>
using namespace std;

int main(){
	int x,y,a,b,c,d,e,f;

	for(int i=1; i<=4; i++){
		cout<<" sistema de ecuaciones "<<i<<endl;
		// solicitamos datos de la primera ecuacion 
		cout<<" ecuacion 1 del sistema\n";
		cout<<" coeficiente de x: ";cin>>a;
		while(a==0){
			cout<<" ingrese el coeficiente de x nuevamente: ";cin>>a;
		}
		cout<<" coeficiente de y: ";cin>>b;
		while(b==0){
			cout<<" ingrese el coeficiente de y nuevamente: ";cin>>b;
		}
		cout<<" termino independiente: ";cin>>c;
		// solicitamos datos de la segunda ecuacion 
		cout<<"\n ecuacion 2 del sistema\n";
		cout<<" coeficiente de x: ";cin>>d;
		while(d==0){
			cout<<" ingrese el coeficiente de x nuevamente: ";cin>>d;
		}
		cout<<" coeficiente de y: ";cin>>e;
		while(e==0){
			cout<<" ingrese el coeficiente de x nuevamente: ";cin>>e;
		}
		cout<<" termino independiente : ";cin>>f;

		cout<<"\n tenemos el sitema de ecuaciones lineales \n";
		cout<<a<<"X + ("<<b<<"Y) = "<<c<<endl;
		cout<<d<<"X + ("<<e<<"Y) = "<<f<<endl;

		// resolvemos el sistemas
		x=((c*e)-(b*f)) / ((a*e)-(b*d));
		y=((a*f)-(c*d)) / ((a*e)*(b*d));

		cout<<"tenemos como respuestas del sitema de ecuaciones "<<i<<"\n";
		cout<<" X = "<<x<<endl;
		cout<<" Y = "<<y<<endl;
	}

	return 0;
}
