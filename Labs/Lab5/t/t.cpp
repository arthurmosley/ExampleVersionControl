#include <iostream>
int foo(int x, int y){
	int answer = y;
	for(int a = 0; a < x; a++)
		answer+= foo(y/2, a);
	return answer;

}

int main(){
	int value = foo(2,6);
	std::cout << foo << std::endl;
}