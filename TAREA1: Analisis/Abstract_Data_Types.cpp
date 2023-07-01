#include <iostream>
using namespace std;

template<typename T>
class CVector{
  private:
    T *m_pVect;  // Puntero al arreglo 
    int m_nCount;  // Numeros de elementos
    int m_nMax;    // Maximo
    int m_nDelta;  // Control
    void Init(int delta); // Inicializa las variables
    void Resize();        // Resize del arreglo
  public:
    CVector<T>(int delta = 10);  // Constructor
    ~CVector();               // Destructor
    void Insert(T elem);    // Funciones
    void MostrarArreglo();
};

template<typename T>
void CVector<T>::Init(int delta){
  this->m_nDelta = delta;
}

template<typename T>
CVector<T>::CVector(int delta){
  Init(delta);
  m_pVect = new T[delta]; // Asignar memoria inicial para m_pVect
  m_nMax = delta;           // Establecer m_nMax como el tamaño inicial
  m_nCount = 0;             // Establecer m_nCount en 0, ya que no hay elementos inicialmente
}

template<typename T>
CVector<T>::~CVector() {
  delete[] m_pVect; // Liberar la memoria asignada al arreglo
}

template<typename T>
void CVector<T>::Insert(T elem){
  if (m_nCount == m_nMax)     // Verify the overflow
    Resize();                 // Resize the vector before inserting elem
  m_pVect[m_nCount++] = elem; // Insert the element at the end
}

template<typename T>
void CVector<T>::Resize(){
  m_pVect = (T*) realloc(m_pVect, sizeof(T) * (m_nMax + m_nDelta));
  m_nMax += m_nDelta;
}

template<typename T>
void CVector<T>::MostrarArreglo(){
  for (int i=0; i<m_nCount; i++) {
    cout<<m_pVect[i]<<" - ";
  }
  cout<<endl;
}


int main() {
  CVector<char> vector; // Objeto vector
  vector.Insert('a');
  vector.Insert('b');
  vector.Insert('c');
  vector.Insert('d');
  vector.Insert('e');
  vector.Insert('f');
  vector.Insert('g');

  vector.MostrarArreglo();
  return 0;
}
