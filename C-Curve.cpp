#include<bits/stdc++.h>
#include <GL/glut.h>
#define PI 3.14159265358979323846
void DrawCCurve(float startX, float startY, float len, float angle, int n)
{
    if (n > 0)
    {
        len = len / sqrt(2);
        DrawCCurve(startX, startY, len, angle + PI / 4, n - 1);
        startX = startX + len * cos(angle + PI / 4);
        startY = startY + len * sin(angle + PI / 4);
        DrawCCurve(startX, startY, len, angle - PI / 4, n - 1);
    }
    else
    {
        glBegin(GL_LINES);
        glVertex2f(startX, startY);
        float endX = startX + len * cos(angle);
        float endY = startY + len * sin(angle);
        glVertex2f(endX, endY);
        glEnd();
    }
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);

    float startX = -0.4;
    float startY = 0.0;
    float len = 0.8;
    float angle = 0.0;

    int n = 3;

    DrawCCurve(startX, startY, len, angle, n);

    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("C Curve");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}

