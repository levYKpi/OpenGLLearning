#include <iostream>

int main(int argn, char *argc[]){
	for(int i = 0; i < argn; i++)
		std::cout << argc[i] << std::endl;
	std::cout << "Hello world" <<std::endl;
	return 0;
}