// SuperObject.h

#ifndef _SUPEROBJECT_H
#define _SUPEROBJECT_H

class SuperObject {
	public:
		virtual void display() = NULL;
		virtual void update(int tick) = NULL;
		virtual void keyboard(unsigned char key, int x, int y) = NULL;
		virtual void specialKey(int key, int x, int y) = NULL;
};

#endif
