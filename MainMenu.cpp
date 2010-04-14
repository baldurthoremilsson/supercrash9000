// MainMenu.cpp

#include "MainMenu.h"
#include "SuperCrash.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

MainMenu::MainMenu() {
	menuTitle = "Supercrash 9000";
	menuItemVector.push_back("Start game");
	menuItemVector.push_back("View high scores");
	menuItemVector.push_back("About the game");
	menuItemVector.push_back("Exit game");
	
	
	calibrate();
}

MainMenu::~MainMenu() {
}

void MainMenu::startGame() {
	SuperCrash::getInstance()->setCurrent(1);
}
void MainMenu::viewHighScores() {
	SuperCrash::getInstance()->setCurrent(2);
}
void MainMenu::exitGame() {
	SuperCrash::getInstance()->setCurrent(4);
}
void MainMenu::aboutGame() {
	SuperCrash::getInstance()->setCurrent(5);
}
void MainMenu::selectItem(int n) {
	switch(n) {
		case 0:
			startGame(); break;
		case 1:
			viewHighScores(); break;
		case 2:
			aboutGame(); break;
		case 3:
			exitGame(); break;
	}
}
