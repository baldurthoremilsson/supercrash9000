// About.cpp

#include "About.h"
#include "SuperCrash.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

About::About() {
	menuTitle = "Information!";
	
	infoString.push_back("Controls:");
	infoString.push_back("  Use arrow keys to navigate craft.");
	infoString.push_back(" ");
	infoString.push_back("Authors:");
	infoString.push_back("  Baldur Thor Emilson");
	infoString.push_back("  Torfi Gunnarsson");
}

About::~About() {
}

void About::display() {
	int i,j;
	glLoadIdentity();
	
	// Here it is possible to draw anything we want into the background
	
	glPushMatrix();
		glLoadIdentity();
		glClear(GL_DEPTH_BUFFER_BIT);

		for(i=0; i<infoString.size(); i++) {
			glPushMatrix();
				glColor3f(1.0, 1.0, 0.1);
				
				glTranslatef(-8.0,2.0-i,-20.0);
				glScalef(0.005,0.005,1.0);
				for (j=0; j<infoString[i].length(); j++) {
					glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,infoString[i][j]);
				}
			glPopMatrix();
			
		}
		// Make the title dance/vibrate... yay fun!
		glRotatef(4.5, rand(), rand(), rand());
		
		glTranslatef(-2.1,1.5,-5.0);
		glScalef(0.004,0.004,0.004);
		
		glColor3f(1.0,0.1,0.1);
		for (i=0; i<menuTitle.length(); i++) {
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,menuTitle[i]);
		}
		
	glPopMatrix();
}

void About::update(int time) {
}

void About::keyboardUp(unsigned char key) {
}

void About::keyboardDown(unsigned char key) {
	if (key == 27 /* ESC */) { 
		SuperCrash::getInstance()->setCurrent(0);
	}
	
}

void About::keyboardSpecialUp(int key) {
}

void About::keyboardSpecialDown(int key) {
	
}

