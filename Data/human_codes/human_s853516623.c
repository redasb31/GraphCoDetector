// AOJ 2867 Many Kinds of Apples
// 2018.3.29 bal4u

#include <stdio.h>

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0, c = getchar_unlocked();
	do n = 10*n + (c & 0xf), c = getchar_unlocked(); while (c >= '0');
	return n;
}

int c[1002];
int a[1002];

int main()
{
	int N, Q, i, t, x, d, ans;

	N = in();
	for (i = 1; i <= N; i++) c[i] = in();
	Q = in();
	ans = 0;
	while (Q--) {
		t = in(), x = in(), d = in();
		if (t == 1) {
			a[x] += d;
			if (a[x] > c[x]) { ans = x; break; }
		} else {
			a[x] -= d;
			if (a[x] < 0) { ans = x; break; }
		}
	}
	printf("%d\n", ans);
	return 0;
}
