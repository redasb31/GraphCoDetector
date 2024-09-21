#include<stdio.h>
#include<math.h>
main()
{
        int px, py, cx, cy, r;
        double a, b, c, tx, ty, ax[2], ay[2];
        scanf("%d %d%*c%d %d %d", &px, &py, &cx, &cy, &r);
        tx = px - cx;
        ty = py - cy;
        a = pow((ty / tx), 2) + 1;
        b = pow(r, 2) * ty / pow(tx, 2);
        c = pow(pow(r, 2) / tx, 2) - pow(r, 2);
        ay[0] = (b + sqrt(pow(b, 2) - a * c)) / a;
        ay[1] = (b - sqrt(pow(b, 2) - a * c)) / a;
        ax[0] = -ty / tx * ay[0] + pow(r, 2) / tx;
        ax[1] = -ty / tx * ay[1] + pow(r, 2) / tx;
        printf("%.6f %.6f\n%.6f %.6f\n",
                   ax[0] + cx, ay[0] + cy, ax[1] + cx, ay[1] + cy);
}