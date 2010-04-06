// MapSide.cpp

#include "MapSide.h"
#include <GL/gl.h>

MapSide::MapSide(int x, int z) {
	X = x;
	Z = z;
	
	planeColor[0] = 0.0;
	planeColor[1] = 0.1;
	planeColor[2] = 0.5;
	gridColor[0] = 0.0;
	gridColor[1] = 1.0;
	gridColor[2] = 1.0;
}

MapSide::~MapSide() {
}

void MapSide::setX(int x) {
	X = x;
}

void MapSide::setZ(int z) {
	Z = z;
}

int MapSide::getX() {
	return X;
}

int MapSide::getZ() {
	return Z;
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

MapSide* MapSide::getNorth() {
	return northSide;
}

MapSide* MapSide::getSouth() {
	return southSide;
}

MapSide* MapSide::getEast() {
	return eastSide;
}

MapSide* MapSide::getWest() {
	return westSide;
}

void MapSide::display() {
	glColor3fv(gridColor);
	glBegin(GL_LINES);
	for(int i = 0; i < X; i++) {
		glVertex3f(-X/2.0, 0.0, i-Z/2.0 + 0.5);
		glVertex3f( X/2.0, 0.0, i-Z/2.0 + 0.5);
	}
	for(int i = 0; i < Z; i++) {
		glVertex3f(i-X/2.0 + 0.5, 0.0, -Z/2.0);
		glVertex3f(i-X/2.0 + 0.5, 0.0,  Z/2.0);
	}
	glEnd();
	
	glColor3fv(planeColor);
	glBegin(GL_QUADS);
		glVertex3f(-X/2.0, 0.0, -Z/2.0);
		glVertex3f(-X/2.0, 0.0,  Z/2.0);
		glVertex3f( X/2.0, 0.0,  Z/2.0);
		glVertex3f( X/2.0, 0.0, -Z/2.0);
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
