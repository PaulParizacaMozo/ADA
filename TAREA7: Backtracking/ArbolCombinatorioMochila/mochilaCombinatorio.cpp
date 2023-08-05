#include <iostream>
#include <vector>

using namespace std;

// Estructura para representar un elemento de la mochila
struct Item {
    int peso;
    int valor;
};

// Variables globales para almacenar la mejor solución encontrada
vector<bool> mejorSeleccion;
int mejorValor = 0;

// Función auxiliar para imprimir la solución encontrada
void imprimirSolucion(const vector<Item>& elementos, const vector<bool>& seleccion) {
    int pesoTotal = 0;
    int valorTotal = 0;
    cout << "Elementos seleccionados: ";
    for (size_t i = 0; i < elementos.size(); ++i) {
        if (seleccion[i]) {
            cout << i << " ";
            pesoTotal += elementos[i].peso;
            valorTotal += elementos[i].valor;
        }
    }
    cout << endl << "Peso total: " << pesoTotal << ", Valor total: " << valorTotal << endl;
}

// Función de backtracking para resolver la mochila 0/1 utilizando un árbol combinatorio
void mochilaCombinatoria(const vector<Item>& elementos, int capacidad, vector<bool>& seleccion, int pesoActual, int valorActual, int indiceActual) {
    if (indiceActual == elementos.size() || pesoActual >= capacidad) {
        // Si se ha llegado al final de los elementos o se alcanzó la capacidad máxima
        // Se comprueba si la combinación actual es mejor que la mejor solución encontrada hasta ahora
        if (pesoActual <= capacidad && valorActual > mejorValor) {
            mejorValor = valorActual;
            mejorSeleccion = seleccion;
        }
        return;
    }

    // Incluir el elemento actual en la mochila
    seleccion[indiceActual] = true;
    mochilaCombinatoria(elementos, capacidad, seleccion, pesoActual + elementos[indiceActual].peso, valorActual + elementos[indiceActual].valor, indiceActual + 1);

    // Excluir el elemento actual de la mochila
    seleccion[indiceActual] = false;
    mochilaCombinatoria(elementos, capacidad, seleccion, pesoActual, valorActual, indiceActual + 1);
}

// Función principal para resolver el problema de la mochila 0/1 usando backtracking con árbol combinatorio
void mochila01(const vector<Item>& elementos, int capacidad) {
    vector<bool> seleccion(elementos.size(), false); // Vector para almacenar los elementos seleccionados
    mejorValor = 0;
    mochilaCombinatoria(elementos, capacidad, seleccion, 0, 0, 0);

    // Imprimir la mejor solución encontrada
    imprimirSolucion(elementos, mejorSeleccion);
}

int main() {
    vector<Item> elementos = {{1,2}, {2,3}, {3,4},{4,5}}; // Ejemplo de elementos con (peso, valor)
    int capacidad = 7; // Capacidad máxima de la mochila
    mochila01(elementos, capacidad);
    return 0;
}
