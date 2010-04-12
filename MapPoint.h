// MapPoint.h

#ifndef _MAPPOINT_H
#define _MAPPOINT_H

#include "SuperObject.h"
#include "Color.h"

class MapPoint {
	private:
		int X;
		int Y;
		
		Color *horiz;
		Color *vert;
		
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
		
		void setColorHoriz(const Color &c);
		void setColorVert(const Color &c);
		const Color* getColorHoriz();
		const Color* setColorHoriz();
};

#endif

