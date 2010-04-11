// SuperCrash.cpp

#include "SuperCrash.h"
#include <GL/glut.h>
#include <stdlib.h>

SuperCrash::SuperCrash(): SuperEngine() {
	SuperEngine::instance = this;
	
	superGame = new SuperGame(this);
	mainMenu = new MainMenu(this);
	pauseMenu = new PauseMenu(this);
	highScore = new HighScore(this);

	current = mainMenu;
	//current = superGame;
	//current = highScore;
	//highScore->setScore(100);
}
SuperCrash::~SuperCrash() {
	delete superGame;
	delete mainMenu;
	delete pauseMenu;
	delete highScore;
}

void SuperCrash::display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	current->display();
	glutSwapBuffers();
}

void SuperCrash::update(int time) {
	current->update(time - lastUpdate);
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
	if (n==0)
		current = mainMenu;
	if (n==1)
		current = superGame;
	if (n==2)
		current = highScore;
	if (n==3) 
		current = pauseMenu;
	if (n==4)
		exit(0);
}
