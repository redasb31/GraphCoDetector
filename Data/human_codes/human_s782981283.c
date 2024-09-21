#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Point {
  double x;
  double y;
};
struct Line {
  struct Point s;
  struct Point e;
};
double convex_cut(int size, struct Point *p);
int main(void){
  int i, n, q;
  struct Point *p;
  scanf("%d", &n);
  p = (struct Point*)malloc(sizeof(struct Point) * (n + 1));
  for (i = 0; i < n; i++) scanf("%lf %lf", &p[i].x, &p[i].y);
  p[i].x = p[0].x;
  p[i].y = p[0].y;
  scanf("%d", &q);
  for (i = 0; i < q; i++) printf("%.6f\n", convex_cut(n, p));
  free(p);
}
double convex_cut(int size, struct Point *p)
{
  int i, num;
  double area;
  struct Point pr, lr, *pc;
  struct Line l;
  pc = (struct Point*)malloc(sizeof(struct Point) * (size + 1));
  scanf("%lf %lf %lf %lf", &l.s.x, &l.s.y, &l.e.x, &l.e.y);
  lr.x = l.e.x - l.s.x;
  lr.y = l.e.y - l.s.y;
  for (num = i = 0; i < size; i++) {
    double d1, d2;
    pr.x = p[i].x - l.s.x;
    pr.y = p[i].y - l.s.y;
    d1 = lr.x * pr.y - lr.y * pr.x;
    pr.x = p[i+1].x - l.s.x;
    pr.y = p[i+1].y - l.s.y;
    d2 = lr.x * pr.y - lr.y * pr.x;
    if (d1 >= 0) pc[num++] = p[i];
    if (d1 * d2 < 0) {
      struct Point base, hypo;
      double dt1, dt2, t;
      base.x = p[i+1].x - p[i].x;
      base.y = p[i+1].y - p[i].y;
      hypo.x = l.s.x - p[i].x;
      hypo.y = l.s.y - p[i].y;
      dt1 = fabs(base.x * hypo.y - base.y * hypo.x);
      hypo.x = l.e.x - p[i].x;
      hypo.y = l.e.y - p[i].y;
      dt2 = fabs(base.x * hypo.y - base.y * hypo.x);
      t = dt1 / (dt1 + dt2);
      hypo.x = l.s.x + t * lr.x;
      hypo.y = l.s.y + t * lr.y;
      pc[num++] = hypo;
      printf("p[i].x: %f, p[i].y: %f, cp.x: %f, cp.y:%f\n", p[i].x, p[i].y, hypo.x, hypo.y);
    }
  }
  pc[num] = pc[0];
  for (area = i = 0; i < num; i++) area += pc[i].x * pc[i+1].y - pc[i].y * pc[i+1].x;
  free(pc);
  return fabs(area) / 2;
}
