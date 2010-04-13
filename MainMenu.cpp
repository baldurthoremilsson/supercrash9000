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
	menuItemVector.push_back("Start Game");
	menuItemVector.push_back("View High Scores");
	menuItemVector.push_back("Exit Game");
	
	
	calibrate();
}

MainMenu::~MainMenu() {
}

void MainMenu::startGame() {
	cout << "Let's start the game now\n";
	SuperCrash::getInstance()->setCurrent(1);
}
void MainMenu::viewHighScores() {
	cout << "Let's look at the high scores now\n";
	SuperCrash::getInstance()->setCurrent(2);
}
void MainMenu::exitGame() {
	cout << "Let's exit the game now\n";
	//superCrash->setCurrent(4); //exit
	SuperCrash::getInstance()->setCurrent(4);
}
void MainMenu::selectItem(int n) {
	switch(n) {
		case 0:
			startGame(); break;
		case 1:
			viewHighScores(); break;
		case 2:
			exitGame(); break;
	}
}
