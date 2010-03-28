// SuperEngine.h
#ifndef _SUPERENGINE_H
#define _SUPERENGINE_H
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
#include "SuperCrash.h"

//Tilvik af SuperEngine stendur fyrir eintak af leiknum
class SuperEngine {
	public:
		SuperEngine();
		~SuperEngine(); // þurfum ekki virtual af því við ætlum ekki að gera neinn klass sem erfir af þessum 
		                // (held allavega að það sé rétt)
		void keyboardUp(int i);
		void keyboardDown(int i);
		void keyboardSpecialUp(unsigned char c);
		void keyboardSpecialDown(unsigned char c);
		void display();
	private:
		SuperCrash s;
};

#endif
