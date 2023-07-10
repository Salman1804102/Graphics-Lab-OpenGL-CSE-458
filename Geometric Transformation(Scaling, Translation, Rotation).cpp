#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include<windows.h>
#include <GL/glut.h>
using namespace std;

int x, y, option = 0, edges;
vector<int> x_cordinates;
vector<int> y_cordinates ;
int transX, transY;
double scaleX, scaleY;
double angle, angleRad;

double round(double d)
{
	return floor(d + 0.5);
}

void drawPolygon()
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(x_cordinates[i], y_cordinates[i]);
	}
	glEnd();
}
void drawPolygonTrans(int x, int y)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(x_cordinates[i] + x, y_cordinates[i] + y);
	}
	glEnd();
}

void drawPolygonScale(double x, double y)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2f(x_cordinates[i] * x,  y_cordinates[i] * y);
	}
	glEnd();
}

void drawPolygonRotation(double angleRad)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(round((x_cordinates[i] * cos(angleRad)) - (y_cordinates[i] * sin(angleRad))), round((x_cordinates[i] * sin(angleRad)) + (y_cordinates[i] * cos(angleRad))));
	}
	glEnd();
}
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	if (option == 1)
	{
		drawPolygon();
		drawPolygonTrans(transX, transY);
	}
	else if (option == 2)
	{
		drawPolygon();
		drawPolygonScale(scaleX, scaleY);
	}
	else if (option == 3)
	{
		drawPolygon();
		drawPolygonRotation(angleRad);
	}
	glFlush();
}
int main(int argc, char** argv)
{
	cout << "Click on what you want to do:\n\n" << endl;

	cout << "1. Translation" << endl;
	cout << "2. Scaling" << endl;
	cout << "3. Rotation" << endl;
	cout << "4. Exit" << endl;

	cin >> option;

	if (option == 4)
 {
		return 0;
	}

	cout << "\n\nEnter no of edges for Polygon:\n" << endl;

	cin >> edges;

	for (int i = 0; i < edges; i++)
	{
		cout << "Enter co-ordinates for vertex  " << i + 1 << " : "; cin >> x >> y;
		x_cordinates.push_back(x);
		y_cordinates.push_back(y);
	}

	if (option == 1)
	{
		cout << "Enter the translation factor for X and Y: "; cin >> transX >> transY;
	}
	else if (option == 2)
	{
		cout << "Enter the scaling factor for X and Y: "; cin >> scaleX >> scaleY;
	}
	else if (option == 3)
	{
		cout << "Enter the angle for rotation: "; cin >> angle;
		angleRad = angle * 3.1416 / 180;
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(200,  300);
	glutCreateWindow("Geometric Transformation Transformations");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}
