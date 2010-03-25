#include <iostream>
#include <GL/glut.h>
#include <Menu.cpp>
#include <Pause.cpp>
#include <SuperGame.cpp>

class SuperCrash {
	private:
		//Menu m;
		//Pause p;
		SuperGame game;
		int state; // t.d. 0=menu, 1=game 2=paused.. ??
	public:
		// public breytur hér

	SuperCrash() {
		// constructor
		state = 1; // byrjum í game til að byrja með...
	}
	~SuperCrash() {
		// destructor
	}
	void display() {
		switch (state) {
			case 0:
				/*m.display(); ?????*/break;
			case 1:
				game.display(); break;
			case 2:
				// ????
		}
		std::cout << "Ímyndum okkur að skjárinn sé teiknaður... trallala\n";
	}
	void keyboard() {}

};




