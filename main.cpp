#include <iostream>
#include <GL/glew.h>
#include "Display.h"

int main(int argn, char *argc[]){
	for(int i = 0; i < argn; i++)
		std::cout << argc[i] << std::endl;
	std::cout << "Hello world" <<std::endl;
	
	Display display(800, 600, "Hello OpenGL");
	while (!dislplay.IsClosed()){
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		display.Update();
	}
	return 0;
}