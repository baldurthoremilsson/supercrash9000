// MapPoint.h

#ifndef _MAPPOINT_H
#define _MAPPOINT_H

#include "SuperObject.h"

class MapPoint {
	private:
		int X;
		int Y;
		SuperObject *object;
		
	public:
		MapPoint();
		MapPoint(int x, int y);
		~MapPoint();
		
		void setX(int x);
		void setY(int y);
		SuperObject *getObject();
		void setObject(SuperObject *obj);
		int getX();
		int getY();
};

#endif
