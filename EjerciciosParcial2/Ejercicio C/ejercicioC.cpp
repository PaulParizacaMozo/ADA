#include <iostream>
#include <vector>
using namespace std;

void verificar(vector<int>&valorMoneda,int &n){
    int sumTotal = 1;
    int cantMonedas = (n > 1)? 2 : 1;
    for (int i = 1; i < n - 1; i++){
        if (sumTotal + valorMoneda[i] < valorMoneda[i+1]){
            sumTotal += valorMoneda[i];
            cantMonedas++;
        }
    }
    cout << cantMonedas << endl;
}

int main(){  
    int pruebas;
    cin>>pruebas;
    while(pruebas--){
        int n;
        cin >> n;
        vector<int> valorMoneda;
        int valor;
        for (int i = 0; i < n; i++){
            cin >> valor;
            valorMoneda.push_back(valor);
        }
        verificar(valorMoneda, n);
    }
    return 0;
}

