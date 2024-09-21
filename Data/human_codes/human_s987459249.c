// AOJ 2586 Wish upon a shooting star
// 2018.3.31 bal4u
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
#define EPS 1e-9
int dcmp(double x) { if (fabs(x) < EPS) return 0; return x <= 0 ? -1 : 1; }
#define EQ(a,b)     (fabs((a)-(b))<EPS)
 
typedef struct { double x, y, z, vx, vy, vz, r, vr; } T;
T t[202];
typedef struct { int id1, id2; double t; } E;
E e[30000]; int sz;
double tm[202]; char f[202];
 
int quadratic(double *x, double a, double b, double c)
{
    int t;
    double d;
 
    if (EQ(a, 0)) return 0; 
    d = b*b - 4*a*c, t = dcmp(d), a *= 2;
    if (t < 0) return 0;
	if (t == 0) { x[0] = -b/a; return 1; }
	d = sqrt(d), x[0] = (-b+d)/a, x[1] = (-b-d)/a;
	return 2;
}
 
int cmp(E *a, E *b) { return dcmp(a->t - b->t); }
 
int main()
{
    int n, i, j, k;
    double x[2], a, b, c;       // ax^2 + bx + c = 0
	double dx, dy, dz, dr, vx, vy, vz, vr;

    while (scanf("%d", &n) && n) {
        sz = 0;
        for (i = 0; i < n; i++) {
			scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &t[i].x, &t[i].y, &t[i].z,
				  &t[i].vx, &t[i].vy, &t[i].vz, &t[i].r, &t[i].vr);
            e[sz].id1 = e[sz].id2 = i, e[sz++].t = t[i].r/t[i].vr;
        }
 
        for (i = 0; i < n; i++) for (j = i+1; j < n; j++) {
			vx = t[i].vx-t[j].vx, vy = t[i].vy-t[j].vy;
			vz = t[i].vz-t[j].vz, vr = t[i].vr+t[j].vr;
            a = vx*vx + vy*vy + vz*vz - vr*vr;
			
			dx = t[i].x-t[j].x, dy = t[i].y-t[j].y;
			dz = t[i].z-t[j].z, dr = t[i].r+t[j].r;
            c = dx*dx + dy*dy + dz*dz - dr*dr;

			b = dx*vx + dy*vy + dz*vz + dr*vr, b *= 2;

            k = quadratic(x, a, b, c);
            while (k--) if (dcmp(x[k]) > 0) {
                e[sz].id1 = i, e[sz].id2 = j, e[sz++].t = x[k];
            }
        }
        qsort(e, sz, sizeof(E), cmp);
        memset(f, 0, sizeof(f));
        for (i = 0; i < sz; i++) {
            j = e[i].id1, k = e[i].id2;
            if (!f[j] && !f[k]) {
                f[j] = f[k] = 1;
                tm[j] = tm[k] = e[i].t;
            }
        }
        for (i = 0; i < n; i++) printf("%.10lf\n", tm[i]);
    }
    return 0;
}
