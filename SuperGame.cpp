// SuperGame.cpp

#include "SuperGame.h"
#include "Map.h"
#include "SuperCrash.h"
#include "HumanPlayer.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>


using namespace std;

SuperGame::SuperGame() {
	map = new Map(10, 5, 5);
	player1 = new HumanPlayer(1, 1, EAST, map->getTop(), Color(1.0, 0.0, 0.0));
}

SuperGame::~SuperGame() {
	delete map;
	delete player1;
}

void SuperGame::display() {
	glLoadIdentity();
	gluLookAt(-8.0, 8.0, -8.0,  0.0, 0.0, 0.0,  0.0, 1.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	map->display();
}

void SuperGame::update(int time) {
	player1->update(time);
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
