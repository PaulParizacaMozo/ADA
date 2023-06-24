#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct tarea {
  int id;
  int limite;
  int beneficio;
};

bool comparartareas(tarea& tarea1, tarea& tarea2) {
  return tarea1.beneficio > tarea2.beneficio;
}

vector<int> Planificaciontareas(vector<tarea>& tareas, int limiteMaximo) {
  sort(tareas.begin(), tareas.end(), comparartareas);
  //for(auto& tarea:tareas){
  //  cout<<tarea.id<<" - "<<tarea.beneficio<<" - "<<tarea.limite<<endl;
  //}
  vector<int> secuencia(limiteMaximo, -1);
  int totalbeneficio = 0;
  for (auto& tarea : tareas) {
    for (int i = tarea.limite - 1; i >= 0; --i) {
      if (secuencia[i] == -1) {
        secuencia[i] = tarea.id;
        totalbeneficio += tarea.beneficio;
        break;
      }
    }
  }
  cout << "Beneficio Total: " << totalbeneficio << endl;
  return secuencia;
}

void printVectortareas(vector<tarea>& tareas){
  cout<<"id\tBen.\tlim."<<endl;
  for(auto& tarea : tareas){
    cout<<tarea.id<<"\t"<<tarea.beneficio<<"\t"<<tarea.limite<<endl;
  }
}

int main() {
  cout<<"***Algoritmo Voraz: Planificacion de tareas***"<<endl;
  //Ejemplo de clase
  vector<tarea> tareas = {
    {1, 3, 7},
    {2, 1, 15},
    {3, 3, 20},
    {4, 1, 5},
    {5, 1, 10},
    {6, 3, 3}
  };
  int limiteMaximo = 3;

  printVectortareas(tareas);

  vector<int> secuencia = Planificaciontareas(tareas, limiteMaximo);
  cout << "Orden de las tareas a realizar: " << endl;
  for (auto& tareaId : secuencia) {
    if (tareaId != -1) cout << tareaId << " ";
  }
  cout << endl;

  return 0;
}
