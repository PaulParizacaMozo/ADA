//Complejidad O(logn)
#include <iostream>
using namespace std;

int potencia(int x, int n) {
    if (n == 0) {
        return 1;
    }
    int div = potencia(x, n / 2);
    int resultado = div * div;

    if (n % 2 == 1) {
        resultado *= x;
    }
    return resultado;
}

int main() {
    int base,exponente;

    cout<<"Ingrese la base: ";
    cin>>base;
    cout<<"Ingrese el exponente: ";
    cin>>exponente;

    int resultado = potencia(base, exponente);

    cout<<"El resultado es: "<<resultado<<endl;

    return 0;
}
