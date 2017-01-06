#include <stdlib.h>
#include <GL/glut.h>
void tableleg(double legthick, double leglen)
{
    glPushMatrix();
    glTranslated(0, 0.15, 0);
    glScaled(legthick, leglen, legthick);
    glutSolidCube(1.2);
    glPopMatrix();
}
void table(double topwid, double topthick, double legthick, double leglen)
{
    double dist = 0.95 * topwid / 2 - legthick / 2;
    glPushMatrix();
    glTranslated(0, leglen, 0);
    glScaled(topwid, topthick, topwid);
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslated(dist, 0, dist);
    tableleg(legthick, leglen);
    glTranslated(0, 0, -2 * dist);
    tableleg(legthick, leglen);
    glTranslated(-2 * dist, 0, 2 * dist);
    tableleg(legthick, leglen);
    glTranslated(0, 0, -2 * dist);
    tableleg(legthick, leglen);
    glPopMatrix();
}
void display()
{
    double winht = 1.0;
    /*float lightintensity[] = {0.7, 0.7, 0.7, 1.0};
    float lightposition[] = {2.0f, 6.0f, 3.0f, 0.0f};
    float mat_ambient[] = {0.7f, 0.7f, 0.7f, 1.0f};
    float mat_diffuse[] = {0.6f, 0.6f, 0.6f, 1.0f};
    float mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};*/

    float lightintensity[] = {.7, .7 ,.7, 1};
    float lightposition[] = {2, 6, 3, 1};
    float mat_ambient[] = {1, 1, 1, 1};
    float mat_diffuse[] = {1, 1, 1, 1};
    float mat_specular[] = {1, 1, 1, 1};

    float mat_shininess[] = {50.0f};
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, lightposition);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightintensity);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-winht, winht, -winht, winht, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(2, 2, 2);
    gluLookAt(2.3, 1.3, 2, 0, -0.1, 0, 0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glTranslated(0.4, 0.38, 0.5);
    glRotated(35, 0, 1, 0);
    glutSolidTeapot(0.08);
    glPopMatrix();
    glTranslated(0.4, 0, 0.4);
    table(0.6, 0.02, 0.02, 0.3);
    glPopMatrix();
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Teapot");
    glutDisplayFunc(display);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glClearColor(.1, .1, .1, 1);
    glutMainLoop();
    return 0;
}