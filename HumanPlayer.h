// HumanPlayer.h

#ifndef _HUMANPLAYER_H
#define _HUMANPLAYER_H

#include "SuperPlayer.h"

class HumanPlayer: public SuperPlayer {
	public:
		HumanPlayer(int x, int y, Edge dir, MapSide *mside, const Color &c);
		~HumanPlayer();
		
		void update(int time);
		void keyboardUp(unsigned char key);
		void keyboardDown(unsigned char key);
		void keyboardSpecialUp(int key);
		void keyboardSpecialDown(int key);
};

#endif
