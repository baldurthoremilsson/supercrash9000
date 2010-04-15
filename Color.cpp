// Color.cpp

#include "Color.h"

Color::Color() {
	colors[RED] = 0.0;
	colors[GREEN] = 0.0;
	colors[BLUE] = 0.0;
}

Color::Color(float r, float g, float b) {
	colors[RED] = r;
	colors[GREEN] = g;
	colors[BLUE] = b;
}

Color::~Color() {
}

Color& Color::operator=(const Color &c) {
	if(this == &c)
		return *this;
	
	colors[RED] = c.getRed();
	colors[GREEN] = c.getGreen();
	colors[BLUE] = c.getBlue();
	
	return *this;
}

float Color::getRed() const {
	return colors[RED];
}

float Color::getGreen() const {
	return colors[GREEN];
}

float Color::getBlue() const {
	return colors[BLUE];
}

void Color::setColor(float r, float g, float b) {
	colors[RED] = r;
	colors[GREEN] = g;
	colors[BLUE] = b;
}

const float* Color::get3fv() const {
	return colors;
}
