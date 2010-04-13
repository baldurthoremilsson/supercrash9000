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
		return; // did not cross MapPoints
	
	// preparation for collision detection
	MapPoint *collisionHV;
	MapPoint *collisionH;
	MapPoint *collisionV;
	
	// creating a wall
	if(direction == NORTH)
		side->getPoint(X,Y)->setVertWall(color);
	else
		side->getPoint(X,Y)->setHorizWall(color);
	
	// fixing the offset
	if(offset < 0.0)
		offset += 1.0;
	else
		offset -= 1.0;
	
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
	
	if(side != farSide && farEdge == SOUTH)
		farSide->getPoint()->setHorizWall(color);
	else if(side != farSide && farEdge == WEST)
		farSide->getPoint()->setVertWall(color);
	
	side = farSide;
	X = farX;
	Y = farY;
	
	if(dir == NORTH || dir == EAST) {
		collisionHV = side->getPoint(X,Y);
		collisionH  = side->getPoint(X-1,Y);
		collisionV  = side->getPoint(X,Y-1);
	}
	
	if(collisionHV->getHorizWall() || collisionHV->getVertWall() || collisionH->getHorizWall() || collisionV->getVertWall())
		; // colided!
	if(collisionHV->getObject()) {
		
	}
	
	lastUpdate = time;
}

