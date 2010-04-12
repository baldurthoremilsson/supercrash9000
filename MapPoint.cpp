// MapPoint.cpp

#include "MapPoint.h"

MapPoint::MapPoint() {
	X = -1;
	Y = -1;
}

MapPoint::MapPoint(int x, int y) {
	X = x;
	Y = y;
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
	return X;;
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

