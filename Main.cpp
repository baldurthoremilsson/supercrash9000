#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
#include "SuperEngine.h"

SuperEngine e; // breyta nöfnum í eitthvað betra seinna. Neinei


void idle() {  
	glutPostRedisplay();
}
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
	
	glutDisplayFunc(display);
	glutIdleFunc(idle);

	initWindow();

    glutMainLoop();
	return 0;
}
