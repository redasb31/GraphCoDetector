#include <stdio.h>
#include <sys/time.h>

#define N	200000
#define M	200000

int min(int a, int b) { return a < b ? a : b; }

unsigned int X;

void srand_() {
	struct timeval tv;

	gettimeofday(&tv, NULL);
	X = tv.tv_sec ^ tv.tv_usec;
	if (X % 2 == 0)
		X++;
}

int rand_() {
	return (X *= 3) >> 1;
}

int ll[M], rr[M];

void sort(int *hh, int l, int r) {
	while (l < r) {
		int i = l, j = l, k = r, h = hh[l + rand_() % (r - l)], tmp;

		while (j < k)
			if (ll[hh[j]] == ll[h])
				j++;
			else if (ll[hh[j]] < ll[h]) {
				tmp = hh[i], hh[i] = hh[j], hh[j] = tmp;
				i++, j++;
			} else {
				k--;
				tmp = hh[j], hh[j] = hh[k], hh[k] = tmp;
			}
		sort(hh, l, i);
		l = k;
	}
}

int n;

void update(int *st, int i, int x) {
	for (i += n; i > 0; i >>= 1)
		st[i] = min(st[i], x);
}

int query(int *st, int l, int r) {
	int x = 0;

	for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
		if ((l & 1) == 1)
			x = min(x, st[l++]);
		if ((r & 1) == 0)
			x = min(x, st[r--]);
	}
	return x;
}

int main() {
	static int pp[N], hh[M], st1[N * 2], st2[N * 2];
	int m, h, i, d, ans;

	srand_();
	scanf("%d", &n);
	d = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &pp[i]);
		if (pp[i] == 0)
			pp[i] = 1;
		else
			pp[i] = -1, d++;
	}
	for (i = 1; i < n; i++)
		pp[i] += pp[i - 1];
	scanf("%d", &m);
	for (h = 0; h < m; h++) {
		scanf("%d%d", &ll[h], &rr[h]), ll[h]--, rr[h]--;
		hh[h] = h;
	}
	sort(hh, 0, m);
	ans = 0;
	for (h = 0; h < m; h++) {
		int h_ = hh[h], x;

		x = query(st1, ll[h_], rr[h_]);
		if (ll[h_] > 0)
			x = min(x, query(st2, 0, ll[h_] - 1) - pp[ll[h_] - 1]);
		x += pp[rr[h_]];
		ans = min(ans, x);
		update(st1, rr[h_], x - pp[rr[h_]]);
		update(st2, rr[h_], x);
	}
	ans += d;
	printf("%d\n", ans);
	return 0;
}
