#include <iostream>
#include <vector>
using namespace std;

struct Objeto {
    int peso;
    int beneficio;
};

vector<bool> mejorMochila;
int maximoBeneficio = 0;

void imprimirSolucion(const vector<Objeto>& elementos, const vector<bool>& seleccion) {
    int pesoTotal = 0;
    int beneficioTotal = 0;
    cout << "Elementos de la mochila-> ";
    for (size_t i = 0; i < elementos.size(); ++i) {
        if (seleccion[i]) {
            cout << i+1 << " ";
            pesoTotal += elementos[i].peso;
            beneficioTotal += elementos[i].beneficio;
        }
    }
    cout << endl << "Peso total-> " << pesoTotal << "\nBeneficio total-> " << beneficioTotal << endl;
}

void mochilaCombinatoria(const vector<Objeto>& elementos, int capacidad, vector<bool>& seleccion, int pesoActual, int beneficioActual, int indiceActual) {
    if (indiceActual == elementos.size() || pesoActual >= capacidad) {
        if (pesoActual <= capacidad && beneficioActual > maximoBeneficio) {
            maximoBeneficio = beneficioActual;
            mejorMochila = seleccion;
        }
        return;
    }
    seleccion[indiceActual] = true;
    mochilaCombinatoria(elementos, capacidad, seleccion, pesoActual + elementos[indiceActual].peso, beneficioActual + elementos[indiceActual].beneficio, indiceActual + 1);
    seleccion[indiceActual] = false;
    mochilaCombinatoria(elementos, capacidad, seleccion, pesoActual, beneficioActual, indiceActual + 1);
}

void mochila(const vector<Objeto>& elementos, int capacidad) {
    vector<bool> seleccion(elementos.size(), false);
    maximoBeneficio = 0;
    mochilaCombinatoria(elementos, capacidad, seleccion, 0, 0, 0);
    imprimirSolucion(elementos, mejorMochila);
}

int main() {
    vector<Objeto> elementos = {{1,2}, {2,3}, {3,4},{4,5}};
    int capacidad = 7;
    mochila(elementos, capacidad);
    return 0;
}
