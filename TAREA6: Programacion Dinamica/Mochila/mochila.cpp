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
        for (int w = 1; w <= capacidad; ++w) {
            if (objetos[i - 1].peso <= w) {
                dp[i][w] = max(objetos[i - 1].beneficio + dp[i - 1][w - objetos[i - 1].peso], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacidad];
}

int main() {
    int capacidad = 10; // Capacidad de la mochila
    vector<Objeto> objetos = {
      {10, 10},
      {3, 9},
      {3, 9},
      {4, 9}
    };
    int n = objetos.size(); // Número de objetos

    int max_beneficio = mochila(capacidad, objetos, n);
    cout << "El beneficio total es: " << max_beneficio << endl;

    return 0;
}
