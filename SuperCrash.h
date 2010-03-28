// SuperCrash.h

#ifndef _SUPERCRASH_H
#define _SUPERCRASH_H

enum GameState {
	MENU,
	GAME,
	PAUSE,
	QUIT
};

//Tilvik af SuperCrash stendur fyrir eintak af leiknum
class SuperCrash {
	private:
		void keyboardUp(int i);
		void keyboardDown(int i);
		void keyboardSpecialUp(unsigned char c);
		void keyboardSpecialDown(unsigned char c);
		void display();
		
		int state; // t.d. 0=menu, 1=game 2=paused.. ??
	public:
		SuperCrash();
		~SuperCrash();
		
};

#endif
