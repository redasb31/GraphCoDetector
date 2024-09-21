// AOJ 2009: Area Separation
// 2017.10.30 bal4u@uu

#include <stdio.h>
#include <math.h>

#define EPS 1e-10

typedef struct { double x, y; } PP;
typedef struct { PP p1, p2; } SEG;
SEG sg[102]; int n;
PP pp[102]; int sz;

double dis(PP p1, PP p2)
{
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;
	return sqrt(dx*dx + dy*dy);
}

int one(PP p1, PP p2)
{
	return p1.x == p2.x && p1.y == p2.y;
}

int intersection(PP *p, PP p1, PP p2, PP p3, PP p4)
{
   int t1, t2, t3, t4;
   double bo, ua;

   t1 = (p1.y-p3.y)*(p3.x-p4.x)-(p1.x-p3.x)*(p3.y-p4.y);
   t2 = (p2.y-p3.y)*(p3.x-p4.x)-(p2.x-p3.x)*(p3.y-p4.y);
   t3 = (p3.y-p1.y)*(p1.x-p2.x)-(p3.x-p1.x)*(p1.y-p2.y);
   t4 = (p4.y-p1.y)*(p1.x-p2.x)-(p4.x-p1.x)*(p1.y-p2.y);
   if ((t1 < 0 && t2 > 0 || t1 > 0 && t2 < 0) && (t3 < 0 && t4 > 0 || t3 > 0 && t4 < 0)) {
      bo = (p4.y-p3.y)*(p2.x-p1.x)-(p4.x-p3.x)*(p2.y-p1.y);
      ua = (p4.x-p3.x)*(p1.y-p3.y)-(p4.y-p3.y)*(p1.x-p3.x);
      p->x = p1.x + ua/bo * (p2.x-p1.x);
      p->y = p1.y + ua/bo * (p2.y-p1.y);
      return 1;
   } else return 0;
}

int main()
{
	int i, j, k, f, ans;
	PP p;

	while(scanf("%d", &n) && n > 0) {
		for (i = 0; i < n; i++)
			scanf("%lf%lf%lf%lf", &sg[i].p1.x, &sg[i].p1.y, &sg[i].p2.x, &sg[i].p2.y);
		ans = 1;
		for (i = 0; i < n; i++) {
			sz = 0;
			for (j = 0; j < i; j++) {
				if (!intersection(&p, sg[i].p1, sg[i].p2, sg[j].p1, sg[j].p2)) continue;
				if (one(p, sg[i].p1) || one(p, sg[i].p2) || one(p, sg[j].p1) || one(p, sg[j].p2)) continue;
				
				for (f = 1, k = 0; k < sz; k++) {
					if (dis(p, pp[k]) < EPS) { f = 0; break; }
				}
				if (f) pp[sz++] = p;
			}
			ans += sz + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}