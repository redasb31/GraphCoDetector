#include<stdio.h>
#include<math.h>

typedef struct{
  double x;
  double y;
} point;

void koch(int d, point p1, point p2){
  if(d == 0)
    return;
  point s, t, u;
  s.x = (p1.x * 2 + p2.x)/3;
  s.y = (p1.y * 2 + p2.y)/3;
  t.x = (p1.x + p2.x * 2)/3;
  t.y = (p1.y + p2.y * 2)/3;
  u.x = (p1.x + p2.y)/2 + (p1.y - p2.y)/(2 * sqrt(3));
  u.y = (-p1.x + p2.x)/(2 * sqrt(3)) + (p1.y + p2.y)/2;
  koch(d-1, p1, s);
  printf("%f %f\n", s.x, s.y);
  koch(d-1, s, u);
  printf("%f %f\n", u.x, u.y);
  koch(d-1, u, t);
  printf("%f %f\n", t.x, t.y);
  koch(d-1, t, p2);
}

int main(void){
  point p1, p2;
  p1.x = 0;
  p1.y = 0;
  p2.x = 100;
  p2.y = 0;
  printf("%f %f\n", p1.x, p1.y);
  koch(p1, p2);
  printf("%f %f\n", p2.x, p2.y);
  return 0;
}