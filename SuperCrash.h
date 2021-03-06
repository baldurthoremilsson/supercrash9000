// SuperCrash.h

#ifndef _SUPERCRASH_H
#define _SUPERCRASH_H

#include "SuperEngine.h"
#include "SuperGame.h"
#include "MainMenu.h"
#include "PauseMenu.h"
#include "HighScore.h"
#include "About.h"


//Tilvik af SuperCrash stendur fyrir eintak af leiknum
class SuperCrash: public SuperEngine {
	protected:
		SuperGame *superGame;
		MainMenu *mainMenu;
		PauseMenu *pauseMenu;
		HighScore *highScore;
		About *about;
		
		SuperObject *current;
		
	public:
		SuperCrash();
		~SuperCrash();
		
		static SuperCrash* getInstance();
		
		SuperGame* getGame();
		
		void display();
		void update(int time);
		void keyboardUp(unsigned char key);
		void keyboardDown(unsigned char key);
		void keyboardSpecialUp(int key);
		void keyboardSpecialDown(int key);

		void setCurrent(int n);
		void startNewGame();
		void showMainMenu();
		void showHighscore(int score);
};

#endif
