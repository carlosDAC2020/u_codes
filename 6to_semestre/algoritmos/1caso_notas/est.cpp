
#include "est.h"

lista::lista(){
  prim = ultm = NULL;
}

void lista::pedirDatos() {
  float prom_est, nota;
  string str="s";
  // solicitamos los datos a los estudiante a la par de que vamos obteniendo su promedio segun sus notas 
  while (str=="s" || str=="S")
  {
    prom_est = 0;
    cout<<"\n ingresa datos del estudiante \n";
    cout<<" codigo :";cin>>str;
    do
    {
      cout<<" nota quices :";cin>>nota;
      if (nota<0 || nota>5  )
      {
        cout<<" nota ingresada no valida !! \n";
      }
    } while (nota<0 || nota>5  );
    prom_est+= nota*0.3;

    do
    {
      cout<<" nota trabajos :";cin>>nota;
      if (nota<0 || nota>5  )
      {
        cout<<" nota ingresada no valida !! \n";
      }
    } while (nota<0 || nota>5  );
    prom_est+= nota *0.2;

    do
    {
      cout<<" nota parciales  :";cin>>nota;
      if (nota<0 || nota>5  )
      {
        cout<<" nota ingresada no valida !! \n";
      }
    } while (nota<0 || nota>5  );
    prom_est+= nota *0.5;

      // evaluamos si un estudiante gano o no la materia 
    cout<<"\n La nota definitiva fue de:"<<prom_est<<endl;
    if (prom_est>3.0)
    {
      cout<<" aprobo la materia \n";
      cant_ganados+=1;
      if (prom_est==5.0)
      {
        // guardamos los codigos de los estudiantes que sacaron 5 en la lista enlazada 
        entrarDatos(str);
      }
    }
    else 
    {
      cout<<" Reprobo la materia \n";
      cant_perdidos+=1;
    }

    // vamos obteniendo la sumatoria de los promedios a demas de ka cantidad de estudiantes 
    prom_general+=prom_est;
    cant_est+=1;

    // pevaluamos si se ingresaran mas estudiantes 
    cout << "\n\nDesea entrar otro estudiante (s=si / !s=no): ";cin>>str;
  }  
}

// en este metodo se hace la insercion del codigo de un estudiante a un nodo el cual pertenecera la lista enlazada 
void lista::entrarDatos(string cod) {
  nuevo = (struct nodo *) new (struct nodo);
  nuevo->code = cod;
  nuevo->sig = NULL;
  if(prim == NULL)
    prim = nuevo;
  else
    ultm->sig = nuevo;
  ultm = nuevo;
}


void lista::imprimirResultados() {
  struct nodo *p = prim;
  cout << "\n Resultados de estudiantes \n";
  cout<<" cantidad de estudiantes aprobados :"<<cant_ganados<<endl;
  cout<<" cantidad de estudiantes reprobados :"<<cant_perdidos<<endl;
  prom_general = prom_general / cant_est;
  cout<<" promedio general :"<<prom_general<<endl;
  cout<<"\n Lista de estudiantes que sacaron 5 en el promedio : \n";
  while(p != NULL)
  {
    cout<<p->code<<endl;
    p = p->sig;
  }
  cout << "\n";
}

