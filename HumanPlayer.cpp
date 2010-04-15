// HumanPlayer.cpp

#include "HumanPlayer.h"
#include "SuperCrash.h"
#include <GL/glut.h>

HumanPlayer::HumanPlayer(int x, int y, Edge dir, MapSide *mside, const Color &c): SuperPlayer(x, y, dir, mside, c) {
}

HumanPlayer::~HumanPlayer() {
}

void HumanPlayer::update(int time) {
	SuperPlayer::update(time);
	if(collided)
		SuperCrash::getInstance()->getGame()->startAnotherGame();
}

void HumanPlayer::keyboardUp(unsigned char key) {
}

void HumanPlayer::keyboardDown(unsigned char key) {
}

void HumanPlayer::keyboardSpecialUp(int key) {
	if(key == GLUT_KEY_LEFT)
		turnLeft = false;
	if(key == GLUT_KEY_RIGHT)
		turnRight = false;
}

void HumanPlayer::keyboardSpecialDown(int key) {
	if(key == GLUT_KEY_LEFT)
		turnLeft = true;
	if(key == GLUT_KEY_RIGHT)
		turnRight = true;
}

