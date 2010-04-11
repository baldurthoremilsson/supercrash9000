// HighScore.cpp

#include "HighScore.h"
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

HighScore::HighScore(SuperCrash *sc) {
	rank = -1;
	mode = 0;
	menuTitle = "High Scores";
	
	// TODO: Get these from a file, also save them to the file when updated
	highScoreName.push_back("Jeff");
	highScoreName.push_back("Bruce");
	highScoreName.push_back("David");
	highScoreName.push_back("Cindy");
	highScoreName.push_back("Barnard");
	highScoreName.push_back("Dan");
	highScoreName.push_back("Peter");
	highScoreName.push_back("Tony");

	highScoreScore.push_back(105806650);
	highScoreScore.push_back(5000);
	highScoreScore.push_back(3000);
	highScoreScore.push_back(2500);
	highScoreScore.push_back(2000);
	highScoreScore.push_back(1500);
	highScoreScore.push_back(1000);
	highScoreScore.push_back(500);
	
	superCrash = sc;
}

HighScore::~HighScore() {
}

void HighScore::display() {
	int i,j;
	glLoadIdentity();
	
	// Here it is possible to draw anything we want into the background
	
	glPushMatrix();
		glLoadIdentity();
		glClear(GL_DEPTH_BUFFER_BIT);

		for(i=0; i<highScoreName.size(); i++) {
			glPushMatrix();
				glColor3f(1.0, 1.0, 0.1);
				
				if (rank == i)
					glColor3f((float)rand()/RAND_MAX, (float)rand()/RAND_MAX, (float)rand()/RAND_MAX);
				
				// int to string
				ostringstream buffer;
				buffer << highScoreScore[i];
				string scoreString = buffer.str();
				
				glTranslatef(-8.0,2.0-i,-20.0);
				glScalef(0.005,0.005,1.0);
				glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,i+49);
				glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,46);
				glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,32);
				glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,32);
				glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,32);
				for (j=0; j<highScoreName[i].length(); j++) {
					glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,highScoreName[i][j]);
				}
				// Continue laying down spaces until length of drawn string is 19
				for(;j<19; j++) {
					glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,32);				
				}
				// Lay down one space for each letter "scoreString" is less than 9
				for(j=scoreString.length(); j<9; j++) {
					glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,32);
				}
				// Now draw the score string
				for (j=0; j<scoreString.length(); j++) {
					glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,scoreString[j]);
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

void HighScore::update(int time) {
}

void HighScore::keyboardUp(unsigned char key) {
}

void HighScore::keyboardDown(unsigned char key) {
	if (mode == 1) {
		switch (key) {
			case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': 
			case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n': 
			case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u': 
			case 'v': case 'w': case 'x': case 'y': case 'z':
			case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': 
			case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N': 
			case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U': 
			case 'V': case 'W': case 'X': case 'Y': case 'Z':
			case ' ': case '!': case '?':
				if (highScoreName[rank].length() < 18)
					highScoreName[rank].push_back(key);
				break;
			case 8: // backspace
				if (highScoreName[rank].length() > 0)
					highScoreName[rank].erase(highScoreName[rank].length()-1,1);
				break;
			case 13: // carriage return, enter
				mode = 0;
				menuTitle = "High Score";
				// TODO: Save to the file we should be using
				break;             
		} 
	}
	
	if (mode == 0 && key == 27 /* ESC */) { 
		cout << "Let's go from High Scores back to main menu now\n";
		superCrash->setCurrent(0);
	}
	
}

void HighScore::keyboardSpecialUp(int key) {
}

void HighScore::keyboardSpecialDown(int key) {
	
}

void HighScore::setScore(int n) {
	rank = -1;
	if (n < highScoreScore[7]) return;
	
	// Figure out the rank
	for(int i=7; i>=0; i--) {
		if (n > highScoreScore[i])
			rank = i;
	}
	
	// Move all other ranks down
	for(int i=6; i>= rank; i--) {
		highScoreScore[i+1] = highScoreScore[i];
		highScoreName[i+1] = highScoreName[i];
	}
	
	highScoreName[rank] = "";
	highScoreScore[rank] = n;
	mode = 1;
	enteringIndex = 0;
	menuTitle = "Enter your name";
}
