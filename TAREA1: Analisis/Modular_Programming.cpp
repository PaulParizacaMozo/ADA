#include <iostream>
using namespace std;

void Resize(int *&rpVect, int &rnMax){
  const int delta = 10; // Aumentar size del Arreglo 
  rpVect = (int*) realloc(rpVect, sizeof(int) * (rnMax + delta));
  rnMax += delta;
}

void Insert(int *&rpVect, int &rnCount, int &rnMax, int elem){
  if (rnCount == rnMax)       // Verify the overflow
    Resize(rpVect, rnMax);    // Resize the vector before inserting elem
  rpVect[rnCount++] = elem;   // Insert the element at the end of the sequence
}

struct Vector{
  int *m_pVect;  // Puntero al arreglo 
  int m_nCount;  // Numeros de elementos
  int m_nMax;    // Maximo
  int m_nDelta;  // Control
};

int main(){
  int *vec1 = nullptr;  // Primer vector
  int cnt1 = 0;         // Contador de elementos del vector 1
  int max1 = 0;         // Tamaño del vector 1

  int *vec2 = nullptr;  // Segundo vector
  int cnt2 = 0;         // Contador de elementos del vector 2
  int max2 = 0;         // Tamaño del vector 2

  for (int i=1; i<20; i++){
      Insert(vec1, cnt1, max1, i*2);
      Insert(vec2, cnt2, max2, i*5);
  }

  cout<<"Vector 1: ";
  for (int i=0; i<cnt1; i++)  {
    cout<<vec1[i]<<" - ";
  }
  cout<<endl;

  cout << "Vector 2: ";
  for (int i=0; i<cnt2; i++)  {
    cout<<vec2[i]<<" - ";
  }
  cout<<endl;

  return 0;
}


