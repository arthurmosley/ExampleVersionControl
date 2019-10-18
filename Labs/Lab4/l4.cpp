#include <iostream>

void compute_squares(unsigned int a[], unsigned int b[], unsigned int n){
  unsigned int* i;
  for(i = a; i < n + a; ++i){
    *(b) = (*i) * (*i);

    std::cout << "a: " << *(i) << std::endl;
    std::cout << "b: " << *(b) << std::endl;
    std::cout << "\n";

    b++;
  }
}

__intptr_t compute_square(__intptr_t n, __intptr_t *a, __intptr_t *b){
	__intptr_t squared;
	__intptr_t *i;
	__intptr_t count = 0;
	for(i=a; i<a+n; ++i){
		squared = *i * *i;
		*(b)=squared;

    std::cout << "a: " << *i << std:: endl;
		std::cout << "b: " << *(b) << std:: endl;
		std::cout << "\n";

		b++;
	}
  return *(b+count);
}


int main(){
  __intptr_t a[] = {1, 2, 3, 4, 5, 6, 7};
  __intptr_t b[] = {0, 0, 0, 0, 0, 0, 0};

  compute_square(7,a,b);
  return 0;
}
