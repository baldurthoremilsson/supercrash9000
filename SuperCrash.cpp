// SuperCrash.cpp

#include "SuperCrash.h"
#include <GL/glut.h>

SuperCrash::SuperCrash(): SuperEngine() {
	SuperEngine::instance = this;
	
	superGame = new SuperGame();
	//mainMenu = new MainMenu();
	//pauseMenu = new PauseMenu();
	current = superGame;
}
SuperCrash::~SuperCrash() {
	delete superGame;
	//delete mainMenu;
	//delete pauseMenu;
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
