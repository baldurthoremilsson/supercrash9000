// SuperPowerup.h

#ifndef _SUPERPOWERUP_H
#define _SUPERPOWERUP_H

#include "SuperObject.h"

class SuperPlayer;

class SuperPowerup : public SuperObject {
	protected:
		int timeToLive;
		int lastUpdate;
		
	public:
		SuperPowerup(int time);
		virtual ~SuperPowerup();
		
		void update(int time);
		bool isAlive();
		void snatched(int time);
		virtual void updatePlayer(int time, SuperPlayer *player) = 0;
		
		void keyboardUp(unsigned char key) {}
		void keyboardDown(unsigned char key) {}
		void keyboardSpecialUp(int key) {}
		void keyboardSpecialDown(int key) {}

};

#endif
