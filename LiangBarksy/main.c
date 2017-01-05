#include <GL/glut.h>
#include <stdio.h>
#include "liangbarsky.h"

void windowInit(double *, double *);
void renderMain(void);
void renderSub(void);
void initialize(double *, double *);

double s1[2], s2[2], w1[2], w2[2], l1[2], l2[2];
int main(int argc, char **argv)
{
    printf("Enter Window Lower Left Coordinates: ");
    scanf("%lf %lf", &s1[0], &s1[1]);

    printf("Enter Window Upper Right Coordinates: ");
    scanf("%lf %lf", &s2[0], &s2[1]);

    printf("Enter ViewPort Lower Left Coordinates: ");
    scanf("%lf %lf", &w1[0], &w1[1]);

    printf("Enter ViewPort Upper Right Coordinates: ");
    scanf("%lf %lf", &w2[0], &w2[1]);

    printf("Enter Line's EndPoint 1: ");
    scanf("%lf %lf", &l1[0], &l1[1]);

    printf("Enter Line's EndPoint 2: ");
    scanf("%lf %lf", &l2[0], &l2[1]);

    //TODO: Check if ViewPort is outside the boundary of the Window

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    windowInit(s1, s2);
    glutCreateWindow("Main");
    initialize(s1, s2);
    glutDisplayFunc(renderMain);

    windowInit(s1, s2);
    glutCreateWindow("Clipped Line Segment");
    initialize(s1, s2);
    glutDisplayFunc(renderSub);

    glutMainLoop();
    return 0;
}

void windowInit(double *w1, double *w2)
{
    double x = w2[0] - w1[0], y = w2[1] - w1[1];
    if (x > y)
        glutInitWindowSize(400, 400 / x * y);
    else
        glutInitWindowSize(400 / y * x, 400);
}
void initialize(double *w1, double *w2)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(w1[0], w2[0], w1[1], w2[1]);
}
void renderMain(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1, 1, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2d(w1[0], w1[1]);
    glVertex2d(w2[0], w1[1]);
    glVertex2d(w2[0], w2[1]);
    glVertex2d(w1[0], w2[1]);
    glEnd();

    glBegin(GL_LINES);
    glVertex2dv(l1);
    glVertex2dv(l2);
    glEnd();
    glutSwapBuffers();
}

void renderSub(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1, 1, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2d(w1[0], w1[1]);
    glVertex2d(w2[0], w1[1]);
    glVertex2d(w2[0], w2[1]);
    glVertex2d(w1[0], w2[1]);
    glEnd();
    liangbarsky(w1, w2, l1, l2);
    glutSwapBuffers();
}
