// SuperPlayer.cpp

#include "SuperPlayer.h"
#include "Color.h"
#include <GL/gl.h>

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
		glTranslatef((X-side->getX())/2.0, 0.0, (Y-side->getZ())/2.0);
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
	
}

