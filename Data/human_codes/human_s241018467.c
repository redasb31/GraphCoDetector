// AOJ 2549 7 Age
// 2018.2.5 bal4u

#include <stdio.h>

#define QMAX 250000
typedef struct { int s, t; } Q;
Q que[QMAX+2]; int top, end;

int lo[501], up[501];
int w[501][501];
int p[501];

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

#define MAX(a,b)	((a)>=(b)?(a):(b))

int main()
{
	int n, s, i, j, k, t, dt, ans;

	n = in(), s = in()-1;
	for (i = 0; i < n; i++) lo[i] = in(), up[i] = in();
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) w[i][j] = in();

	for (k = 0; k < n; k++) for (i = 0; i < n; i++) for (j = 0; j < n; j++)
		if ((t = w[i][k] + w[k][j]) < w[i][j]) w[i][j] = t;

	top = end = 0;
	for (i = 0; i < n; i++) if (up[i] > w[s][i]) {
		p[i] = up[i]-MAX(w[s][i], lo[i]);
		que[end].s = i, que[end++].t = up[i];
	}

	while (top != end) {
		k = que[top].s, t = que[top++].t;
		for (i = 0; i < n; i++) if (up[i] > t+w[k][i]) {
			dt = up[i] - MAX(t+w[k][i], lo[i]);
			if (p[i] < p[k] + dt) {
				p[i] = p[k] + dt;
				que[end].s = i, que[end++].t = up[i];
			}
		}
	}
	ans = 0;
	for (i = 0; i < n; i++) if (p[i] > ans) ans = p[i];
	printf("%d\n", ans);
	return 0;
}

