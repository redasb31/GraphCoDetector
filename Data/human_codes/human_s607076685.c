// AOJ 2592: Flowers
// 2017.11.30 bal4u@uu

#include <stdio.h>

int vw[100002], pf[100002], vf[100002], th[100002];
int n, pw;

double calc(double x)
{
	int i;
	double t, ans = pw * x;
	
	for (i = 0; i < n; i++) {
		t = th[i] - x * vw[i];
		if (t > 0) ans += t / (double)vf[i] * pf[i];
	}
	return ans;
}

int main()
{
	int i;
	double l, r, lm, rm, x, y, t, ans;

	while (scanf("%d", &n) && n > 0) {
		scanf("%d", &pw);
		for (i = 0; i < n; i++) scanf("%d%d%d%d", vw+i, pf+i, vf+i, th+i);

		l = 0, r = 1000;
		ans = 1e10;
		for (i = 0; i < 200; i++) {
			lm = (l * 2 + r) / 3;
			rm = (l + r * 2) / 3;
			x = calc(lm);
			y = calc(rm);
			if (x < y) r = rm;
			else       l = lm;
			t = x; if (y < t) t = y;
			if (ans > t) ans = t;
		}
		printf("%.8lf\n", ans);
	}
	return 0;
}