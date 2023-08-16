#include<windows.h>
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
	float curr_x = x1;
	float curr_y = y1;
	glBegin(GL_POINTS);
	glVertex2i(x1, y1);
	glEnd();
	while (curr_x != x2 && curr_y != y2)
	{
		float m = (y2 - curr_y) / (x2 - curr_x);
		if (m > 1)
		{
			curr_x = curr_x + (1.0 / m);
			curr_y = curr_y + 1;
		}
		else if (m > 0 && m < 1)
		{
			curr_x = curr_x + 1;
			curr_y = curr_y + m;
		}
		glBegin(GL_POINTS);
		glVertex2i(curr_x, curr_y);
		glEnd();
	}
	glFlush();
}
void myInit (void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, 100, -100);
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
