// SuperGame.h

#ifndef _SUPERGAME_H
#define _SUPERGAME_H

#include "SuperObject.h"
#include "Map.h"
#include "SuperPlayer.h"

class SuperCrash;

class SuperGame: public SuperObject {
	private:
		Map *map;
		SuperPlayer *player1;
		
		int score;
		int lastUpdate;
		
	public:
		SuperGame();
		~SuperGame();
		
		void startAnotherGame();
		void gameOver();
		
		void display();
		void update(int time);
		void keyboardUp(unsigned char key);
		void keyboardDown(unsigned char key);
		void keyboardSpecialUp(int key);
		void keyboardSpecialDown(int key);
};

#endif
