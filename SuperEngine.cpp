// SuperEngine.cpp

#include "SuperEngine.h"
#include <GL/glut.h>

SuperEngine *SuperEngine::instance;

SuperEngine::SuperEngine() {
	int argc = 0;
	glutInit(&argc, NULL);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutCreateWindow("SuperCrash 9000");
	
	glutDisplayFunc(SuperEngine::SEdisplay);
	glutIdleFunc(SuperEngine::SEupdate);
	glutKeyboardFunc(SuperEngine::SEkeyboardDown);
	glutKeyboardUpFunc(SuperEngine::SEkeyboardUp);
	glutSpecialFunc(SuperEngine::SEkeyboardSpecialDown);
	glutSpecialUpFunc(SuperEngine::SEkeyboardSpecialUp);
	
	
	glClearColor (0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0,1.0,1.0);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}

SuperEngine::~SuperEngine() {
}

void SuperEngine::SEdisplay() {
	SuperEngine::instance->display();
}

void SuperEngine::SEupdate() {
	SuperEngine::instance->update(glutGet(GLUT_ELAPSED_TIME));
}

void SuperEngine::SEkeyboardUp(unsigned char key, int x, int y) {
	SuperEngine::instance->keyboardUp(key);
}

void SuperEngine::SEkeyboardDown(unsigned char key, int x, int y) {
	SuperEngine::instance->keyboardDown(key);
}

void SuperEngine::SEkeyboardSpecialUp(int key, int x, int y) {
	SuperEngine::instance->keyboardSpecialUp(key);
}

void SuperEngine::SEkeyboardSpecialDown(int key, int x, int y) {
	SuperEngine::instance->keyboardSpecialDown(key);
}

void SuperEngine::run() {
	glutMainLoop();
}
