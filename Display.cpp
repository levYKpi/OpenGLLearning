#include "Display.h"
#include <iostream>

Display::Display(int width, int height, const std::string& title){
	std::cout << "Display constuctor\n";
}

Display::~Display(){
	std::cout << "Display destuctor\n";
}