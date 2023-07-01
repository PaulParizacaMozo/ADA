#include <iostream>
#include <cstdlib>
using namespace std;

int *gpVect = nullptr;  // Puntero a arreglo de enteros
int gnCount = 0;        // Contador (numero de elementos cargados)
int gnMax = 0;          // Tamaño de la memoria

void Resize() {
  const int delta = 10; // Aumentar size del Arreglo 
  gpVect = (int*) realloc(gpVect, sizeof(int) * (gnMax + delta));
  
  // int *pTemp, i;
  // pTemp = new int[gnMax + delta]; // Alloc a new vector
  // for(i = 0 ; i < gnMax ; i++) // Transfer the elements
  // pTemp[i] = gpVect[i]; // we can also use the function memcpy
  // delete [ ] gpVect; // delete the old vector
  // gpVect = pTemp; // Update the pointer
  // gnMax += delta; // The Max has to be increased by delta
}

void Insert(int elem) {
    if (gnCount == gnMax)     // Comprueba si aun hay espacio
        Resize();             // Cambia el tamaño del vector
    gpVect[gnCount++] = elem; //Inserta elemento
}

int main() {
  Insert(3);
  Insert(6);
  for(int i=1; i<50; i++){
    Insert(i*100);
  }
  for(int i=0; i<gnCount; i++) {
    cout<<gpVect[i]<<" - ";
  }
  delete[] gpVect;
  gpVect = nullptr;
  return 0;
}
