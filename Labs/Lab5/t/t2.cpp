#include <iostream>
int foo(int x, int y){
	int answer = y;
	for(int a = 0; a < x; a++)
	{
		answer += foo(y/2, a);
		std::cout << answer << std::endl;
	}

	//std::cout << "\t" << answer << std::endl;
	return answer;

}

int main(){
	int value = foo(2,6);
	std::cout << value << std::endl;
	return 1;
}