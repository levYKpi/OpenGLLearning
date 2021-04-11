#include <iostream>
#include <GL/glew.h>
#include "Display.h"
#include "Shader.h"

int main(int argn, char *argc[]){
	for(int i = 0; i < argn; i++)
		std::cout << argc[i] << std::endl;
	std::cout << "Hello world" <<std::endl;
	
	Display display(800, 600, "Hello OpenGL");
	Shader shader("./res/BaseShader");
	while (!display.IsClosed()){
		display.Clear();
		shader.Bind();
		display.Update();
	}
	return 0;
}