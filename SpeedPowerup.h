// SpeedPowerup.h

#ifndef _SPEEDPOWERUP_H
#define _SPEEDPOWERUP_H

#include "SuperObject.h"

using namespace std;

class SpeedPowerup : public SuperObject {
	protected:
		virtual void updatePlayer();
		virtual void updateSide();
	public:
		SpeedPowerup();
		virtual ~SpeedPowerup();
		virtual void display();

};

#endif
