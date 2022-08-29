#include "lista.h"

lista::lista(){
  prim = ultm = NULL; 
}

void lista::pedirDatos(){
    string nombre, code;
    int sex;
    char tipo ;
    double salaario;
    char res = 's';
    while (res == 's' || res == 'S') {
        // ingreso de los datos 
        cout << "\n\nDigite el codigo del empleado ";cin>>code;
        if (validar(code) == 0) {

            cout << "\n Nombre: ";cin >> nombre;
        
        // solicitud y validacion del sexo
        do
        {
            cout << "\n Sexo \n 1=femenino \n 2= masculino \n eliga: ";cin >> sex;
            if (sex<1 || sex>2)
            {
                cout<<" porfavor ingresar F(femenino) o m(masculino)!!";
            }
        } while (sex<1 || sex>2);
        
        // solicitud y validacion del tipo de contrato
        do
        {
            cout<<"\n Tipo de contrato(C / S):";cin>>tipo;
            if ((tipo =! 's') || (tipo =! 'S') || (tipo =! 'c') || (tipo =! 'C'))
            {
                cout<<" solo ingresas las opcions \n c = por contrarto \n s = prestacion de servicios 'n";
            }
        } while ((tipo =! 's') || (tipo =! 'S') || (tipo =! 'c') || (tipo =! 'C'));
        
        // solicitud y validacion del salario
        do
        {
            cout<<"\n salaario:";cin>>salaario;
            if (salaario<0)
            {
                cout<<" no ingresar numeros negativos para los salaario !!";
            }
            
        } while (salaario<0);

            entrarDatos(code, nombre, sex, tipo, salaario);
            cout << "\n\tDatos guardado con exito\n";
        } else
            cout << "\n\tDatos existente no se guardaron\n";
        do {
            cout << "\n\nDesea entrar otros datos (s/n): ";
            cin>>res;
            } while (res != 's' && res != 'S' && res != 'n' && res != 'N');
        }
}

void lista::entrarDatos(string code, string name, int sex, char tip, double salaario){
  nuevo = (struct nodo *) new (struct nodo);
  nuevo->code = code;
  nuevo->name= name;
  nuevo->sexo = sex;
  nuevo->tipo = tip;
  nuevo->salario = salaario;
  nuevo->sig = nuevo->ant = NULL;
  if(prim == NULL){
    prim = ultm = nuevo;
  }
  else{
    ultm->sig = nuevo;
    nuevo->ant = ultm;
  }
  ultm=nuevo;
}

void lista::quitarDatos(){
  string code;
  char res = 's';
  while (res == 's' || res == 'S') {
    cout << "\n\nDigite el codigo del empleado: ";cin>>code;
    if (validar(code) == 1) {
      borrarDatos(code);
      cout << "\n\tDato borrado con exito\n";
    } else
      cout << "\n\tEl dato no existe\n";
    do {
      cout << "\n\nDesea borrar otro dato (s/n): ";
      cin>>res;
        } while (res != 's' && res != 'S' && res != 'n' && res != 'N');
    }
}

void lista::borrarDatos(string v){
  struct nodo *p = prim;
  if(prim->code == v){
    prim = prim->sig;
    prim->ant = NULL;
    delete(p);
  }
  else{
    if(ultm->code == v){
      p = ultm;
      ultm = ultm->ant;
      ultm->sig = NULL;
      delete(p);
    }
    else{
      while(p->code != v){
        p = p->sig;
      }
      p->ant->sig = p->sig;
      p->sig->ant = p->ant;
      delete(p);
    }
  }
}

int lista::validar(string v){
  struct nodo *p = prim;
  while(p != NULL and p->code != v){
    p = p->sig;
  }
  if(p == NULL){
    return 0;
  }
  return 1;
}

void lista::imprimir1(){
  struct nodo *p = prim;
  cout << "\n\n EMPLEADOS";
  cout<<"--------------------------------\n";
  while(p != NULL){
    cout <<" codigo:"<<p->code<<endl;
    cout <<" nombre:"<<p->name<<endl;
    cout <<" sexo:";
    if (p->sexo==1)
    {
      cout<<"Femenino \n";
    }
    else{
      cout<<"Masculino \n";
    }
    cout <<" Tipo de contrato:"<<p->tipo<<endl;
    cout <<" Salario:"<<p->salario<<endl;
    cout<<"--------------------------------";
    p = p->sig;
  }
  cout << "\n";
}

void lista::mostra_stadisticas(){
    struct nodo *p = prim;

    // variables auxiliares 
    int  cantMujeres=0, cantHombres=0, cantCc=0 ,cantCs=0, cantSal2mill=0, cantE=0;

    while(p != NULL){
        // obtenemos las cantidades de hombres y mujeres 
        if (p->sexo==1)
        {
            cantMujeres+=1;
        }
        else{
            cantHombres+=1;
        }

        // cantidad de personas por tipo de contrato 
        if (p->tipo=='c' || p->tipo=='C')
        {
            cantCc+=1;
        }
        else{
            cantCs+=1;
        }
        
        // cantidad de personas que ganan mas de 2 millones 
        if (p->salario>=2000000)
        {
            cantSal2mill+=1;
        }

    cantE+=1;
    p = p->sig;
  }

  // obtenemos los porcentajes de mujeres y hombres
    float porcentM = (cantMujeres*100)/cantE;
    float porcentH = (cantHombres*100)/cantE; 

    cout<<"\n\n     ESTADISTICAS \n";
    cout<<" Porcentajede mujeres:"<<porcentM<<endl;
    cout<<" Porcentajede hombres:"<<porcentH<<endl;
    cout<<" Empleatos tipo C:"<<cantCc<<endl;  
    cout<<" Empleados tipo S:"<<cantCs<<endl;
    cout<<" Cant empleados que ganana mas de 2 millones:"<<cantSal2mill<<endl;
}

