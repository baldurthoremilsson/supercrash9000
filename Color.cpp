// Color.cpp

#include "Color.h"

Color::Color(float red, float green, float blue) {
	color[0] = red;
	color[1] = green;
	color[2] = blue;
}

Color::~Color() {
}

Color& Color::operator=(const Color &c) {
	color[0] = c.color[0];
	color[1] = c.color[1];
	color[2] = c.color[2];
	
	return *this;
}

float* Color::get3fv() {
	return color;
}
