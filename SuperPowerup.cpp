// SuperPowerup.cpp

#include "SuperPowerup.h"

using namespace std;

SuperPowerup::SuperPowerup(int time) {
	timeToLive = time+10000;
	lastUpdate = time;
}

SuperPowerup::~SuperPowerup() {
}

void SuperPowerup::update(int time) {
	lastUpdate = time;
}

void SuperPowerup::snatched(int time) {
	timeToLive = time+10000;
	lastUpdate = time;
}

bool SuperPowerup::isAlive() {
	return timeToLive > lastUpdate;
}

