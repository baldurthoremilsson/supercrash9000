// SuperPlayer.cpp

#include "SuperPlayer.h"

SuperPlayer::SuperPlayer(int x, int y, Edge direction) {
}

SuperPlayer::~SuperPlayer() {
}

void SuperPlayer::display() {
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
		glTransformf((X-side->getX())/2.0, 0.0, (Y-side->getY())/2.0);
		glRotatef(this->getRotation(), 0.0, -1.0, 0.0);
		glBegin(GL_TRIANGLE_STRIP);
			glVertex3f(0.0, 0.5, -1.0);
			glVertex3f(0.25, 0.0, -1.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(-0.25, 0.0, -1.0);
			glVertex3f(0.25, 0.0, -1.0);
		glEnd();
	glPopMatrix();
}

void SuperPlayer::update(int time) {
}
