#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <GL/glut.h>
#include <stdio.h>

void reshape(int, int);
void keyboard(unsigned char, int, int);
void rotation();
void mouse(int, int, int, int);

typedef enum __Boolean__ {
    false,
    true
} bool;

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double W = w, H = h;

    int o = 2;
    if (w > h)
        glOrtho(-o * W / H, o * W / H, -o, o, -10, 10);
    else
        glOrtho(-o, o, -o * H / W, o * H / W, -10, 10);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

bool isRotate = true;
float rd[] = {0, 0, 1};
void rotation()
{
    glMatrixMode(GL_MODELVIEW);
    if (isRotate == true)
        glRotatef(0.5, rd[0], rd[1], rd[2]);
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if (state == GLUT_UP)
    {
        rd[0] = rd[1] = rd[2] = 0;
        switch (button)
        {
        case GLUT_LEFT_BUTTON:
            rd[0] = 1;
            break;
        case GLUT_MIDDLE_BUTTON:
            rd[2] = 1;
            break;
        case GLUT_RIGHT_BUTTON:
            rd[1] = 1;
            break;
        }
    }
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'r')
        isRotate = (isRotate == false) ? true : false;
    glutPostRedisplay();
}

#endif