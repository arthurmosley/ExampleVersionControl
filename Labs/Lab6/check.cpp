#include <vector>
#include <iostream>
#include <cmath>
#include <list>


void reverse_vector(std::vector<int>& vec) 
{
  for (unsigned int i=0; i<(vec.size()/2); i++) 
  {
    int temp = 0;
    temp = vec[i];
    vec[i] = (vec[vec.size() - (i + 1)]);
    vec[vec.size() - (i + 1)] = temp;
  }
}

void reverse_list(std::list<int> &l)
{
  int tmp = l.size();
  if(tmp == 1)
  {
    std::cout << "a" << std::endl;
  }
  else if (tmp == 0) {
    std::cout << "nothin" << std::endl;
  }
  else
  {

    std::list<int>::iterator ii;
    std::list<int>::iterator b;
    //1
    //to the back
    b = l.insert(l.end(), l.front());
    l.pop_front();
    for(unsigned int i = 0; i < l.size(); i++)
    {
      //front to back
      b = l.insert(b, l.front());

      l.pop_front();
    }





    for(ii = l.begin(); ii != l.end(); ++ii)
    {

        std::cout << *ii << std::endl;
    }
  }
}

int main()
{
  std::vector<int> aa;
  std::vector<int> bb;
  std::vector<int> cc;
  std::list<int> a;
  std::list<int> b;
  std::list<int> c;
  for(unsigned int i = 0; i < 10; i++)
  {
    aa.push_back(i);
  }
  for(unsigned int i = 0; i < 10; i=i+2)
  {
    bb.push_back(i);
  }
  for(unsigned int i = 0; i < 1; i++)
  {
    cc.push_back(i);
  }
  for(unsigned int i = 0; i < 5; i++)
  {
    a.push_back(i);
  }
  for(unsigned int i = 0; i < 10; i=i+2)
  {
    b.push_back(i);
  }
  for(unsigned int i = 0; i < 1; i++)
  {
    c.push_back(i);
  }
  std::cout << "Original VECTOR" << std::endl;
  for(unsigned int i = 0; i < aa.size(); i++)
    std::cout << aa[i] << std::endl;
  reverse_vector(aa);
  std::cout << "Reversed VECTOR" << std::endl;
  for(unsigned int i = 0; i < aa.size(); i++)
    std::cout << aa[i] << std::endl;


  std::cout << "REVERSE LIST" << std::endl;
  reverse_list(a);



  //reverse_list(b);
  //reverse_list(c);
  return 0;
}
