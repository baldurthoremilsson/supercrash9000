// SuperGame.cpp

#include "SuperGame.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

SuperGame::SuperGame() {
}

SuperGame::~SuperGame() {
}

void SuperGame::display() {
	glLoadIdentity();
	gluLookAt(4.0, 4.0, 4.0,  0.0, 0.0, 0.0,  0.0, 1.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glutWireSphere(1.0 ,10, 10);
}

void SuperGame::update(int time) {
}

void SuperGame::keyboardUp(unsigned char key) {
}

void SuperGame::keyboardDown(unsigned char key) {
}

void SuperGame::keyboardSpecialUp(int key) {
}

void SuperGame::keyboardSpecialDown(int key) {
}
