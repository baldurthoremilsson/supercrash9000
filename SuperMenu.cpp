// SuperMenu.cpp

#include "SuperMenu.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

SuperMenu::SuperMenu() {
	menuTitle = "Supercrash 9000";
	menuItem[0] = "Hello";
	menuItem[1] = "World!";
	menuItem[2] = "This";
	menuItem[3] = "is";
	menuItem[4] = "a";
	menuItem[5] = "friggin'";
	menuItem[6] = "awesome";
	menuItem[7] = "menu.";
	
	numItems = 8;
	selectedItem = 0;
//	float temp[8] = {0.0,0.5,1.0,1.5,2.0,2.5,3.5,4.5};
//	topSpace = temp[numItems-1];	
}

SuperMenu::~SuperMenu() {
}

void SuperMenu::display() {
	int i,j;
	float temp[8] = {0.0,0.5,1.0,1.5,2.0,2.5,3.5,4.5};
	float topSpace = temp[numItems-1];
	
	glLoadIdentity();
//	gluLookAt(4.0, sin(glutGet(GLUT_ELAPSED_TIME)), 6.0,  0.0, 0.0, 0.0,  0.0, 1.0, 0.0);
//	glColor3f(1.0, 0.0, 0.0);
//	glutWireSphere(1.0 ,10, 10);
	
	// Hér er hægt að teikna eitthvað í bakgrunninum á menu-inu.. woot
	// Teikna bara þessa asnalegu kúlu til að sýna fram á það. :)
	
	glPushMatrix();
		glLoadIdentity();
		glClear(GL_DEPTH_BUFFER_BIT);
		
		for(i=0; i<numItems; i++) {
			glPushMatrix();
				glColor3f(0.0, 1.0, 1.0);
				if (i == selectedItem)
					glColor3f(0.0,1.0,0.0);
				glTranslatef(0.0,topSpace-1.3*i,-10.0); 	// 4. Færi kassann þangað sem hann á að vera
				glRotatef(itemRotation[i], 1.0,0.0,0.0);	// 3. Sný kassanum aðeins
				glScalef(10.0,1.0,1.0); 					// 2. Stilli stærðina á kassanum
				glutWireCube(1); 							// 1. Teikna kassa
				
				glTranslatef(-(float)menuItem[i].length()/50,-0.002,0.0);
				glScalef(0.0004,0.004,0.004);
				for (j=0; j<menuItem[i].length(); j++) {
					glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,menuItem[i][j]);
				}
			glPopMatrix();
			
		}
	glPopMatrix();
}

void SuperMenu::update(int time) {
	int i;
	for(i=0; i<numItems; i++)
		if (i != selectedItem)
			itemRotation[i] += 0.0;
	itemRotation[selectedItem] += 0.1;		
}

void SuperMenu::keyboardUp(unsigned char key) {

}

void SuperMenu::keyboardDown(unsigned char key) {
}

void SuperMenu::keyboardSpecialUp(int key) {
}

void SuperMenu::keyboardSpecialDown(int key) {
	if (key == GLUT_KEY_LEFT && numItems<8)
		numItems++;
	if (key == GLUT_KEY_RIGHT && numItems > 0)
		numItems--;
	if (key == GLUT_KEY_DOWN) {
		selectedItem++;
		if (selectedItem >= numItems)
			selectedItem = 0;
	}
	if (key == GLUT_KEY_UP) {
		selectedItem--;
		if (selectedItem < 0)
			selectedItem = numItems-1;
	}
}




/*

#include "SuperMenu.h"
#include <string>
#include <vector>
#include <GL/glut.h>
#include <iostream>


	
void SuperMenu::changeSelection(int i) {
	currentSelection += i;
	if (currentSelection > numChoices)
		currentSelection = 0;
	if (currentSelection < 0)
		currentSelection = numChoices;
}
void SuperMenu::display() {
	
	std::cout << "Teikna menu núna \n";
}
void SuperMenu::update(int tick){};
void SuperMenu::keyboardUp(unsigned char key){};
void SuperMenu::keyboardDown(unsigned char key){};
void SuperMenu::keyboardSpecialUp(int key){};
void SuperMenu::keyboardSpecialDown(int key){
	if (key == GLUT_KEY_UP)
		changeSelection(-1);
	if (key == GLUT_KEY_DOWN)
		changeSelection(1);
	if (key == GLUT_KEY_F1)
		makeSelection();
};

*/
