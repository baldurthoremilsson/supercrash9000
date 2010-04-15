// MapPoint.cpp

#include "MapPoint.h"
#include "Color.h"
#include "SuperPowerup.h"
#include <cstddef>

using namespace std;

MapPoint::MapPoint() {
	horiz = NULL;
	vert = NULL;
	powerup = NULL;
}

MapPoint::~MapPoint() {
	delete horiz;
	delete vert;
}

SuperPowerup* MapPoint::getPowerup() {
	return powerup;
}
void MapPoint::setPowerup(SuperPowerup *spu) {
	powerup = spu;
}

void MapPoint::setHorizWall(const Color &c) {
	if(!horiz)
		horiz = new Color();
	(*horiz) = c;
}

void MapPoint::setVertWall(const Color &c) {
	if(!vert)
		vert = new Color();
	(*vert) = c;
}

const Color* MapPoint::getHorizWall() {
	return horiz;
}

const Color* MapPoint::getVertWall() {
	return vert;
}
