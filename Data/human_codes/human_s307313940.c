// AOJ 1284 The Teacher's Side of Math
// 2018.3.9 bal4u

#include <stdio.h>
#include <string.h>
#include <math.h>

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = 10*n + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

#define EPS        1e-8
#define N 23

double A[N][N], C[N];		// 行列の係数と右側
double X[N];				// 解
double B[N][N];				// ワーキング行列

// AX=C, 不定解時のリターン値はゼロ、正常な終了値は１
int gauss_jordan(int n)		// n x n 行列の大きさ
{
	int i, j, k, pivot;
	double t;

	for (i = 0; i < n; i++) for (j = 0; j < n; j++) B[i][j] = A[i][j];
	for (i = 0; i < n; i++) B[i][n] = C[i];

	for (i = 0; i < n; i++) {
		pivot = i;
		for (j = i; j < n; j++) {
			if (fabs(B[j][i]) > fabs(B[pivot][i])) pivot = j;
		}
		for (j = 0; j <= n; j++) {					// swap(B[i],B[pivot]);
			t = B[i][j], B[i][j] = B[pivot][j], B[pivot][j] = t;
		}
		if (fabs(B[i][i]) < EPS) return 0;			// error

		for (j = i+1; j <= n; j++) B[i][j] /= B[i][i];
		for (j = 0; j < n; j++) if (i != j) {
			for (k = i+1; k <= n; k++) B[j][k] -= B[j][i]*B[i][k];
		}
	}
	for (i = 0; i < n; i++) X[i] = B[i][n];
	return 1;
}

long long comb[N][N];

long long calc(int a, int p)
{
	long long ans = 1;
	while (p--) ans *= a;
	return ans;
}

int main()
{
	int a, m, b, n, mn, i, j;
	long long c;

	for (i = 0; i <= 21; i++) for (j = 0; j <= i; j++) {
		if (j == 0 || j == i) comb[i][j] = 1;
		else comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
	}

	while (a = in()) {
		m = in(), b = in(), n = in(), mn = m*n;

		memset(A, 0, sizeof(A));
		memset(C, 0, sizeof(A));
		A[0][0] = 1, C[0] = 1;
		for (i = 0; i <= mn; i++) for (j = 0; j <= i; j++) {
			c = comb[i][j] * calc(a, j/m) * calc(b, (i-j)/n);
			A[(j%m)*n+(i-j)%n+1][i<mn? i+1: 0] += c;
		}

		gauss_jordan(mn+1);
		putchar('1');
		for (i = mn; i > 0; i--) printf(" %d", (int)round(X[i]));
		putchar('\n');
	}
	return 0;
}
