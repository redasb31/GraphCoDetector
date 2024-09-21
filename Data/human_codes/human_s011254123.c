#include<stdio.h>
#include<stdlib.h>
#define INF 1e10
#define NMMAX 100

int cmp(const void *a, const void *b);
double width(int *x, int *y, int m, double a);

int main(void)
{
  int i, m, n, min1, max1, min2, max2, x1[NMMAX], y[NMMAX], x2[NMMAX], z[NMMAX], x[NMMAX*2];
  while (scanf("%d %d", &m, &n), m != 0 && n != 0) {
    double res = 0.0;
    scanf("%d %d", &x1[0], &y[0]);
    min1 = max1 = x[0] = x1[0];
    for (i = 1; i < m; i++) {
      scanf("%d %d", &x1[i], &y[i]);
      x[i] = x1[i];
      if (x1[i] < min1) min1 = x1[i];
      if (x1[i] > max1) max1 = x1[i];
    }
    scanf("%d %d", &x2[0], &z[0]);
    min2 = max2 = x[m] = x2[0];
    for (i = 1; i < n; i++) {
      scanf("%d %d", &x2[i], &z[i]);
      x[m+i] = x2[i];
      if (x2[i] < min2) min2 = x2[i];
      if (x2[i] > max2) max2 = x2[i];
    }
    qsort(x, m + n, sizeof(int), cmp);
    for (i = 0; i + 1 < m + n; i++) {
      double a = x[i], b = x[i+1], c = (a + b) / 2;
      if (c >= min1 && c <= max1 && c >= min2 && c <= max2) {
        double fa, fb, fc;
        fa = width (x1, y, m, a) * width(x2, z, n, a);
        fb = width (x1, y, m, b) * width(x2, z, n, b);
        fc = width (x1, y, m, c) * width(x2, z, n, c);
        res += (b - a) / 6 * (fa + 4 * fc + fb);
      }
    }
    printf("%.10f\n", res);
  }
}

int cmp(const void *a, const void *b)
{
  return *(int*)a - *(int*)b;
}
double width(int *x, int *y, int m, double a)
{
  int i;
  double lb = INF, ub = -INF;
  for (i = 0; i < m; i++) {
    double x1 = x[i], y1 = y[i], x2 = x[(i+1)%m], y2 = y[(i+1)%m];
    if ((x1 - a) * (x2 - a) <= 0 && x1 != x2) {
      double yc = y1 + (y2 - y1) * (a - x1) / (x2 - x1);
      if (yc < lb) lb = yc;
      if (yc > ub) ub = yc;
    }
  }
  if (ub - lb > 0) return ub - lb;
  return 0;
}
