// AOJ 1039 Frisbee Dogs
// 2018.2.9 bal4u

#include <stdio.h>
#include <string.h>
#include <math.h>

#define INF 1e10
#define EPS 1e-9
#define EQ(a,b)  (fabs((a)-(b))<EPS)
typedef struct { double x, y; } PP;

PP d[11], a[11];
double v[11];
PP fp[1001], fv[1001];
int ans[11];

double norm(PP *a) { return a->x * a->x + a->y * a->y; }

double calc(int id, PP *d, double v, PP *fp, PP *fv)
{
    double _a, _b, _c, _d, s, k, k1, k2;
    PP t;
    
    t.x = fp->x - d->x, t.y = fp->y - d->y;
    _a = norm(fv) - v*v;
    _b = t.x * fv->x + t.y * fv->y;
    _c = norm(&t);
 
    if (EQ(_a, 0)) {
        if (EQ(_b,0)) return INF;
        k = -_c/(2*_b); if (k < 0) return INF;
    } else {
		_d = _b*_b - _a*_c; if (_d < 0) return INF;
	    s = sqrt(_d), k1 = (-_b+s)/_a, k2 = (-_b-s)/_a;
		if (k1 < 0 && k2 < 0) return INF;
		if (k1 < 0) k1 = INF; if (k2 < 0) k2 = INF;
		k = k1; if (k2 < k) k = k2;
	}
    a[id].x = (t.x + fv->x *k)/k;
    a[id].y = (t.y + fv->y *k)/k;
    return k;
}

int main()
{
    int n, m, i, j;
    double t[11];
    double tm;
    
    while (scanf("%d%d", &n, &m) && n) {
        for (i = 0; i < n; i++) scanf("%lf%lf%lf", &d[i].x, &d[i].y, v+i);
        for (i = 0; i < m; i++) scanf("%lf%lf%lf%lf", &fp[i].x, &fp[i].y, &fv[i].x, &fv[i].y);

        memset(ans, 0, sizeof(ans));
        for (i = 0; i < m; i++) {
            tm = INF;
            for (j = 0; j < n; j++) {
                t[j] = calc(j, &d[j], v[j], &fp[i], &fv[i]);
				if (tm > t[j]) tm = t[j];
			}
            for (j = 0; j < n; j++) if (t[j] < INF) {
                d[j].x += a[j].x * tm, d[j].y += a[j].y * tm;
				if (EQ(t[j], tm)) ans[j]++;
            }
        }
        printf("%d", ans[0]);
        for (i = 1; i < n; i++) printf(" %d", ans[i]);
        putchar('\n');
    }
    return 0;
}
