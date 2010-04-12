// SuperPowerup.h

#ifndef _SUPERPOWERUP_H
#define _SUPERPOWERUP_H

#include "SuperObject.h"
#include "SuperPlayer.h"

using namespace std;

class SuperPowerup : public SuperObject {
	protected:
		SuperPlayer *player;
		int ttlSide;
		int ttlPlayer;
		int t;
		virtual void updatePlayer()=0;
		virtual void updateSide()=0;
	public:
		SuperPowerup();
		virtual ~SuperPowerup();
		void update(int time);
		virtual void display()=0;
		void keyboardUp(unsigned char key) {}
		void keyboardDown(unsigned char key) {}
		void keyboardSpecialUp(int key) {}
		void keyboardSpecialDown(int key) {}
		int alive;

};

#endif
