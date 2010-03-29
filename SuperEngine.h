// SuperEngine.h

#ifndef _SUPERENGINE_H
#define _SUPERENGINE_H

#include "SuperObject.h"

class SuperEngine: public SuperObject {
	protected:
		SuperEngine();
		~SuperEngine();
		
		static void SEdisplay();
		static void SEupdate();
		static void SEkeyboardUp(unsigned char key, int x, int y);
		static void SEkeyboardDown(unsigned char key, int x, int y);
		static void SEkeyboardSpecialUp(int key, int x, int y);
		static void SEkeyboardSpecialDown(int key, int x, int y);
		
	public:
		static SuperEngine *instance;
		
		void run();
};

#endif
