#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Arista {
    int origen;
    int destino;
    int peso;
    Arista(int o, int d, int p) : origen(o), destino(d), peso(p) {}
};

class Grafo{
    public:
        int nNodos;
        vector<vector<int>>matriz;
    //Metodos
        Grafo(int n){
            this->nNodos = n;
            this->matriz.resize(n);
            for(vector<int>&vec : matriz){
                vec.resize(n);
                fill(vec.begin(), vec.end(), 0);
            }
        }
        void AñadirArista(int origen, int destino, int peso){
            matriz[origen-1][destino-1] = peso;
            matriz[destino-1][origen-1] = peso;
        }

        vector<int> masCerca(int nInicial) {
            vector<bool> visitados(nNodos, false);
            vector<int> recorrido;

            int nActual = nInicial-1;
            visitados[nActual] = true;
            recorrido.push_back(nActual);

            while (recorrido.size() < nNodos) {
                int nMasCercano = -1;
                int distMin = INT_MAX;

                for (int nAux = 0; nAux < nNodos; nAux++) {
                    if (!visitados[nAux] && matriz[nActual][nAux] > 0 && matriz[nActual][nAux] < distMin) {
                        nMasCercano = nAux;
                        distMin = matriz[nActual][nAux];
                    }
                }

                if (nMasCercano != -1) {
                    nActual = nMasCercano;
                    visitados[nActual] = true;
                    recorrido.push_back(nActual);
                }
            }
        
            for(int i=0; i<nNodos-1; i++){
                cout<<recorrido[i]+1<<" - "<<recorrido[i+1]+1<<endl;
            }
        return recorrido;
    }
};

int main(int argc, char *argv[])
{
    
    int nNodos, nAristas;
    //cout << "Ingrese el número de nodos: ";
    //cin >> nNodos;
    //cout << "Ingrese el número de aristas: ";
    //cin >> nAristas;
    nNodos = 5;
    nAristas = 10;
    Grafo graph(nNodos);

    //cout << "Ingrese las aristas en el formato 'nodoA nodoB peso':\n";
    //for (int i = 0; i < nAristas; i++) {
    //    int nodeA, nodeB, weight;
    //    cin >> nodeA >> nodeB >> weight;
    //    graph.AñadirArista(nodeA, nodeB, weight);
    //}

    graph.AñadirArista(1,2,10);
    graph.AñadirArista(2,3,20);
    graph.AñadirArista(3,4,15);
    graph.AñadirArista(4,5,50);
    graph.AñadirArista(5,1,45);
    graph.AñadirArista(5,2,40);
    graph.AñadirArista(5,3,30);
    graph.AñadirArista(1,4,25);
    graph.AñadirArista(1,3,55);
    graph.AñadirArista(2,4,25);
    int NodoInicial;
    cout << "Ingrese el nodo de inicio: ";
    cin >> NodoInicial;
    vector<int> recorrido = graph.masCerca(NodoInicial);
    cout << "Recorrido del viajero: ";
    for (int node : recorrido) {
        cout << node+1 << " ";
    }
    cout << endl;
    return 0;
}
