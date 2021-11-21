#include <iostream>
#include<cmath>
using namespace std;


// 1) . Si n = 5 y p = 2 , ¿Qué valor retorna f?

// esta funcion la podemos tomar como una exponencial
int f(int n,int p){ // donde n es la base y p es la potencia a la cual es elevado 

  // tenemos la variable i la cual ira manejando el ciclo q veremos a continuacio
  // y la variable e la cual ira iterando su valor el cual inicialmente es fijado en uno 
  // multiplicsndoce por el valor de la base n en cada iteracion del cilo 
  int i =1, e = 1;
  
  // el cilo realizara iteraciones hasta que el valor de la variable i sea igual a la potencia 
  while(i<= p){ 
    e=e*n; // se realiza la multiplicacion sucesiva de la base 
    i++; // se le va sumando 1 a i para que el siclo corra
  }
  return e; // finalmente retonamos el valor del exponencial obtenido
}


// 2) . Si numero = 9 y ind = 2 , ¿Qué valor retorna f2?

//  se eleva un numero a un a potencia fraccionaria 
// tomamos como parametros el numero a elevar y el denominador de la fraccion a la que es elevado 
float f2(int numero, float ind){ 
   float resultado;
   // elevamos el primer parametro a una fraccion la cual 
   // tiene como numerador 1 y denomunador el segundo 
   // parametro pasado a la funcion
   resultado = pow(numero, 1/ind); // usamos la funcion pow de la libreria math
   // este procedimiento podriamos tomarlo como si le sacaramos
   // la raiz al numero pasado como primer parametro
   // siendo dicha raiz dada por el segundo parametro de la funcion 

   return resultado; // retornamos el resultado del procedimineto 
}

// 3).  Cómo se hace el llamado a la siguiente función

// funcion para aplicar el teorema de pitagoras 
float hipot(float a, float b, float &c){
  // tomamos como parametro los dos catetos a demas 
  // de la variable por referecia a la cual le asignaremos
  // el valor de la hipotenusa obtenido aplicando 
  // el teorema de pitagoras de la siguiente manera  
  return sqrt(pow(a,2)+pow(b,2));
}

// 4).  funcion para el punto 4
void f4(int &y){
  y = y*y;
}

// 5) ¿Qué imprime la siguiente función? 
int F1(int n){
    int res;
    if (n == 1) res = 1;
    else  res = n + F1(n - 1);
    /* lo que internamente realiza la funcion en la variable res 
  cuando n 4 usano recursividad en la linea anteriror son las 
  siguinetes sumas sucecibas desde 1 hasta n 
  4+3 =7
  7+2=9
  9+1=10 ---> res retornada cuando ya n=1
  */
    return res;
}

 int F2(int n){
    int res;
    if ( n == 1) res = 1;
    else res = n * F2 (n-1);
    /* lo que internamente realiza la funcion en la variable res 
  cuando n 4 usano recursividad en la linea anteriror son las 
  siguientes multiplicacciones sucecibas esto podemos decir
  q es como realizar la operacion para obtener el factorial
  de n
  4*3=12
  12*2=24
  24*1=24 ---> res y este es el resultado que retorna 
  */
    return res;
}


int main(){
    //    ejecuciones 

    // 1)
    cout<<"\n el punto 1 retorna \n "<<f(5,2)
    <<endl;
    
    // 2) 
    cout<<"\n el punto 2 retorna \n"<<f2(9, 2)<<endl;

    // el llamdo de la funcion hipot se hace de la siguiente manera
      // damos valores a los catetos 
    float catA=4.5;
    float catB=6.7;
      // declaramos la variable de la hipotenusa 
    float hipotenusa=0.0;
      // llamamos la funcion pasandole como parametros las variables anteriores 
    cout<<"\n haciendo uso de la funcion hipot \n";
    cout<<" le pasamos los catetos con los valores";
    cout<<" \n 4.5 y 6.7 respectivamente ";
    cout<<"\n y obtenemos como el valor de la hipotenusa. "<<hipot(catA, catB, hipotenusa)<<endl;

    // 4) . ¿Qué valor tiene x en la línea 60?
    int x = 0;
    x = 4;
    f4(x);
    cout << "\n el valor en la linea 60 de x es: " << x << endl;

    // llamamos las funciones  
    int num=4, funcion1, funcion2;
    funcion1 = F1(num); //  = 10
    funcion2 = F2(num);//   = 24
    cout<<"\n funcional1= " << funcion1<<endl;
    cout<<" funcional1= " << funcion2<<endl;



    return 0;
}
