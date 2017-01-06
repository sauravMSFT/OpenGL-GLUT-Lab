#ifndef CUBE_SAHU_H
#define CUBE_SAHU_H

#include <GL/glut.h>

typedef float Point[3];
typedef float Color[3];
typedef int Face[4];

Point vertices[8] = {
    {-1, -1, 1},
    {-1, 1, 1},
    {1, 1, 1},
    {1, -1, 1},
    {-1, -1, -1},
    {-1, 1, -1},
    {1, 1, -1},
    {1, -1, -1}};

Color colors[6] = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
    {1, 1, 0},
    {0, 1, 1},
    {1, 0, 1}};

Face faces[6] = {
    {0, 3, 2, 1},
    {2, 3, 7, 6},
    {4, 5, 6, 7},
    {0, 1, 5, 4},
    {1, 2, 6, 5},
    {0, 4, 7, 3}};

void drawFace(Face face)
{
    int i = 0;
    for (i = 0; i < 4; ++i)
    {
        float *p = vertices[face[i]];
        glVertex3f(p[0], p[1], p[2]);
    }
}

void drawCube()
{
    int i = 0;
    glBegin(GL_QUADS);
    for (; i < 6; ++i)
    {
        glColor3fv(colors[i]);
        drawFace(faces[i]);
    }
    glEnd();
}
#endif