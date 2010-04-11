// SuperGame.h

#ifndef _SUPERGAME_H
#define _SUPERGAME_H

#include "SuperObject.h"
#include "Map.h"

class SuperCrash;

class SuperGame: public SuperObject {
	private:
		SuperCrash *superCrash;
		Map *map;
		
	public:
		SuperGame(SuperCrash *sc);
		~SuperGame();
		
		void display();
		void update(int time);
		void keyboardUp(unsigned char key);
		void keyboardDown(unsigned char key);
		void keyboardSpecialUp(int key);
		void keyboardSpecialDown(int key);
};

#endif
