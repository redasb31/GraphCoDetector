/*
 * ID: 2497
 * Problem A: Approximate Circle
 */

#include <stdio.h>

int main(void)
{
    int n;
    double x1 = 0, y1 = 0;
    double x2 = 0, xy = 0, y2 = 0;
    double x3 = 0, x2y = 0, xy2 = 0, y3 = 0;

    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++) {
        double x, y, xd, yd;
        scanf("%lf %lf", &x, &y);
        x1 += x; y1 += y;
        xd = x * x; yd = y * y;
        x2 += xd; xy += x * y; y2 += yd;
        x3 += x * xd; x2y += xd * y; xy2 += x * yd; y3 += y * yd;
    }
    x1 /= n; y1 /= n;
    x2 /= n; xy /= n; y2 /= n;
    x3 /= n; x2y /= n; xy2 /= n; y3 /= n;

    double A = -x3 - xy2 +  x1 * (x2 + y2);
    double B = -x2y - y3 +  y1 * (x2 + y2);
    double C = xy -  x1 * y1;
    double X = x2 -  x1 * x1;
    double Y = y2 -  y1 * y1;

    double det = X * Y - C * C;
    double a = ( Y * A - C * B) / det;
    double b = (-C * A + X * B) / det;
    double c = -(x2 + y2 + a * x1 + b * y1);

    printf("%f %f %f\n", a, b, c);

    return 0;
}

