// MapSide.h

#ifndef _MAPSIDE_H
#define _MAPSIDE_H

#include "SuperObject.h"
#include "MapPoint.h"
#include <list>
#include <GL/gl.h>

using namespace std;

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
		
		//MapPoint *points;
		//list<SuperObject> *objects;
		
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
		
		MapSide* getSide(Edge e);
		Edge getEdge(Edge e);
		
		void display();
		void update(int time);
		void keyboardUp(unsigned char key);
		void keyboardDown(unsigned char key);
		void keyboardSpecialUp(int key);
		void keyboardSpecialDown(int key);
};

#endif
