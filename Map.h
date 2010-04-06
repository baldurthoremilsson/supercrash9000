// Map.h

#ifndef _MAP_H
#define _MAP_H

#include "definitions.h"
#include "MapSide.h"

class Map: public SuperObject {
	private:
		int X;
		int Y;
		int Z;
		
		MapSide *topSide;
		MapSide *bottomSide;
		MapSide *leftSide;
		MapSide *rightSide;
		MapSide *frontSide;
		MapSide *backSide;
	public:
		Map(int x, int y, int z);
		~Map();
		
		void display();
		void update(int time);
		void keyboardUp(unsigned char key);
		void keyboardDown(unsigned char key);
		void keyboardSpecialUp(int key);
		void keyboardSpecialDown(int key);
};

#endif
