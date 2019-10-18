#include <iostream>   // library for reading & writing from the console/keyboard
#include <cmath>      // library with the square root function & absolute value
#include <cstdlib>    // library with the exit function


// Returns true if the candidate root is indeed a root of the polynomial a*x*x + b*x + c = 0
bool check_root(int a, int b, int c, float root) {
  // plug the value into the formula
  float check = a * root * root + b * root + c;
  // see if the absolute value is zero (within a small tolerance)
  if (fabs(check) > 0.0001) {
    std::cerr << "ERROR:  " << root << " is not a root of this formula." << std::endl;
    return false;
  } else {
    return true;
  }
}

/* Use the quadratic formula to find the two real roots of polynomial.   Returns
true if the roots are real, returns false if the roots are imaginary.  If the roots
are real, they are returned through the reference parameters root_pos and root_neg. */
bool find_roots(int a, int b, int c, float &root_pos, float &root_neg) {
  // compute the quantity under the radical of the quadratic formula
  int radical = b*b - 4*a*c;
  // if the radical is negative, the roots are imaginary
  if (radical < 0) {
    std::cerr << "ERROR:  Imaginary roots" << std::endl;
    return false;
  }
  float sqrt_radical = sqrt(radical); //one error
  // compute the two roots

  root_pos = (-b + sqrt_radical) / (2*a);
  root_neg = (-b - sqrt_radical) / (2*a);
  return true;
}

int main() 
{
  // We will loop until we are given a polynomial with real roots
  int b_array[5];
  int c_array[5];
  float smaller_root[5];
  bool success;
std::cout << "Enter 5 b values for 5 quadratics: a*x*x + b*x + c = 0" << std::endl;
    //int my_b, my_c;
  for(unsigned int i=0; i < 5; i++)
    std::cin >> b_array[i];
  std::cout << "Enter 5 c values for 5 quadratics: a*x*x + b*x + c = 0" << std::endl;
  for(unsigned int i = 0; i < 5; i++)
    std::cin >> c_array[i];
    // create a place to store the roots
  float root_1[5], root_2[5];
  for(unsigned int i = 0; i < 5; i++)
  {
    success = find_roots(1,b_array[i],c_array[i], root_1[i],root_2[i]);
    if(root_1[i] < root_2[i])
      smaller_root[i] = root_1[i];
    else
      smaller_root[i] = root_2[i];
  }
  for(unsigned int i = 0; i < 5; i++)
  {
    if (!success) 
      std::cout << "The roots are imaginary" << std::endl;
    std::cout << "Smaller Root: " << smaller_root[i] << std::endl;
  }

    // If the polynomial has imaginary roots, skip the rest of this loop and start over

    
    // Check our work...
    /*if (check_root(1,my_b,my_c, root_1) && check_root(1,my_b,my_c, root_2)) {
      // Verified roots, break out of the while loop
      break;
    } else {
      std::cerr << "ERROR:  Unable to verify one or both roots." << std::endl;
      // if the program has an error, we choose to exit with a
      // non-zero error code
      exit(1);
    }*/

  // by convention, main should return zero when the program finishes normally*/
  return 0;
}
