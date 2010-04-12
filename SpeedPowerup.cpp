// SpeedPowerup.cpp

#include "SpeedPowerup.h"
#include "SuperPlayer.h"
#include <GL/glut.h>

using namespace std;

SpeedPowerup::SpeedPowerup() {
}

SpeedPowerup::~SpeedPowerup() {
}
void SpeedPowerup::display() {
	glColor3f(0.97,0.5,0.09); // Orange
	glutSolidCube(1);
}
void SpeedPowerup::updatePlayer() {}
void SpeedPowerup::updateSide() {}


