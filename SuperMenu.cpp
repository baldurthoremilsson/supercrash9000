// SuperMenu.cppn

#include "SuperMenu.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

SuperMenu::SuperMenu() {
	menuTitle = "Supercrash 9000";/*
	menuItemVector.push_back("woot");
	menuItemVector.push_back("it");
	menuItemVector.push_back("seems");
	menuItemVector.push_back("to");
	menuItemVector.push_back("work!");
	menuItemVector.push_back("bleh!");
	*/
	calibrate();
}

SuperMenu::~SuperMenu() {
}

void SuperMenu::display() {
	int i,j;
	//float temp[8] = {0.0,0.5,1.0,1.5,2.0,2.5,3.5,4.5};
	//float topSpace = temp[menuItemVector.size()-1];
	
	glLoadIdentity();
	
	// Hér er hægt að teikna eitthvað í bakgrunninum á menu-inu.. woot
	// Til dæmis þessa asnalegu kúlu sem er hægt að afcommenta
	
	//gluLookAt(4.0, sin(glutGet(GLUT_ELAPSED_TIME)), 6.0,  0.0, 0.0, 0.0,  0.0, 1.0, 0.0);
	//glColor3f(1.0, 0.0, 0.0);
	//glutWireSphere(1.0 ,10, 10);
	
	glPushMatrix();
		glLoadIdentity();
		glClear(GL_DEPTH_BUFFER_BIT);
		

		
		for(i=0; i<menuItemVector.size(); i++) {
			glPushMatrix();
				glColor3f(1.0, 0.1, 0.1);
				if (i == selectedItem)
					glColor3f(0.1,1.0,0.1);
				glTranslatef(0.0,topSpace-1.3*i,-10.0); 	// 4. Færi kassann þangað sem hann á að vera
				glRotatef(itemRotation[i], 1.0,0.0,0.0);	// 3. Sný kassanum aðeins
				glScalef(10.0,1.0,1.0); 					// 2. Stilli stærðina á kassanum
				glutWireCube(1); 							// 1. Teikna kassa
				
				glTranslatef(-(float)menuItemVector[i].length()/50,-0.002,0.0);
				glScalef(0.0004,0.004,0.004);
				string temp = menuItemVector[i];
				for (j=0; j<temp.length(); j++) {
					glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,menuItemVector[i][j]);
				}
			glPopMatrix();
			
		}
		
		glTranslatef(-3.0,1.5,-5.0);
		glScalef(0.004,0.004,0.004);
		
		// Látum titilinn dansa... haha! (kannski fjarlægja í seinni útgáfu)
		glRotatef(3.0, rand(), rand(), rand());
		glColor3f(1.0,0.1,0.1);
		for (i=0; i<menuTitle.length(); i++) {
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,menuTitle[i]);
		}
		
	glPopMatrix();
}

void SuperMenu::update(int time) {
	int i;
	for(i=0; i<menuItemVector.size(); i++)
		if (i != selectedItem)
			itemRotation[i] += 0.0;
	itemRotation[selectedItem] += 0.1;		
}

void SuperMenu::keyboardUp(unsigned char key) {

}

void SuperMenu::keyboardDown(unsigned char key) {
	if (key == 13) { // carriage return, enter
		selectItem(selectedItem);
	}
}

void SuperMenu::keyboardSpecialUp(int key) {
}

void SuperMenu::keyboardSpecialDown(int key) {
	if (key == GLUT_KEY_LEFT && menuItemVector.size()<8) {
		menuItemVector.push_back("test");
		calibrate();
	}
	if (key == GLUT_KEY_RIGHT && menuItemVector.size() > 0) {
		menuItemVector.pop_back();
		calibrate();
	}
		
		
	if (key == GLUT_KEY_DOWN) {
		selectedItem++;
		if (selectedItem >= menuItemVector.size())
			selectedItem = 0;
	}
	if (key == GLUT_KEY_UP) {
		selectedItem--;
		if (selectedItem < 0)
			selectedItem = menuItemVector.size()-1;
	}
	
}

void SuperMenu::calibrate() {
	selectedItem = 0;
	float temp[8] = {0.0,0.5,1.0,1.5,2.0,2.5,3.5,4.5};
	topSpace = temp[menuItemVector.size()-1];	
}
