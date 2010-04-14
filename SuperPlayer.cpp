// SuperPlayer.cpp

#include "SuperPlayer.h"
#include "Color.h"
#include <cstddef>
// todo: remove debug
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

SuperPlayer::SuperPlayer(int x, int y, Edge dir, MapSide *mside, const Color &c) {
	X = x;
	Y = y;
	direction = dir;
	side = mside;
	color = c;
	
	offset = 0.0;
	speed = 0.1;
	
	side->addObject(this);
	
	turnLeft = false;
	turnRight = false;
}

SuperPlayer::~SuperPlayer() {
}


int SuperPlayer::getRotation() {
	if(direction == NORTH && speed >= 0.0)
		return 0;
	if(direction == NORTH && speed < 0.0)
		return 180;
	if(direction == EAST && speed >= 0.0)
		return 90;
	// if(direction == EAST && speed < 0.0)
		return 270;
}

Edge SuperPlayer::getEdge() {
	if(direction == NORTH && speed >= 0.0)
		return NORTH;
	if(direction == NORTH && speed < 0.0)
		return SOUTH;
	if(direction == EAST && speed >= 0.0)
		return EAST;
	// if(direction == EAST && speed < 0.0)
		return WEST;
}

void SuperPlayer::setAttributes(int newX, int newY, MapSide *newSide, Edge newDirection) {
	X = newX;
	Y = newY;
	direction = newDirection;
	side->removeObject(this);
	side = newSide;
	side->addObject(this);
}

void SuperPlayer::goWest() {
	int farX;
	int farY;
	if(X == 1) {
		MapSide *farSide = side->getSide(WEST);
		Edge farDirection;
		switch(side->getEdge(WEST)) {
			case NORTH:
				farX = farSide->getX() - (Y-1);
				farY = farSide->getY();
				farDirection = SOUTH;
				break;
			case SOUTH:
				farX = Y;
				farY = 1;
				farDirection = NORTH;
				break;
			case WEST:
				farX = 1;
				farY = farSide->getY() - (Y-1);
				farDirection = EAST;
				break;
			case EAST:
				farX = farSide->getX();
				farY = Y;
				farDirection = WEST;
				break;
		}
		this->setAttributes(farX, farY, farSide, farDirection);
	}
	else
		X--;
}

void SuperPlayer::goEast() {
	int farX;
	int farY;
	if(X == side->getX()) {
		MapSide *farSide = side->getSide(EAST);
		Edge farDirection;
		switch(side->getEdge(EAST)) {
			case NORTH:
				farX = Y;
				farY = farSide->getY();
				farDirection = SOUTH;
				break;
			case SOUTH:
				farX = farSide->getX() - (Y-1);
				farY = 1;
				farDirection = NORTH;
				break;
			case WEST:
				farX = 1;
				farY = Y;
				farDirection = EAST;
				break;
			case EAST:
				farX = farSide->getX();
				farY = farSide->getY() - (Y-1);
				farDirection = WEST;
				break;
		}
		this->setAttributes(farX, farY, farSide, farDirection);
	}
	else
		X++;
}

void SuperPlayer::goNorth() {
	int farX;
	int farY;
	if(Y == side->getY()) {
		MapSide *farSide = side->getSide(NORTH);
		Edge farDirection;
		switch(side->getEdge(NORTH)) {
			case NORTH:
				farX = farSide->getX() - (X-1);
				farY = farSide->getY();
				farDirection = SOUTH;
				break;
			case SOUTH:
				farX = X;
				farY = 1;
				farDirection = NORTH;
				break;
			case WEST:
				farX = 1;
				farY = farSide->getY() - (X-1);
				farDirection = EAST;
				break;
			case EAST:
				farX = farSide->getX();
				farY = X;
				farDirection = WEST;
				break;
		}
		this->setAttributes(farX, farY, farSide, farDirection);
	}
	else
		Y++;
}

void SuperPlayer::goSouth() {
	int farX;
	int farY;
	if(Y == 1) {
		MapSide *farSide = side->getSide(SOUTH);
		Edge farDirection;
		switch(side->getEdge(SOUTH)) {
			case NORTH:
				farX = X;
				farY = farSide->getY();
				farDirection = SOUTH;
				break;
			case SOUTH:
				farX = farSide->getX() - (X-1);
				farY = 1;
				farDirection = NORTH;
				break;
			case WEST:
				farX = 1;
				farY = X;
				farDirection = EAST;
				break;
			case EAST:
				farX = farSide->getX();
				farY = farSide->getY() - (X-1);
				farDirection = WEST;
				break;
		}
		this->setAttributes(farX, farY, farSide, farDirection);
	}
	else
		Y--;
}

void SuperPlayer::display() {
	glColor3fv(color.get3fv());
	glPushMatrix();
		//glRotatef(this->getRotation(), 0.0, -1.0, 0.0);
		glTranslatef(X-side->getX()/2.0-0.5, 0.0, -(Y-side->getY()/2.0-0.5));
		glutSolidSphere(0.2, 10, 10);
		/*
		glBegin(GL_TRIANGLE_STRIP);
			glVertex3f( 0.0,  0.0, offset+0.0);
			glVertex3f( 0.0,  0.5, offset-1.0);
			glVertex3f(-0.25, 0.0, offset-1.0);
			glVertex3f( 0.25, 0.0, offset-1.0);
			glVertex3f( 0.0,  0.0, offset+0.0);
		glEnd();
		*/
	glPopMatrix();
}

void SuperPlayer::update(int time) {
	// todo: PowerUp updates
	if(direction == NORTH || direction == EAST)
		offset += speed * (time-lastUpdate)/1000.0;
	else
		offset -= speed * (time-lastUpdate)/1000.0;
	
	if(offset >= 0.0 && offset <= 1.0)
		return; // did not cross MapPoints
	
	/* oldstuff
	// preparation for collision detection
	MapPoint *collisionHV;
	MapPoint *collisionH;
	MapPoint *collisionV;
	*/
	
	// creating a wall
	if(direction == NORTH || direction == SOUTH)
		side->getPoint(X,Y)->setVertWall(color);
	else
		side->getPoint(X,Y)->setHorizWall(color);
	
	// fixing the offset
	if(offset < 0.0)
		offset += 1.0;
	else
		offset -= 1.0;
	
	switch(direction) {
		case NORTH: goNorth(); break;
		case SOUTH: goSouth(); break;
		case EAST: goEast(); break;
		case WEST: goWest(); break;
	}
	
	
	
	return;
	
	// dir == the way we're heading
	Edge dir;
	if(direction == NORTH && speed > 0.0 && turnLeft == turnRight ||
	   direction == EAST  && speed > 0.0 && turnLeft ||
	   direction == EAST  && speed < 0.0 && turnRight)
		dir = NORTH;
	else if(direction == NORTH && speed < 0.0 && turnLeft == turnRight ||
	        direction == EAST  && speed > 0.0 && turnRight ||
	        direction == EAST  && speed < 0.0 && turnLeft)
		dir = SOUTH;
	else if(direction == EAST  && speed > 0.0 && turnLeft == turnRight ||
	        direction == NORTH && speed < 0.0 && turnLeft ||
	        direction == NORTH && speed > 0.0 && turnRight)
		dir = EAST;
	else
		dir = WEST;
	
	if(speed < 0.0 && (dir == NORTH || dir == EAST) || speed > 0.0 && (dir == SOUTH || dir == WEST))
		speed *= -1.0;
	
	direction = (dir == NORTH || dir == SOUTH) ? NORTH : EAST;
	
	// preparation for collision detection
	if(dir == SOUTH || dir == WEST) {
		collisionHV = side->getPoint(X, Y);
		collisionH  = side->getPoint(X-1, Y);
		collisionV  = side->getPoint(X, Y-1);
	}
	
	switch(dir) {
		case NORTH: Y++; break;
		case SOUTH: Y--; break;
		case EAST: X++; break;
		case WEST: X--; break;
	}
	return;
	Edge farEdge = side->getEdge(dir);
	MapSide *farSide = side;
	int farX = X;
	int farY = Y;
	
	if(X == 0) { // dir == WEST
		side->getPoint(X,Y)->setVertWall(color);
		farSide = side->getSide(dir);
		
		switch(farEdge) {
			case NORTH:
				farX = farSide->getX() - (Y-1);
				farY = farSide->getY();
				break;
			case SOUTH:
				farX = Y;
				farY = 1;
				break;
			case EAST:
				farX = farSide->getX();
				farY = Y;
				break;
			case WEST:
				farX = 1;
				farY = farSide->getY() - (Y-1);
				break;
		}
	} else if(X > side->getX()) { // dir == EAST
		farSide = side->getSide(dir);
		
		switch(farEdge) {
			case NORTH:
				farX = Y;
				farY = farSide->getX();
				break;
			case SOUTH:
				farX = farSide->getX() - (Y-1);
				farY = 1;
				break;
			case EAST:
				farX = farSide->getX();
				farY = farSide->getY() - (Y-1);
				break;
			case WEST:
				farX = 1;
				farY = Y;
				break;
		}
	}
	if(Y == 0) { // dir == SOUTH
		side->getPoint(X,Y)->setHorizWall(color);
		farSide = side->getSide(dir);
		
		switch(farEdge) {
			case NORTH:
				farX = X;
				farY = farSide->getY();
				break;
			case SOUTH:
				farX = farSide->getX() - (X-1);
				farY = 1;
				break;
			case EAST:
				farX = farSide->getX();
				farY = farSide->getY() - (X-1);
				break;
			case WEST:
				farX = 1;
				farY = X;
				break;
		}
	} else if(Y > side->getY()) { // dir == NORTH
		farSide = side->getSide(dir);
		
		switch(farEdge) {
			case NORTH:
				farX = farSide->getX() - (X-1);
				farY = farSide->getY();
				break;
			case SOUTH:
				farX = X;
				farY = 1;
				break;
			case EAST:
				farX = farSide->getX();
				farY = X;
				break;
			case WEST:
				farX = 1;
				farY = farSide->getY() - (X-1);
				break;
		}
	}
	
	if(side != farSide && farEdge == SOUTH) {
		side->removeObject(this);
		farSide->addObject(this);
		
		if(farEdge == SOUTH)
		farSide->getPoint(0,farY)->setHorizWall(color);
		else if(farEdge == WEST)
		farSide->getPoint(farX,0)->setVertWall(color);
	}
	
	side = farSide;
	X = farX;
	Y = farY;
	
	if(dir == NORTH || dir == EAST) {
		collisionHV = side->getPoint(X,Y);
		collisionH  = side->getPoint(X-1,Y);
		collisionV  = side->getPoint(X,Y-1);
	}
	
	if(collisionHV->getHorizWall() || collisionHV->getVertWall() || collisionH->getHorizWall() || collisionV->getVertWall())
		; // todo: colided!
	if(collisionHV->getObject()) {
		// todo: get object
	}
	
	lastUpdate = time;
}

