// PauseMenu.h

#ifndef _PAUSEMENU_H
#define _PAUSEMENU_H

#include "SuperMenu.h"
#include <string>
#include <vector>

using namespace std;

//Tilvik af PauseMenu stendur fyrir pause menu (!)
class PauseMenu : public SuperMenu {
	protected:
		virtual void selectItem(int n);
		void resumeGame();
		void exitGame();
	public:
		PauseMenu();
		virtual ~PauseMenu();
};

#endif
