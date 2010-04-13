// SuperPlayer.h

#ifndef _SUPERPLAYER_H
#define _SUPERPLAYER_H

#include "SuperObject.h"
#include "MapSide.h"

class SuperPlayer: public SuperObject {
	protected:
		int X;
		int Y;
		MapSide *side;
		Edge direction;
		float offset;
		float speed;
		
		Edge getEdge();
		float getRotation();
		
	public:
		SuperPlayer(int x, int y, Edge direction);
		~SuperPlayer();
		
		virtual void display();
		virtual void update(int time);
};

#endif
