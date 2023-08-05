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
    cout << "Elementos de la mochila -> ";
    for (int i = 0; i < (int)elementos.size(); ++i) {
        if (seleccion[i]) {
            cout << i+1<< " ";
            pesoTotal += elementos[i].peso;
            beneficioTotal += elementos[i].beneficio;
        }
    }
    cout << endl << "Peso total-> " << pesoTotal << "\nBeneficio total-> " << beneficioTotal << endl;
}

void mochilaBacktracking(const vector<Objeto>& elementos, int capacidad, vector<bool>& seleccion, int pesoActual, int beneficioActual, int indiceActual) {
    if (indiceActual == elementos.size() || pesoActual >= capacidad) {
        if (pesoActual <= capacidad && beneficioActual > maximoBeneficio) {
            maximoBeneficio = beneficioActual;
            mejorMochila = seleccion;
        }
        return;
    }
    if (pesoActual + elementos[indiceActual].peso <= capacidad) {
        seleccion[indiceActual] = true;
        mochilaBacktracking(elementos, capacidad, seleccion, pesoActual + elementos[indiceActual].peso, beneficioActual + elementos[indiceActual].beneficio, indiceActual + 1);
        seleccion[indiceActual] = false;
    }
    mochilaBacktracking(elementos, capacidad, seleccion, pesoActual, beneficioActual, indiceActual + 1);
}

void mochila01(const vector<Objeto>& elementos, int capacidad) {
    vector<bool> seleccion(elementos.size(), false);
    maximoBeneficio = 0;
    mochilaBacktracking(elementos, capacidad, seleccion, 0, 0, 0);
    imprimirSolucion(elementos, mejorMochila);
}

int main() {
    vector<Objeto> elementos = {{1, 2}, {2, 3}, {3, 4}, {4,5}};
    int capacidad = 7;
    mochila01(elementos, capacidad);
    return 0;
}
