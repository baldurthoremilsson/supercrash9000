// SuperGame.cpp

#include "SuperGame.h"
#include "Map.h"
#include "SuperCrash.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>


using namespace std;

SuperGame::SuperGame() {
	map = new Map(5, 5, 5);
}

SuperGame::~SuperGame() {
}

void SuperGame::display() {
	glLoadIdentity();
	gluLookAt(-10.0, -10.0, -10.0,  0.0, 0.0, 0.0,  0.0, 1.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	map->display();
	//glutWireSphere(1.0 ,10, 10);
}

void SuperGame::update(int time) {
}

void SuperGame::keyboardUp(unsigned char key) {
}

void SuperGame::keyboardDown(unsigned char key) {
	if (key == 27)
		SuperCrash::getInstance()->setCurrent(3);
}

void SuperGame::keyboardSpecialUp(int key) {
}

void SuperGame::keyboardSpecialDown(int key) {
}
