// AOJ 0284: Happy End Problem
// 2018.1.30 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M2	6.283185307179586476925286766559	// 2*pi

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	if (c == '-') {
		c = getchar_unlocked();
		do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
		while (c >= '0');
		return -n;
	}
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

typedef struct { int id, x, y; } P;
P p[41];
double a[41][41];
int c[41][41];
double dp[41][41][41][41]; char f[41][41][41][41];
int prev[41][41][41][41];
int ans[42];

int cmp(P *a, P *b) { if (a->y - b->y) return a->y - b->y; return a->x - b->x; }
int cross(int i, int j) { return p[i].x*p[j].y - p[i].y*p[j].x; }

int main()
{
	int N, Q, K, i, j, k, m, n;
	int ii, mm;
	double min;

	N = in();
	for (i = 0; i < N; i++) {
		p[i].id = i+1, p[i].x = in(), p[i].y = in();
	}
	qsort(p, N, sizeof(P), cmp);

	for (i = 0; i < N; i++ ) for(j = 0; j < N; j++) {
		c[i][j] = cross(i, j);
		if (i != j) {
			a[i][j] = atan2(p[j].y-p[i].y, p[j].x-p[i].x);
			if (a[i][j] < 0) a[i][j] += M2;
		}
	}

	for (i = 0; i < N; i++) {
		for (j = i+1; j < N; j++) dp[i][1][j][i] = c[i][j], f[i][1][j][i] = 1;
		for (j = 1; j < N; j++) for (k = i+1; k < N; k++) for (m = i; m < N; m++) {
			if (!f[i][j][k][m]) continue;
                         
			for (n = i; n < N; n++) if (n != m && n != k) {
				if (a[m][k] > a[k][n]) continue;
				if (!f[i][j+1][n][k] || dp[i][j+1][n][k] > dp[i][j][k][m] + c[k][n]) {
					dp[i][j+1][n][k] = dp[i][j][k][m] + c[k][n];
					f[i][j+1][n][k] = 1;
					prev[i][j+1][n][k] = m;
				}
			}
		}
	}

    Q = in();
	while (Q--) {
        K = in();
        min = 1e20, ii = mm = 0;
        for (i = 0; i < N; i++) for(m = 0; m < N; m++) {
			if (f[i][K][i][m] && min > dp[i][K][i][m]) {
				min = dp[i][K][i][m];
				ii = i, mm = m;
			}
		}

		if (min == 1e20) { puts("NA"); continue; }
		for (k = ii, i = 0; i < K; i++) {
			j = prev[ii][K-i][k][mm];
			k = mm, mm = j;
			ans[K-1-i] = p[k].id;
        }

		printf("%d", ans[0]);
		for (i = 1; i < K; i++) printf(" %d", ans[i]);
        putchar('\n');
    }
}
