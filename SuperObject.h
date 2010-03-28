// SuperObject.h

#ifndef _SUPEROBJECT_H
#define _SUPEROBJECT_H

class SuperObject {
	public:
		virtual void display() = NULL;
		virtual void update(int tick) = NULL;
		virtual void keyboardUp(unsigned char key) = NULL;
		virtual void keyboardDown(unsigned char key) = NULL;
		virtual void keyboardSpecialUp(int key) = NULL;
		virtual void keyboardSpecialDown(int key) = NULL;
};

#endif
