// Map.cpp

#include "Map.h"
#include "MapSide.h"
#include <GL/gl.h>
#include <GL/glut.h>

Map::Map(int x, int y, int z) {
	X = x;
	Y = y;
	Z = z;
	
	topSide = new MapSide(x,z);
	bottomSide = new MapSide(x,z);
	frontSide = new MapSide(x,y);
	backSide = new MapSide(x,y);
	leftSide = new MapSide(z,y);
	rightSide = new MapSide(z,y);
	
	topSide->setNorth(backSide, NORTH);
	topSide->setSouth(frontSide, NORTH);
	topSide->setEast(leftSide, NORTH);
	topSide->setWest(rightSide, NORTH);
	
	bottomSide->setNorth(frontSide, SOUTH);
	bottomSide->setSouth(backSide, SOUTH);
	bottomSide->setEast(rightSide, SOUTH);
	bottomSide->setWest(leftSide, SOUTH);
	
	frontSide->setNorth(topSide, SOUTH);
	frontSide->setSouth(bottomSide, NORTH);
	frontSide->setEast(rightSide, WEST);
	frontSide->setWest(leftSide, EAST);
	
	backSide->setNorth(topSide, NORTH);
	backSide->setSouth(bottomSide, SOUTH);
	backSide->setEast(leftSide, WEST);
	backSide->setWest(rightSide, EAST);
	
	leftSide->setNorth(topSide, WEST);
	leftSide->setSouth(bottomSide, WEST);
	leftSide->setEast(frontSide, WEST);
	leftSide->setWest(backSide, EAST);
	
	rightSide->setNorth(topSide, EAST);
	rightSide->setSouth(bottomSide, EAST);
	rightSide->setEast(backSide, WEST);
	rightSide->setWest(frontSide, EAST);
}

Map::~Map() {
	delete topSide;
	delete bottomSide;
	delete frontSide;
	delete backSide;
	delete leftSide;
	delete rightSide;
}

MapSide* Map::getTop() {
	return topSide;
}

MapSide* Map::getBottom() {
	return bottomSide;
}

MapSide* Map::getLeft() {
	return leftSide;
}

MapSide* Map::getRight() {
	return rightSide;
}

MapSide* Map::getFront() {
	return frontSide;
}

MapSide* Map::getBack() {
	return backSide;
}

void Map::display() {
	glColor3f(1.0, 0.0, 0.0); // RED
	glPushMatrix();
		glTranslatef(0.0, Y/2.0, 0.0);
		topSide->display();
	glPopMatrix();
	
	glColor3f(0.0, 1.0, 0.0); // GREEN
	glPushMatrix();
		glTranslatef(0.0, -Y/2.0, 0.0);
		glRotatef(180.0, 1.0, 0.0, 0.0);
		bottomSide->display();
	glPopMatrix();
	
	glColor3f(0.0, 0.0, 1.0); // BLUE
	glPushMatrix();
		glTranslatef(-X/2.0, 0.0, 0.0);
		glRotatef(270.0, 0.0, 1.0, 0.0);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		leftSide->display();
	glPopMatrix();
	
	glColor3f(1.0, 1.0, 0.0); // YELLOW
	glPushMatrix();
		glTranslatef(X/2.0, 0.0, 0.0);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		rightSide->display();
	glPopMatrix();
	
	glColor3f(0.0, 1.0, 1.0); // CYAN
	glPushMatrix();
		glTranslatef(0.0, 0.0, -Z/2.0);
		glRotatef(180.0, 0.0, 1.0, 0.0);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		frontSide->display();
	glPopMatrix();
	
	glColor3f(1.0, 0.0, 1.0); // MAGENTA
	glPushMatrix();
		glTranslatef(0.0, 0.0, Z/2.0);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		backSide->display();
	glPopMatrix();
}

void Map::update(int time) {
	topSide->update(time);
	bottomSide->update(time);
	leftSide->update(time);
	rightSide->update(time);
	frontSide->update(time);
	backSide->update(time);
}

void Map::keyboardUp(unsigned char key) {
	topSide->keyboardUp(key);
	bottomSide->keyboardUp(key);
	leftSide->keyboardUp(key);
	rightSide->keyboardUp(key);
	frontSide->keyboardUp(key);
	backSide->keyboardUp(key);
}

void Map::keyboardDown(unsigned char key) {
	topSide->keyboardDown(key);
	bottomSide->keyboardDown(key);
	leftSide->keyboardDown(key);
	rightSide->keyboardDown(key);
	frontSide->keyboardDown(key);
	backSide->keyboardDown(key);
}

void Map::keyboardSpecialUp(int key) {
	topSide->keyboardSpecialUp(key);
	bottomSide->keyboardSpecialUp(key);
	leftSide->keyboardSpecialUp(key);
	rightSide->keyboardSpecialUp(key);
	frontSide->keyboardSpecialUp(key);
	backSide->keyboardSpecialUp(key);
}

void Map::keyboardSpecialDown(int key) {
	topSide->keyboardSpecialDown(key);
	bottomSide->keyboardSpecialDown(key);
	leftSide->keyboardSpecialDown(key);
	rightSide->keyboardSpecialDown(key);
	frontSide->keyboardSpecialDown(key);
	backSide->keyboardSpecialDown(key);
}
