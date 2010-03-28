// SuperEngine.cpp

#include "SuperEngine.h"

SuperEngine::SuperEngine() {
	//s = new SuperCrash;
}
SuperEngine::~SuperEngine() {
	// delete everything!!11
}

void SuperEngine::keyboardUp(int i) {
	s.keyboardUp(i);
}

void SuperEngine::keyboardDown(int i) {
	s.keyboardDown(i);
}

void SuperEngine::keyboardSpecialUp(unsigned char c) {
	s.keyboardSpecialUp(c);
}

void SuperEngine::keyboardSpecialDown(unsigned char c) {
	s.keyboardSpecialDown(c);
}

void SuperEngine::display() {
	std::cout << "  SuperEngine teiknar!  ";
	s.display();
}

