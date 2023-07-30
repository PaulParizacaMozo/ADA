#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Objeto {
    int peso;
    int beneficio;
};

int mochila(int capacidad, const vector<Objeto>& objetos, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(capacidad + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= capacidad; ++j) {
            if (objetos[i - 1].peso <= j) {
                dp[i][j] = max(objetos[i - 1].beneficio + dp[i - 1][j - objetos[i - 1].peso], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][capacidad];
}

int main() {
    //Ejemplo1
    cout<<"EJEMPLO 1\n";
    int capacidad1 = 7; // Capacidad de la mochila
    vector<Objeto> objetos1 = {
      {1, 2},
      {2, 3},
      {3, 4},
      {4, 5}
    };
    int n1 = objetos1.size(); // Número de objetos

    int max_beneficio1 = mochila(capacidad1, objetos1, n1);
    cout << "El beneficio total es: " << max_beneficio1 << endl;

    //Ejemplo2
    cout<<"\nEJEMPLO 2\n";
    int capacidad2 = 100; // Capacidad de la mochila
    vector<Objeto> objetos2 = {
      {1, 2},
      {100, 190}
    };
    int n2 = objetos1.size(); // Número de objetos

    int max_beneficio2 = mochila(capacidad2, objetos2, n2);
    cout << "El beneficio total es: " << max_beneficio2 << endl;

    return 0;
}
