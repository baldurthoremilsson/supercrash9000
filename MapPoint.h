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
		
		void setColorHoriz(const Color &c);
		void setColorVert(const Color &c);
		const Color* getColorHoriz();
		const Color* setColorHoriz();
};

#endif

