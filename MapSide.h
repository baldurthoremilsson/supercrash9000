// MapSide.h

#ifndef _MAPSIDE_H
#define _MAPSIDE_H

#include "definitions.h"
#include "SuperObject.h"
#include <GL/gl.h>

enum Edge {
	NORTH,
	SOUTH,
	EAST,
	WEST
};

class MapSide: public SuperObject {
	private:
		int X;
		int Z;
		
		MapSide *northSide;
		MapSide *southSide;
		MapSide *eastSide;
		MapSide *westSide;
		
		Edge northEdge;
		Edge southEdge;
		Edge eastEdge;
		Edge westEdge;
		
		GLfloat planeColor[3];
		GLfloat gridColor[3];
		
	public:
		MapSide(int x, int z);
		~MapSide();
		
		void setX(int x);
		void setZ(int z);
		int getX();
		int getZ();
		
		void setNorth(MapSide *s, Edge sn);
		void setSouth(MapSide *s, Edge sn);
		void setEast(MapSide *s, Edge sn);
		void setWest(MapSide *s, Edge sn);
		MapSide* getNorth();
		MapSide* getSouth();
		MapSide* getEast();
		MapSide* getWest();
		
		void display();
		void update(int time);
		void keyboardUp(unsigned char key);
		void keyboardDown(unsigned char key);
		void keyboardSpecialUp(int key);
		void keyboardSpecialDown(int key);
};

#endif
