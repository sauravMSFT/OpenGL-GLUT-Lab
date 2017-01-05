#ifndef __COHENSUTHERLAND__
#define __COHENSUTHERLAND__

void __cohensutherland__(double *, double *, double *, double *);
void cohensutherland(double *, double *, double *, double *);
int areacode(double *, double *, double *);
void drawLine(double *, double *);

#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

void cohensutherland(double *w1, double *w2, double *l1, double *l2)
{
    double p1[2], p2[2];
    for (int i = 0; i < 2; ++i)
    {
        p1[i] = l1[i];
        p2[i] = l2[i];
    }
    __cohensutherland__(w1, w2, p1, p2);
}

void __cohensutherland__(double *w1, double *w2, double *l1, double *l2)
{
    int c1, c2;
    double *modPoint;
    c1 = areacode(w1, w2, l1), c2 = areacode(w1, w2, l2);
    do
    {
        if ((c1 & c2) != 0)
            return;
        else
        {
            double slope = (l2[1] - l1[1]) / (l2[0] - l1[0]);
            modPoint = (c1 == 0) ? l2 : l1;
            if (modPoint[0] < w1[0])
            {
                modPoint[0] = w1[0];
                modPoint[1] = l1[1] + modPoint[0] * slope;
            }
            else if (modPoint[0] > w2[0])
            {
                modPoint[0] = w2[0];
                modPoint[1] = l1[1] + modPoint[0] * slope;
            }
            if (modPoint[1] < w1[1])
            {
                modPoint[1] = w1[1];
                modPoint[0] = l1[0] + (modPoint[1] - l1[1]) / slope;
            }
            else if (modPoint[1] > w2[1])
            {
                modPoint[1] = w2[1];
                modPoint[0] = l1[0] + (modPoint[1] - l1[1]) / slope;
            }
        }
        c1 = areacode(w1, w2, l1), c2 = areacode(w1, w2, l2);
    } while ((c1 != 0) || (c2 != 0));
    drawLine(l1, l2);
}

int areacode(double *w1, double *w2, double *p)
{
    int code = 0x0000;
    if (p[0] < w1[0])
    {
        code |= LEFT;
    }
    if (p[0] > w2[0])
    {
        code |= RIGHT;
    }
    if (p[1] < w1[1])
    {
        code |= BOTTOM;
    }
    if (p[1] > w2[1])
    {
        code |= TOP;
    }
    return code;
}
void drawLine(double *p1, double *p2)
{
    glBegin(GL_LINES);
    glVertex2dv(p1);
    glVertex2dv(p2);
    glEnd();
}
#endif