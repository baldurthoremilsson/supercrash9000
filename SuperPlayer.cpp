// SuperPlayer.cpp

#include "SuperPlayer.h"
#include "Color.h"
#include <cstddef>
#include <GL/gl.h>

using namespace std;

SuperPlayer::SuperPlayer(int x, int y, Edge dir, MapSide *mside, const Color &c) {
	X = x;
	Y = y;
	direction = dir;
	side = mside;
	color = c;
	
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

void SuperPlayer::draw() {
	glColor3fv(color.get3fv());
	glPushMatrix();
		glRotatef(this->getRotation(), 0.0, -1.0, 0.0);
		glTranslatef((X-side->getX())/2.0, 0.0, (Y-side->getY())/2.0);
		glBegin(GL_TRIANGLE_STRIP);
			glVertex3f(-1.0, 0.5,  0.0 );
			glVertex3f( 0.0, 0.0,  0.0 );
			glVertex3f(-1.0, 0.0,  0.25);
			glVertex3f(-1.0, 0.5, -0.25);
			glVertex3f( 0.0, 0.0,  0.0 );
		glEnd();
	glPopMatrix();
}

void SuperPlayer::update(int time) {
	// todo: PowerUp updates
	offset += speed * (time-lastUpdate)/1000.0;
	
	if(offset >= 0.0 && offset <= 1.0)
		return;
	
	if(offset < 0.0)
		offset += 1.0;
	else
		offset -= 1.0;
	
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
	        directoin == NORTH && speed < 0.0 && turnLeft ||
	        directoin == NORTH && speed > 0.0 && turnRight)
		dir = EAST;
	else
		dir = WEST;
	
	switch(dir) {
		case NORTH: X++; break;
		case SOUTH: X--; break;
		case EAST: Y++; break;
		case WEST: Y--; break;
	}
	// sumthin
	
	Edge farEdge = side->getEdge(dir);
	MapSide *farSide = side;
	int farX = X;
	int farY = Y;
	
	if(X == 0) { // dir == SOUTH
		farSide = side->getSide(dir);
		// todo: create wall
		
		switch(farEdge) {
			case NORTH:
				farX = 
				farY = 
				break;
			case SOUTH:
				farX = 
				farY = 
				break;
			case EAST:
				farX = 
				farY = 
				break;
			case WEST:
				farX = 
				farY = 
				break;
		}
	} else if(X > side->getX()) { // dir == NORTH
		farSide = side->getSide(dir);
		
		switch(farEdge) {
			case NORTH:
				farX = 
				farY = 
				break;
			case SOUTH:
				farX = 
				farY = 
				break;
			case EAST:
				farX = 
				farY = 
				break;
			case WEST:
				farX = 
				farY = 
				break;
		}
	}
	if(Y == 0) { // dir == WEST
		farSide = side->getSide(dir);
		// todo: createwall
		
		switch(farEdge) {
			case NORTH:
				farX = 
				farY = 
				break;
			case SOUTH:
				farX = 
				farY = 
				break;
			case EAST:
				farX = 
				farY = 
				break;
			case WEST:
				farX = 
				farY = 
				break;
		}
	} else if(Y > side->getY()) { // dir == EAST
		farSide = side->getSide(dir);
		
		switch(farEdge) {
			case NORTH:
				farX = 
				farY = 
				break;
			case SOUTH:
				farX = 
				farY = 
				break;
			case EAST:
				farX = 
				farY = 
				break;
			case WEST:
				farX = 
				farY = 
				break;
		}
	}
	
	MapPoint *prevPoint = side->getPoint(X,Y);
	MapPoint *currPoint;
	
	Edge newEdge;
	Side *newSide = NULL;
	if(offset < 0.0 && direction == NORTH) { // going SOUTH
		// todo: make wall
		if(Y == 1) {
			newEdge = side->getEdge(SOUTH);
			newSide = side->getSide(SOUTH);
			
			switch(newEdge) {
			case NORTH:
				Y = newSide->getY();
				break;
			case SOUTH:
				X = newSide->getX() - (X-1);
				break;
			case EAST:
				Y = newSide->getY() - (X-1);
				X = newSide->getX();
				break;
			case WEST:
				Y = X;
				X = 1;
				break;
			}
		} else
			Y--;
	} else if(offset < 0.0 && direction == EAST) { // going WEST
		// todo: make wall
		if(X == 1) {
			newEdge = side->getEdge(WEST);
			newSide = side->getSide(WEST);
			
			switch(newEdge) {
			case NORTH:
				X = newSide->getX() - (Y-1);
				Y = newSide->getY();
				break;
			case SOUTH:
				X = Y;
				Y = 1;
				break;
			case EAST:
				X = newSide->getX();
				break;
			case WEST:
				Y = newSide->getY() - (Y-1)
				break;
			}
		} else
			X--;
	} else if(offset > 1.0 && direction NORTH) { // going NORTH
		// todo: make wall
		if(Y == side->getX()) {
			newEdge = side->getEdge(NORTH);
			newSide = side->getSide(NORTH);
			
			switch(newEdge) {
			case NORTH:
				Y = newSide->getY() - (Y-1);
				X = newSide->getX();
				break;
			case SOUTH:
				Y = 1;
				break;
			case EAST:
				Y = X;
				X = newSide->getX();
				break;
			case WEST:
				Y = newSide->getY() - (X-1);
				X = 1;
				break;
			}
		} else
			Y++;
	} else { // offset > 1.0 && direction == EAST // going EAST
		// todo: make wall
		if(X == side->getY()) {
			newEdge = side->getEdge(EAST);
			newSide = side->getSide(EAST);
			
			switch(newEdge) {
			case NORTH:
				Y = X;
				X = newSide->getX();
				break;
			case SOUTH:
				X = newSide->getX() - (Y-1);
				Y = 1;
				break;
			case EAST:
				Y = newSide->getY() - (Y-1);
				X = newSide->getX();
				break;
			case WEST:
				X = 1;
				break;
			}
		} else
			X++;
	}
	if(newSide == NULL)
		currPoint = side->getPoint(X,Y);
	else {
		currPoint = newSide->getPoint(X,Y);
	}
	
	lastUpdate = time;
}

