// AOJ 2239 Nearest Station
// 2018.4.7 bal4u

#include <stdio.h>
#include <stdlib.h>

#define ABS(a)  ((a)>=0?(a):-(a))

long long d[50]; int sz;
char f[50];

int cmp(long long *a, long long *b)
{
	if (*a == *b) return 0;
	if (*a < *b) return -1;
	return 1;
}

// 見つからなければ、一つ小さい要素を返す
int binarySearch(long long x)
{
	int m, l = 1, r = sz;

    while (l < r) {
        m = (l+r) >> 1;
		if (d[m] == x) return m;
        if (d[m] < x) l = m + 1; else r = m;
    }
	return l-1;
}

int main()
{
	int  i, j;
	long long n, m, a, b, p, q;
	long long g, s, t, pa, pb, ans;

	scanf("%lld%lld%lld%lld%lld%lld", &n, &m, &a, &b, &p, &q);
	if (a == 1 && b == 1) {
		s = p + q, t = m/s;
		if (t > n) t = n;
		ans = ABS(m - t*s);
		if (t < n) {
			if (++t > n) t = n;
			t = ABS(m - t*s);
			if (ans > t) ans = t;
		}
	} else {
		sz = 0, pa = pb = 1;
		for (i = 0; i < n; i++) {
			d[sz++] = s = p*pa + q*pb;
			if (s > m) break;
			if (s == m) { ans = 0; goto done; }
			pa *= a, pb *= b;
		}
		qsort(d, sz, sizeof(long long), cmp);

		ans = g = m, s = 0;
		while (sz) {
			i = binarySearch(g);
			t = ABS(d[i]-g);
			if (t < ans) {
				ans = t;
				if (!ans) goto done;
			}

			j = i+1; while (j < sz && d[j] == d[i]) j++;
			if (j < sz) {
				t = ABS(d[j]-g);
				if (t < ans) ans = t;
			}
			s += d[i], g = ABS(m-s);
			while (++i < sz) d[i-1] = d[i];
			sz--;
		}
	}
done:
	printf("%lld\n", ans);
	return 0;
}
