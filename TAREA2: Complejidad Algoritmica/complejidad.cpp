#include <cmath>
#include <cstddef>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

//Ejercicio 1
void Ejer1(int n){
  cout<<"N -> "<<n<<endl;
  int contador = 0;
  for (int i=0; i<n; i++){ 
    contador++;
    contador++;
    if (i%2 == 0) {
      contador++; //contador del print
      //print
    }  
  }
  contador++;
  cout<<"Contador -> "<<contador<<endl;
}
void FormulaEjer1(int n){
  cout<<"Formula -> "<<ceil(n+1+n+(n+1)/2)<<endl;
}
//Ejercicio 2
void Ejer2(int n){
  cout<<"N -> "<<n<<endl;
  int cnt = 0;
  for(int i=0; i<n; i++){
    cnt++;
    for(int j = i; j<n; j++){
      cnt++;
      cnt++;
      //cout<<"linea"<<endl; 
    }
    cnt++;
  }
  cnt++;
  cout<<"Contador -> "<<cnt<<endl;

}
void FormulaEjer2(int n){
  cout<<"Formula -> "<<pow(n,2)+1+3*n<<endl;
}
//Ejercicio 3
void Ejer3(string n1,string n2){
  cout<<"N1 -> "<<n1<<endl;
  cout<<"N2 -> "<<n2<<endl;
  int cnt = 0;
  for (int i=0; i<(int)n1.size(); i++){
    cnt++;
    for (int j=0; j<(int)n2.size(); j++){
      cnt++;
      cnt++;
      //cout<<n1[i]<<","<<n2[j]<<endl; //(A)(B) 
    }
    cnt++;
  }
  cnt++;
  cout<<"Contador -> "<<cnt<<endl;
}
void FormulaEjer3(string n1,string n2){
  cout<<"Formula -> "<<2*n1.size()*n2.size()+2*n1.size()+1<<endl;
}
//Ejercicio 4
void Ejer4(int n){
  cout<<"N -> "<<n<<endl;
  int cnt = 0;
  for (int i=0; i<n; i++) {
  cnt++;
    cnt++;
    int j = 1;
    while (j<n) {
    cnt++;
    cnt++;
    cnt++;
      //cout<<"algo"<<endl;
      j = j *2;
    }
    cnt++;
  }
  cnt++;
  cout<<"Contador -> "<<cnt<<endl;
}
void FormulaEjer4(int n){
  cout<<"Formula -> "<<3*n*log2(n)+3*n+1<<endl;
}
//Ejercicio 5
void Ejer5(int n){
  cout<<"N -> "<<n<<endl;
  int cnt = 0;
  for(int i=0; i<n; i++){
    cnt++;
    cnt++;
    if(i%2 == 0){
      cnt++;
      //cout<<i<<endl;
    }
  }
  cnt++;
  for(int i=0; i<n; i++){
    cnt++;
    cnt++;
    if(i%2 != 0){
      cnt++;
      //cout<<i<<endl;
    }
  }
  cnt++;
  cout<<"Contador -> "<<cnt<<endl;
}
void FormulaEjer5(int n){
  cout<<"Formula -> "<<4*n+2+ceil(n/2)+ceil((n+1)/2)<<endl;
}

//Ejercicio 6
void Ejer6(int n){
  cout<<"N -> "<<n<<endl;
  int cnt = 0;
  cnt++;
  int i = 1;
  while (i<n) {
    cnt++;
    cnt++;
    cnt++;
    //cout<<i<<endl;
    i = i * 2;
  }
  cnt++;
  cout<<"Contador -> "<<cnt<<endl;
}
void FormulaEjer6(int n){
  cout<<"Formula -> "<<3*log2(n)+2<<endl;
}
//Ejercicio 7
void Ejer7(){
  int cnt = 0;
  cnt++;
  int N = 1000;
  cnt++;
  if(N%2 == 0){ 
    //cout<<"par"<<endl; 
    cnt++;
  } else {
    //cout<<"impar"<<endl;
    cnt++;
  }
  cout<<"Contador -> "<<cnt<<endl;
}
void FormulaEjer7(){
  cout<<"Formula -> "<<1+1+1<<endl;
}


int main(){
  //Ejercicio1
  cout<<"Ejercicio 1:\n";
  Ejer1(10);
  FormulaEjer1(10);
  //Ejercicio2
  cout<<"\nEjercicio 2:\n";
  Ejer2(123);
  FormulaEjer2(123);
  //Ejercicio3
  cout<<"\nEjercicio 3:\n";
  Ejer3("hola11","hola");
  FormulaEjer3("hola","amigo");
  //Ejercicio4
  cout<<"\nEjercicio 4:\n";
  Ejer4(1024);
  FormulaEjer4(1024);
  //Ejercicio5
  cout<<"\nEjercicio 5:\n";
  Ejer5(456);
  FormulaEjer5(456);
  //Ejercicio6
  cout<<"\nEjercicio 6:\n";
  Ejer5(128);
  FormulaEjer5(128);
  //Ejercicio6
  cout<<"\nEjercicio 7:\n";
  Ejer7();
  FormulaEjer7();

}
