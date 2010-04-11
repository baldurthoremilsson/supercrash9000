// SuperMenu.h

// Do not want circular include
class SuperCrash;

#ifndef _SUPERMENU_H
#define _SUPERMENU_H

#include "SuperObject.h"
#include <string>
#include <vector>

using namespace std;

//Tilvik af SuperMenu stendur fyrir einhvern menu skjá með 1 eða fleiri valmöguleikum
class SuperMenu : public SuperObject {
	protected:
		SuperCrash *superCrash;
		vector<string>menuItemVector;
		string menuTitle;
		int numItems;
		int selectedItem;
		float itemRotation[8];
		float topSpace;
		void calibrate();
		virtual void selectItem(int n) = 0;
	public:
		SuperMenu();
		virtual ~SuperMenu();
		
		void display();
		void update(int time);
		void keyboardUp(unsigned char key);
		void keyboardDown(unsigned char key);
		void keyboardSpecialUp(int key);
		void keyboardSpecialDown(int key);


};

#endif
