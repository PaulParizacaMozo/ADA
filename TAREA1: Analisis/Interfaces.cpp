#include <iostream>
using namespace std;
// Class CVector definition
class CArithmetic{
  private:
    // Some attributes go here
  public:
    static double Addition(double a, double b);
    static double Substraction(double a, double b);
    static double Multiplication(double a, double b);
    static double Division(double a, double b);
    // More methods go here
};

double CArithmetic::Addition(double a, double b){
  return a + b;
}

double CArithmetic::Substraction(double a, double b){
  return a - b;
}

double CArithmetic::Multiplication(double a, double b){
  return a * b;
}

double CArithmetic::Division(double a, double b){
  if (b == 0.0)
    throw (int)0; // Indica la excepcion
  return a / b;
}

int main(){
  double x, y, z;
  x = 1.1;
  y = 0;
  try{
    z = CArithmetic::Division(x, y);
    cout<<"(/) -> "<<z;
  }
  catch (int errorcode){
    cout<<"Error "<<errorcode<<": El divisor es 0, esto provoca el error.\n";
  }
  //El programa maneja el error y continua la ejecucion
  x = 13.5;
  y = 5.2;
  z = CArithmetic::Addition(x, y);
  cout<<"(+) -> "<<z;

  return 0;
}
