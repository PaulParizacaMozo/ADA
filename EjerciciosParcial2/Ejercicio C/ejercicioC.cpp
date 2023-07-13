#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int binarySearch(vector<int>& arreglo, int& objetivo) {
  sort(arreglo.begin(),arreglo.end());
  int i_menor = 0;
  int i_mayor = arreglo.size() - 1;

  while (i_menor <= i_mayor) {
    int i_mitad = i_menor + (i_mayor - i_menor) / 2;

    if (arreglo[i_mitad] == objetivo) {
      return i_mitad;
    } else if (arreglo[i_mitad] < objetivo) {
      i_menor = i_mitad + 1;
    } else {
      i_mayor = i_mitad - 1;
    }
  }
  return -1;
}


void verificar(vector<int>& monedas, vector<int>&coleccion) {
    int nuevas = 0;
    int sizeMonedas = monedas.size();
    for (int i=0; i<sizeMonedas; i++) {
      if (binarySearch(coleccion,monedas[i]) == -1) {
        nuevas++;
        coleccion.push_back(monedas[i]);
      }
    }
    cout<<nuevas<<endl;
}

void printVector(vector<int>vec){
    for(auto& v : vec){
        cout<<v<<"\t";
    }
    cout<<endl;
}

int main(){
    int a,b,c,d,e,f;
    int casos;
    int cantidad;
    vector<vector<int>>pruebas;

    vector<int>coleccion;

    cin>>casos;
    pruebas.resize(casos);
    for(int i=0; i<casos; i++){
        cin>>cantidad;
        pruebas[i].resize(cantidad);
        for(int j=0; j<cantidad; j++){
            cin>>a;
            pruebas[i][j] = a;
        }
        verificar(pruebas[i],coleccion);
    }
    
    return 0;
}
