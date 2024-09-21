#include <stdio.h>
#include <stdlib.h>

#define N	100000
#define M	100000
#define MD	1000000007

int ll[N], rr[N];

int compare_l(const void *a, const void *b) {
	int i = *(int *) a;
	int j = *(int *) b;

	return ll[i] != ll[j] ? ll[i] - ll[j] : rr[j] - rr[i];
}

int compare_r(const void *a, const void *b) {
	int i = *(int *) a;
	int j = *(int *) b;

	return rr[i] != rr[j] ? rr[i] - rr[j] : ll[j] - ll[i];
}

int ft[N + 1];

void update(int i, int n, int x) {
	while (i < n) {
		ft[i] = (ft[i] + x) % MD;
		i |= i + 1;
	}
}

int query(int i) {
	int x = 0;

	while (i >= 0) {
		x = (x + ft[i]) % MD;
		i &= i + 1, i--;
	}
	return x;
}

int main() {
	static int xx[N], yy[M], ii[N];
	int n, m, n_, i, j;

	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", &xx[i]);
	for (j = 0; j < m; j++)
		scanf("%d", &yy[j]);
	n_ = 0;
	for (i = 0, j = 0; i < n; i++) {
		while (j < m && yy[j] < xx[i])
			j++;
		if (j > 0 && j < m)
			ll[n_] = xx[i] - yy[j - 1], rr[n_] = yy[j] - xx[i], n_++;
	}
	n = n_;
	for (i = 0; i < n; i++)
		ii[i] = i;
	qsort(ii, n, sizeof *ii, compare_l);
	n_ = 0;
	for (i = 0; i < n; i++)
		if (n_ == 0 || ll[ii[n_ - 1]] != ll[ii[i]] || rr[ii[n_ - 1]] != rr[ii[i]])
			ii[n_++] = ii[i];
	n = n_;
	qsort(ii, n, sizeof *ii, compare_r);
	for (i = 0; i < n; i++)
		rr[ii[i]] = i + 1;
	qsort(ii, n, sizeof *ii, compare_l);
	update(0, n + 1, 1);
	for (i = 0; i < n; i++)
		update(rr[ii[i]], n + 1, query(rr[ii[i]] - 1));
	printf("%d\n", query(n));
	return 0;
}
