#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
#include "SuperCrash.cpp"

class SuperEngine {
	private:
		SuperCrash s;
		// private breytur hér
	public:
		int gftdrt;
		// public breytur hér
		
	SuperEngine() {
		// constructor
	}
	~SuperEngine() {
		// destructor
	}
	void display() {
		s.display();
	}
	void keyboard() {}
	
	void test() {
		std::cout << "testing";
	}
	
};

SuperEngine e; // breyta nöfnum í eitthvað betra seinna??


void idle() {/*e.test();*/}
void display() {
	e.display();
	glutSwapBuffers();
}
void reshape() {}
void keyboardUp() {}
void keyboardDown() {}
void keyboardSpecialUp(){}
void keyboardSpecialDown(){}


void initWindow(){
	glClearColor (0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0,1.0,1.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(512, 512);
    glutCreateWindow("Supercrash 9000");
    //e = new SuperEngine;
    //e.display();
   
    //SuperEngine e = new SuperEngine;
	glutDisplayFunc(display);
	// glutReshapeFunc(reshape);
	// glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);

	initWindow();

    glutMainLoop();
	return 0;
}
