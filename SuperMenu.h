// SuperMenu.h

#ifndef _SUPERMENU_H
#define _SUPERMENU_H

#include "SuperObject.h"
#include <string>


//Tilvik af SuperMenu stendur fyrir einhvern menu skjá með 1 eða fleiri valmöguleikum
class SuperMenu : public SuperObject {
	protected:
		std::string menuItem[8];
		std::string menuTitle;
		int numItems;
		int selectedItem;
		float itemRotation[8];
		float topSpace;
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
