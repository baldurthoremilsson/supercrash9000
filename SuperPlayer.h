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
		
		list<SuperPowerup*> powerups;
		
		bool turnLeft;
		bool turnRight;
		
		int collided;
		
		int lastUpdate;
		
		int getRotation();
		void setAttributes(int newX, int newY, MapSide *newSide, Edge newDirection);
		
		void goWest();
		void goEast();
		void goNorth();
		void goSouth();
		
		bool checkCollision();
		
	public:
		SuperPlayer(int x, int y, Edge dir, MapSide *mside, const Color &c);
		~SuperPlayer();
		
		virtual void display();
		virtual void update(int time);
		
		//friend PowerUp;
};

#endif
