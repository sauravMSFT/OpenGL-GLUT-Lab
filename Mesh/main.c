#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#define MAXX 11
#define MAXY 11
#define DX 20
#define DY 20

float x[MAXX] = {0}, y[MAXY] = {0}, x0 = 50, y0 = 50;
int i, j;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    for (i = 0; i < MAXX - 1; ++i)
    {
        for (j = 0; j < MAXY - 1; ++j)
        {
            glBegin(GL_LINE_LOOP);
            glColor3f(0, 1, 0);
            glVertex2f(x[i], y[j]);
            glVertex2f(x[i], y[j + 1]); 
            glColor3f(0, 0, 1);
            glVertex2f(x[i + 1], y[j + 1]);
            glVertex2f(x[i + 1], y[j]);
            glEnd();
        }
    }
    glFlush();
}

int main(int argc, char **args)
{
    for (i = 0; i < MAXX; ++i)
        x[i] = x0 + i * DX;
    for (i = 0; i < MAXY; ++i)
        y[i] = y0 + i * DY;

    glutInit(&argc, args);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rectangular Mesh");
    glutDisplayFunc(display);
    glClearColor(1, 1, 1, 1);
    glColor3f(1, 0, 0);
    gluOrtho2D(0, 300, 0, 300);
    glutMainLoop();
}
