#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minCoins(vector<int>& denominaciones, int X) {
    int n = denominaciones.size();

    // Crear una tabla para almacenar los resultados de subproblemas
    vector<int> dp(X + 1, INT_MAX);

    // El número mínimo de monedas para representar 0 es 0
    dp[0] = 0;

    // Calcular el número mínimo de monedas para cada valor desde 1 hasta X
    for (int i = 1; i <= X; i++) {
        // Considerar todas las denominaciones disponibles
        for (int j = 0; j < n; j++) {
            // Si la denominación actual es menor o igual al valor actual (i),
            // entonces podemos usar esa denominación para reducir el problema
            if (denominaciones[j] <= i) {
                // Calcular el número de monedas necesarias para el valor (i)
                // utilizando la denominación actual
                int subproblema = dp[i - denominaciones[j]];

                // Actualizar el resultado solo si el subproblema tiene una solución
                // válida y si el resultado actual es mejor que la solución anterior
                if (subproblema != INT_MAX && subproblema + 1 < dp[i]) {
                    dp[i] = subproblema + 1;
                }
            }
        }
    }

    // La solución para el valor X está en dp[X]
    return dp[X];
}

int main() {
    vector<int> denominaciones = {1, 5, 10, 25};
    int X = 30;

    int minMonedas = minCoins(denominaciones, X);

    cout << "Cantidad mínima de monedas necesarias para representar " << X << " centavos: " << minMonedas << endl;

    return 0;
}
