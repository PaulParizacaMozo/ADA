#include <iostream>

namespace MyNS{
  int gnCount; // Global counter
  // Some small function implemented inline
  double Addition(double a, double b){ // Global function
    return a + b;
  }
  double Substraction(double a, double b){// Global function
    return a - b;
  }
  // Some prototypes
  long factorial(int n); // Global function
  class CTest{
  public:
    CTest();
    void Method1();
  };
};

int main(){
  double n1 = 10;
  double n2 = 20;
  std::cout<<"(+) -> "<<n1<<" + "<<n2<<" = "<<MyNS::Addition(n1,n2)<<"\n";
  std::cout<<"(-) -> "<<n2<<" - "<<n1<<" = "<<MyNS::Addition(n2,n1)<<"\n";
}
