#include <GL/glut.h>

void DrawGasket(float x1, float y1, float x2, float y2, float x3, float y3, int n)
{
    if(n > 0)
    {
        float x12 = (x1 + x2) / 2;
        float y12 = (y1 + y2) / 2;
        float x23 = (x2 + x3) / 2;
        float y23 = (y2 + y3) / 2;
        float x13 = (x3 + x1) / 2;
        float y13 = (y3 + y1) / 2;

        DrawGasket(x1, y1, x12, y12, x13, y13, n - 1);
        DrawGasket(x2, y2, x12, y12, x23, y23, n - 1);
        DrawGasket(x3, y3, x23, y23, x13, y13, n - 1);
    }
    else
    {
        glBegin(GL_TRIANGLES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glEnd();
    }
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.5, 1.0);

    float x1 = -1.0;
    float y1 = -0.4;
    float x2 = 0.0;
    float y2 = 0.4;
    float x3 = 1.0;
    float y3 = -0.4;

    int n = 2;

    DrawGasket(x1, y1, x2, y2, x3, y3, n);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Gasket");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}
