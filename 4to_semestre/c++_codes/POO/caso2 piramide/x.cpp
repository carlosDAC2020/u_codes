/*
//-----------------------------------------------
/*en esta funcion hallamos  el area de la base 
de la piramide elevando el valor del atributo 
de los lados al cuadrado */ 
float Piramide::base(){
  float base;
  base=pow(lado,2);
  return base;
}

//-------------------------------------------
/* funcion para hallar el area delos rectangulos de las caras 
en esta fiuncion hacemos uso del atributo de los lados y altura de la piramide*/
float Piramide::area_triangular(){
  // declaramos variables auxiliares 
  float area_triangulos, at;
  float a=lado/2;
  // hallamos la altura de los triangulos de las caras de la piramide
  at==sqrt( (pow(a,2)) + (pow(altura,2)) );

  // hallamos el area de los triangulos de las caras
  area_triangulos=(lado*at)/2;

  return area_triangulos;
}
//---------------------------------------
/* funcion para hallar el area lateral de la piramide 
la cual es la suma de las areas de las caras de dicha piramide
esta funcion toma como parametro el area de los rectangulos de las caras */
float Piramide::area_lateral(float area_triangulos){
  float area_lateral;
  // hallamos el area lateral
  area_lateral=area_triangulos*4;

  return area_lateral;
}

//--------------------------------------------
/*funcion para hallar el area total de la piramide 
esta funcion toma como parametro el area de la base 
y el area lateral de la piramide*/
float Piramide::area_total(float base, float area_lateral){
  float area_total;
  area_total=base+area_lateral;

  return area_total;
}
//-----------------------------------------------
/*funcion para hallar el volumen de una piramide rectangular 
dicha funcion toma como parametro el area de la base de la piramide */
float Piramide::volumen(float base){
  float volumen;
  volumen=((1/3)*base)*altura;
}
//------------------------------------------------