#include <GL/glut.h>
#include <stdio.h>
#include "sierpinski.h"
#define O 1

void initialize();
void render(void);
int divisions;
double a[3] = {-0.5, -0.2357, 0};
double b[3] = {0, 0.4714, 0};
double c[3] = {0.5, -0.2357, 0};
double d[3] = {0, 0, 0.7071};
int main(int argc, char **argv)
{
    //Command Line Args
    if (argc - 1 >= 1)
    {
        divisions = atoi(argv[1]);
        if (divisions < 1)
        {
            printf("Invalid number of divisions. Aborting...\n");
            exit(0);
        }
    }
    else
    {
        printf("Enter the number of divisions: ");
        scanf("%d", &divisions);
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(480, 480);
    int id = glutCreateWindow("3D Sierpinksi Gasket");
    initialize();
    glutMainLoop();
    return 0;
}

void initialize()
{
    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(-O, O, -O, O);
    glClearColor(1, 1, 1, 1);
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(render);
    glutIdleFunc(render);
}
int angle = 0;
void render(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //For Rotation
    /*	
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotated(angle, 1, 1, 1);
    */
    sierpinski(a, b, c, d, divisions);
    //glPopMatrix();
    glutSwapBuffers();

    angle++;
    angle %= 360;
}
