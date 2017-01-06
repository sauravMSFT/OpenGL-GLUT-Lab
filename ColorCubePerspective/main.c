#include <stdio.h>
#include <GL/glut.h>
#include "cube.h"
#include "callbacks.h"

void render();

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Perspective Viewing");

    glutDisplayFunc(render);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutIdleFunc(rotation);

    glClearColor(1, 1, 1, 1);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}

void render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(viewer[0], viewer[1], viewer[2],
              0, 0, 0,
              0, 1, 0);
    //rotation();
    drawCube();
    glutSwapBuffers();
}
