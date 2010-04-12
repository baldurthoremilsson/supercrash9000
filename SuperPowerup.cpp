// SuperPowerup.cpp

#include "SuperPowerup.h"

using namespace std;

SuperPowerup::SuperPowerup() {
	alive = 1;
	ttlPlayer = 1000;
	ttlSide = 5000;
	t = 0;
}

SuperPowerup::~SuperPowerup() {
}

void SuperPowerup::update(int time) {
	t++;
	if (player != NULL) {
		updatePlayer();
		if (t>ttlPlayer)
			alive = 0;
	}
	else {
		updateSide();
		if (t>ttlSide)
			alive = 0;
	}
}

