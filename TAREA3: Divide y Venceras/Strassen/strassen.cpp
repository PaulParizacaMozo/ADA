#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> sumaMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> resultado(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            resultado[i][j] = A[i][j] + B[i][j];
        }
    }
    return resultado;
}

vector<vector<int>> restaMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> resultado(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            resultado[i][j] = A[i][j] - B[i][j];
        }
    }
    return resultado;
}

vector<vector<int>> strassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    // Caso base: matrices 1x1
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    // División de las matrices en submatrices
    int mitad = n / 2;
    vector<vector<int>> A11(mitad, vector<int>(mitad));
    vector<vector<int>> A12(mitad, vector<int>(mitad));
    vector<vector<int>> A21(mitad, vector<int>(mitad));
    vector<vector<int>> A22(mitad, vector<int>(mitad));
    vector<vector<int>> B11(mitad, vector<int>(mitad));
    vector<vector<int>> B12(mitad, vector<int>(mitad));
    vector<vector<int>> B21(mitad, vector<int>(mitad));
    vector<vector<int>> B22(mitad, vector<int>(mitad));

    for (int i = 0; i < mitad; ++i) {
        for (int j = 0; j < mitad; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mitad];
            A21[i][j] = A[i + mitad][j];
            A22[i][j] = A[i + mitad][j + mitad];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mitad];
            B21[i][j] = B[i + mitad][j];
            B22[i][j] = B[i + mitad][j + mitad];
        }
    }

    // Calcula los productos recursivamente

    vector<vector<int>> P = strassen(sumaMatrices(A11, A22), sumaMatrices(B11, B22));
    vector<vector<int>> Q = strassen(sumaMatrices(A21, A22), B11);
    vector<vector<int>> R = strassen(A11, restaMatrices(B12, B22));
    vector<vector<int>> S = strassen(A22, restaMatrices(B21, B11));
    vector<vector<int>> T = strassen(sumaMatrices(A11, A12), B22);
    vector<vector<int>> U = strassen(restaMatrices(A11, A21), sumaMatrices(B11, B12));
    vector<vector<int>> V = strassen(restaMatrices(A12, A22), sumaMatrices(B21, B22));
    
    

    // Calcula las submatrices 
    vector<vector<int>> C11 = sumaMatrices(restaMatrices(sumaMatrices(P, S), T), V);
    vector<vector<int>> C12 = sumaMatrices(R, T);
    vector<vector<int>> C21 = sumaMatrices(Q, S);
    vector<vector<int>> C22 = restaMatrices(restaMatrices(sumaMatrices(P, R), Q), U);


    // Combina las submatrices 
    vector<vector<int>> resultado(n, vector<int>(n, 0));
    for (int i = 0; i < mitad; ++i) {
        for (int j = 0; j < mitad; ++j) {
            resultado[i][j] = C11[i][j];
            resultado[i][j + mitad] = C12[i][j];
            resultado[i + mitad][j] = C21[i][j];
            resultado[i + mitad][j + mitad] = C22[i][j];
        }
    }
    return resultado;
}

// Función auxiliar para imprimir una matriz
void printmatriz(const vector<vector<int>>& matriz) {
    for (const auto& linea : matriz) {
        for (int elemento : linea) {
            cout << elemento << "\t";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {{4,5,6,7}, {3,2,1,1}, {9,8,7,6}, {1,2,3,4}};
    vector<vector<int>> B = {{1,3,5,7}, {1,2,3,4}, {3,3,3,3}, {4,3,2,1}};

    cout << "Matriz A:" << endl;
    printmatriz(A);

    cout << "Matriz B:" << endl;
    printmatriz(B);

    cout << "Resultado de AXB:" << endl;
    vector<vector<int>> resultado = strassen(A, B);
    printmatriz(resultado);

    return 0;
}
