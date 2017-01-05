#ifndef __SIERPINSKI__
#define __SIERPINSKI__

#include <GL/glut.h>

void sierpinski(double *, double *, double *, double *, int);
void __sierpinski__(double *, double *, double *, double *, int);
void tetrahedron(double *, double *, double *, double *);
void triangle(double *, double *, double *);
double *midpoint(double *, double *, double *);

void sierpinski(double *a, double *b, double *c, double *d, int divisions)
{
    glBegin(GL_TRIANGLES);
    __sierpinski__(a, b, c, d, divisions);
    glEnd();
}

void __sierpinski__(double *a, double *b, double *c, double *d, int divisions)
{
    if (divisions == 1)
        tetrahedron(a, b, c, d);
    else
    {
        double ab[3], bc[3], ca[3], ad[3], bd[3], cd[3];

        midpoint(a, b, ab);
        midpoint(b, c, bc);
        midpoint(c, a, ca);
        midpoint(a, d, ad);
        midpoint(b, d, bd);
        midpoint(c, d, cd);

        __sierpinski__(a, ab, ca, ad, divisions - 1);
        __sierpinski__(ab, b, bc, bd, divisions - 1);
        __sierpinski__(ca, bc, c, cd, divisions - 1);
        __sierpinski__(ad, bd, cd, d, divisions - 1);
    }
}

double *midpoint(double *a, double *b, double *mid)
{
    //unsafe, can throw segmentation error
    for (int i = 0; i < 3; ++i)
    {
        mid[i] = (a[i] + b[i]) / 2;
    }
}

void tetrahedron(double *a, double *b, double *c, double *d)
{
    glColor3d(0, 0, 1);
    triangle(a, b, c);
    glColor3d(1, 0, 0);
    triangle(a, d, b);
    glColor3d(1, 0.5, 0);
    triangle(b, d, c);
    glColor3d(0, 0, 0);
    triangle(a, c, d);
}

void triangle(double *a, double *b, double *c)
{
    glVertex3dv(a);
    glVertex3dv(b);
    glVertex3dv(c);
}

#endif
