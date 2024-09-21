// AOJ 2060 Tetrahedra
// 2018.3.23 bal4u

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0, c = getchar_unlocked();
	do n = 10*n + (c & 0xf), c = getchar_unlocked(); while (c >= '0');
	return n;
}

long long max;
int a[16], a2[16], n;

int check(int i, int j, int k)
{
	int s = a[i] + a[j] + a[k];
	int z = a[i];
	if (z < a[j]) z = a[j];
	if (z < a[k]) z = a[k];
	return (z<<1) >= s;
}

void calc(int i, int j, int k, int p, int q, int r)
{
	long long V;
	long long A, B, C, P, Q, R;

	A = a2[i], B = a2[j], C = a2[k], P = a2[p], Q = a2[q], R = a2[r];
	V = A*R*(-A+B+C+P+Q-R) + B*Q*(A-B+C+P-Q+R) + C*P*(A+B-C-P+Q+R)
		- B*C*R - A*C*Q -A*B*P - P*Q*R;
	if (V > max) max = V;
}

int cmp(int *a, int *b) { return *a - *b; }

int main()
{
	int i, j, k, p, q, r;
	while (n = in()) {
		for (i = 0; i < n; i++) a[i] = in();
		qsort(a, n, sizeof(int), cmp);
		for (i = n-1; ; i--) if (a[i] < a[i-1]+a[i-2]) break;
		n = i+1;

		for (i = 0; i < n; i++) a2[i] = a[i]*a[i];

		max = 0;
		for (i = 0; i < n; i++) for (j = i+1; j < n; j++) for (k = j+1; k < n; k++) {
			if (check(i, j, k)) continue;
			for (p = 0; p < n; p++) {
			if (p == i || p == j || p == k || check(i, j, p)) continue;
			for (q = 0; q < n; q++) {
			if (q == i || q == j || q == k || q == p || check(i, k, q)) continue;
			for (r = 0; r < n; r++) {
			if (r == i || r == j || r == k || r == q || r == p || check(j, k, r)) continue;
			calc(i, j, k, p, q, r);
		}}}}
		printf("%.10lf\n", sqrt((double)max/144));
	}
	return 0;
}

