// MapPoint.h

#ifndef _MAPPOINT_H
#define _MAPPOINT_H

#include "SuperObject.h"
#include "Color.h"

class MapPoint {
	private:
		Color *horiz;
		Color *vert;
		
		SuperObject *object;
		
	public:
		MapPoint();
		~MapPoint();
		
		SuperObject *getObject();
		void setObject(SuperObject *obj);
		
		void setHorizWall(const Color &c);
		void setVertWall(const Color &c);
		const Color* getHorizWall();
		const Color* setVertWall();
};

#endif

