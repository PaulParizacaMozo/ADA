#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

//Muestra todas las monedas del cambio 
template<typename T>
vector<T> cambioMoneda1(T cantidad, vector<T>& monedas) {
    vector<T> solucion;
    for (int i=0; i<(int)monedas.size(); i++) {
      while (cantidad >= monedas[i]) {
        cantidad -= monedas[i];
        solucion.push_back(monedas[i]);
      }
    }
    return solucion;
}

//muestra cuantas de cada moneda se necesita para el cambio
template<typename T>
vector<int> cambioMoneda2(T cantidad, vector<T>& monedas) {
    int sizeMonedas = monedas.size();
    vector<int>solucion(sizeMonedas,0);
    for (int i=0; i<sizeMonedas; i++) {
      while (cantidad >= monedas[i]) {
        cantidad -= monedas[i];
        solucion[i]++;
      }
    }
    return solucion;
}

int main() {
  //Ejemplo1 
  cout<<"EJEMPLO 1\n";
  float cantidad = 3.89;
  vector<float> monedas = {2, 1, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};
  vector<float> solucion = cambioMoneda1(cantidad, monedas);
  cout<<"El cambio para "<<cantidad<<" es: ";
  for (auto& moneda : solucion){
    cout<<moneda<<" ";}
  cout<<endl;

  //Ejemplo2  
  cout<<"\nEJEMPLO 2\n";
  int cantidad2 = 180;
  vector<int> monedas2 = {100, 90, 1};
  vector<int> solucion2 = cambioMoneda2(cantidad2, monedas2);
  cout << "El cambio para " << cantidad << " es: \n";
  for (int i=0; i<(int)monedas2.size(); i++) {
    if(solucion2[i] != 0){
      cout<<" -> "<<solucion2[i]<<" monedas de "<<monedas2[i]<<endl;
    }
  }

    return 0;
}
