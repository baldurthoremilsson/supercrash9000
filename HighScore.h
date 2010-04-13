// HichScore.h

#ifndef _HIGHSCORE_H
#define _HIGHSCORE_H

#include "SuperObject.h"
#include <string>
#include <vector>


using namespace std;

//Tilvik af HighScore stendur fyrir High Score lista
class HighScore : public SuperObject {
	protected:
		vector<string> highScoreName;
		vector<int>highScoreScore;
		string menuTitle;
		int mode; 			// 0: just looking at the hig scores, 1: entering name
		
		int rank; 			// player rank (if entering name)
		int enteringIndex;	// Which letter is player entering now
	public:
		HighScore();
		virtual ~HighScore();
		
		void display();
		void update(int time);
		void keyboardUp(unsigned char key);
		void keyboardDown(unsigned char key);
		void keyboardSpecialUp(int key);
		void keyboardSpecialDown(int key);
		void setScore(int n);


};

#endif
