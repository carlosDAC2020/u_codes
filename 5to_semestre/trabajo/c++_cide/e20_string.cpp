
#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;


int main()
{
    // solicitamos al usuario que ingrese dos cadenas de texto
    char cadena1[100]="", cadena2[100]="";
    

    // funciones de la libreria <string>
    cout<<"\n prueba de funciones de la libreria <string> \n";
   
    /* strncat()
    Añade los n priemros caracteres de una cadena de texto a otra
    el valor n es pasdo como parametro al igual que las cadenmas 
    de caracteres
    */ 
    cout<<"\n funcion - strncat() \n ";
    cout<<" ingresa una cadena de texto: ";cin>>cadena1;
    cout<<" ingresa otra cadena de texto: ";cin>>cadena2;
    strncat(cadena1, cadena2, 3);
    cout<<"\n al unir los priemros 3 caracteres de la cadena 2 a la 1 obtenemos \n"<<cadena1;

     /* strcat() 
    une dos cadenas de texto en una sola 
    */
    cout<<"\n funcion - strcat() \n ";
    cout<<" ingresa una cadena de texto: ";cin>>cadena1;
    cout<<" ingresa otra cadena de texto: ";cin>>cadena2;
    strcat(cadena1,cadena2);
    cout<<"\n  union de la cadena 1 y 2 :"<<cadena1<<endl;


    /* empty()
    nos dice si una cadena de texto esta vacia retornando true (verdadero)
    si es asi
    */
   cout<<"\n metodos - empty() \n ";
    string cad_vacia="";
    if (cad_vacia.empty())
    {
        cout<<" la cadena esta vacia ";
    }
    else{
        cout<<" la cadena esta llena ";
    }

    /* size() y length()
    Retorna el tamaño de una cadena de caracteres.
   */
    cout<<"\n metodos - size() y length() \n ";
    string c1, c2;
    cout<<" ingresa una cadena de texto: ";cin>>c1;
    cout<<" tamanio de la cadena del string ("<<c1<<") es de :"<<c1.size()<<endl;
    cout<<" ingresa otra cadena de texto: ";cin>>c2;
    cout<<" tamanio de la cadena del string ("<<c2<<") es de :"<<c2.length()<<endl;


    // funciones con <string.h>
    cout<<"\n prueba de funciones de la libreria <string.h> \n";

    /* strlen()
    nos da el tamaño de uan cadena de caracteres 
   */
    cout<<"\n funcion - strlen() \n ";
    cout<<" ingresa una cadena de texto: ";cin>>cadena1;
    cout<<" ingresa otra cadena de texto: ";cin>>cadena2;

    cout<<"\n tamanios de las cadenas ingresadas \n";
    cout<<" c1: "<<strlen(cadena1)<<endl;
    cout<<" c2: "<<strlen(cadena2)<<endl;

    /* strcpy()
    Se usa para copiar una cadena de texto sobre otra 
   */
    cout<<"\n funcion - strcpy() \n ";
    cout<<" ingresa una cadena de texto: ";cin>>cadena1;
    cout<<" ingresa otra cadena de texto: ";cin>>cadena2;

    cout<<"\n valores inciales de las cadenas ingresadas \n";
    cout<<" c1: "<<cadena1<<endl;
    cout<<" c2: "<<cadena2<<endl;

    cout<<" aplicamos la funcion strcpy() copiamos el valor de c2 en c1 obtenemos \n";
    strcpy(cadena1, cadena2);
    cout<<" c1: "<<cadena1<<endl;

    /* strncpy()
    Copia una cantidad definida de los priemros n caracteres de una
    cadena de texto a otra.
    */
    cout<<"\n funcion - strncpy() \n ";
    cout<<" ingresa una cadena de texto: ";cin>>cadena1;
    cout<<" ingresa otra cadena de texto: ";cin>>cadena2;

    cout<<"\n valores inciales de las cadenas ingresadas \n";
    cout<<" c1: "<<cadena1<<endl;
    cout<<" c2: "<<cadena2<<endl;

    cout<<" al aplicar la funcion strncpy() \n";
    strncpy(cadena1, cadena2, 3);
    cout<<" copiamos los primeros 3 caracteres c2 a c1 y obtenemos \n";
    cout<<" c1: "<<cadena1<<endl;


    /* strcmp()
    compara dos cadenas de texto que son tomadas como parametro
    y retorna cero si estas son iguales  
    */
    cout<<"\n metodo - strcmp() \n ";
    cout<<" ingresa una cadena de texto: ";cin>>cadena1;
    cout<<" ingresa otra cadena de texto: ";cin>>cadena2;

    if (strcmp(cadena1, cadena2)==0)
    {
        cout<<" los strings ingresados son igules \n";
    }
    else{
        cout<<" los strings ingresados no son igules \n";
    }

    /* strncmp()
    Se utiliza para comparar los primeros n caracteres de 
    una cadena de texto
    */
    cout<<"\n funcion - strncmp() \n ";
    cout<<" ingresa una cadena de texto: ";cin>>cadena1;
    cout<<" ingresa otra cadena de texto: ";cin>>cadena2;

    cout<<"\n comoramos si los priemros 3 caracters de las cadenas ingresadas on iguales \n";
    if (strncmp(cadena1, cadena2, 3)==0)
    {
        cout<<" son iguales \n";
    }
    else{
        cout<<" no son iguales \n";
    }
    
    return 0;
}