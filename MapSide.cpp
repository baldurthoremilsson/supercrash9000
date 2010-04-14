// MapSide.cpp

#include "MapSide.h"
#include <GL/gl.h>
#include <GL/glut.h>

MapSide::MapSide(int x, int y, Color panel) {
	X = x;
	Y = y;
	
	//panelColor.setColor(0.0, 0.1, 0.5);
	panelColor = panel;
	gridColor.setColor(0.0, 1.0, 1.0);
	
	points = new MapPoint*[x+1];
	for (int row = 0; row < x+1; row++) {
		points[row] = new MapPoint[y+1];
	}
}

MapSide::~MapSide() {
}

void MapSide::setX(int x) {
	X = x;
}

void MapSide::setY(int y) {
	Y = y;
}

int MapSide::getX() {
	return X;
}

int MapSide::getY() {
	return Y;
}

void MapSide::setNorth(MapSide *s, Edge sn) {
	northSide = s;
	northEdge = sn;
}

void MapSide::setSouth(MapSide *s, Edge sn) {
	southSide = s;
	southEdge = sn;
}

void MapSide::setEast(MapSide *s, Edge sn) {
	eastSide = s;
	eastEdge = sn;
}

void MapSide::setWest(MapSide *s, Edge sn) {
	westSide = s;
	westEdge = sn;
}

MapSide* MapSide::getSide(Edge e) {
	if(e == NORTH)
		return northSide;
	if(e == SOUTH)
		return southSide;
	if(e == EAST)
		return eastSide;
	if(e == WEST)
		return westSide;
}

Edge MapSide::getEdge(Edge e) {
	if(e == NORTH)
		return northEdge;
	if(e == SOUTH)
		return southEdge;
	if(e == EAST)
		return eastEdge;
	if(e == WEST)
		return westEdge;
}

MapPoint* MapSide::getPoint(int x, int y) {
	return &points[x][y];
}

void MapSide::addObject(SuperObject *o) {
	objects.push_back(o);
}

void MapSide::removeObject(SuperObject *o) {
	objects.remove(o);
}

void MapSide::display() {
	glColor3fv(gridColor.get3fv());
	float Xoff = X/2.0;
	float Yoff = Y/2.0;
	float gridHeight = 0.05;
	glBegin(GL_QUADS);
	float ld, lu, ru, rd
	for(int x = 0; x < X; x++) {
		glVertex3f(x-Xoff + 0.48,       0.00, -( Yoff));
		glVertex3f(x-Xoff + 0.50, gridHeight, -( Yoff+gridHeight));
		glVertex3f(x-Xoff + 0.50, gridHeight, -(-Yoff-gridHeight));
		glVertex3f(x-Xoff + 0.48,       0.00, -(-Yoff));
		glVertex3f(x-Xoff + 0.50, gridHeight, -( Yoff+gridHeight));
		glVertex3f(x-Xoff + 0.52,       0.00, -( Yoff));
		glVertex3f(x-Xoff + 0.52,       0.00, -(-Yoff));
		glVertex3f(x-Xoff + 0.50, gridHeight, -(-Yoff-gridHeight));
	}
	for(int y = 0; y < Y; y++) {
		glVertex3f( Xoff           ,       0.00, -(y-Yoff + 0.48));
		glVertex3f( Xoff+gridHeight, gridHeight, -(y-Yoff + 0.50));
		glVertex3f(-Xoff-gridHeight, gridHeight, -(y-Yoff + 0.50));
		glVertex3f(-Xoff           ,       0.00, -(y-Yoff + 0.48));
		glVertex3f( Xoff+gridHeight, gridHeight, -(y-Yoff + 0.50));
		glVertex3f( Xoff           ,       0.00, -(y-Yoff + 0.52));
		glVertex3f(-Xoff           ,       0.00, -(y-Yoff + 0.52));
		glVertex3f(-Xoff-gridHeight, gridHeight, -(y-Yoff + 0.50));
	}
	
	for(int x = 0; x <= X; x++) {
		for(int y = 0; y <= Y; y++) {
			if(getPoint()->getVertWall(x,y))
				
		}
	}
	glEnd();
	
	glColor3fv(panelColor.get3fv());
	glBegin(GL_QUADS);
		glVertex3f(-X/2.0, 0.0, -Y/2.0);
		glVertex3f(-X/2.0, 0.0,  Y/2.0);
		glVertex3f( X/2.0, 0.0,  Y/2.0);
		glVertex3f( X/2.0, 0.0, -Y/2.0);
	glEnd();
	
	for(list<SuperObject*>::iterator it = objects.begin(); it != objects.end(); it++)
		(*it)->display();
}

void MapSide::update(int time) {
}

void MapSide::keyboardUp(unsigned char key) {
}

void MapSide::keyboardDown(unsigned char key) {
}

void MapSide::keyboardSpecialUp(int key) {
}

void MapSide::keyboardSpecialDown(int key) {
}
