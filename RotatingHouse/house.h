#ifndef HOUSE_H
#define HOUSE_H

#include <GL/glut.h>
double val[3];
double *rgb(double r, double g, double b)
{
    val[0] = r / 255;
    val[1] = g / 255;
    val[2] = b / 255;
    return val;
}
void house()
{
    glBegin(GL_POLYGON);
    glColor3dv(rgb(255, 255, 255));
    glVertex2d(-2.9, -2.9);
    glVertex2d(-2.9, -7);
    glVertex2d(2.9, -7);
    glVertex2d(2.9, -2.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3dv(rgb(236, 83, 75));
    glVertex2d(-3, -3);
    glVertex2d(0, 0);
    glVertex2d(3, -3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3dv(rgb(56, 0, 40));
    glVertex2d(-0.75, -7);
    glVertex2d(-0.75, -4);
    glVertex2d(0.75, -4);
    glVertex2d(0.75, -7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3dv(rgb(91, 243, 54));
    glVertex2d(-100, -7);
    glVertex2d(-100, -100);
    glVertex2d(100, -100);
    glVertex2d(100, -7);
    glEnd();
}

#endif