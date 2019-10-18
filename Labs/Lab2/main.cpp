#include "Time.h"
#include <iostream>
#include <algorithm>
#include <vector>



int main(){
  //Check 1/2
  Time t1;


  Time t2(5, 3, 5);
  std::cout << "\nOriginal numbers set: " << t2.getHour() << " " << t2.getMinute() << " " << t2.getSecond() << std::endl;
  t2.setHour(6);
  t2.setMinute(6);
  t2.setSecond(40);
  std::cout << "Modified numbers set: " << t2.getHour() << " " << t2.getMinute() << " " << t2.getSecond() << std::endl;

  std::cout << "\n";

  Time t3(12, 12, 9);
  Time t4(14, 4, 5);
  Time t5(12, 15, 12);
  std::cout << "t2: ";
  t2.PrintAmPm();
  std::cout << "t3: ";
  t3.PrintAmPm();
  std::cout << "t4: ";
  t4.PrintAmPm();
  std::cout << "t5: ";
  t5.PrintAmPm();
  std::cout << "t1: ";
  t1.PrintAmPm();

  std::cout << "\n";

  std::vector<Time> test;


  test.push_back(t1);
  test.push_back(t2);
  test.push_back(t3);
  test.push_back(t4);
  test.push_back(t5);

  sort(test.begin(), test.end(), isEarlierThan);

  for(unsigned int i = 0; i < test.size(); i++){
    std::cout << i+1 << ": ";
     test[i].PrintAmPm();
    //std::cout << "Hello" << std::endl;
  
  }
}
