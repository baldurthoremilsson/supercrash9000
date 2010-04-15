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
	map = NULL;
	player1 = NULL;
	
	score = 0;
	lastUpdate = -1;
	
	startAnotherGame();
}

SuperGame::~SuperGame() {
	delete map;
	delete player1;
}

void SuperGame::startAnotherGame() {
	delete map;
	delete player1;
	
	map = new Map(5,5,5);
	player1 = new HumanPlayer(2, 3, EAST, map->getTop(), Color(1.0, 0.0, 0.0));
}

void SuperGame::gameOver() {
	SuperCrash::getInstance()->showHighscore(score);
	score = 0;
	lastUpdate = -1;
	startAnotherGame();
}

void SuperGame::display() {
	glLoadIdentity();
	gluLookAt(6.0, 6.0, -6.0,  0.0, 0.0, 0.0,  0.0, 1.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	map->display();
}

void SuperGame::update(int time) {
	if(lastUpdate > 0)
		score += time - lastUpdate;
	player1->update(time);
	lastUpdate = time;
}

void SuperGame::keyboardUp(unsigned char key) {
}

void SuperGame::keyboardDown(unsigned char key) {
	if (key == 27)
		SuperCrash::getInstance()->setCurrent(3);
}

void SuperGame::keyboardSpecialUp(int key) {
	player1->keyboardSpecialUp(key);
}

void SuperGame::keyboardSpecialDown(int key) {
	player1->keyboardSpecialDown(key);
}
