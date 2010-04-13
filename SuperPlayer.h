// SuperPlayer.h

#ifndef _SUPERPLAYER_H
#define _SUPERPLAYER_H

#include "SuperObject.h"
#include "MapSide.h"
#include "Color.h"

class SuperPlayer: public SuperObject {
	protected:
		int X;
		int Y;
		MapSide *side;
		Edge direction;
		float offset;
		float speed;
		Color color;
		
		list<SuperObject*> objects;
		
		bool turnLeft;
		bool turnRight;
		
		int lastUpdate;
		
		int getRotation();
		Edge getEdge();
		
	public:
		SuperPlayer(int x, int y, Edge dir, MapSide *mside, const Color &c);
		~SuperPlayer();
		
		virtual void display();
		virtual void update(int time);
		
		//friend PowerUp;
};

#endif
