// SuperObject.h

#ifndef _SUPEROBJECT_H
#define _SUPEROBJECT_H

class SuperObject {
	public:
		virtual void display() = 0;
		virtual void update(int time) = 0;
		virtual void keyboardUp(unsigned char key) = 0;
		virtual void keyboardDown(unsigned char key) = 0;
		virtual void keyboardSpecialUp(int key) = 0;
		virtual void keyboardSpecialDown(int key) = 0;
};

#endif
