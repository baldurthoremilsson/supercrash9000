// MapPoint.h

#ifndef _MAPPOINT_H
#define _MAPPOINT_H

#include "Color.h"
#include "SuperPowerup.h"

class MapPoint {
	private:
		Color *horiz;
		Color *vert;
		
		SuperPowerup *powerup;
		
	public:
		MapPoint();
		~MapPoint();
		
		SuperPowerup* getPowerup();
		void setPowerup(SuperPowerup *spu);
		
		void setHorizWall(const Color &c);
		void setVertWall(const Color &c);
		const Color* getHorizWall();
		const Color* getVertWall();
};

#endif

