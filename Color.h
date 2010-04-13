// Color.h

#ifndef _COLOR_H
#define _COLOR_H

#define RED 0
#define GREEN 1
#define BLUE 2

class Color {
	private:
		float colors[3];
		
	public:
		Color();
		Color(float r, float g, float b);
		~Color();
		
		Color& operator=(const Color &c);
		void setColor(float r, float g, float b);
		
		float getRed() const;
		float getGreen() const;
		float getBlue() const;
		
		const float* get3fv();
};

#endif
