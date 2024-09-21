#include <stdio.h>
#include <math.h>

int main(void)
{
    double x1, y1, x2, y2, xq, yq;

    while (~scanf("%lf,%lf,%lf,%lf,%lf,%lf", &x1, &y1, &x2, &y2, &xq, &yq)){
        double dx1 = x2 - x1, dy1 = y2 - y1;
        double dx2 = xq - x2, dy2 = yq - y2;
        double dx3 = x1 - xq, dy3 = y1 - yq;
        double a1, b1, a2, b2;
        double x, y;

        if (dx1 == 0){
            printf("%.10f %.10f\n", x1 + dx3, yq);
            continue;
        }
        if (dy1 == 0){
            printf("%.10f %.10f\n", xq, y1 + dy3);
            continue;
        }

        a1 = dy1 / dx1;
        b1 = y1 - x1 * a1;
        a2 = -(1 / a1);
        b2 = yq - xq * a2;
        x = (b2 - b1) / (a1 - a2);
        y = a1 * x + b1;
        printf("%.10f %.10f\n", x + x - xq, y + y - yq);
    }

    return 0;
}