#include <iostream>
#include <string>
#include <utility>
#include <cassert>
 
#include "ds_set.h"
 
int main() {
  int up_count = 0;
  int down_count = 0;
 
  ds_set<std::string> set1;
  set1.insert("hello");
  set1.insert("good-bye");
  set1.insert("friend");
  set1.insert("abc");
  set1.insert("puppy");
  set1.insert("zebra");
  set1.insert("daddy");
  set1.insert("puppy");  // should recognize that this is a duplicate!
 
  assert(set1.sanity_check());
  assert (set1.size() == 7);
 
  ds_set<std::string>::iterator p = set1.begin();
  assert(p != set1.end() && *p == std::string("abc"));
 
  p = set1.find( "foo" );
  assert (p == set1.end());
 
  p = set1.find("puppy");
  assert (p != set1.end());
  assert (*p == "puppy");
 
  std::cout << "Here is the tree, printed sideways.\n"
        << "The indentation is proportional to the depth of the node\n"
        << "so that the value stored at the root is the only value printed\n"
        << "without indentation.  Also, for each node, the right subtree\n"
        << "can be found above where the node is printed and indented\n"
        << "relative to it\n";
  set1.print_as_sideways_tree( std::cout );
  std::cout << std::endl;
 
 
  // copy the set
  ds_set<std::string> set2( set1 );
  assert(set1.sanity_check());
  assert(set2.sanity_check());
  assert(set1.size() == set2.size());
   
 
  //  Now add stuff to set2
  set2.insert( std::string("a") );
  set2.insert( std::string("b") );
  std::cout << "After inserting stuff:\n";
  set2.print_as_sideways_tree( std::cout );
  std::cout << std::endl;
  assert(set1.sanity_check());
  assert(set2.sanity_check());
  assert(set1.size() == set2.size() - 2);
 
 
  //  Now erase stuff from set2
  set2.erase("hello");
  set2.erase("a");
  set2.erase("hello"); 
  set2.erase("abc");
  set2.erase("friend");
  std::cout << "After erasing stuff:\n";
  set2.print_as_sideways_tree( std::cout );
  std::cout << std::endl;
  assert(set1.sanity_check());
  assert(set2.sanity_check());
  assert(set1.size() == set2.size() + 2);
 
 //testing the iterators
  ds_set<std::string>::iterator p8 = set1.end();
  for(; p8 !=set1.begin(); p8--)
  {
    up_count++;
    std::cout << "COUNT UP:   " << up_count << std::endl;
  } 

  ds_set<std::string>::iterator p7 = set1.begin();
  for(p7; p7!=set1.end(); p7++)
  {
    down_count++;
    std::cout << "COUNT DOWN:   " << down_count << std::endl;
  }

  // Test the iterators!
  ds_set<std::string>::iterator p1 = set1.end();
  p1--;
  for (; p1 != set1.begin(); p1--)
  {
    std::cout << *p1 << std::endl;
  }
  std::cout << *p1 << std::endl;
 
  //set1.print_as_sideways_tree(std::cout);
 
  ds_set<int> set3;
  set3.insert(0);
  set3.insert(2);
  set3.insert(4);
  set3.insert(8);
  set3.insert(16);
  set3.insert(32);
  set3.insert(64);
  set3.insert(128);

  ds_set<std::string> set4;
  set4.insert("U");
  set4.insert("L");
  set4.insert("C");
  set4.insert("D");

  set3.print_as_sideways_tree(std::cout);

  std::cout << set3.accumulate(0) << std::endl;

  std::cout << set3.accumulate(1) << std::endl;
 
  std::cout << set3.accumulate(15) << std::endl;
 
  std::cout << set3.accumulate(8) << std::endl;

  std::cout << "\n\n\n\n" << std::endl;
  std::cout << set4.accumulate("Z") << std::endl;
 
  std::cout << set4.accumulate("K") << std::endl;
 
  std::cout << set4.accumulate("F") << std::endl; 
 
 
  return 0;
}