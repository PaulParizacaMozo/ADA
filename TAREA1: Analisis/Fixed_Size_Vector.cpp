#include <iostream>
using namespace std;

int gVect[100]; // Arreglo 
int gnCount = 0; // Contador de cantidad de elementos actual del arreglo 

void Insert(int elem){
  if( gnCount < 100 ) // Verifica que no sobrepase el limite del arreglo
    gVect[gnCount++] = elem; // Inserta elemento segun el orden del contador
}

int main(){
  Insert(3);
  Insert(6);
  Insert(10);
  Insert(1);
  Insert(5);
  Insert(919);

  for(int i=0; i<=gnCount-1; i++){
    cout<<gVect[i]<<"\t";
  }

  return 0;
}
