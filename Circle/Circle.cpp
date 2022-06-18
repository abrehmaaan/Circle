#include <iostream>
#include <GL/glut.h>
#include<math.h>
using namespace std;

class GLintPoint {
public:
	GLint x, y;
};

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
}

GLint radius = 100;
GLintPoint origin = { 250, 250 };
GLfloat theta;

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_LINE_LOOP);
	for (int i = 0;i < 360;i++) {
		theta = i * 3.142 / 180;
		glVertex2f(origin.x + radius * cos(theta), origin.y + radius * sin(theta));
	}
	glEnd();
	
	glFlush();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Circle");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}