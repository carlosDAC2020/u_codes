#include "encuesta.h"

encuesta::encuesta(){
  prim = ultm = NULL;
}

void encuesta::pedirDatos() {
  string cod,name;
  int eda, sex, ne;
  float ingresos;
  cout<<" a cuantas personas se encuestara?: ";cin>>ne;
  
  for(int i=1; i<=ne; i++) {
    cout << "\n\n Datos del Encuestado "<<i;
    cout<<"\n codigo:";cin >> cod;
    if (validar(cod) == 0) {
        cout << "\n Nombre: ";cin >> name;
        do
        {
            cout << "\n Sexo \n 1=femenino \n 2= masculino \n eliga: ";cin >> sex;
            if (sex<1 || sex>2)
            {
                cout<<" porfavor ingresar F(femenino) o m(masculino)!!";
            }
        } while (sex<1 || sex>2);
        do
        {
            cout<<"\n Edad:";cin>>eda;
            if (eda<0)
            {
                cout<<" no ingresar numeros negativos para la edad !!";
            }
        } while (eda<0);
        do
        {
            cout<<"\n Ingresos:";cin>>ingresos;
            if (ingresos<0.0)
            {
                cout<<" no ingresar numeros negativos para los ingresos !!";
            }
            
        } while (ingresos<0.0);
        
      entrarDatos(cod,name,sex,eda,ingresos);
      cout << "\n\tEncuesta guardado con exito\n";
    } 
    else
    {
        cout << "\n\tEncuesta ya existente, no se guardo\n";
    }
  }
}

void encuesta::entrarDatos(string code, string name, int sex, int edad, float ingresos) {
  nuevo = (struct nodo *) new (struct nodo);
  nuevo->codigo = code;
  nuevo->nombre = name;
  nuevo->sexo = sex;
  nuevo->edad = edad;
  nuevo->ingresosA = ingresos;
  nuevo->sig = NULL;
  if(prim == NULL)
    prim = nuevo;
  else
    ultm->sig = nuevo;

  ultm = nuevo;
}

int encuesta::validar(string v) {
  struct nodo *p = prim;
  while(p != NULL and p->codigo != v)
    p = p->sig;
  if(p == NULL) return 0;
  return 1;
}

void encuesta::borrarDatos(string v) {
  struct nodo *p = prim;
  if(prim->codigo == v){
    prim = prim->sig;
    delete(p);
  }
  else{
    struct nodo *q = prim->sig;
    while(q->codigo != v){
      p = p->sig;
      q = q->sig;
    }
    if(ultm == q){
      ultm = p;
      ultm->sig = NULL;
      delete(q);
    }
    else{
      p->sig = q->sig;
      delete(q);
    }
  }
}

void encuesta::quitarDatos(){
  string cod;
  char res = 's';
  while (res == 's' || res == 'S') {
    cout << "\n\nDigite codigo del encuestado a borrar: ";
    cin>>cod;
    if (validar(cod) == 1) {
      borrarDatos(cod);
      cout << "\n\tDato borrado con exito\n";
    } else
      cout << "\n\tEl dato no existe\n";
    do {
        cout << "\n\nDesea borrar otro dato (s/n): ";
        cin>>res;
    } while(res != 's' && res != 'S' && res != 'n' && res != 'N');
  }
}

void encuesta::imprimir() {
  struct nodo *p = prim;
  cout << "Listado de encuestados \n";
  int n=1;
  while(p != NULL)
  {
    cout << " Encuestado "<<n<<endl;
    cout << " Codigo :"<<p->codigo<<endl;
    cout << " Nombre :"<<p->nombre<<endl;
    cout << " Sexo :";
    if (p->sexo==1)
    {
      cout<<"Femenino \n";
    }
    else{
      cout<<"Masculino \n";
    }
    
    cout << " ingresos :"<<p->edad<<endl;
    cout << " Ingresos :"<<p->ingresosA<<endl;
    cout<<endl;
    p = p->sig;
  }
  cout << "\n";
}

void encuesta::promEdad(){
    struct nodo *p = prim;
    int sumEdadGeneral=0, sumEdadMujeres=0, CantMujeres=0, sumEdadHombres=0, CantHombres=0;
    int ne=0;
    while (p != NULL)
    {
        sumEdadGeneral+=p->edad;
        ne+=1;
        if (p->sexo==1)
        {
            sumEdadMujeres+=p->edad;
            CantMujeres+=1;
        }
        else
        {
            sumEdadHombres+=p->edad;
            CantHombres+=1;
        }
        
        p = p->sig;
    }

    float promEdadGeneral = sumEdadGeneral / ne;
    float promEdadMujeres = sumEdadMujeres / CantMujeres;
    float promEdadHombres = sumEdadHombres / CantHombres;
    
    cout<<"\n    promedio de edades \n";
    cout<<" General:"<<promEdadGeneral<<" \n";
    cout<<" Mujeres:"<<promEdadMujeres<<" \n";
    cout<<" Hombre:"<<promEdadHombres<<" \n";

}

void encuesta::promIngresos(){
    struct nodo *p = prim;
    int sumIngresosGeneral=0, sumIngresosMujeres=0, CantMujeres=0, sumIngresosHombres=0, CantHombres=0;
    int ne=0;
    while (p != NULL)
    {
        sumIngresosGeneral+=p->ingresosA;
        ne+=1;
        if (p->sexo==1)
        {
            sumIngresosMujeres+=p->ingresosA;
            CantMujeres+=1;
        }
        else
        {
            sumIngresosHombres+=p->ingresosA;
            CantHombres+=1;
        }
        p = p->sig;
    }

    float promIngresosGeneral = sumIngresosGeneral / ne;
    float promIngresosMujeres = sumIngresosMujeres / CantMujeres;
    float promIngresosHombres = sumIngresosHombres / CantHombres;
    
    cout<<"\n    promedio de ingresoses \n";
    cout<<" General:"<<promIngresosGeneral<<" \n";
    cout<<" Mujeres:"<<promIngresosMujeres<<" \n";
    cout<<" Hombre:"<<promIngresosHombres<<" \n";

}

void encuesta::porcentajes(){
    struct nodo *p = prim;

    int CantMujeres=0, CantHombres=0, ne=0;

    while (p == NULL)
    {
         if (p->sexo==1)
        {
            CantMujeres+=1;
        }
        else
        {
            CantHombres+=1;
        }
        p = p->sig;
        ne+=1;
    }
    
    float porcentMujeres = (CantMujeres / ne) * 100;
    float porcentHombres = (CantHombres / ne) * 100;

    cout<<"\n    Porcentajes \n";
    cout<<" Mujeres:"<<porcentMujeres<<"% \n";
    cout<<" Hombre:"<<porcentHombres<<"% \n";
}