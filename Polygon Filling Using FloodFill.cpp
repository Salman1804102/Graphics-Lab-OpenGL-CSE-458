#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
using namespace std;

float fillColor[3] = {1.0, 0.0, 0.0};
float OldColor[3] = {0.0, 1.0, 0.0};
int xi, yi;
int z1 = 800, z2 = 800;

void polygon(int x1, int y1, int x2, int y2)
{
    glColor3fv(fillColor);
    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x1, y2);
    glVertex2i(x2, y1);
    glVertex2i(x2, y2);
    glVertex2i(x1, y1);
    glVertex2i(x2, y1);
    glVertex2i(x1, y2);
    glVertex2i(x2, y2);
    glEnd();
    glFlush();
}

void display()
{
    glClearColor(0.0, 1.0, 0.0, 0.1);
    glClear(GL_COLOR_BUFFER_BIT);
    polygon(100, 250, 200, 350);
    glFlush();
}

void pp(int x, int y, float f[3])
{
    glBegin(GL_POINTS);
    glColor3fv(f);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}


void gp(int x, int y, float pixels[3])
{
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, pixels);
}

void floodfill(int x, int y, float fillColor[3], float OldColor[3])
{
    float interiorColor[3];
    gp(x, y, interiorColor);
    if((interiorColor[0] == OldColor[0]) && (interiorColor[1] == OldColor[1]) && (interiorColor[2] == OldColor[2]))
    {
        pp(x, y, fillColor);
        floodfill(x+1, y, fillColor, OldColor);
        floodfill(x-1, y, fillColor, OldColor);
        floodfill(x, y+1, fillColor, OldColor);
        floodfill(x, y-1, fillColor, OldColor);
    }
}
void mouse(int btn, int state, int x, int y)
{
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        xi = x;
        yi= z2 - y;
        floodfill(xi, yi, fillColor, OldColor);
    }
}
void myinit()
{
    glViewport(0,0,z1,z2);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,(GLdouble)z1,0.0,(GLdouble)z2);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(z1,z2);
    glutCreateWindow("Boundary Fill");
    glutDisplayFunc(display);
    myinit();
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
