#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979

typedef struct {
    double x;
    double y;
    double theta;
} xystruct;

int comp(const void* a, const void* b)
{
    return ((xystruct*)a)->theta - ((xystruct*)b)->theta;
}

int main()
{
    int n;
    int i,j,jj;
    xystruct xy[100];
    double dist,maxd;
    double X;
    double Y;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%lf%lf", &xy[i].x, &xy[i].y);
        if(xy[i].x*xy[i].x+xy[i].y*xy[i].y<0.0000000001){
          xy[i].theta=0;
        }else{
          xy[i].theta=atan2(xy[i].y, xy[i].x);
        }
    }
    qsort(xy, n, sizeof(xystruct), comp);
  
    maxd = 0;
    for (i = 0; i<n; i++) {
        X = xy[i].x;
        Y = xy[i].y;
        maxd = X * X + Y * Y;
        for (jj = i+1; jj < i+n; jj++) {
            j=jj%n;
            X += xy[j].x;
            Y += xy[j].y;
            dist = X * X + Y * Y;
            if (dist > maxd) maxd = dist;
        }
    }
    printf("%.10f\n", sqrt(maxd));
    return 0;
}
