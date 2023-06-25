#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void printArreglo(const vector<T>& arreglo) {
  int size = arreglo.size();
  for (int i = 0; i<size; i++) {
    if (i == size - 1) cout<<arreglo[i]<<"\n";
    else cout<<arreglo[i]<<" - ";
  }
}

template<typename T>
int particion(vector<T>& arreglo, int i_menor, int i_mayor) {
  T pivote = arreglo[i_mayor];
  int i = i_menor - 1;

  for (int j = i_menor; j <= i_mayor - 1; j++) {
    if (arreglo[j] < pivote) {
      i++;
      swap(arreglo[i], arreglo[j]);
    }
  }
  swap(arreglo[i + 1], arreglo[i_mayor]); //pivote a su nueva posicion
  return i + 1;
}

template<typename T>
void quickSort(vector<T>& arreglo, int i_menor, int i_mayor) {
  if (i_menor < i_mayor) {
    int pi = particion(arreglo, i_menor, i_mayor);
    quickSort(arreglo, i_menor, pi - 1);
    quickSort(arreglo, pi + 1, i_mayor);
  }
}

template<typename T>
void quickSort(vector<T>& arreglo) {
  int size = arreglo.size();
  quickSort(arreglo, 0, size - 1);
}



int main() {
    vector<int> arreglo1 = {7, 2, 1, 6, 8, 5, 3, 4};
    cout << "\nEjemplo 1:\nArreglo Inicial: ";
    printArreglo(arreglo1);

    quickSort(arreglo1);

    cout << "Arreglo Ordenado: ";
    printArreglo(arreglo1);

    vector<float> arreglo2 = {4.5, 2.1, 7.8, 1.3, 3.9};
    cout << "\nEjemplo 2:\nArreglo Inicial: ";
    printArreglo(arreglo2);

    quickSort(arreglo2);

    cout << "Arreglo Ordenado: ";
    printArreglo(arreglo2);

    vector<char> arreglo3 = {'d', 'f', 'a', 'g', 'b'};
    cout << "\nEjemplo 3\nArreglo Inicial: ";
    printArreglo(arreglo3);

    quickSort(arreglo3);

    cout << "Arreglo Ordenado: ";
    printArreglo(arreglo3);

    return 0;
}
