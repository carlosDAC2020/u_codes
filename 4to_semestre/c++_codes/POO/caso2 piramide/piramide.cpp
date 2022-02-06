#include <iostream>
#include "piramide.h"
#include <math.h>
using namespace std;

  // metodo constructor 
Piramide::Piramide(float h, float l)
{
  altura=h;
  lado_base=l;
}


void Piramide::getaltura(float h){
    altura=h;
}

void Piramide::getlasdo_base(float l){
    lado_base=l;
}


void Piramide::imprime(){
  cout<<" datos de la piramide \n";
  cout<<" altura:"<<altura<<"\n";
  cout<<" lado de la base :"<<lado_base<<"\n";
}
