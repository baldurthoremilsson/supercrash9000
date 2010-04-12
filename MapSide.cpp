// MapSide.cpp

#include "MapSide.h"
#include <GL/gl.h>

MapSide::MapSide(int x, int y) {
	X = x;
	Y = y;
	
	panelColor.setColor(0.0, 0.1, 0.5);
	gridColor.setColor(0.0, 1.0, 1.0);
	//points = new MapPoint[x+1][55+1];
	//test = new int[11][43];
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

void MapSide::display() {
	glColor3fv(gridColor.get3fv());
	glBegin(GL_LINES);
	for(int i = 0; i < X; i++) {
		glVertex3f(-X/2.0, 0.0, i-Y/2.0 + 0.5);
		glVertex3f( X/2.0, 0.0, i-Y/2.0 + 0.5);
	}
	for(int i = 0; i < Y; i++) {
		glVertex3f(i-X/2.0 + 0.5, 0.0, -Y/2.0);
		glVertex3f(i-X/2.0 + 0.5, 0.0,  Y/2.0);
	}
	glEnd();
	
	glColor3fv(planelColor.get3fv());
	glBegin(GL_QUADS);
		glVertex3f(-X/2.0, 0.0, -Y/2.0);
		glVertex3f(-X/2.0, 0.0,  Y/2.0);
		glVertex3f( X/2.0, 0.0,  Y/2.0);
		glVertex3f( X/2.0, 0.0, -Y/2.0);
	glEnd();
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
