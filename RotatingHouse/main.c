#include <stdio.h>
#include <GL/glut.h>
#include "house.h"

void render();

double x, y;
int angle = 0;
int main(int argc, char **argv)
{
    if (argc >= 3)
    {
        x = atof(argv[1]);
        y = atof(argv[2]);
    }
    else
    {
        printf("Enter the rotation coordinates: ");
        scanf("%lf %lf", &x, &y);
    }
    // printf("Rotation coordinates: ");
    // printf("x = %lf, y = %lf", x, y);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutCreateWindow("House");
    glutDisplayFunc(render);
    int o = 10;
    glClearColor(2.0 / 255, 113.0 / 255, 188.0 / 255, 1);
    gluOrtho2D(-o, o, -o, o);

    glutMainLoop();
    return 0;
}
void render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslatef(x, y, 0);
    glRotatef(angle, 0, 0, 1);
    glTranslatef(-x, -y, 0);

    house();
    glPopMatrix();
    angle += 1; angle %= 360;
    glutPostRedisplay();
    glutSwapBuffers();
}
