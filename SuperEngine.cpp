#include <cstdio>
#include <cstdlib>
#include <GL/glut.h>



int main(int argc, char** argv) {
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(512, 512);
    glutCreateWindow("Supercrash 9000");
   // glutDisplayFunc(draw);
   // glutReshapeFunc(reshape);
   // glutKeyboardFunc(keyboard);
   // glutIdleFunc(idle);

   // init();

    glutMainLoop();
	return 0;
}
