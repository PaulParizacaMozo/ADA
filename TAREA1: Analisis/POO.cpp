#include <iostream>
using namespace std;

class CVector{
  private:
    int *m_pVect;  // Puntero al arreglo 
    int m_nCount;  // Numeros de elementos
    int m_nMax;    // Maximo
    int m_nDelta;  // Control
    void Init(int delta); // Inicializa las variables
    void Resize();        // Resize del arreglo
  public:
    CVector(int delta = 10);  // Constructor
    ~CVector();               // Destructor
    void Insert(int elem);    // Funciones
    void MostrarArreglo();
};

void CVector::Init(int delta){
  this->m_nDelta = delta;
}

CVector::CVector(int delta){
  Init(delta);
  m_pVect = new int[delta]; // Asignar memoria inicial para m_pVect
  m_nMax = delta;           // Establecer m_nMax como el tamaño inicial
  m_nCount = 0;             // Establecer m_nCount en 0, ya que no hay elementos inicialmente
}

CVector::~CVector() {
  delete[] m_pVect; // Liberar la memoria asignada al arreglo
}

void CVector::Insert(int elem){
  if (m_nCount == m_nMax)     // Verify the overflow
    Resize();                 // Resize the vector before inserting elem
  m_pVect[m_nCount++] = elem; // Insert the element at the end
}

void CVector::Resize(){
  m_pVect = (int*) realloc(m_pVect, sizeof(int) * (m_nMax + m_nDelta));
  m_nMax += m_nDelta;
}

void CVector::MostrarArreglo(){
  for (int i=0; i<m_nCount; i++) {
    cout<<m_pVect[i]<<" - ";
  }
  cout<<endl;
}


int main() {
  CVector vector; // Objeto vector
  vector.Insert(2);
  vector.Insert(6);
  vector.Insert(1);
  vector.Insert(5);
  vector.Insert(9);

  vector.MostrarArreglo();
  return 0;
}
