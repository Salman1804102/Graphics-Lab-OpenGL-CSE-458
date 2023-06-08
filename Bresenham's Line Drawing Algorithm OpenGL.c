#include<stdlib.h>
#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
float x1, x2, y1, y2;
void TakeInput()
{
	printf("Value of x1 : ");
	scanf("%f", & x1);
	printf("Value of y1 : ");
	scanf("%f", & y1);
	printf("Value of x2 : ");
	scanf("%f", & x2);
	printf("Value of y2 : ");
	scanf("%f", & y2);
}
void display(void)
{
	float dx = abs(x2 - x1);
	float dy = abs(y2 - y1);
	float p = 2 * dy - dx;
	int itr = (int)dx - 1;
	glBegin(GL_POINTS);
	glVertex2f(x1, y1);
	glEnd();
	while (itr--)
	{
		if (p < 0)
		{
			p = p + 2.0 * dy;
			x1 = x1 + 1;
			y1 = y1;
		}
		else if (p > 0)
		{
			p = p + 2 * dy - 2 * dx;
			x1 = x1 + 1;
			y1 = y1 + 1;
		}
		glBegin(GL_POINTS);
		glVertex2f(x1, y1);
		glEnd();
	}
	glFlush();
}
void myInit (void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100.0, 100.0, 100.0, -100.0);
}
int main(int argc, char ** argv)
{
	TakeInput();
	glutInit( & argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("");
	myInit ();
	glutDisplayFunc(display);
	glutMainLoop();
}
