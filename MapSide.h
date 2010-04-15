// MapSide.h

#ifndef _MAPSIDE_H
#define _MAPSIDE_H

#include "SuperObject.h"
#include "MapPoint.h"
#include "Color.h"
#include <list>
#include <GL/gl.h>

#define WALLHEIGHT 0.5
#define WALLWIDTH  0.2

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
		int Y;
		
		MapSide *northSide;
		MapSide *southSide;
		MapSide *eastSide;
		MapSide *westSide;
		
		Edge northEdge;
		Edge southEdge;
		Edge eastEdge;
		Edge westEdge;
		
		Color panelColor;
		Color gridColor;
		
		MapPoint **points;
		list<SuperObject*> objects;
		
		void displayWall(float *a, float *b, float *c, float *d, float *e, float *f, float *g, float *h);
		
	public:
		MapSide(int x, int y);
		MapSide(int x, int y, Color panel);
		~MapSide();
		
		void setX(int x);
		void setY(int y);
		int getX();
		int getY();
		
		void setNorth(MapSide *s, Edge sn);
		void setSouth(MapSide *s, Edge sn);
		void setEast(MapSide *s, Edge sn);
		void setWest(MapSide *s, Edge sn);
		
		MapSide* getSide(Edge e);
		Edge getEdge(Edge e);
		
		MapPoint* getPoint(int x, int y);
		
		void addObject(SuperObject *o);
		void removeObject(SuperObject *o);
		
		bool wallOnPoint(int x, int y);
		
		void display();
		void update(int time);
		void keyboardUp(unsigned char key);
		void keyboardDown(unsigned char key);
		void keyboardSpecialUp(int key);
		void keyboardSpecialDown(int key);
};

#endif
