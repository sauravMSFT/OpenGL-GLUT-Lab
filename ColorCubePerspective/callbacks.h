#ifndef CALLBACKS_SS_H
#define CALLBACKS_SS_H

#include <GL/glut.h>
#include <stdio.h>

void reshape(int, int);
void keyboard(unsigned char, int, int);
void lookAt();
void rotation();
void mouse(int, int, int, int);

typedef enum __Boolean__ {
    false,
    true
} bool;

double viewer[] = {0, 0, 8};
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double W = w, H = h;

    gluPerspective(30, W / H, 4, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(viewer[0], viewer[1], viewer[2],
              0, 0, 0,
              0, 1, 0);
    glutPostRedisplay();
}

int angle = 0;
bool isRotate = true;
float rd[] = {0, 0, 1};

void rotation()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    if (isRotate == true)
    {
        glRotatef(angle, rd[0], rd[1], rd[2]);
        angle += 1;
        angle %= 360;
    }
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
    switch (key)
    {
    case 'r':
        isRotate = (isRotate == false) ? true : false;
        break;
    case 'x':
        viewer[0] += 0.25;
        break;
    case 'X':
        viewer[0] -= 0.25;
        break;
    case 'y':
        viewer[1] += 0.25;
        break;
    case 'Y':
        viewer[1] -= 0.25;
        break;
    case 'z':
        viewer[2] += 0.25;
        break;
    case 'Z':
        viewer[2] -= 0.25;
        break;

    default:
        break;
    }
    glutPostRedisplay();
}

#endif