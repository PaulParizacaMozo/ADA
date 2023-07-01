//Uso de puntero a funciones
#include <iostream>
using namespace std;

float Addition(float n1, float n2){
  return n1 + n2;
}
float Subtraction(float n1, float n2){
  return n1 - n2;
}
float Multiplication(float n1, float n2){
  return n1 * n2;
}
float Division(float n1, float n2){
  return n1 / n2;
}

int main(){
  typedef float (*lpfnOperation)(float, float);
  lpfnOperation vpf[4] = {&::Addition, 
                          &::Subtraction,
                          &::Multiplication, 
                          &::Division};
  float n1,n2,n3;
  int opt;
  //Ingrese los numeros 
  cin >> n1 >> n2;
  cout<<" 0-Addition\n 1-Subtraction\n 2-Multiplication\n 3-Division\nOpcion-> ";
  cin >> opt;
  // The next line replaces
  n3 = vpf[opt](n1, n2);
  cout<<"Resultado -> "<<n3;
}
