#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para representar una arista
struct Arista{
    int origen;
    int destino;
    int peso;
    void set(int o, int d, int p){
        this->origen = o;
        this->destino = d;
        this->peso = p;
    }
};

// Función para comparar dos aristas según su peso
bool compareAristas(Arista& a, Arista& b) {
    return a.peso < b.peso;
}

// Función para encontrar el subconjunto al que pertenece el elemento
int findSubCon(vector<int>& padre, int i) {
    if (padre[i] == -1)
        return i;
    return findSubCon(padre, padre[i]);
}

// Función para unir dos subconjuntos en un solo subconjunto
void unionSubCon(vector<int>& padre, int x, int y) {
    int xroot = findSubCon(padre, x);
    int yroot = findSubCon(padre, y);
    padre[xroot] = yroot;
}

// Función principal para encontrar el ciclo hamiltoniano
void HeristicaAristas(vector<Arista>& Aristas, int V) {
    vector<int> padre(V, -1);
    vector<Arista> resultado(V - 1);
    
    // Ordenar las aristas en orden ascendente según su peso
    sort(Aristas.begin(), Aristas.end(), compareAristas);
    
    int i = 0, e = 0;
    while (e < V - 1) {
        Arista siguienteArista = Aristas[i++];
        
        int x = findSubCon(padre, siguienteArista.origen);
        int y = findSubCon(padre, siguienteArista.destino);
        
        // Si agregar la arista no forma un ciclo, la añadimos al resultado
        if (x != y) {
            resultado[e++] = siguienteArista;
            unionSubCon(padre, x, y);
        }
    }
    
    // Verificar si se formó un ciclo hamiltoniano
    int count = 0;
    for (i = 0; i < V - 1; i++) {
        if (resultado[i].origen != -1)
            count++;
    }
    
    if (count == V - 1) {
        cout << "Camino encontrado: ";
        for (i = 0; i < V - 1; i++)
            cout << resultado[i].origen << " - ";
        cout << resultado[V - 2].destino << endl;
    } else {
        cout << "No se encontró ningún ciclo en el grafo." << endl;
    }
}

void printAristas(vector<Arista>aristas){
    cout<<"Aristas: \n";
    for(Arista a : aristas){
        cout<<a.origen<<" - "<<a.peso<<" - "<<a.destino<<endl;
    }
    cout<<"\n";
}

int main() {
    int V, E;
    //cout << "Ingrese el número de vértices del grafo: ";
    //cin >> V;
    //cout << "Ingrese el número de aristas del grafo: ";
    //cin >> E;
    //
    //vector<Arista> Aristas(E);
    //
    //cout << "Ingrese las aristas en el formato (origen, destino, peso):" << endl;
    //for (int i = 0; i < E; i++) {
    //    cin >> Aristas[i].origen >> Aristas[i].destino >> Aristas[i].peso;
    //}
    V = 5;
    E = 10;

    vector<Arista> aristas;
    Arista a1;
    a1.set(1,2,10); 
    aristas.push_back(a1);
    Arista a2;
    a2.set(2,3,20);
    aristas.push_back(a2);
    Arista a3;
    a3.set(3,4,15);
    aristas.push_back(a3);
    Arista a4;
    a4.set(4,5,50);
    aristas.push_back(a4);
    Arista a5;
    a5.set(5,1,45);
    aristas.push_back(a5);
    Arista a6;
    a6.set(5,2,40);
    aristas.push_back(a6);
    Arista a7;
    a7.set(5,3,30);
    aristas.push_back(a7);
    Arista a8;
    a8.set(1,4,25);
    aristas.push_back(a8);
    Arista a9;
    a9.set(1,3,55);
    aristas.push_back(a9);
    Arista a10;
    a10.set(2,4,25);
    aristas.push_back(a10);

    printAristas(aristas);
    HeristicaAristas(aristas, V);
    
    return 0;
}
