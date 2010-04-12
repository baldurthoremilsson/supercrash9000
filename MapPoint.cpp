// MapPoint.cpp

#include "MapPoint.h"
#include "Color.h"
#include <cstddef>

using namespace std;

MapPoint::MapPoint() {
	X = -1;
	Y = -1;
}

MapPoint::MapPoint(int x, int y) {
	X = x;
	Y = y;
	
	horiz = NULL;
	vert = NULL;
}

MapPoint::~MapPoint() {
}

void MapPoint::setX(int x) {
	X = x;
}

void MapPoint::setY(int y) {
	Y = y;
}

int MapPoint::getX() {
	return X;
}

int MapPoint::getY() {
	return Y;
}

SuperObject* MapPoint::getObject() {
	return object;
}
void MapPoint::setObject(SuperObject *obj) {
	object = obj;
}

void MapPoint::setColorHoriz(const Color &c) {
	if(!horiz)
		horiz = new Color();
	(*horiz) = c;
}

void MapPoint::setColorVert(const Color &c) {
	if(!vert)
		vert = new Color();
	(*vert) = c;
}

const Color* MapPoint::getColorHoriz() {
	return horiz;
}

const Color* MapPoint::setColorHoriz() {
	return vert;
}

