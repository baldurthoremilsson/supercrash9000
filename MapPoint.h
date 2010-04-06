// MapPoint.h

#ifndef _MAPPOINT_H
#define _MAPPOINT_H

#include "definitions.h"
#include "SuperObject.h"

class MapPoint: public SuperObject {
	private:
		int X;
		int Y;
		
	public:
		MapPoint(int x, int y);
		~MapPoint();
		
		void setX(int x);
		void setY(int y);
		int getX();
		int getY();
};

#endif
