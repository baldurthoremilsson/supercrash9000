// SuperMenu.h

#ifndef _MAINMENU_H
#define _MAINMENU_H

#include "SuperMenu.h"
#include <string>
#include <vector>

using namespace std;

//Tilvik af MainMenu stendur fyrir aðalvalmynd
class MainMenu : public SuperMenu {
	protected:
		virtual void selectItem(int n);
		void startGame();
		void viewHighScores();
		void exitGame();
	public:
		MainMenu();
		virtual ~MainMenu();
};

#endif
