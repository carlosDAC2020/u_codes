#include "matriz.h"

matriz::matriz(int f, int c)
{
    filas = (f < 1 ? 1 : f);
    columnas = (c < 1 ? 1 : c);
    Matrix = new float*[filas];
    for (int i = 0; i < filas; i++)
        Matrix[i] = new float[columnas];
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            Matrix[i][j] = 0.0;
}

matriz::matriz(const matriz& orig)
{
    filas = orig.filas;
    columnas = orig.columnas;
    Matrix = new float*[filas];
    for (int i = 0; i < filas; i++)
        Matrix[i] = new float[columnas];
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            Matrix[i][j] = orig.Matrix[i][j];
}

matriz::~matriz()
{
    for (int i = 0; i < filas; i++)
    {
        delete[] Matrix[i];
    }
    delete[] Matrix;
}

void matriz::setfilas(int f){
    filas=f;
}

void matriz::setcolumnas(int c){
    columnas=c;
}

void matriz::pedir_datos(){
    int f,c;
    cout<<" filas=";cin>>f;
    setfilas(f);
    cout<<" columnas=";cin>>c;
    setcolumnas(c);
}


void matriz::getMatrix() const
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
            cout << Matrix[i][j] << " ";
        cout << "\n";
    }
}

void matriz::setMatriz()
{
    cout << "\nFilas = " ;cin>>filas;
    cout << "\nColumnas = ";cin>>columnas;
    
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
        {
            cout << "Matrix[" << i + 1 << "][" << j + 1 << "]... ";
            cin >> Matrix[i][j];
        }
}

int matriz::operator==(const matriz &a) const
{
    if (filas != a.filas)
        return 0;
    if (columnas != a.columnas)
        return 0;
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            if (Matrix[i][j] != a.Matrix[i][j])
                return 0;
    return 1;
}

const matriz &matriz::operator=(const matriz &a)
{
    if (&a != this)
    {
        if (filas != a.filas || columnas != a.columnas)
        {
            for (int i = 0; i < filas; i++)
            {
                delete[] Matrix[i];
            }
            delete[] Matrix;
            filas = a.filas;
            columnas = a.columnas;
            Matrix = new float*[filas];
            for (int i = 0; i < filas; i++)
                Matrix[i] = new float[columnas];
        }
        for(int i = 0; i < filas; i++)
            for(int j = 0; j < columnas; j++)
                Matrix[i][j] = a.Matrix[i][j];
    }
    return *this;
}

matriz matriz::operator+(const matriz &a) const
{
  
  if (filas == a.filas && columnas == a.columnas){
      matriz res;
      res.filas=filas;
      res.columnas=columnas;
      res.Matrix = new float*[filas];
      for (int i = 0; i < filas; i++)
          res.Matrix[i] = new float[columnas];

      for(int i = 0; i < filas; i++)
            for(int j = 0; j < columnas; j++)
                res.Matrix[i][j] = Matrix[i][j]+a.Matrix[i][j];

      return res;
    }

  else{
    cout<<" operacion no valida ";
  }
}

matriz matriz::producto_escalar(){
  int c;
  cout<<" ingrese el valor del numero por el cual se multiplicara la matriz: ";cin>>c;
  matriz res;
  res.filas=filas;
  res.columnas=columnas;
  res.Matrix = new float*[filas];
  for (int i = 0; i < filas; i++)
      res.Matrix[i] = new float[columnas];

  for(int i = 0; i < filas; i++)
        for(int j = 0; j < columnas; j++)
            res.Matrix[i][j] = Matrix[i][j]*c;

  return res;
}

matriz matriz::operator*(const matriz &a) const{
  if(columnas==a.filas){
    matriz res(filas,a.columnas);

    for(int i=0; i<res.filas; i++){
        for(int j=0; j<res.columnas; j++){
            int aux=0, x=0;
            while(x<res.columnas){
                aux+=Matrix[i][x]*a.Matrix[x][i];
                x+=1;
            }
            res.Matrix[i][j]=aux;
        }
    }
  }
}