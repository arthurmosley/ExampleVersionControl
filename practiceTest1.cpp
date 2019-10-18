#include <iostream>	// library for reading & writing from the console/keyboard



int main(){
  double *p = new double;
  *p = 35.1;
  double * q = p;
  std::cout << *p << " " << *q << std::endl;
  p = new double;
  *p = 27.1;
  std::cout << *p << " " << *q << std::endl;
  *q = 12.5;
  std::cout << *p << " " << *q << std::endl;
  delete p;
  delete q;
  return -1;
}
