#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void merge(vector<T>& arreglo, int izquierda, int medio, int derecha) {
    int n1 = medio - izquierda + 1;
    int n2 = derecha - medio;

    vector<T> izq(n1);
    vector<T> der(n2);

    for (int i = 0; i < n1; i++) {
        izq[i] = arreglo[izquierda + i];
    }
    for (int j = 0; j < n2; j++) {
        der[j] = arreglo[medio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = izquierda;

    while (i < n1 && j < n2) {
        if (izq[i] <= der[j]) {
            arreglo[k] = izq[i];
            i++;
        } else {
            arreglo[k] = der[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arreglo[k] = izq[i];
        i++;
        k++;
    }

    while (j < n2) {
        arreglo[k] = der[j];
        j++;
        k++;
    }
}

template <typename T>
void mergeSort(vector<T>& arreglo, int izquierda, int derecha) {
    if (izquierda < derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        mergeSort(arreglo, izquierda, medio);
        mergeSort(arreglo, medio + 1, derecha);

        merge(arreglo, izquierda, medio, derecha);
    }
}

template <typename T>
void printarregloay(const vector<T>& arreglo) {
    int size = arreglo.size();
    for (int i = 0; i < size; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

int main() {
    //Ejemplos
    vector<int> arreglo = {3,9,2,10,5,7,11};
    cout << "Ejemplo 1\nVector original: ";
    printarregloay(arreglo);
    mergeSort(arreglo, 0, arreglo.size() - 1);
    cout << "Vector ordenado: ";
    printarregloay(arreglo);


    vector<char> arreglo2 = {'z','b','g','c','a','f','d',};
    cout << "\nEjemplo 2\nVector original: ";
    printarregloay(arreglo2);
    mergeSort(arreglo2, 0, arreglo2.size() - 1);
    cout << "Vector ordenado: ";
    printarregloay(arreglo2);

    return 0;
}
