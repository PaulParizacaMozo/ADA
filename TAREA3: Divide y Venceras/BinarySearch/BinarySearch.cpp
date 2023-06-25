#include <iostream>
#include <vector>
using namespace std;

template <typename T>
int binarySearch(vector<T>& arreglo, T& objetivo) {
  int i_menor = 0;
  int i_mayor = arreglo.size() - 1;

  while (i_menor <= i_mayor) {
    int i_mitad = i_menor + (i_mayor - i_menor) / 2;

    if (arreglo[i_mitad] == objetivo) {
      return i_mitad;
    } else if (arreglo[i_mitad] < objetivo) {
      i_menor = i_mitad + 1;
    } else {
      i_mayor = i_mitad - 1;
    }
  }

  return -1; // Si no se encuentra el elemento, se devuelve -1
}

template <typename T>
void printArreglo(vector<T>& arreglo){
  cout<<"Arreglo ->  ";
  for(auto& elemento: arreglo){
    cout<<elemento<<"  ";
  }
  cout<<endl;
}

int main() {
  //Arreglo ordenado
  cout<<"Ejemplo 1: \n";
  vector<int> arreglo = {2,4,6,8,10,12,14,16,18,20};
  int objetivo = 6;
  int pos = binarySearch(arreglo, objetivo);
  printArreglo(arreglo);
  cout<<" -El elemento "<<objetivo<<(pos != -1 ? " si se encuentra en el arreglo.\n" : " no se encuentra en el arreglo.\n");
  if(pos!=-1) cout<<" -Posicion en el arreglo -> "<<pos<<endl;

  cout<<"\nEjemplo 2: \n";
  vector<float> arreglo2 = {2.4, 3.2, 4.8, 5.4, 7.8, 9.1};
  float objetivo2 = 7.8;
  pos = binarySearch(arreglo2, objetivo2);
  printArreglo(arreglo2);
  cout<<" -El elemento "<<objetivo2<<(pos != -1 ? " si se encuentra en el arreglo.\n" : " no se encuentra en el arreglo.\n");
  if(pos!=-1) cout<<" -Posicion en el arreglo -> "<<pos<<endl;

  objetivo2 = 4.5;
  pos = binarySearch(arreglo2, objetivo2);
  cout<<" -El elemento "<<objetivo2<<(pos != -1 ? " si se encuentra en el arreglo.\n" : " no se encuentra en el arreglo.\n");
  if(pos!=-1) cout<<" -Posicion en el arreglo -> "<<pos<<endl;
  
  cout<<"\nEjemplo 3: \n";
  vector<char> arreglo3 = {'a', 'b', 'c', 'd', 'e'};
  char objetivo3 = 'd';

  pos = binarySearch(arreglo3, objetivo3);
  printArreglo(arreglo3);
  cout<<" -El elemento "<<objetivo3<<(pos != -1 ? " si se encuentra en el arreglo.\n" : " no se encuentra en el arreglo.\n");
  if(pos!=-1) cout<<" -Posicion en el arreglo -> "<<pos<<endl;
  return 0;
}
