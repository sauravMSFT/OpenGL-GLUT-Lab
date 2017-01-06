#include <stdio.h>
#include <GL/glut.h>
#include "cube.h"
#include "callbacks.h"

void render();

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Color Cube");

    glutDisplayFunc(render);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glClearColor(1, 1, 1, 1);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}

void render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    rotation();
    drawCube();
    glutSwapBuffers();
}