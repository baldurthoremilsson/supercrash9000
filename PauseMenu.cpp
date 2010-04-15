// PauseMenu.cpp

#include "PauseMenu.h"
#include "SuperCrash.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

PauseMenu::PauseMenu() {
	menuTitle = "    PAUSED";
	menuItemVector.push_back("Resume game");
	menuItemVector.push_back("Quit grid");
	
	calibrate();
}

PauseMenu::~PauseMenu() {
}

void PauseMenu::resumeGame() {
	cout << "Let's resume the game now\n";
	SuperCrash::getInstance()->setCurrent(1);
}
void PauseMenu::exitGame() {
	cout << "Pause Menu wants to go back to main menu\n";
	SuperCrash::getInstance()->setCurrent(0);
}

void PauseMenu::selectItem(int n) {
	switch(n) {
		case 0:
			resumeGame(); break;
		case 1:
			exitGame(); break;
	}
}
