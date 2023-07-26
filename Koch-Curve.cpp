#include <GL/glut.h>
#include<bits/stdc++.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
void DrawKochCurve(float startX, float startY, float len, float angle, int n)
{
    if (n > 0)
    {
        len = len / 3.0;
        DrawKochCurve(startX, startY, len, angle, n - 1);
        startX += len * cos(angle);
        startY += len * sin(angle);
        DrawKochCurve(startX, startY, len, angle - M_PI / 3.0, n - 1);
        startX += len * cos(angle - M_PI / 3.0);
        startY += len * sin(angle - M_PI / 3.0);
        DrawKochCurve(startX, startY, len, angle + M_PI / 3.0, n - 1);
        startX += len * cos(angle + M_PI / 3.0);
        startY += len * sin(angle + M_PI / 3.0);
        DrawKochCurve(startX, startY, len, angle, n - 1);
    }
    else
    {
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 0.0);
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
    glColor3f(1.0, 1.0, 0.0);

    float startX = -0.5;
    float startY = -0.3;
    float len = 1.0;
    float angle = 0.0;

    int n = 3;

    DrawKochCurve(startX, startY, len, angle, n);

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Koch Curve");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}
