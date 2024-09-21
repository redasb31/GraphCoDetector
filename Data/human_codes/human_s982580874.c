// AOJ 2678 Cube Coloring
// 2018.2.27

#include <stdio.h>

#define ABS(a)	((a)>=0?(a):-(a))
int N;
int a[3], b[3], c[3];
long long df[3002];
long long df2[3002];
long long ans[1002];

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = 10*n + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

void calc(int a, int b, int c, int s)
{
	int i, x;
	long long t;

	if (a < b) x = a, a = b, b = x;
	if (a < c) x = a, a = c, c = x;
	if (b < c) x = b, b = c, c = x;
	if (!c) return;

	if (b == 1) {
		df[0] += a / N, df[N] -= a / N;
		df[s]++, df[s + a % N]--;
	} else if (c == 1) {
		if (a >= N) {
			t = (long long)(a / N) * b;
			df[0] += t, df[N] -= t;
			calc(a % N, b, c, s);
		} else {
			df2[s]++, df2[s + b]--;
			df2[s + a]--, df2[s + a + b]++;
		}
	} else if (a >= N) {
		t = (long long)a / N * b * c;
		df[0] += t, df[N] -= t;
		calc(a % N, b, c, s);
	} else for (i = 0; i < c; i++) calc(a, b, 1, (s + i) % N);
}

int main()
{
	int X, Y, Z, A, B, C, n3, i, ii, j, k;
	long long sum;

	X = in(), Y = in(), Z = in(), A = in(), B = in(), C = in(), N = in();
	n3 = 3*N;
	a[0] = A, a[1] = 1, a[2] = X-A-1;
	b[0] = B, b[1] = 1, b[2] = Y-B-1;
	c[0] = C, c[1] = 1, c[2] = Z-C-1;
	for (i = 0; i < 3; i++) for (j = 0; j < 3; j++) for (k = 0; k < 3; k++) {
		calc(a[i], b[j], c[k], (ABS(i-1) + ABS(j-1) + ABS(k-1)));
    }
    sum = 0; for (i = 0; i < n3; i++) sum += df2[i], df[i] += sum;
	sum = 0; for (ii = i = 0; i < n3; i++) {
		sum += df[i], ans[ii] += sum;
		if (++ii == N) ii = 0;
	}
	printf("%lld", ans[0]);
	for (i = 1; i < N; i++) printf(" %lld", ans[i]);
	putchar('\n');
	return 0;
}
