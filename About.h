// About.h

#ifndef _ABOUT_H
#define _ABOUT_H

#include "SuperObject.h"
#include <string>
#include <vector>


using namespace std;

class About : public SuperObject {
	protected:
		vector<string> infoString;
		string menuTitle;
	public:
		About();
		virtual ~About();
		
		void display();
		void update(int time);
		void keyboardUp(unsigned char key);
		void keyboardDown(unsigned char key);
		void keyboardSpecialUp(int key);
		void keyboardSpecialDown(int key);


};

#endif
