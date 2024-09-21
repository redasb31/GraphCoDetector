// AOJ 1190: Anchored Balloon
// 2017.12.8 bal4u@uu

#include <stdio.h>
#include <math.h>

#define N 150
int n;
int x[10], y[10], l[10];

double sach(double xx, double yy)
{
	int i;
    double t, ans = 1e10;

    for (i = 0; i < n; i++) {
        t = l[i]*l[i] - (xx-x[i])*(xx-x[i]) - (yy-y[i])*(yy-y[i]);
        if (t < ans) ans = t;
    }
    return ans;
}

double ysach(double xx)
{
	int i;
    double l = -100.0, r = 100.0, m1, m2;

    i = N; while(i--) {
        m1 = (2*l + r) / 3;
        m2 = (l + 2*r) / 3;
        if (sach(xx, m1) > sach(xx, m2)) r = m2; else l = m1;
    }
    return sach(xx, l);
}

double xysach()
{
	int i;
    double l = -100.0, r = 100.0, m1, m2;

    i = N; while (i--) {
        m1 = (2*l + r) / 3;
        m2 = (l + 2*r) / 3;
        if (ysach(m1) > ysach(m2)) r = m2; else l = m1;
    }
    return sqrt(ysach(l));
}

int main()
{
	int i;

    while (scanf("%d", &n) && n > 0) {
		for (i = 0; i < n; i++) scanf("%d%d%d", x+i, y+i, l+i);
        printf("%.07f\n", xysach());
    }
}