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
	MapPoint *prevPoint = side->getPoint(X,Y);
	MapPoint *currPoint;
	offset += speed * (time-lastUpdate)/1000.0;
	
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

