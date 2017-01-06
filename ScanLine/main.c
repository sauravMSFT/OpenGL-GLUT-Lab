#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

void initialize();
void display(void);
void scanline(float, float, float, float, float, float, float, float);
float x1, x2, x3, x4, y1, y2, y3, y4;

int main(int argc, char **argv)
{
    printf("\nEnter 4 points (x, y) coordinates: ");
    scanf("%f %f %f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(640, 640);
    glutCreateWindow("Scan Line Fill Algorithm");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 640);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

void display(void)
{
    glClearColor(1, 1, 1, 1);

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3d(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glVertex2d(x1, y1);
    glVertex2d(x2, y2);
    glVertex2d(x3, y3);
    glVertex2d(x4, y4);
    glEnd();

    scanline(x1, y1, x2, y2, x3, y3, x4, y4);

    glutSwapBuffers();
}

void edgeDetect(float x1, float y1, float x2, float y2, int *le, int *re)
{
    float tmp;
    if (y2 < y1)
    {
        tmp = y2;
        y2 = y1;
        y1 = tmp;
        tmp = x2;
        x2 = x1;
        x1 = tmp;
    }

    float mx, x;
    if (y2 != y1)
        mx = (x2 - x1) / (y2 - y1);
    else
        mx = (x2 - x1);
    x = x1;

    for (int i = y1; i < y2; ++i)
    {
        if (x < (float)le[i])
            le[i] = x;
        if (x > (float)re[i])
            re[i] = x;
        x += mx;
    }
}

void drawPixel(float x, float y, double *c)
{
    glColor3dv(c);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void scanline(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    int le[640], re[640];
    for (int i = 0; i < 640; ++i)
    {
        le[i] = 640;
        re[i] = 0;
    }

    edgeDetect(x1, y1, x2, y2, le, re);
    edgeDetect(x2, y2, x3, y3, le, re);
    edgeDetect(x3, y3, x4, y4, le, re);
    edgeDetect(x4, y4, x1, y1, le, re);

    double color[3] = {0, 0, 1};

    for (int i = 0; i < 640; ++i)
    {
        color[0] = (double)(rand() % 255) / 255;
        color[1] = (double)(rand() % 255) / 255;
        color[2] = (double)(rand() % 255) / 255;
        if (le[i] <= re[i])
            for (int j = le[i]; j < re[i]; ++j)
                drawPixel(j, i, color);
    }
}