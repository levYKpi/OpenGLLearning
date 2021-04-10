#include <iostream>
#include "Display.h"

int main(int argn, char *argc[]){
	for(int i = 0; i < argn; i++)
		std::cout << argc[i] << std::endl;
	std::cout << "Hello world" <<std::endl;
	
	Display dislpay(800, 600, "Hello OpenGL");
	return 0;
}