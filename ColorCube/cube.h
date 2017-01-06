#ifndef CUBE_SPIN_H
#define CUBE_SPIN_H

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
    for (int i = 0; i < 4; ++i)
        glVertex3fv(vertices[face[i]]);
}

void drawCube()
{
    glBegin(GL_QUADS);
    for (int i = 0; i < 6; ++i)
    {
        glColor3fv(colors[i]);
        drawFace(faces[i]);
    }
    glEnd();
}
#endif