#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Objeto {
  int peso;
  int beneficio;
};

bool compararPorMejorProporcion(Objeto& obj1, Objeto& obj2) {
  float proporcion1 = static_cast<float>(obj1.beneficio) / obj1.peso;
  float proporcion2 = static_cast<float>(obj2.beneficio) / obj2.peso;
  return proporcion1 > proporcion2;
}

bool compararPorMenosPeso(Objeto& obj1, Objeto& obj2) {
  return obj1.peso < obj2.peso;
}

bool compararPorMayorBeneficio(Objeto& obj1, Objeto& obj2) {
  return obj1.beneficio > obj2.beneficio;
}

//Mochila con objetos enteros
//float mochila(int capacidad, vector<Objeto>& objetos, bool (*comparador)(Objeto&, Objeto&)) {
//  sort(objetos.begin(), objetos.end(), comparador);
//
//  float beneficioTotal = 0.0;
//  int pesoActual = 0;
//
//  for (auto& obj : objetos) {
//    if (pesoActual + obj.peso <= capacidad) {
//      pesoActual += obj.peso;
//      beneficioTotal += obj.beneficio;
//    } else {
//      int pesoRestante = capacidad - pesoActual;
//      beneficioTotal += obj.beneficio * (static_cast<float>(pesoRestante) / obj.peso);
//      break;
//    }
//  }
//
//  return beneficioTotal;
//}

float mochila(float capacidad, vector<Objeto>& objetos,bool (*comparador)(Objeto&, Objeto&)) {
  sort(objetos.begin(), objetos.end(), comparador);

  float beneficioTotal = 0.0;
  float pesoActual = 0.0;

  for (auto& obj : objetos) {
    if (pesoActual + obj.peso <= capacidad) {
      pesoActual += obj.peso;
      beneficioTotal += obj.beneficio;
    } else {
      float pesoRestante = capacidad - pesoActual;
      beneficioTotal += obj.beneficio * (pesoRestante / obj.peso);
      break;
    }
  }

  return beneficioTotal;
}

int main() {
  cout<<"\n***EJEMPLO 1***\n";
  int capacidadTotal = 10;
  vector<Objeto> objetos = {
    {10, 10},
    {3, 9},
    {3, 9},
    {4, 9}
  };

  float beneficioOptimo1 = mochila(capacidadTotal, objetos, compararPorMayorBeneficio);
  cout << "El beneficio total por mayor beneficio es: " << beneficioOptimo1 << endl;
  float beneficioOptimo2 = mochila(capacidadTotal, objetos, compararPorMenosPeso);
  cout << "El beneficio total por menor peso es: " << beneficioOptimo2 << endl;
  float beneficioOptimo3 = mochila(capacidadTotal, objetos, compararPorMejorProporcion);
  cout << "El beneficio total por mejor proporcion es: " << beneficioOptimo3 << endl;

  cout<<"\n***EJEMPLO 2***\n";
  int capacidadTotal2 = 10;
  vector<Objeto> objetos2 = {
    {10, 10},
    {3, 1},
    {3, 1},
    {4, 1}
  };

  float beneficio1 = mochila(capacidadTotal2, objetos2, compararPorMayorBeneficio);
  cout << "El beneficio total por mayor beneficio es: " << beneficio1 << endl;
  float beneficio2 = mochila(capacidadTotal2, objetos2, compararPorMenosPeso);
  cout << "El beneficio total por menor peso es: " << beneficio2 << endl;
  float beneficio3 = mochila(capacidadTotal2, objetos2, compararPorMejorProporcion);
  cout << "El beneficio total por mejor proporcion es: " << beneficio3 << endl;

  cout<<"\n***EJEMPLO 3***\n";
  int capacidadTotal3 = 20;
  vector<Objeto> objetos3 = {
    {18, 25},
    {15, 24},
    {10, 15}
  };

  float beneficio10 = mochila(capacidadTotal3, objetos3, compararPorMayorBeneficio);
  cout << "El beneficio total por mayor beneficio es: " << beneficio10 << endl;
  float beneficio20 = mochila(capacidadTotal3, objetos3, compararPorMenosPeso);
  cout << "El beneficio total por menor peso es: " << beneficio20 << endl;
  float beneficio30 = mochila(capacidadTotal3, objetos3, compararPorMejorProporcion);
  cout << "El beneficio total por mejor proporcion es: " << beneficio30 << endl;

  return 0;
}
