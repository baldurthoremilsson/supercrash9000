// SuperCrash.h

#ifndef _SUPERCRASH_H
#define _SUPERCRASH_H
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
//#include "SuperGame.h"
//#include "SuperMenu.h"   // lögum game og menu seinna

//Tilvik af SuperCrash stendur fyrir eintak af leiknum
class SuperCrash {
	public:
		SuperCrash();
		~SuperCrash(); // þurfum ekki virtual af því við ætlum ekki að gera neinn klass sem erfir af þessum 
		               // (held allavega að það sé rétt)
		void keyboardUp(int i);
		void keyboardDown(int i);
		void keyboardSpecialUp(unsigned char c);
		void keyboardSpecialDown(unsigned char c);
		void display();
	private:
		//SuperGame game;
		//SuperMenu menu;
		int state; // t.d. 0=menu, 1=game 2=paused.. ??
};

#endif
