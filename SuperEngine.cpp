// SuperEngine.cpp

#include "SuperEngine.h"
#include <cstddef>
#include <GL/glut.h>

using namespace std;

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
	
	
	glClearColor(0.0, 0.0, 0.0, 1.0);
	
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
	gluPerspective(60.0, 640.0/480.0, 0.5, 100.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	FPS = 30;
}

SuperEngine::~SuperEngine() {
}

void SuperEngine::sleep() {
	// sleep(1000.0/FPS + lastUpdate - glutGet(GLUT_ELAPSED_TIME))
	lastUpdate = glutGet(GLUT_ELAPSED_TIME);
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
