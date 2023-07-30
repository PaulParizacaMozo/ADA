#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minMonedas(vector<int>& monedas, int P) {
    int n = monedas.size();

    vector<int> dp(P + 1, INT_MAX);// Tabla 
    dp[0] = 0;
    for (int i = 1; i <= P; i++) {
        for (int j = 0; j < n; j++) {
            if (monedas[j] <= i) {
                int subproblema = dp[i - monedas[j]];
                if (subproblema != INT_MAX && subproblema + 1 < dp[i]) {
                    dp[i] = subproblema + 1;
                }
            }
        }
    }
    return dp[P];
}

int main() {
    //Ejemplo1
    cout<<"Ejemplo 1\n";
    vector<int> monedas = {1,4,6};
    int P = 8;
    int solucion = minMonedas(monedas, P);
    cout<<"P = "<<P<<"\n-> Cantidad mínima de monedas: "<<solucion<<endl;

    return 0;
}
