#include <iostream>
#include <list>
#include <vector>
#include <cassert>



void print(const std::string &label, const std::list<std::string> &data) {
  std::cout << label;
  for (std::list<std::string>::const_iterator itr = data.begin();
       itr != data.end(); itr++) {
    std::cout << " " << *itr;
  }
  std::cout << std::endl;
}

void update(std::list<std::string>& data, std::vector<std::string>& add, std::vector<std::string>& remove)
{
  std::list<std::string>::iterator j;
  for(int i = 0; i < add.size(); i++)
  {
    for(j = data.begin(); j!=data.end(); j++)
    {
      if(*j == add[i])
      {
        break;
      }
      if(*j > add[i])
      {
      data.insert(j, add[i]);
      break;
      }
    }
  }
  for(int i = 0; i < remove.size(); i++)
  {
    for(j = data.begin(); j!=data.end(); j++)
    {
      if((*j).find(remove[i]) != std::string::npos)
      {
        j = data.erase(j);
        j--;
      }
    }
  }
}

int main() {


  // Examples demonstrating STL string find:
  // catfish contains the substring fish
  assert (std::string("catfish").find(std::string("fish")) != std::string::npos);
  // fish contains the substring fish
  assert (std::string("fish").find(std::string("fish")) != std::string::npos);
  // fish does not contain the substring catfish
  assert (std::string("fish").find(std::string("catfish")) == std::string::npos);


  // A simple example:
  std::list<std::string> data;
  data.push_back("antelope");
  data.push_back("catfish");
  data.push_back("giraffe");
  data.push_back("jellyfish");
  data.push_back("llama");
  data.push_back("whale_shark");
  data.push_back("zebra");

  std::vector<std::string> add;
  add.push_back("tiger");
  add.push_back("llama");
  add.push_back("elephant");

  std::vector<std::string> remove;
  remove.push_back("fish");
  remove.push_back("bear");
  remove.push_back("whale");

  print ("before:",data);
  update(data,add,remove);
  print ("after: ",data);

  // at the end, data should contain: antelope elephant giraffe llama tiger zebra
  assert (data.size() == 6);

}
