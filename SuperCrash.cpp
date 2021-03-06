// SuperCrash.cpp

#include "SuperCrash.h"
#include <GL/glut.h>
#include <stdlib.h>

SuperCrash::SuperCrash(): SuperEngine() {
	SuperEngine::instance = this;
	
	superGame = new SuperGame();
	mainMenu = new MainMenu();
	pauseMenu = new PauseMenu();
	highScore = new HighScore();
	about = new About();

	current = mainMenu;
}

SuperCrash::~SuperCrash() {
	delete superGame;
	delete mainMenu;
	delete pauseMenu;
	delete highScore;
	delete about;
}

SuperCrash* SuperCrash::getInstance() {
	return (SuperCrash*)instance;
}

SuperGame* SuperCrash::getGame() {
	return superGame;
}

void SuperCrash::display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	current->display();
	glutSwapBuffers();
}

void SuperCrash::update(int time) {
	current->update(time);
	glutPostRedisplay();
	sleep();
}

void SuperCrash::keyboardUp(unsigned char key) {
	current->keyboardUp(key);	
}

void SuperCrash::keyboardDown(unsigned char key) {
	current->keyboardDown(key);
}

void SuperCrash::keyboardSpecialUp(int key) {
	current->keyboardSpecialUp(key);
}

void SuperCrash::keyboardSpecialDown(int key) {
	current->keyboardSpecialDown(key);
}

void SuperCrash::setCurrent(int n) {
	if (n==0) {
		superGame->gameOver();
	} if (n==1)
		current = superGame;
	if (n==2)
		current = highScore;
	if (n==3) 
		current = pauseMenu;
	if (n==4)
		exit(0);
	if (n==5)
		current = about;
}

void SuperCrash::startNewGame() {
	delete superGame;
	current = superGame = new SuperGame();
}

void SuperCrash::showMainMenu() {
	current = mainMenu;
}

void SuperCrash::showHighscore(int score) {
	highScore->setScore(score);
	current = highScore;
}

