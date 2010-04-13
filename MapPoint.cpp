// MapPoint.cpp

#include "MapPoint.h"
#include "Color.h"
#include <cstddef>

using namespace std;

MapPoint::MapPoint() {
	horiz = NULL
	vert = NULL;
}

MapPoint::~MapPoint() {
}

SuperObject* MapPoint::getObject() {
	return object;
}
void MapPoint::setObject(SuperObject *obj) {
	object = obj;
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

const Color* MapPoint::setVertWall() {
	return vert;
}
