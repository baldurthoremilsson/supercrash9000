// Color.h

#ifndef _COLOR_H
#define _COLOR_H

class Color {
	private:
		float color[3];
		
	public:
		Color(float red, float green, float blue);
		~Color();
		
		Color& operator=(const Color &c);
		
		float* get3fv();
};

#endif
