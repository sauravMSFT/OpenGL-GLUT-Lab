#ifndef __LIANGBARSKY__
#define __LIANGBARSKY__

void liangbarsky(double *, double *, double *, double *);

double max(double x, double y)
{
    return (x > y) ? x : y;
}
double min(double x, double y)
{
    return (x < y) ? x : y;
}
void drawLine(double x1, double y1, double x2, double y2)
{
    glBegin(GL_LINES);
    glVertex2d(x1, y1);
    glVertex2d(x2, y2);
    glEnd();
}
void liangbarsky(double *W1, double *W2, double *l1, double *l2)
{
    double delX = l2[0] - l1[0], delY = l2[1] - l1[1];
    double p[4] = {
        -delX,
        delX,
        -delY,
        delY};
    double q[4] = {
        -W1[0] + l1[0],
        W2[0] - l1[0],
        -W1[1] + l1[1],
        W2[1] - l1[1]};
    double t1 = 0, t2 = 1;
    for (int i = 0; i < 4; ++i)
    {
        if (p[i] == 0)
        {
            if (q[i] < 0)
                return;
        }
        else if (p[i] < 0)
            t1 = max(t1, (double)q[i] / p[i]);
        else
            t2 = min(t2, (double)q[i] / p[i]);
    }
    if (t1 <= t2)
    {
        double x1 = l1[0] + t1 * delX, y1 = l1[1] + t1 * delY;
        double x2 = l1[0] + t2 * delX, y2 = l1[1] + t2 * delY;
        drawLine(x1, y1, x2, y2);
    }
}

#endif