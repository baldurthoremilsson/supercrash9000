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
	speed = 0.2;
	
	side->addObject(this);
	
	turnLeft = false;
	turnRight = false;
}

SuperPlayer::~SuperPlayer() {
}


int SuperPlayer::getRotation() {
	if(direction == NORTH)
		return 0;
	if(direction == SOUTH)
		return 180;
	if(direction == EAST)
		return 270;
	// if(direction == WEST)
		return 90;
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
		side->getPoint(0,Y)->setHorizWall(this->color);
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
				farSide->getPoint(farX,0)->setVertWall(this->color);
				offset = 1.0-offset;
				break;
			case WEST:
				farX = 1;
				farY = farSide->getY() - (Y-1);
				farDirection = EAST;
				farSide->getPoint(0,farY)->setHorizWall(this->color);
				offset = 1.0-offset;
				break;
			case EAST:
				farX = farSide->getX();
				farY = Y;
				break;
		}
		this->setAttributes(farX, farY, farSide, farDirection);
	}
	else {
		X--;
		if(X < side->getX() && X > 1)
			if(turnLeft && !turnRight) {
				Y--;
				direction = SOUTH;
			} else if(turnRight && !turnLeft) {
				direction = NORTH;
				offset = 1.0-offset;
			}
	}
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
				offset = 1.0-offset;
				break;
			case SOUTH:
				farX = farSide->getX() - (Y-1);
				farY = 1;
				farDirection = NORTH;
				farSide->getPoint(farX,0)->setVertWall(this->color);
				break;
			case WEST:
				farX = 1;
				farY = Y;
				farDirection = EAST;
				farSide->getPoint(0,farY)->setHorizWall(this->color);
				break;
			case EAST:
				farX = farSide->getX();
				farY = farSide->getY() - (Y-1);
				farDirection = WEST;
				offset = 1.0-offset;
				break;
		}
		this->setAttributes(farX, farY, farSide, farDirection);
	}
	else {
		X++;
		if(X < side->getX() && X > 1)
			if(turnLeft && !turnRight) {
				direction = NORTH;
			} else if(turnRight && !turnLeft) {
				Y--;
				direction = SOUTH;
				offset = 1.0-offset;
			}
	}
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
				offset = 1.0-offset;
				break;
			case SOUTH:
				farX = X;
				farY = 1;
				farDirection = NORTH;
				farSide->getPoint(farX,0)->setVertWall(this->color);
				break;
			case WEST:
				farX = 1;
				farY = farSide->getY() - (X-1);
				farDirection = EAST;
				farSide->getPoint(0,farY)->setHorizWall(this->color);
				break;
			case EAST:
				farX = farSide->getX();
				farY = X;
				farDirection = WEST;
				offset = 1.0-offset;
				break;
		}
		this->setAttributes(farX, farY, farSide, farDirection);
	}
	else {
		Y++;
		if(Y < side->getY() && Y > 1)
			if(turnLeft && !turnRight) {
				direction = WEST;
				X--;
				offset = 1.0-offset;
			} else if(turnRight && !turnLeft) {
				direction = EAST;
			}
	}
}

void SuperPlayer::goSouth() {
	int farX;
	int farY;
	if(Y == 1) {
		side->getPoint(X,0)->setVertWall(this->color);
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
				farSide->getPoint(farX,0)->setVertWall(this->color);
				offset = 1.0-offset;
				break;
			case WEST:
				farX = 1;
				farY = X;
				farDirection = EAST;
				farSide->getPoint(0,farY)->setHorizWall(this->color);
				offset = 1.0-offset;
				break;
			case EAST:
				farX = farSide->getX();
				farY = farSide->getY() - (X-1);
				farDirection = WEST;
				break;
		}
		this->setAttributes(farX, farY, farSide, farDirection);
	}
	else {
		Y--;
		if(Y < side->getY() && Y > 1)
			if(turnLeft && !turnRight) {
				direction = EAST;
			} else if(turnRight && !turnLeft) {
				direction = WEST;
				X--;
				offset = 1.0-offset;
			}
	}
}

bool SuperPlayer::checkCollision() {
	MapPoint *point = side->getPoint(X,Y);
	if(point->getPowerup()) {
		powerups.push_back(point->getPowerup());
		point->setPowerup(NULL);
	}
	collided = side->wallOnPoint(X,Y);
}

void SuperPlayer::display() {
	glColor3fv(color.get3fv());
	glPushMatrix();
		//if(X == 1 && offset > 0.5)
		
		glTranslatef(X-side->getX()/2.0-0.5, 0.0, -(Y-side->getY()/2.0-0.5));
		glRotatef(this->getRotation(), 0.0, 1.0, 0.0);
		if(direction == SOUTH || direction == WEST)
			glTranslatef(0.0, 0.0, offset);
		else
			glTranslatef(0.0, 0.0, -offset);
		
		glBegin(GL_TRIANGLE_STRIP);
			glVertex3f( 0.0,  0.0 , -0.5);
			glVertex3f( 0.0,  0.25,  0.0);
			glVertex3f(-0.13, 0.0 ,  0.0);
			glVertex3f( 0.13, 0.0 ,  0.0);
			glVertex3f( 0.0,  0.0 , -0.5);
		glEnd();
	glPopMatrix();
}

void SuperPlayer::update(int time) {
	MapPoint *lastPoint = side->getPoint(X,Y);
	Edge lastDir = direction;
	collided = false;
	
	// todo: PowerUp updates
	if(direction == NORTH || direction == EAST)
		offset += speed * (time-lastUpdate)/1000.0;
	else
		offset -= speed * (time-lastUpdate)/1000.0;
	lastUpdate = time;
	
	if(offset >= 0.0 && offset <= 1.0)
		return; // did not cross MapPoints
	
	// fixing the offset
	if(offset < 0.0)
		offset += 1.0;
	else
		offset -= 1.0;
	
	switch(direction) {
		case NORTH:
			goNorth();
			checkCollision();
			break;
		case SOUTH:
			checkCollision();
			goSouth();
			break;
		case EAST:
			goEast();
			checkCollision();
			break;
		case WEST:
			checkCollision();
			goWest();
			break;
	}
	
	// creating a wall
	if(lastDir == NORTH || lastDir == SOUTH)
		lastPoint->setVertWall(color);
	else
		lastPoint->setHorizWall(color);
	
	if(collided)
		std::cout << "Collision: (" << X << "," << Y << ")\n"; // die()
}

