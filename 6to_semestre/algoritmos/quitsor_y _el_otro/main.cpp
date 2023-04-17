#include <iostream>
using namespace std;

// Declaración de funciones
int partition(int [], int, int); // encuentra el punto de partición y reorganiza el arreglo
void quickSort(int [], int, int); // implementa el algoritmo de QuickSort
void swap(int *, int *); // intercambia dos elementos de un arreglo
void print(int [], int); // imprime el arreglo

int main() {
  int A[] = {10, 5, 4, 3, 2}; // Declaración e inicialización de un arreglo
  print(A, 5); // Se imprime el arreglo A antes de ser ordenado
  quickSort(A, 0, 5); // Se llama a la función quickSort para ordenar el arreglo A
  print(A, 5); // Se imprime el arreglo A después de ser ordenado
  cout << "\n"; // Se imprime una línea en blanco
  return 0;
}

// La función partition encuentra el punto de partición y reorganiza el arreglo
int partition(int array[], int low, int high) {
  int pivot = array[high]; // El último elemento del arreglo es el pivote
  int i = (low - 1); // Se inicializa una variable i con el índice del elemento más bajo del arreglo (low - 1)
  for (int j = low; j <= high; j++) { // Se recorre el arreglo desde el índice más bajo (low) hasta el índice más alto (high)
    if (array[j] < pivot) { // Si un elemento es menor que el pivote
      i++; // Se incrementa la variable i
      swap(&array[i], &array[j]); // Se intercambia el elemento actual con el elemento en la posición i
    }
  }
  swap(&array[i + 1], &array[high]); // Se intercambia el pivote con el elemento en la posición i+1
  return (i + 1); // Se devuelve la posición de i+1
}

// La función quickSort implementa el algoritmo de QuickSort
void quickSort(int array[], int low, int high) {
  if (low < high) { // Si el índice más bajo es menor que el índice más alto
    int pi = partition(array, low, high); // Se encuentra el punto de partición del arreglo usando la función partition
    quickSort(array, low, pi - 1); // Se llama a la función quickSort para ordenar los elementos antes del punto de partición
    quickSort(array, pi + 1, high); // Se llama a la función quickSort para ordenar los elementos después del punto de partición
  }
}

// La función swap intercambia dos elementos de un arreglo
void swap(int *a, int *b){
  int t = *a;
  *a = *b;
  *b = t;
}

// La función print imprime el arreglo
void print(int array[], int n)
{
  cout << "\n[";
  for(int i = 0; i < n; i++)
    cout << " " << array[i] << " ";
  cout << "]";
}